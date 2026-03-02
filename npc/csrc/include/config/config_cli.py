#!/usr/bin/env python3
import os
import inquirer

def main():
    npc_home = os.getenv('NPC_HOME', os.path.dirname(os.path.dirname(os.path.dirname(__file__))))
    config_file = os.path.join(npc_home, 'csrc/include/config/config.h')

    current_config = {}
    if os.path.exists(config_file):
        with open(config_file, 'r') as f:
            for line in f:
                line = line.strip()
                if line.startswith('#define CONFIG_') and len(line.split()) >= 3:
                    parts = line.split()
                    option = parts[1]  
                    value = parts[2]   
                    option_name = option.replace('CONFIG_', '')
                    current_config[option_name] = (value == '1')
    
    questions = [
        inquirer.Checkbox('options',
            message="Option",
            choices=[
                ('波形跟踪   (WAVE)', 'WAVE'),
                ('差分测试   (DIFFTEST)', 'DIFFTEST'),
                ('函数跟踪   (FTRACE)', 'FTRACE'),
                ('事件跟踪   (ETRACE)', 'ETRACE'),
                ('内存跟踪   (MTRACE)', 'MTRACE'),
                ('环形缓冲区 (RINGBUFF)', 'RINGBUFF'),
                ('监视点     (WATCHPOINT)', 'WATCHPOINT'),
                ('快照恢复   (LIGHTSSS)', 'LIGHTSSS'),
                ('开启VGA    (VGA)', 'VGA'),
            ],
            default=[opt for opt, enabled in current_config.items() if enabled]
        )
    ]
    
    answers = inquirer.prompt(questions)
    
    if answers:
        content = """#ifndef __CONFIG_H__
#define __CONFIG_H__

"""
        
        all_options = ['WAVE', 'DIFFTEST', 'FTRACE', 'ETRACE', 'MTRACE', 'RINGBUFF', 'WATCHPOINT', 'LIGHTSSS', 'VGA']
        for option in all_options:
            enabled = option in answers['options']
            content += f"#define CONFIG_{option} {1 if enabled else 0}\n"

        content += "\n#endif\n"

        os.makedirs(os.path.dirname(config_file), exist_ok=True)
        with open(config_file, 'w') as f:
            f.write(content)

        print(f"Config save in {config_file}")
        print("Remake to adapt")

if __name__ == "__main__":
    main()

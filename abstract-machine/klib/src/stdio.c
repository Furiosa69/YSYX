#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int sprintf(char *out, const char *fmt, ...) {
    va_list ap;
    int len;

    // 清空缓冲区
    for (len = 0; out[len]; len++) {
        out[len] = '\0';
    }

    va_start(ap, fmt);
    len = vsprintf(out, fmt, ap);
    va_end(ap);

    return len;
}


int vsprintf(char *out, const char *fmt, va_list ap) {
    int len = 0;
    char buf[128];
    int buf_len = 0;

    while (*fmt != '\0') {
        if (*fmt == '%') {
            fmt++; // 跳过 '%'
            
            // 解析格式说明符
            int width = 0;
            int zero_pad = 0;
            
            // 检查零填充标志
            if (*fmt == '0') {
                zero_pad = 1;
                fmt++;
            }
            
            // 解析宽度
            while (*fmt >= '0' && *fmt <= '9') {
                width = width * 10 + (*fmt - '0');
                fmt++;
            }
            
            switch (*fmt) {
                case 'd': { // 处理 %d（有符号十进制整数）
                    int val = va_arg(ap, int);
                    int negative = 0;
                    buf_len = 0; // 重置缓冲区长度
                    
                    if (val == 0) {
                        buf[buf_len++] = '0';
                    } else {
                        if (val < 0) {
                            negative = 1;
                            val = -val;
                        }
                        
                        // 将数字转换为字符串（反向）
                        while (val > 0) {
                            buf[buf_len++] = "0123456789"[val % 10];
                            val /= 10;
                        }
                    }
                    
                    // 计算需要填充的数量
                    int total_digits = buf_len;
                    if (negative) total_digits++; // 负号占一个位置
                    
                    int padding = width > total_digits ? width - total_digits : 0;
                    
                    // 如果是零填充且有负号，先输出负号
                    if (negative && zero_pad) {
                        out[len++] = '-';
                        negative = 0; // 标记负号已处理
                    }
                    
                    // 输出填充
                    if (zero_pad) {
                        for (int i = 0; i < padding; i++) {
                            out[len++] = '0';
                        }
                    } else {
                        for (int i = 0; i < padding; i++) {
                            out[len++] = ' ';
                        }
                    }
                    
                    // 输出负号（如果还没输出）
                    if (negative) {
                        out[len++] = '-';
                    }
                    
                    // 输出数字（反向输出缓冲区）
                    for (int i = buf_len - 1; i >= 0; i--) {
                        out[len++] = buf[i];
                    }
                    break;
                }
                case 's': { // 处理 %s（字符串）
                    char *s = va_arg(ap, char*);
                    int str_len = 0;
                    
                    // 先计算字符串长度
                    char *temp = s;
                    while (*temp) {
                        str_len++;
                        temp++;
                    }
                    
                    // 计算需要填充的空格数量
                    int padding = width > str_len ? width - str_len : 0;
                    
                    // 输出空格填充
                    for (int i = 0; i < padding; i++) {
                        out[len++] = ' ';
                    }
                    
                    // 输出字符串
                    while (*s) {
                        out[len++] = *s++;
                    }
                    break;
                }
                case 'l': { // 处理 %lx（64 位无符号十六进制整数）
                    if (*(fmt + 1) == 'x') {
                        fmt++; // 跳过 'l'
                        unsigned long val = va_arg(ap, unsigned long);
                        buf_len = 0; // 重置缓冲区长度
                        
                        if (val == 0) {
                            buf[buf_len++] = '0';
                        } else {
                            // 将数字转换为十六进制字符串（反向）
                            while (val > 0) {
                                buf[buf_len++] = "0123456789abcdef"[val % 16];
                                val /= 16;
                            }
                        }
                        
                        // 计算需要填充的数量
                        int padding = width > buf_len ? width - buf_len : 0;
                        
                        // 输出填充
                        if (zero_pad) {
                            for (int i = 0; i < padding; i++) {
                                out[len++] = '0';
                            }
                        } else {
                            for (int i = 0; i < padding; i++) {
                                out[len++] = ' ';
                            }
                        }
                        
                        // 输出十六进制数字（反向输出缓冲区）
                        for (int i = buf_len - 1; i >= 0; i--) {
                            out[len++] = buf[i];
                        }
                    } else {
                        // 如果不是 %lx，直接输出 %l
                        out[len++] = '%';
                        out[len++] = 'l';
                    }
                    break;
                }
                default: // 处理其他格式（如 %%）
                    out[len++] = '%';
                    out[len++] = *fmt;
                    break;
            }
        } else {
            out[len++] = *fmt; // 普通字符直接输出
        }
        fmt++; // 移动到下一个字符
    }
    out[len] = '\0'; // 添加字符串结束符
    return len; // 返回输出字符串的长度
}
int printf(const char *fmt, ...) {
    char buf[128]; 
    int len;

    va_list ap;
    va_start(ap, fmt);

    len = vsprintf(buf, fmt, ap);

    va_end(ap);

    for (int i = 0; i < len; i++) {
        putch(buf[i]); 
    }

    return len; 
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif

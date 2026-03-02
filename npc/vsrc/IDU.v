module IDU (
	input  [31:0] inst,
	output [ 3:0] pc_cnt,
	output [ 3:0] lsu_cnt,
	output        mem_cnt,
	output [ 3:0] alu_cnt,
	output [ 5:0] ins_cnt,
	output [ 2:0] csr_cnt,
	output [ 4:0] rs1,
	output [ 4:0] rs2,
	output [ 4:0] rd,
	output [31:0] imm,
	output [11:0] csr_imm,
	output 				auipc,
	output 				lui,
	output				ebreak,
	output				load,
	output				jal,
	output 				jalr
);

	wire [6:0] opcode;
	wire [2:0] fun3;
	wire [6:0] fun7;

	assign opcode = inst[ 6: 0];
	assign   fun3 = inst[14:12]; 
	assign   fun7 = inst[31:25];

	assign  rd = inst[11: 7];
	assign rs1 = inst[19:15];
	assign rs2 = inst[24:20];

	wire UType,JType,BType,IType,SType,RType,IcsrType;
	assign ins_cnt = {UType,JType,BType,IType,SType,RType};

	// U Type
  assign auipc  = ( opcode == 7'b0010111 );
  assign lui    = ( opcode == 7'b0110111 );
  assign UType  = ( auipc | lui );
  // J Type
  assign JType  = ( opcode == 7'b1101111 ); // jal
	assign jal    = JType;
  // I Type
	assign jalr		= ( opcode == 7'b1100111 );
	assign load   = ( opcode == 7'b0000011 );
	wire 	 I_imm  = ( opcode == 7'b0010011 );
  assign IType  = ( jalr ) || ( load ) || ( I_imm );  // jalr lb lh lw lbu lhu addi slti sltiu xori ori andi alli slli srli srai 
  // B Type
  assign BType  = ( opcode == 7'b1100011 ); // beq bne blt bge blut bgeu
  // S Type
  assign SType  = ( opcode == 7'b0100011 ); // sb sh sw
  // R Type
  assign RType  = ( opcode == 7'b0110011 ); // add sub sll slt sltu xor srl sra or and
	// ICSR Type
	assign IcsrType = ( opcode == 7'b1110011); // ecall ebreak csrrw csrrs
	
  // others
	wire ecall,mret;
  assign ebreak = ( inst == 32'b00000000000100000000000001110011);
	assign ecall  = ( inst == 32'b00000000000000000000000001110011);
	assign mret   = ( inst == 32'b00110000001000000000000001110011);


	assign imm = ( {32{JType}} & {{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0} 						) | 
         			 ( {32{UType}} & {inst[31:12],{12{1'b0}}} 																					) |
							 ( {32{BType}} & {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0} ) |
         			 ( {32{SType}} & {{20{inst[31]}},inst[31:25],inst[11:7]} 														) |
         			 ( {32{IType}} & {{20{inst[31]}},inst[31:20]} );

	assign csr_cnt = IcsrType ? ( fun3 === 3'b001 ) ? 3'b001 : // csrrw
															( fun3 === 3'b010 ) ? 3'b010 : // csrrs
															( ebreak 					) ? 3'b011 : // ebreak
															( ecall           ) ? 3'b100 : // ecall
															( mret 						) ? 3'b101 : 3'b000 :// mret
									 3'b000;

	assign csr_imm = IcsrType ? inst[31:20] : 0 ;

	assign pc_cnt = BType ? ( fun3 === 3'b000 ) ? 4'b0001 : // beq
													( fun3 === 3'b001 ) ? 4'b0010 : // bne
													( fun3 === 3'b100 ) ? 4'b0011 : // blt
													( fun3 === 3'b101 ) ? 4'b0100 : // bge
													( fun3 === 3'b110 ) ? 4'b0101 : // bltu
													( fun3 === 3'b111 ) ? 4'b0110 : 4'b0000:// bgeu
	 								JType ? 4'b0111 : 
									jalr	? 4'b1000 :
									mret  ? 4'b1001 :
									ecall ? 4'b1010 :
									4'b0000;

	assign lsu_cnt = SType ? (( fun3 === 3'b000 ) ? 4'b0001 : // sb
													  ( fun3 === 3'b001 ) ? 4'b0010 : // sh
													  ( fun3 === 3'b010 ) ? 4'b0011 : 4'b0000):// sw
									 load  ? (( fun3 === 3'b000 ) ? 4'b0100 : // lb
													  ( fun3 === 3'b001 ) ? 4'b0101 : // lh
													  ( fun3 === 3'b010 ) ? 4'b0110 : // lw
													  ( fun3 === 3'b100 ) ? 4'b0111 : // lbu
													  ( fun3 === 3'b101 ) ? 4'b1000 : 4'b0000):// lhu
									 4'b0000; 

	assign mem_cnt = UType | JType | IType | RType | ( csr_cnt === 3'b001) | ( csr_cnt === 3'b010 );

	assign alu_cnt = ( RType ) ? (( fun3 === 3'b000 ) ? ((fun7 === 7'b0000000 ) ? 4'b0001 : 4'b0010): // + (add) / - (sub)
														    ( fun3 === 3'b010 ) ? 4'b0011 : // sign< (slt)
															  ( fun3 === 3'b011 ) ? 4'b0100 : // unsign< (sltu)
															  ( fun3 === 3'b111 ) ? 4'b0101 : // & (and)
															  ( fun3 === 3'b110 ) ? 4'b0110 : // | (or) 
															  ( fun3 === 3'b100 ) ? 4'b0111 : // ^ (xor)
															  ( fun3 === 3'b001 ) ? 4'b1000 : // <<0 (sll)
															  ( fun3 === 3'b101 ) ? ((fun7 === 7'b0000000 ) ? 4'b1001 : 4'b1010): 4'b0000):// 0>> (srl) / sign>> (sra)
									 ( I_imm ) ? (( fun3 === 3'b000 ) ? 4'b0001 : // + (addi)
									 						  ( fun3 === 3'b010 ) ? 4'b0011 : // sign< (slti)
														    ( fun3 === 3'b011 ) ? 4'b0100 : // unsign< (sltiu)
															  ( fun3 === 3'b111 ) ? 4'b0101 : // & (andi)
															  ( fun3 === 3'b110 ) ? 4'b0110 : // | (ori)
															  ( fun3 === 3'b100 ) ? 4'b0111 : // ^ (xori)
															  ( fun3 === 3'b001 ) ? 4'b1000 : // <<0 (slli)
															  ( fun3 === 3'b101 ) ? ((fun7 === 7'b0000000 ) ? 4'b1001 : 4'b1010): 4'b0000):// 0>> (srli) / sign>> (srai)
									 ( jalr ) ?                         4'b0001 :
									 ( jal  ) ? 												4'b0001 :
									 ( auipc) ? 												4'b0001 :
									 ( lui  ) ? 												4'b0001 :
									 ( IcsrType ) ? (( fun3 === 3'b010 ) ? 4'b0001 : // csrrs
									 								 ( fun3 === 3'b001 ) ? 4'b0001 : 4'b0000) : // csrrw
									 4'b0000;

endmodule

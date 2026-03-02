module EXU(
	input  [31:0] pc_in,
	input  [ 3:0] pc_cnt,
	input  [ 3:0] alu_cnt,
	input  [ 2:0] csr_cnt,
	input 				auipc,
	input 				lui,
	input 				jalr,
	input					load,
	input					jal,
	input  [31:0] imm,
	input  [31:0] csr_data,
	output [31:0] alu_result,
	output 				br_taken,
	input  [31:0] rdata1,
	input  [31:0] rdata2,
	input  [31:0] data_load,
	input  [ 5:0] ins_cnt 

);

	wire UType,JType,BType,IType,SType,RType;
	assign {UType,JType,BType,IType,SType,RType} = ins_cnt; 
	
	wire [31:0] alu_a,alu_b;

	assign alu_a = ( auipc ) ? pc_in :
								 ( lui   ) ? 32'b0 :
								 ( jalr  ) ? pc_in :
								 ( jal   ) ? pc_in : 
								 ( csr_cnt === 3'b010 ) ? csr_data :
								 ( csr_cnt === 3'b001 ) ? csr_data :
								 rdata1;

	assign alu_b = ( jal   ) ? 32'd4 :
								 ( jalr  ) ? 32'd4 :
								 ( UType | JType | IType ) ? imm :
								 ( RType | SType | BType ) ? rdata2 : 32'b0;

	assign br_taken = ( pc_cnt == 4'b0001 ) ? ($signed(alu_a) == $signed(alu_b)) :
										( pc_cnt == 4'b0010 ) ? ($signed(alu_a) != $signed(alu_b)) :
										( pc_cnt == 4'b0011 ) ? ($signed(alu_a) <  $signed(alu_b)) :
										( pc_cnt == 4'b0100 ) ? ($signed(alu_a) >= $signed(alu_b)) :
										( pc_cnt == 4'b0101 ) ? (        alu_a  <          alu_b ) :
										( pc_cnt == 4'b0110 ) ? (        alu_a  >=         alu_b ) : 
										1'b0;

	wire  [31:0]  _alu_result;
	wire  [63:0]  shift_temp ;
	assign shift_temp = ({{32{alu_a[31]}}, alu_a} >>	alu_b[4:0]);
	assign _alu_result = ( alu_cnt === 4'b0001 ) ? (  			 alu_a  + 				 alu_b ): // + (add/addi/jalr)
											 ( alu_cnt === 4'b0010 ) ? (  			 alu_a  - 				 alu_b ): // - (sub)
											 ( alu_cnt === 4'b0011 ) ? (($signed(alu_a) <  $signed(alu_b))? 32'd1:32'd0 ): // sign< (slt/slti)
											 ( alu_cnt === 4'b0100 ) ? ((        alu_a  <          alu_b )? 32'd1:32'd0 ): // unsign< (sltu/sltiu)
											 ( alu_cnt === 4'b0101 ) ? ( 				 alu_a  & 				 alu_b ): // & (and/andi)
											 ( alu_cnt === 4'b0110 ) ? ( 				 alu_a  | 				 alu_b ): // | (or/ori)
											 ( alu_cnt === 4'b0111 ) ? (         alu_a  ^ 				 alu_b ): // ^ (xor/xori)
											 ( alu_cnt === 4'b1000 ) ? ( 				 alu_a <<      alu_b[4:0]): // <<0 (sll/slli)
											 ( alu_cnt === 4'b1001 ) ? (         alu_a >>      alu_b[4:0]): // 0>> (srl/srli)
											 ( alu_cnt === 4'b1010 ) ? ( shift_temp[31:0] ): // sign>> (sra/srai)
											 32'b0;

	assign alu_result = ( load ) ? data_load : _alu_result;


endmodule

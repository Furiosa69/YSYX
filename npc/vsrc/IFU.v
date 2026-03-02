module IFU(
	input 						clk,
	input 						reset,
	input 		 [31:0]	imm,
	input							br_taken,
	output reg [31:0] inst,
	output reg [31:0] pc_out ,
	input 		 [31:0] ret,
	input 		 [31:0] csr_data,
	input 		 [ 3:0] pc_cnt  
);

	wire jalr  = (pc_cnt === 4'b1000);
	wire jal   = (pc_cnt === 4'b0111);
	wire ecall = (pc_cnt === 4'b1010);
	wire mret  = (pc_cnt === 4'b1001);
	wire bxx   = (pc_cnt === 4'b0001) | (pc_cnt === 4'b0010) | (pc_cnt === 4'b0011) | (pc_cnt === 4'b0100) | (pc_cnt === 4'b0101) | (pc_cnt === 4'b0110);

	wire [31:0] target_pc;
  assign target_pc  = (bxx && br_taken) ? pc_out + imm : 
                      (jal						) ? pc_out + imm :
		  				 	      (jalr 					) ? ret          : 
											(mret 					) ? csr_data 		 :
											(ecall				  ) ? csr_data     : 
											pc_out + 32'd4;

	always @(posedge clk) begin
		if(reset) begin
			pc_out <= 32'h80000000;
		end else begin
   	  pc_out 	<=  target_pc;
		end
	end

	always @(*) begin
		inst = pmem_read(pc_out, 4);
	end

endmodule


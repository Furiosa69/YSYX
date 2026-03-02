module GPR(
	input 				clk,
	input 				reset,
	input  [31:0] pc_in,
	input  [ 4:0] raddr1,
	input  [ 4:0] raddr2,
	output [31:0] rdata1,
	output [31:0] rdata2,
	input  [ 4:0] waddr,
	input	 [31:0] wdata,
	input 				ebreak,
	input         mem_cnt 
);

	reg [31:0] rf [0:31];

	wire wen;

	assign wen = mem_cnt;

	always @(posedge clk) begin
		if(reset) begin
			for(integer i = 1; i < 32; i = i + 1) rf[i] <= 0;
		end else begin
			if(wen && (waddr != 0)) rf[waddr] <= wdata;
		end
	end

	always @(*) begin
		if(ebreak) NPCTRAP(pc_in,rf[10]);
	end

	assign rdata1 = raddr1 == 0 ? 0 :rf[raddr1];
	assign rdata2 = raddr2 == 0 ? 0 :rf[raddr2];

endmodule 

module LSU (
	input  [ 3:0] lsu_cnt,
	output [31:0] data_load,
	input  [31:0] data_store,
	input  [31:0] addr_load,
	input  [31:0] addr_store
);

	reg [31:0] temp;
	
	always @(*) begin
			case(lsu_cnt)
				4'b0001 : begin
					pmem_write(addr_store, data_store, 1);	
					temp = 0;
				end
				4'b0010 : begin
					pmem_write(addr_store, data_store, 2);	
					temp = 0;
				end
				4'b0011 : begin
					pmem_write(addr_store, data_store, 4);	
					temp = 0;
				end
				4'b0100 : begin
					temp = pmem_read(addr_load,1);
				end
				4'b0101 : begin
					temp = pmem_read(addr_load,2);
				end
				4'b0110 : begin
					temp = pmem_read(addr_load ,4);
				end
				4'b0111 : begin
					temp = pmem_read(addr_load ,1);
				end
				4'b1000 : begin
					temp = pmem_read(addr_load ,2);
				end
				default : temp = 0;
			endcase
	end

	assign data_load = (lsu_cnt === 4'b0100) ? {{24{temp[ 7]}},temp[ 7:0]} :
								     (lsu_cnt === 4'b0101) ? {{16{temp[15]}},temp[15:0]} :
										 (lsu_cnt === 4'b0110) ? 								 temp				 :
										 (lsu_cnt === 4'b0111) ? {				 24'b0,temp[ 7:0]} :
										 (lsu_cnt === 4'b1000) ? {				 16'b0,temp[15:0]} :
										 32'b0;
endmodule

module CSR(
	input 				clk,
	input 				reset,
	input  [31:0] pc_in,
	input  [ 2:0] csr_cnt,
	input  [11:0] csr_imm,
	input  [31:0] wdata,
	output [31:0] rdata
);

	reg [31:0] mtvec  	;
	reg [31:0] mepc   	;
	reg [31:0] mstatus	;
	reg [31:0] mcause 	;
	reg [31:0] mcycle 	;
	reg [31:0] mcycleh	;
	reg [31:0] mvendorid;
	reg [31:0] marchid  ;

	wire [31:0] temp;

	assign rdata = ( csr_cnt === 3'b101 ) ? mepc  :
								 ( csr_cnt === 3'b100 ) ? mtvec :
								 temp;
								 
	assign temp = ( csr_imm === 12'h305 ) ? mtvec   	:
						    ( csr_imm === 12'h341 ) ? mepc    	:
						    ( csr_imm === 12'h300 ) ? mstatus 	:
						    ( csr_imm === 12'h342 ) ? mcause  	:
								( csr_imm === 12'hb00 ) ? mcycle  	:
								( csr_imm === 12'hb80 ) ? mcycleh 	:
								( csr_imm === 12'hf11 ) ? mvendorid :
								( csr_imm === 12'hf12 ) ? marchid 	:
						    0;

	always @(posedge clk) begin
		if(reset) begin
			mcycle	<= 0;
			mcycleh <= 0;
		end else if ( mcycle == 32'hffffffff ) begin
			mcycle 	<= 0;
			mcycleh <= mcycleh + 32'h1;
		end else begin
			mcycle  <= mcycle  + 32'h1;
		end
	end

	always @(posedge clk) begin
		if(reset) begin
			mtvec 		<= 0;
			mepc  		<= 0;
			mstatus 	<= 32'h1800;
			mcause  	<= 0;
			mvendorid <= 0;
			marchid 	<= 0;
		end if(csr_cnt === 3'b010) begin // csrrs
				case (csr_imm)
					12'h305 : mtvec   	<= temp | wdata ;
					12'h341 : mepc    	<= temp | wdata ;
					12'h300 : mstatus 	<= temp | wdata ;
					12'h342 : mcause  	<= temp | wdata ;
					12'hb00 : mcycle  	<= temp | wdata ;
					12'hb80 : mcycleh 	<= temp | wdata ;
					12'hf11 : mvendorid <= temp | wdata ;
					12'hf12 : marchid 	<= temp | wdata ;
				default : ;
				endcase
		end else if (csr_cnt === 3'b001) begin // csrrw
				case (csr_imm)
					12'h305 : mtvec   	<= wdata ;
					12'h341 : mepc    	<= wdata ;
					12'h300 : mstatus 	<= wdata ;
					12'h342 : mcause  	<= wdata ;
					12'hb00 : mcycle  	<= wdata ;
					12'hb80 : mcycleh 	<= wdata ;
					12'hf11 : mvendorid <= wdata ;
					12'hf12 : marchid 	<= wdata ;
				default : ;
				endcase
		end else if (csr_cnt === 3'b100) begin // ecall
				mepc   <= pc_in;
				mcause <= {1'b0, 31'd11};
		end else begin
			;
		end
	end

endmodule

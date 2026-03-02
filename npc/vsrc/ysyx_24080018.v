parameter GPR_WIDTH = 5;
parameter PC_WIDTH  = 32;
parameter INS_WIDTH = 32;

module ysyx_24080018(
	input 			    clock,
	input 			    reset,

  input           io_master_awready,
  output          io_master_awvalid,
  output [31:0]   io_master_awaddr ,
  input           io_master_wready ,
  output          io_master_wvalid ,
  output [31:0]   io_master_wdata  ,
  output [ 3:0]   io_master_wstrb  ,
  output          io_master_bready ,
  input           io_master_bvalid ,
  input  [ 1:0]   io_master_bresp  ,
  input           io_master_arready,
  output          io_master_arvalid,
  output [31:0]   io_master_araddr ,
  output          io_master_rready ,
  input           io_master_rvalid ,
  input  [ 1:0]   io_master_rresp  ,
  input  [31:0]   io_master_rdata
);

wire [GPR_WIDTH-1:0] idu_waddr,exu_waddr,mem_waddr;
wire [GPR_WIDTH-1:0] raddr1,raddr2;
wire [PC_WIDTH-1 :0] ifu_pc,idu_pc,exu_pc,mem_pc;
wire [INS_WIDTH-1:0] inst;
wire [ 3:0] idu_lsu_cnt,exu_lsu_cnt;
wire        idu_wbu_cnt,exu_wbu_cnt,mem_wbu_cnt;
wire 	      idu_ebreak,exu_ebreak,mem_ebreak;
wire [31:0] exu_wdata,mem_wdata;
wire [ 3:0] alu_cnt;
wire [ 5:0] ins_cnt;
wire [ 2:0] idu_csr_cnt,exu_csr_cnt;
wire [ 3:0] pc_cnt;
wire [31:0] rdata1,rdata2;
wire [31:0] addr_lsu;
wire [31:0] data_store;
wire [31:0] imm;
wire [11:0] csr_imm;
wire [31:0] csr_data;
wire 	      br_taken;
wire 	      auipc,lui,load,jalr,jal;
wire 	      ControlHazard;

wire ifu_idu_valid,idu_exu_valid,exu_mem_valid,mem_wbu_valid,exu_csr_valid;
wire idu_ifu_ready,exu_idu_ready,mem_exu_ready,wbu_mem_ready,csr_exu_ready;
wire wbu_ifu_retire,csr_ifu_retire;

wire [31:0] ret_addr;
assign ret_addr = (mem_waddr == raddr1) ? mem_wdata : rdata1;

ysyx_24080018_IFU ifu(
	.clk		        (clock),
	.reset		      (reset),
	.ifu_idu_valid	(ifu_idu_valid),
	.idu_ifu_ready	(idu_ifu_ready),
	.wbu_ifu_retire (wbu_ifu_retire),
	.csr_ifu_retire (csr_ifu_retire),
	.i_ControlHazard(ControlHazard),
	.i_imm		      (imm),
	.i_br_taken	    (br_taken),
	.i_pc_idu	      (idu_pc),
	.i_ret		      (ret_addr),
	.i_pc_cnt	      (pc_cnt),
	.o_inst		      (inst),
	.o_pc		        (ifu_pc),

  .o_ifu_araddr   (o_ifu_araddr ),
  .o_ifu_arvalid  (o_ifu_arvalid),
  .i_ifu_arready  (i_ifu_arready),
  .i_ifu_rdata    (i_ifu_rdata  ),
  .i_ifu_rresp    (i_ifu_rresp  ),
  .i_ifu_rvalid   (i_ifu_rvalid ),
  .o_ifu_rready   (o_ifu_rready ),
);

ysyx_24080018_IDU idu(
	.clk		        (clock),
	.reset		      (reset),
	.ifu_idu_valid	(ifu_idu_valid),
	.idu_ifu_ready	(idu_ifu_ready),
	.idu_exu_valid	(idu_exu_valid),
	.exu_idu_ready	(exu_idu_ready),
	.i_inst		      (inst),
	.i_pc		        (ifu_pc),
	.o_pc		        (idu_pc),
	.o_lsu_cnt	    (idu_lsu_cnt),
	.o_wbu_cnt	    (idu_wbu_cnt),
	.o_alu_cnt	    (alu_cnt),
	.o_ins_cnt	    (ins_cnt),
	.o_csr_cnt	    (idu_csr_cnt),
	.o_pc_cnt	      (pc_cnt),
	.o_auipc 	      (auipc),
	.o_lui		      (lui),
	.o_ebreak	      (idu_ebreak),
	.o_jalr		      (jalr),
	.o_jal 		      (jal),
	.o_load		      (load),
	.o_rd  		      (idu_waddr),
	.o_rs1 		      (raddr1),
	.o_rs2 		      (raddr2),
	.o_csr_imm	    (csr_imm),
	.o_imm		      (imm),
	.o_ControlHazard(ControlHazard)
);

ysyx_24080018_EXU exu(
	.clk	         (clock),
	.reset	       (reset),
	.idu_exu_valid (idu_exu_valid),
	.exu_idu_ready (exu_idu_ready),
	.exu_mem_valid (exu_mem_valid),
	.mem_exu_ready (mem_exu_ready),
	.exu_csr_valid (exu_csr_valid),
	.csr_exu_ready (csr_exu_ready),
	.o_pc	         (exu_pc),
	.o_alu_result  (exu_wdata),
	.o_br_taken    (br_taken),
	.o_data_store  (data_store),
	.o_addr_lsu    (addr_lsu),
	.o_waddr       (exu_waddr),
	.o_lsu_cnt     (exu_lsu_cnt),
	.o_ebreak      (exu_ebreak),
	.o_wbu_cnt     (exu_wbu_cnt),
	.o_csr_cnt     (exu_csr_cnt),
	.i_pc	         (idu_pc),
	.i_wbu_cnt     (idu_wbu_cnt),
	.i_ebreak      (idu_ebreak),
	.i_lsu_cnt		 (idu_lsu_cnt),
	.i_waddr			 (idu_waddr),
	.i_pc_cnt 		 (pc_cnt),
	.i_alu_cnt		 (alu_cnt),
	.i_ins_cnt		 (ins_cnt),
	.i_csr_cnt		 (idu_csr_cnt),
	.i_auipc			 (auipc),
	.i_lui 				 (lui),
	.i_load				 (load),
	.i_jalr				 (jalr),
	.i_jal 				 (jal),
	.i_imm 				 (imm),
	.i_csr_data		 (csr_data),
	.i_rdata1	 		 (rdata1),
	.i_rdata2	 		 (rdata2),
	.i_raddr1	 		 (raddr1),
	.i_raddr2	 		 (raddr2),
	.i_bypass_waddr(mem_waddr),
	.i_bypass_wdata(mem_wdata)

);

ysyx_24080018_LSU lsu(
	.clk					   (clock        ),
	.reset				   (reset        ),
	.exu_mem_valid   (exu_mem_valid),
	.mem_exu_ready   (mem_exu_ready),
	.mem_wbu_valid   (mem_wbu_valid),
	.wbu_mem_ready   (wbu_mem_ready),
	.o_waddr			   (mem_waddr    ),
	.o_wdata			   (mem_wdata    ),
	.o_ebreak			   (mem_ebreak   ),
	.o_pc					   (mem_pc       ),
	.o_wbu_cnt		   (mem_wbu_cnt  ),
	.i_pc					   (exu_pc       ),
	.i_wbu_cnt		   (exu_wbu_cnt  ),
	.i_ebreak			   (exu_ebreak   ),
	.i_waddr			   (exu_waddr    ),
	.i_wdata			   (exu_wdata    ),
	.i_lsu_cnt		   (exu_lsu_cnt  ),
	.i_lsu_wdata     (data_store   ),
	.i_lsu_addr      (addr_lsu     ),

  .o_lsu_awaddr   (o_lsu_awaddr ),
  .o_lsu_awvalid  (o_lsu_awvalid),
  .i_lsu_awready  (i_lsu_awready),
  .o_lsu_araddr   (o_lsu_araddr ),
  .o_lsu_arvalid  (o_lsu_arvalid),
  .i_lsu_arready  (i_lsu_arready),
  .i_lsu_rdata    (i_lsu_rdata  ),
  .i_lsu_rresp    (i_lsu_rresp  ),
  .i_lsu_rvalid   (i_lsu_rvalid ),
  .o_lsu_rready   (o_lsu_rready ),
  .o_lsu_wdata    (o_lsu_wdata  ),
  .o_lsu_wstrb    (o_lsu_wstrb  ),
  .o_lsu_wvalid   (o_lsu_wvalid ),
  .i_lsu_wready   (i_lsu_wready ),
  .i_lsu_bresp    (i_lsu_bresp  ),
  .i_lsu_bvalid   (i_lsu_bvalid ),
  .o_lsu_bready   (o_lsu_bready )
);

ysyx_24080018_GPR gpr(
	.clk					 (clock),
	.reset				 (reset),
	.mem_wbu_valid (mem_wbu_valid),
	.wbu_mem_ready (wbu_mem_ready),
	.wbu_ifu_retire(wbu_ifu_retire),
	.rdata1				 (rdata1),
	.rdata2				 (rdata2),
	.raddr1				 (raddr1),
	.raddr2				 (raddr2),
	.i_wbu_cnt		 (mem_wbu_cnt),
	.i_ebreak 		 (mem_ebreak),
	.i_pc					 (mem_pc),
	.i_waddr			 (mem_waddr),
	.i_wdata			 (mem_wdata)
);

ysyx_24080018_CSR csr(
	.clk					 (clock),
	.reset				 (reset),
	.exu_csr_valid (exu_csr_valid),
	.csr_exu_ready (csr_exu_ready),
	.csr_ifu_retire(csr_ifu_retire),
	.i_csr_cnt		 (exu_csr_cnt),
	.i_csr_imm		 (csr_imm),
	.i_wdata			 (rdata1),
	.o_rdata			 (csr_data)
);

ysyx_24080018_arbiter arbiter(
  .clock         (clock),
  .reset         (reset),

  .o_ifu_araddr  (o_ifu_araddr ),
  .o_ifu_arvalid (o_ifu_arvalid),
  .i_ifu_arready (i_ifu_arready),
  .i_ifu_rdata   (i_ifu_rdata  ),
  .i_ifu_rresp   (i_ifu_rresp  ),
  .i_ifu_rvalid  (i_ifu_rvalid ),
  .o_ifu_rready  (o_ifu_rready ),
                               
  .o_lsu_awaddr  (o_lsu_awaddr ),
  .o_lsu_awvalid (o_lsu_awvalid),
  .i_lsu_awready (i_lsu_awready),
  .o_lsu_araddr  (o_lsu_araddr ),
  .o_lsu_arvalid (o_lsu_arvalid),
  .i_lsu_arready (i_lsu_arready),
  .i_lsu_rdata   (i_lsu_rdata  ),
  .i_lsu_rresp   (i_lsu_rresp  ),
  .i_lsu_rvalid  (i_lsu_rvalid ),
  .o_lsu_rready  (o_lsu_rready ),
  .o_lsu_wdata   (o_lsu_wdata  ),
  .o_lsu_wstrb   (o_lsu_wstrb  ),
  .o_lsu_wvalid  (o_lsu_wvalid ),
  .i_lsu_wready  (i_lsu_wready ),
  .i_lsu_bresp   (i_lsu_bresp  ),
  .i_lsu_bvalid  (i_lsu_bvalid ),
  .o_lsu_bready  (o_lsu_bready ),

  .io_master_awready (io_master_awready),
  .io_master_awvalid (io_master_awvalid),
  .io_master_awaddr  (io_master_awaddr ),
  .io_master_wready  (io_master_wready ),
  .io_master_wvalid  (io_master_wvalid ),
  .io_master_wdata   (io_master_wdata  ),
  .io_master_wstrb   (io_master_wstrb  ),
  .io_master_bready  (io_master_bready ),
  .io_master_bvalid  (io_master_bvalid ),
  .io_master_bresp   (io_master_bresp  ),
  .io_master_arready (io_master_arready),
  .io_master_arvalid (io_master_arvalid),
  .io_master_araddr  (io_master_araddr ),
  .io_master_rready  (io_master_rready ),
  .io_master_rvalid  (io_master_rvalid ),
  .io_master_rresp   (io_master_rresp  ),
  .io_master_rdata   (io_master_rdata  )
);
endmodule

	

module ysyx_24080018_IFU( 
  input             clk,
  input             reset,

  output            ifu_idu_valid,
  input             idu_ifu_ready,
  input							wbu_ifu_retire,
	input 						csr_ifu_retire,
  
	input 						i_ControlHazard,
  input      [31:0] i_imm,
  input             i_br_taken,
	input	[PC_WIDTH-1:0] i_pc_idu,
  input      [31:0] i_ret,
  input      [ 3:0] i_pc_cnt,

  output 		 [INS_WIDTH-1:0] o_inst,
  output reg [PC_WIDTH-1:0] o_pc,

  output     [31:0] o_ifu_araddr   ,
  output            o_ifu_arvalid  ,
  input             i_ifu_arready  ,

  input      [31:0] i_ifu_rdata    ,
  input      [ 1:0] i_ifu_rresp    ,
  input             i_ifu_rvalid   ,
  output            o_ifu_rready   
);

  wire jalr  = (i_pc_cnt === 4'b1000);
  wire jal   = (i_pc_cnt === 4'b0111);
  wire bxx   = (i_pc_cnt === 4'b0001) | (i_pc_cnt === 4'b0010) | (i_pc_cnt === 4'b0011) | (i_pc_cnt === 4'b0100) | (i_pc_cnt === 4'b0101) | (i_pc_cnt === 4'b0110);

  wire [PC_WIDTH-1:0] target_pc;
	wire retire;
	assign retire = wbu_ifu_retire || csr_ifu_retire;
  assign target_pc  = (bxx && !i_br_taken) ? o_pc :
											(bxx &&  i_br_taken) ? (i_ControlHazard) ? (i_pc_idu + i_imm) : o_pc + i_imm : 
                      (jal            	 ) ? (i_ControlHazard) ? (i_pc_idu + i_imm) : o_pc + i_imm :
                      (jalr           	 ) ? i_ret          : 
                      o_pc + 32'd4;
  
  localparam IDLE = 1'b0;
  localparam WAIT = 1'b1;
  reg cstate, nstate;
	reg [PC_WIDTH-1:0] temp_pc;

  assign o_ifu_rready   = (cstate == IDLE);
  assign ifu_idu_valid  = i_ifu_rvalid && (i_ifu_rresp == 2'h0) && o_ifu_rready;
	assign o_ifu_araddr 	= (temp_pc != o_pc) && (temp_pc != 0) ? temp_pc : o_pc;

	reg prev_idle;
	
	assign o_ifu_arvalid  = (!reset && (cstate == IDLE) && 
	                        (!prev_idle  && !i_ControlHazard) &&       // 刚进入IDLE且无冒险
                          (i_ifu_arready)
	                        ) ? 1'b1 : 1'b0;

  always @(posedge clk) begin
    if(reset) begin
      o_pc <= 32'h30000000;
	    prev_idle <= 1'b0;
			temp_pc <= 0;
    end else begin
	    prev_idle <= (cstate == IDLE);
			if (i_ControlHazard) begin
				temp_pc <= target_pc; // 没办法改变了
      end else if (retire) begin
        o_pc <= (temp_pc != o_pc ) && (temp_pc != 0 ) ? temp_pc : target_pc;
      end 
			if (o_ifu_arvalid) begin
				temp_pc <= 0;
			end
    end
  end

	assign o_inst = i_ifu_rdata;

  always @(posedge clk) begin
    if(reset) begin
      cstate <= IDLE;
    end else begin
      cstate <= nstate;
    end
  end

  always @(*) begin
    case (cstate)
      IDLE : begin
				if (i_ControlHazard) begin
					nstate = IDLE;
        end else if ((target_pc != o_pc) && i_ifu_rvalid && (i_ifu_rresp == 2'h0)) begin
          nstate = WAIT;
        end else begin
          nstate = IDLE;
        end
      end
      WAIT : begin
				if (i_ControlHazard) begin
						nstate = WAIT;
        end else if (retire) begin
          if (target_pc != o_pc) begin
            nstate = IDLE;  
          end else begin
            nstate = WAIT;  
          end
        end else begin
          nstate = WAIT;    
        end
      end
      default: begin
        nstate = IDLE;
      end
    endcase
  end

endmodule

module ysyx_24080018_IDU (
	input							clk,
	input							reset,

  input             ifu_idu_valid,
  output            idu_ifu_ready,
  output            idu_exu_valid,
  input             exu_idu_ready,

  input  		 [INS_WIDTH-1:0] i_inst,
	input			 [PC_WIDTH-1:0] i_pc,
	
	output reg [PC_WIDTH-1:0] o_pc,
  output reg [ 3:0] o_pc_cnt,
  output reg [ 3:0] o_lsu_cnt,
  output reg        o_wbu_cnt,
  output reg [ 3:0] o_alu_cnt,
  output reg [ 5:0] o_ins_cnt,
  output reg [ 2:0] o_csr_cnt,
  output reg [GPR_WIDTH-1:0] o_rs1,
  output reg [GPR_WIDTH-1:0] o_rs2,
  output reg [GPR_WIDTH-1:0] o_rd,
  output reg [31:0] o_imm,
  output reg [11:0] o_csr_imm,
  output reg        o_auipc,
  output reg        o_lui,
  output reg        o_ebreak,
  output reg        o_load,
  output reg        o_jal,
  output reg        o_jalr,
	output reg				o_ControlHazard 
);

  wire [ 6:0] opcode;
  wire [ 2:0] fun3;
  wire [ 6:0] fun7;
  wire [ 3:0] pc_cnt;
  wire [ 3:0] lsu_cnt;
  wire        wbu_cnt;
  wire [ 3:0] alu_cnt;
  wire [ 5:0] ins_cnt;
  wire [ 2:0] csr_cnt;
  wire [GPR_WIDTH-1:0] rs1;
  wire [GPR_WIDTH-1:0] rs2;
  wire [ 4:0] rd;
  wire [31:0] imm;
  wire [11:0] csr_imm;
  wire        auipc;
  wire        lui;
  wire        ebreak;
  wire        load;
  wire        jal;
  wire        jalr;

  assign opcode = i_inst[ 6: 0];
  assign   fun3 = i_inst[14:12];
  assign   fun7 = i_inst[31:25];

  assign  rd = i_inst[11: 7];
  assign rs1 = i_inst[19:15];
  assign rs2 = i_inst[24:20];

  wire UType,JType,BType,IType,SType,RType,IcsrType;
  assign ins_cnt = {UType,JType,BType,IType,SType,RType};

  // U Type
  assign auipc  = ( opcode == 7'b0010111 );
  assign lui    = ( opcode == 7'b0110111 );
  assign UType  = ( auipc | lui );
  // J Type
  assign JType  = ( opcode == 7'b1101111 );           // jal
  assign jal    = JType;
  // I Type
  assign jalr   = ( opcode == 7'b1100111 );
  assign load   = ( opcode == 7'b0000011 );
  wire   I_imm  = ( opcode == 7'b0010011 );
  assign IType  = ( jalr ) || ( load ) || ( I_imm );  // jalr lb lh lw lbu lhu addi slti sltiu xori ori andi alli slli srli srai 
  // B Type
  assign BType  = ( opcode == 7'b1100011 );           // beq bne blt bge blut bgeu
  // S Type
  assign SType  = ( opcode == 7'b0100011 );           // sb sh sw
  // R Type
  assign RType  = ( opcode == 7'b0110011 );           // add sub sll slt sltu xor srl sra or and
  // ICSR Type
  assign IcsrType = ( opcode == 7'b1110011);          // ecall ebreak csrrw csrrs
	// others
  wire ecall,mret;
  assign ebreak = ( i_inst == 32'b00000000000100000000000001110011);
  assign ecall  = ( i_inst == 32'b00000000000000000000000001110011);
  assign mret   = ( i_inst == 32'b00110000001000000000000001110011);


  assign imm = ( {32{JType}} & {{12{i_inst[31]}},i_inst[19:12],i_inst[20],i_inst[30:21],1'b0}             ) |
               ( {32{UType}} & {i_inst[31:12],{12{1'b0}}}                                           ) |
               ( {32{BType}} & {{19{i_inst[31]}}, i_inst[31], i_inst[7], i_inst[30:25], i_inst[11:8], 1'b0} ) |
               ( {32{SType}} & {{20{i_inst[31]}},i_inst[31:25],i_inst[11:7]}                            ) |
               ( {32{IType}} & {{20{i_inst[31]}},i_inst[31:20]} );

  assign csr_cnt = IcsrType ? ( fun3 === 3'b001 ) ? 3'b001 :         // csrrw
                              ( fun3 === 3'b010 ) ? 3'b010 :         // csrrs
                              ( ebreak          ) ? 3'b011 :         // ebreak
                              ( ecall           ) ? 3'b100 :         // ecall
                              ( mret            ) ? 3'b101 : 3'b000 :// mret
                   3'b000;

  assign csr_imm = IcsrType ? i_inst[31:20] : 0 ;

  assign pc_cnt = BType ? ( fun3 === 3'b000 ) ? 4'b0001 :         // beq
                          ( fun3 === 3'b001 ) ? 4'b0010 :         // bne
                          ( fun3 === 3'b100 ) ? 4'b0011 :         // blt
                          ( fun3 === 3'b101 ) ? 4'b0100 :         // bge
                          ( fun3 === 3'b110 ) ? 4'b0101 :         // bltu
                          ( fun3 === 3'b111 ) ? 4'b0110 : 4'b0000:// bgeu
                  JType ? 4'b0111 :
                  jalr  ? 4'b1000 :
                  mret  ? 4'b1001 :
                  ecall ? 4'b1010 :
                  4'b0000;

  assign lsu_cnt = SType ? (( fun3 === 3'b000 ) ? 4'b0001 :          // sb
                            ( fun3 === 3'b001 ) ? 4'b0010 :          // sh
                            ( fun3 === 3'b010 ) ? 4'b0011 : 4'b0000):// sw
                   load  ? (( fun3 === 3'b000 ) ? 4'b0100 :          // lb
                            ( fun3 === 3'b001 ) ? 4'b0101 :          // lh
                            ( fun3 === 3'b010 ) ? 4'b0110 :          // lw
                            ( fun3 === 3'b100 ) ? 4'b0111 :          // lbu
                            ( fun3 === 3'b101 ) ? 4'b1000 : 4'b0000):// lhu
                   4'b0000;

  assign wbu_cnt = UType | JType | IType | RType | ( csr_cnt === 3'b001) | ( csr_cnt === 3'b010 );

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
                   ( jalr ) ?    4'b0001 :
                   ( jal  ) ?    4'b0001 :
                   ( auipc) ?    4'b0001 :
                   ( lui  ) ?    4'b0001 :
                   ( IcsrType ) ? (( fun3 === 3'b010 ) ? 4'b0001 :            // csrrs
                                   ( fun3 === 3'b001 ) ? 4'b0001 : 4'b0000) : // csrrw
                   4'b0000;

  localparam IDLE = 1'b0;
  localparam DECODE = 1'b1;
  reg cstate, nstate;

  assign idu_ifu_ready = (cstate == IDLE) ;
  assign idu_exu_valid = (cstate == DECODE);


	always @(posedge clk) begin
    if(reset) begin
			cstate <= IDLE;
    end else begin
			cstate <= nstate;
    end
  end

  always @(*) begin
    case (cstate)
      IDLE : begin
        if(ifu_idu_valid && !o_ControlHazard) begin
          nstate = DECODE;  
        end else begin
          nstate = IDLE;    
        end
      end
      DECODE : begin
				if ( o_ControlHazard ) begin
					nstate = IDLE;
				end else if (exu_idu_ready) begin
          nstate = IDLE;    
        end else begin
          nstate = DECODE;  
        end
      end
      default: begin
        nstate = IDLE;
      end
    endcase
  end

  always @(posedge clk) begin
    if(reset) begin
      o_ControlHazard <= 1'b0;
			o_pc			<= 32'h30000000;
      o_pc_cnt  <= 4'b0;
      o_lsu_cnt <= 4'b0;
      o_wbu_cnt <= 1'b0;
      o_alu_cnt <= 4'b0;
      o_ins_cnt <= 6'b0;
      o_csr_cnt <= 3'b0;
      o_rs1 		<= 5'b0;
      o_rs2 		<= 5'b0;
      o_rd 			<= 5'b0;
      o_imm 		<= 32'b0;
      o_csr_imm <= 12'b0;
      o_auipc 	<= 1'b0;
      o_lui 		<= 1'b0;
      o_ebreak  <= 1'b0;
      o_load 		<= 1'b0;
      o_jal  		<= 1'b0;
      o_jalr 		<= 1'b0;
    end else begin
      case (cstate)
        IDLE : begin
          if(ifu_idu_valid) begin
        		o_ControlHazard <= (pc_cnt != 4'b0000) ;
						o_pc			<= i_pc;
            o_pc_cnt  <= pc_cnt;
            o_lsu_cnt <= lsu_cnt;
            o_wbu_cnt <= wbu_cnt;
            o_alu_cnt <= alu_cnt;
            o_ins_cnt <= ins_cnt;
            o_csr_cnt <= csr_cnt;
            o_rs1 		<= rs1;
            o_rs2 		<= rs2;
            o_rd  		<= (ecall || ebreak || SType || BType) ? 0 : rd;
            o_imm 		<= imm;
            o_csr_imm <= csr_imm;
            o_auipc 	<= auipc;
            o_lui 		<= lui;
            o_ebreak  <= ebreak;
            o_load 		<= load;
            o_jal  		<= jal;
            o_jalr 		<= jalr;
          end
        end
        DECODE : begin
					o_ControlHazard <= 1'b0;
  				if(exu_idu_ready) begin
						o_pc			<= o_pc;
  				  o_pc_cnt  <= 4'b0;
  				  o_lsu_cnt <= 4'b0;
  				  o_wbu_cnt <= 1'b0;
  				  o_alu_cnt <= 4'b0;
  				  o_ins_cnt <= 6'b0;
  				  o_csr_cnt <= 3'b0;
  				  o_rs1 		<= 5'b0;
  				  o_rs2 		<= 5'b0;
  				  o_rd 			<= 5'b0;
  				  o_imm 		<= 32'b0;
  				  o_csr_imm <= 12'b0;
  				  o_auipc   <= 1'b0;
  				  o_lui 		<= 1'b0;
  				  o_ebreak  <= 1'b0;
  				  o_load 		<= 1'b0;
  				  o_jal  		<= 1'b0;
  				  o_jalr 		<= 1'b0;
  				end else begin
  				end
        end
      endcase
    end
  end

endmodule


module ysyx_24080018_EXU(
  input             clk,
  input             reset,

  input             idu_exu_valid,
  output            exu_idu_ready,
  output            exu_mem_valid,
  input             mem_exu_ready,
  output            exu_csr_valid,
  input             csr_exu_ready,

	input 				    i_ebreak,
  input  [31:0]     i_rdata1,
  input  [31:0]     i_rdata2,
	input	 [GPR_WIDTH-1:0]     i_waddr,
  input  [ 5:0]     i_ins_cnt,
  input  [PC_WIDTH-1:0]     i_pc,
  input  [ 3:0]     i_pc_cnt,
  input  [ 3:0]     i_alu_cnt,
  input  [ 2:0]     i_csr_cnt,
  input             i_auipc,
  input             i_lui,
  input             i_jalr,
  input             i_load,
  input             i_jal,
  input  [31:0]     i_imm,
  input  [31:0]     i_csr_data,
	input	 [ 3:0]     i_lsu_cnt,
	input					    i_wbu_cnt,
	input	 [GPR_WIDTH-1:0]     i_raddr1,
	input	 [GPR_WIDTH-1:0]     i_raddr2,
	input	 [GPR_WIDTH-1:0]     i_bypass_waddr,
	input	 [31:0]     i_bypass_wdata,

	output reg 				o_wbu_cnt,
	output reg 				o_ebreak,
	output reg [ 2:0] o_csr_cnt,
	output reg [ 3:0] o_lsu_cnt,
	output reg [GPR_WIDTH-1:0] o_waddr,
	output reg [31:0] o_data_store,
	output reg [31:0] o_addr_lsu,
	output reg [PC_WIDTH-1:0] o_pc ,
  output reg [31:0] o_alu_result,
  output        		o_br_taken
);

  localparam IDLE = 1'b0;
  localparam WAIT = 1'b1;
  reg cstate, nstate;

  wire UType,JType,BType,IType,SType,RType;
  assign {UType,JType,BType,IType,SType,RType} = i_ins_cnt;

  wire  [31:0]  _alu_result;

  assign exu_mem_valid = cstate === WAIT && (i_csr_cnt === 3'b0);
  assign exu_csr_valid = cstate === WAIT && (i_csr_cnt != 3'b0);

  assign exu_idu_ready = (cstate == IDLE);

  always @(posedge clk) begin
    if(reset) begin
      cstate <= IDLE;
		end else begin
      cstate <= nstate;
    end
  end

  always @(*) begin
    	case (cstate)
    	  IDLE : begin
    	    if(idu_exu_valid) begin
    	      nstate = WAIT;  
    	    end else begin
    	      nstate = IDLE;     
    	    end
    	  end
    	  WAIT : begin
    	    if(i_load || SType) begin
						if(mem_exu_ready) begin
							nstate = IDLE;
						end else begin
							nstate = WAIT;
						end
    	    end else if(i_csr_cnt != 3'b000) begin
						if(csr_exu_ready) begin
							nstate = IDLE;
						end else begin
							nstate = WAIT;
						end
    	    end else begin
    	      nstate = IDLE;      
    	    end
    	  end
    	  default: begin
    	    nstate = IDLE;
    	  end
    	endcase
  end

  always @(posedge clk) begin
    if(reset) begin
			o_pc							<= 32'h30000000;
			o_waddr 				  <= 5'b0;
    end else begin
      case (cstate)
        IDLE : begin
          if(idu_exu_valid) begin
						o_pc 				 <= i_pc ;
						o_lsu_cnt		 <= i_lsu_cnt;
						o_waddr 		 <= i_waddr;
						o_data_store <= ((i_bypass_waddr != 0) && (i_bypass_waddr == i_raddr2)) ? i_bypass_wdata : i_rdata2 ;
						o_addr_lsu	 <= ((i_bypass_waddr != 0) && (i_bypass_waddr == i_raddr1)) ? i_bypass_wdata + i_imm : i_rdata1 + i_imm;
						o_alu_result <= _alu_result;
						o_ebreak		 <= i_ebreak;
						o_csr_cnt 	 <= i_csr_cnt;
						o_wbu_cnt		 <= i_wbu_cnt;
          end
        end
        WAIT : begin
        end
      endcase
    end
  end


  wire [31:0] alu_a,alu_b;

  assign alu_a = ( i_jalr  ) ? i_pc 	:
								 ( (RType | IType | SType | BType) && (i_bypass_waddr == i_raddr1)  && (i_bypass_waddr != 0)) ? i_bypass_wdata : // RAW
								 ( i_auipc ) ? i_pc   :
                 ( i_lui   ) ? 32'b0  :
                 ( i_jal   ) ? i_pc 	:
                 ( i_csr_cnt === 3'b010 ) ? i_csr_data :
                 ( i_csr_cnt === 3'b001 ) ? i_csr_data :
                 i_rdata1;

  assign alu_b = ( (RType | SType | BType) && (i_bypass_waddr == i_raddr2)  && (i_bypass_waddr != 0)) ? i_bypass_wdata : // RAW
								 ( i_jal   ) ? 32'd4 :
                 ( i_jalr  ) ? 32'd4 :
                 ( UType | JType | IType ) ? i_imm :
                 ( RType | SType | BType ) ? i_rdata2 : 32'b0;

  wire _br_taken;
  assign _br_taken = ( i_pc_cnt == 4'b0001 ) ? ($signed(alu_a) == $signed(alu_b)) :
                     ( i_pc_cnt == 4'b0010 ) ? ($signed(alu_a) != $signed(alu_b)) :
                     ( i_pc_cnt == 4'b0011 ) ? ($signed(alu_a) <  $signed(alu_b)) :
                     ( i_pc_cnt == 4'b0100 ) ? ($signed(alu_a) >= $signed(alu_b)) :
                     ( i_pc_cnt == 4'b0101 ) ? (        alu_a  <          alu_b ) :
                     ( i_pc_cnt == 4'b0110 ) ? (        alu_a  >=         alu_b ) :
                     1'b0;
	assign o_br_taken = _br_taken;

  wire  [63:0]  shift_temp ;
  assign shift_temp = ({{32{alu_a[31]}}, alu_a} >>  alu_b[4:0]);
  assign _alu_result = ( i_alu_cnt === 4'b0001 ) ? (         alu_a  +          alu_b ): // + (add/addi/jalr)
                       ( i_alu_cnt === 4'b0010 ) ? (         alu_a  -          alu_b ): // - (sub)
                       ( i_alu_cnt === 4'b0011 ) ? (($signed(alu_a) <  $signed(alu_b))? 32'd1:32'd0 ): // sign< (slt/slti)
                       ( i_alu_cnt === 4'b0100 ) ? ((        alu_a  <          alu_b )? 32'd1:32'd0 ): // unsign< (sltu/sltiu)
                       ( i_alu_cnt === 4'b0101 ) ? (         alu_a  &          alu_b ): // & (and/andi)
                       ( i_alu_cnt === 4'b0110 ) ? (         alu_a  |          alu_b ): // | (or/ori)
                       ( i_alu_cnt === 4'b0111 ) ? (         alu_a  ^          alu_b ): // ^ (xor/xori)
                       ( i_alu_cnt === 4'b1000 ) ? (         alu_a <<      alu_b[4:0]): // <<0 (sll/slli)
                       ( i_alu_cnt === 4'b1001 ) ? (         alu_a >>      alu_b[4:0]): // 0>> (srl/srli)
                       ( i_alu_cnt === 4'b1010 ) ? ( shift_temp[31:0] ):                // sign>> (sra/srai)
                       32'b0;

endmodule

module ysyx_24080018_LSU (
  input             clk,
  input             reset,

  input             exu_mem_valid,
  output            mem_exu_ready,
  output            mem_wbu_valid,
  input             wbu_mem_ready,

	output reg [31:0] o_wdata,
	output reg [GPR_WIDTH-1:0] o_waddr,
	output reg 				o_wbu_cnt,
	output reg				o_ebreak,
	output reg [PC_WIDTH-1:0] o_pc,
	input			 [PC_WIDTH-1:0] i_pc,
	input							i_ebreak,
	input			 				i_wbu_cnt,
	input 		 [GPR_WIDTH-1:0] i_waddr,
	input			 [31:0] i_wdata,
  input  		 [ 3:0] i_lsu_cnt,
  input  		 [31:0] i_lsu_wdata,
  input  		 [31:0] i_lsu_addr,

  output     [31:0] o_lsu_awaddr ,// tochange
  output            o_lsu_awvalid,// ok
  input             i_lsu_awready,// ok

  output     [31:0] o_lsu_araddr ,// tochange
  output            o_lsu_arvalid,// ok
  input             i_lsu_arready,// ok

  input      [31:0] i_lsu_rdata  ,// ok
  input      [ 1:0] i_lsu_rresp  ,// ok
  input             i_lsu_rvalid ,// ok
  output            o_lsu_rready ,// ok

  output     [31:0] o_lsu_wdata  ,// ok
  output     [ 3:0] o_lsu_wstrb  ,// ok
  output            o_lsu_wvalid ,// ok
  input             i_lsu_wready ,// ok

  input      [ 1:0] i_lsu_bresp  ,// ok
  input             i_lsu_bvalid ,// ok
  output            o_lsu_bready  // ok

//	output		 				o_lsu_reqValid,
//	output		 [31:0] o_lsu_addr,
//	output		 [ 1:0] o_lsu_size,
//	output						o_lsu_wen,
//	output		 [31:0] o_lsu_wdata,
//	output		 [ 3:0] o_lsu_wmask,
//	input							i_lsu_respValid,
//	input			 [31:0] i_lsu_rdata
);

  localparam IDLE  = 1'b0;
	localparam WAIT  = 1'b1;
  
  reg cstate, nstate;
  wire [31:0] temp;
	wire [31:0] lsu_rdata;
  wire [ 1:0] o_lsu_size;
  wire        o_lsu_wen,

	wire load,store;

	assign load  = (i_lsu_cnt === 4'b0100) || (i_lsu_cnt === 4'b0101) || (i_lsu_cnt === 4'b0110) || (i_lsu_cnt === 4'b0111) || (i_lsu_cnt === 4'b1000);
	assign store = (i_lsu_cnt === 4'b0001) || (i_lsu_cnt === 4'b0010) || (i_lsu_cnt === 4'b0011);

  assign mem_exu_ready = cstate === IDLE;
  assign mem_wbu_valid = (load || store) ? (cstate === WAIT) && (i_lsu_wready || i_lsu_rvalid) : (cstate == WAIT);

  wire shakehand;
  assign shakehand = !reset && exu_mem_valid && mem_exu_ready;
	assign o_lsu_awvalid  = shakehand && store;
	assign o_lsu_arvalid  = shakehand && load ;
  assign o_lsu_wvalid   = (cstate == IDLE);
  assign o_lsu_rready   = (cstate == IDLE);
  assign o_lsu_bready   = (cstate == IDLE);

  assign o_lsu_araddr   = i_lsu_addr;
  assign o_lsu_awaddr   = i_lsu_addr;
	assign o_lsu_wdata 		= i_lsu_wdata << i_lsu_addr[1:0]*8;
	assign o_lsu_wen   		= store;
	assign o_lsu_size   	= (i_lsu_cnt == 4'b0001) ? 2'b00 : // sb
	 												(i_lsu_cnt == 4'b0010) ? 2'b01 : // sh
												  (i_lsu_cnt == 4'b0011) ? 2'b10 : // sw
										 			(i_lsu_cnt == 4'b0100) ? 2'b00 : // lb
										 			(i_lsu_cnt == 4'b0101) ? 2'b01 : // lh
										 			(i_lsu_cnt == 4'b0110) ? 2'b10 : // lw
										 			(i_lsu_cnt == 4'b0111) ? 2'b00 : // lbu
										 			(i_lsu_cnt == 4'b1000) ? 2'b01 : // lhu
										 			2'b0;

	wire [3:0] wmask_half,wmask_byte;
	assign wmask_half  = (i_lsu_addr[1]   == 1'b0) ? 4'h3 : 4'hc ;
	assign wmask_byte  = (i_lsu_addr[1:0] == 2'd0) ? 4'h1 :
											 (i_lsu_addr[1:0] == 2'd1) ? 4'h2 :
											 (i_lsu_addr[1:0] == 2'd2) ? 4'h4 :
											 (i_lsu_addr[1:0] == 2'd3) ? 4'h8 :
											 4'h0;
	assign o_lsu_wstrb = (i_lsu_cnt == 4'b0001) ? wmask_byte : // sb
										 	 (i_lsu_cnt == 4'b0010) ? wmask_half : // sh
										 	 (i_lsu_cnt == 4'b0011) ? 4'hf       : // sw
										 	 4'd0;

  always @(posedge clk) begin
    if(reset) begin
      cstate <= IDLE;
    end else begin
      cstate <= nstate;
    end
  end

always @(*) begin
    nstate = cstate;
    case (cstate)
      IDLE : begin
        if((i_lsu_cnt === 4'b0) && exu_mem_valid) begin
          nstate = WAIT;
        end else if (load && exu_mem_valid) begin
          nstate = WAIT;
        end else if (store && exu_mem_valid) begin
          nstate = WAIT;
        end
      end
      WAIT : begin
        if((i_lsu_cnt === 4'b0) && wbu_mem_ready) begin
          nstate = IDLE;
        end else if (load && i_lsu_rvalid && i_lsu_arready) begin
          nstate = IDLE;
        end else if (store && i_lsu_wready && i_lsu_awready && (i_lsu_bresp==2'h0) && i_lsu_bvalid) begin
          nstate = IDLE;
        end
      end
      default: nstate = IDLE;
    endcase
end

always @(posedge clk) begin
    if (reset) begin
        o_waddr   <= 5'b0;
        o_wdata   <= 32'b0;
        o_wbu_cnt <= 1'b0;
        o_ebreak  <= 1'b0;
        o_pc      <= 32'b0;
    end else begin
        case (cstate)
          WAIT : begin
            if((i_lsu_cnt === 4'b0) && wbu_mem_ready) begin
              o_waddr   <= i_waddr;
              o_wdata   <= i_wdata;
              o_wbu_cnt <= i_wbu_cnt;
              o_ebreak  <= i_ebreak;
              o_pc      <= i_pc;
            end else if (load && i_lsu_rvalid) begin
              o_waddr   <= i_waddr;
              o_wdata   <= lsu_rdata;
              o_wbu_cnt <= i_wbu_cnt;
              o_ebreak  <= i_ebreak;
              o_pc      <= i_pc;
            end else if (store && i_lsu_wready && (i_lsu_bresp==2'h0) && i_lsu_bvalid) begin
              o_waddr   <= 5'b0;  // store不写寄存器
              o_wdata   <= 32'b0;
              o_wbu_cnt <= i_wbu_cnt;
              o_ebreak  <= i_ebreak;
              o_pc      <= i_pc;
            end
          end
          default: begin
          end
        endcase
    end
end

	assign temp  = (i_lsu_rvalid && (i_lsu_rresp == 2'h0) && load) ? i_lsu_rdata : 32'b0;

	reg [7:0] byte_sel;
	always @(*) begin
		case (i_lsu_addr[1:0]) 
			2'b00 : byte_sel = temp[ 7: 0] ;
			2'b01 : byte_sel = temp[15: 8] ;
			2'b10 : byte_sel = temp[23:16] ;
			2'b11 : byte_sel = temp[31:24] ;
		endcase
	end

	reg [15:0] half_sel;
	always @(*) begin
		case (i_lsu_addr[1])
			1'b0 : half_sel = temp[15: 0] ;
			1'b1 : half_sel = temp[31:16] ;
		endcase
	end

	assign lsu_rdata = (i_lsu_cnt == 4'b0100) ? {{24{byte_sel[ 7]}}, byte_sel} : // lb
										 (i_lsu_cnt == 4'b0101) ? {{16{half_sel[15]}}, half_sel} : // lh
										 (i_lsu_cnt == 4'b0110) ? temp 												   : // lw
										 (i_lsu_cnt == 4'b0111) ? {24'b0         		 , byte_sel} : // lbu
										 (i_lsu_cnt == 4'b1000) ? {16'b0				 		 , half_sel} : // lhu
										 32'b0 ; 

endmodule


module ysyx_24080018_GPR(
  input         clk,
  input         reset,

  input         mem_wbu_valid,
  output        wbu_mem_ready,
	output				wbu_ifu_retire,

  output [31:0] rdata1,
  output [31:0] rdata2,

  input  [GPR_WIDTH-1:0] raddr1,
  input  [GPR_WIDTH-1:0] raddr2,
  input  [GPR_WIDTH-1:0] i_waddr,
  input  [31:0] i_wdata,
  input  [PC_WIDTH-1:0] i_pc,
  input         i_ebreak,
  input         i_wbu_cnt
);
  
  localparam IDLE = 1'b0;
	localparam WAIT = 1'b1;
  
  reg cstate, nstate;
  reg [31:0] rf [0:31];
  
  assign wbu_mem_ready = cstate === IDLE;

  assign rdata1 = (raddr1 == 5'b0) ? 32'b0 : rf[raddr1];
  assign rdata2 = (raddr2 == 5'b0) ? 32'b0 : rf[raddr2];

	wire wen;
  assign wen = i_wbu_cnt && mem_wbu_valid;
	assign wbu_ifu_retire = (mem_wbu_valid && wbu_mem_ready);

  always @(posedge clk) begin
    if(reset) begin
      cstate <= IDLE;
    end else begin
      cstate <= nstate;
    end
  end

  always @(*) begin
    case (cstate)
      IDLE : begin
        if(mem_wbu_valid) begin
          nstate = WAIT;    
				end else begin
          nstate = IDLE;       
        end
      end
			WAIT : begin
				nstate = IDLE;
			end
      default: begin
        nstate = IDLE;
      end
    endcase
  end

  always @(posedge clk) begin
    if(reset) begin 
      for(integer i = 1; i < 16; i = i + 1) begin
        rf[i] <= 32'b0;
      end
    end else begin
			if(wbu_mem_ready && mem_wbu_valid ) begin
				if(wen && (i_waddr != 5'b0)) begin
					rf[i_waddr] <= i_wdata;
				end 
			end
    end
  end

endmodule

module ysyx_24080018_CSR(
  input         exu_csr_valid,
  output        csr_exu_ready,
	output				csr_ifu_retire,

  input         clk,
  input         reset,
  input  [ 2:0] i_csr_cnt,
  input  [11:0] i_csr_imm,
  input  [31:0] i_wdata,
  output [31:0] o_rdata
);

  localparam IDLE = 1'b0;
	localparam WAIT = 1'b1;
  reg cstate, nstate;

  reg [31:0] mcycle   ;
  reg [31:0] mcycleh  ;
  reg [31:0] mvendorid;
  reg [31:0] marchid  ;

  wire [31:0] temp;

  assign csr_exu_ready  = (cstate == IDLE);
	assign csr_ifu_retire = (csr_exu_ready && exu_csr_valid);

	assign o_rdata = temp;
  assign temp = ( i_csr_imm == 12'hb00 ) ? mcycle    :
                ( i_csr_imm == 12'hb80 ) ? mcycleh   :
								( i_csr_imm == 12'hf11 ) ? mvendorid :
                ( i_csr_imm == 12'hf12 ) ? marchid   :
                32'b0;

  always @(posedge clk) begin
    if(reset) begin
      cstate <= IDLE;
    end else begin
      cstate <= nstate;
    end
  end

  always @(*) begin
    case (cstate)
      IDLE : begin
        if(exu_csr_valid) begin
          nstate = WAIT;
        end else begin
          nstate = IDLE;     
        end
      end
      WAIT : begin
        nstate = IDLE;   
      end
    endcase
  end

  always @(posedge clk) begin
    if(reset) begin
      mcycle    <= 32'b0;
      mcycleh   <= 32'b0;
      mvendorid <= 32'h79737978 ;
      marchid   <= 32'h16F6E92  ;
    end else begin
      case (cstate)
        IDLE : begin
          if(i_csr_cnt == 3'b010) begin // csrrs
            case (i_csr_imm)
              12'hb00 : mcycle    <= temp | i_wdata;
              12'hb80 : mcycleh   <= temp | i_wdata;
              12'hf11 : mvendorid <= temp | i_wdata;
              12'hf12 : marchid   <= temp | i_wdata;
              default : ; 
            endcase
          end else if (i_csr_cnt == 3'b001) begin // csrrw
            case (i_csr_imm)
              12'hb00 : mcycle    <= i_wdata;
              12'hb80 : mcycleh   <= i_wdata;
              12'hf11 : mvendorid <= i_wdata;
              12'hf12 : marchid   <= i_wdata;
              default : ; 
            endcase
          end
        end
        WAIT : begin
		//			$display("change csr");
        end
      endcase
      
      if (mcycle == 32'hffffffff) begin
        mcycle  <= 32'b0;
        mcycleh <= mcycleh + 32'b1;
      end else begin
        mcycle  <= mcycle + 32'b1;
      end

    end
  end
endmodule


module ysyx_24080018_arbiter(
  input            clock,
  input            reset,

  input     [31:0] o_ifu_awaddr  ,
  input            o_ifu_awvalid ,
  output           i_ifu_awready ,
  input     [31:0] o_ifu_araddr  ,
  input            o_ifu_arvalid ,
  output           i_ifu_arready ,
  output    [31:0] i_ifu_rdata   ,
  output    [ 1:0] i_ifu_rresp   ,
  output           i_ifu_rvalid  ,
  input            o_ifu_rready  ,
  input     [31:0] o_ifu_wdata   ,
  input     [ 3:0] o_ifu_wstrb   ,
  input            o_ifu_wvalid  ,
  output           i_ifu_wready  ,
  output    [ 1:0] i_ifu_bresp   ,
  output           i_ifu_bvalid  ,
  input            o_ifu_bready  ,

  input     [31:0] o_lsu_awaddr  ,
  input            o_lsu_awvalid ,
  output           i_lsu_awready ,
  input     [31:0] o_lsu_araddr  ,
  input            o_lsu_arvalid ,
  output           i_lsu_arready ,
  output    [31:0] i_lsu_rdata   ,
  output    [ 1:0] i_lsu_rresp   ,
  output           i_lsu_rvalid  ,
  input            o_lsu_rready  ,
  input     [31:0] o_lsu_wdata   ,
  input     [ 3:0] o_lsu_wstrb   ,
  input            o_lsu_wvalid  ,
  output           i_lsu_wready  ,
  output    [ 1:0] i_lsu_bresp   ,
  output           i_lsu_bvalid  ,
  input            o_lsu_bready  ,

  input           io_master_awready,
  output          io_master_awvalid,
  output [31:0]   io_master_awaddr,
  input           io_master_wready,
  output          io_master_wvalid,
  output [31:0]   io_master_wdata,
  output [ 3:0]   io_master_wstrb,
  output          io_master_bready,
  input           io_master_bvalid,
  input  [ 1:0]   io_master_bresp,
  input           io_master_arready,
  output          io_master_arvalid,
  output [31:0]   io_master_araddr,
  output          io_master_rready,
  input           io_master_rvalid,
  input  [ 1:0]   io_master_rresp,
  input  [31:0]   io_master_rdata
);
    localparam IDLE     = 3'b001;
    localparam IFU_RD   = 3'b011;
    localparam LSU_WR   = 3'b100;
    localparam LSU_RD   = 3'b101;
    localparam RESP     = 3'b110;
    
    reg [2:0] state;
    reg [2:0] next_state;
    
    wire ifu_req  = o_ifu_arvalid ;
    wire lsu_req  = o_lsu_awvalid || o_lsu_arvalid || o_lsu_wvalid;
    
    reg current_master;
    reg current_is_write;  // 1: 写操作, 0: 读操作
    
    reg [31:0] captured_rdata;
    reg [1:0] captured_rresp;
    reg [1:0] captured_bresp;
    reg response_ready;
    
    reg last_master;  // 上次获得总线的主机
    
    always @(*) begin
        if (ifu_req && !lsu_req) begin
            current_master = 1'b0;
        end else if (!ifu_req && lsu_req) begin
            current_master = 1'b1;
        end else if (ifu_req && lsu_req) begin
            current_master = ~last_master;  // 切换
        end else begin
            current_master = 1'b0;  // 无请求，默认IFU
        end
    end
    
    always @(posedge clock) begin
        if (!rst_n) begin
            state <= IDLE;
            last_master <= 1'b0;
        end else begin
            state <= next_state;
            if (state == RESP && next_state == IDLE) begin
                last_master <= current_master;
            end
        end
    end
    
    always @(*) begin
        next_state = state;
        case (state)
            IDLE: begin
                if (ifu_req || lsu_req) begin
                    if (current_master == 1'b0) begin  // IFU获得总线
                        if (o_ifu_arvalid) begin
                            next_state = IFU_RD;
                        end
                    end else begin  // LSU获得总线
                        if (o_lsu_awvalid) begin
                            next_state = LSU_WR;
                        end else if (o_lsu_arvalid) begin
                            next_state = LSU_RD;
                        end
                    end
                end
            end
            
            IFU_RD: begin
                if (io_master_arvalid && io_master_arready) begin
                    next_state = RESP;
                end
            end
            
            LSU_WR: begin
                if (io_master_awvalid && io_master_awready && 
                    io_master_wvalid && io_master_wready) begin
                    next_state = RESP;
                end
            end
            
            LSU_RD: begin
                if (io_master_arvalid && io_master_arready) begin
                    next_state = RESP;
                end
            end
            
            RESP: begin
                if ((current_master == 1'b0 && current_is_write && io_master_bvalid && io_master_bready) ||
                    (current_master == 1'b0 && !current_is_write && io_master_rvalid && io_master_rready) ||
                    (current_master == 1'b1 && current_is_write && io_master_bvalid && io_master_bready) ||
                    (current_master == 1'b1 && !current_is_write && io_master_rvalid && io_master_rready)) begin
                    next_state = IDLE;
                end
            end
            
            default: next_state = IDLE;
        endcase
    end
    
    assign io_master_awaddr  = o_lsu_awaddr;
    assign io_master_awvalid = (state == LSU_WR) ? o_lsu_awvalid : 1'b0;
    
    assign io_master_wdata   = o_lsu_wdata;
    assign io_master_wstrb   = o_lsu_wstrb;
    assign io_master_wvalid  = (state == LSU_WR) ? o_lsu_wvalid : 1'b0;
    
    assign io_master_araddr  =  o_lsu_araddr;
    assign io_master_arvalid = (state == IFU_RD) ? o_ifu_arvalid :
                               (state == LSU_RD) ? o_lsu_arvalid : 1'b0;
    
    assign io_master_bready = (state == RESP && current_is_write) ? o_lsu_bready : 1'b0;
    assign io_master_rready = (state == RESP && !current_is_write) ? 
                              ((current_master == 1'b0) ? o_ifu_rready : o_lsu_rready) : 1'b0;
    
    assign i_ifu_arready = (state == IFU_RD) ? io_master_arready : 1'b0;
    assign i_lsu_awready = (state == LSU_WR) ? io_master_awready : 1'b0;
    assign i_lsu_wready  = (state == LSU_WR) ? io_master_wready : 1'b0;
    assign i_lsu_arready = (state == LSU_RD) ? io_master_arready : 1'b0;
    
    always @(posedge io_master_arready) begin
        if (state == RESP && !current_is_write && io_master_rvalid && io_master_rready) begin
            captured_rdata <= io_master_rdata;
            captured_rresp <= io_master_rresp;
            response_ready <= 1'b1;
        end else if ((current_master == 1'b0 && o_ifu_rready) ||
                     (current_master == 1'b1 && o_lsu_rready)) begin
            response_ready <= 1'b0;
        end
    end
    
    always @(posedge io_master_awready) begin
        if (state == RESP && current_is_write && io_master_bvalid && io_master_bready) begin
            captured_bresp <= io_master_bresp;
            response_ready <= 1'b1;
        end else if (current_master == 1'b1 && o_lsu_bready) begin
            response_ready <= 1'b0;
        end
    end
    
    assign i_ifu_rdata  = (current_master == 1'b0 && !current_is_write) ? 
                          (response_ready ? captured_rdata : io_master_rdata) : 32'b0;
    assign i_ifu_rresp  = (current_master == 1'b0 && !current_is_write) ? 
                          (response_ready ? captured_rresp : io_master_rresp) : 2'b00;
    assign i_ifu_rvalid = (current_master == 1'b0 && !current_is_write) ? 
                          (response_ready || io_master_rvalid) : 1'b0;
    
    assign i_lsu_rdata  = (current_master == 1'b1 && !current_is_write) ? 
                          (response_ready ? captured_rdata : io_master_rdata) : 32'b0;
    assign i_lsu_rresp  = (current_master == 1'b1 && !current_is_write) ? 
                          (response_ready ? captured_rresp : io_master_rresp) : 2'b00;
    assign i_lsu_rvalid = (current_master == 1'b1 && !current_is_write) ? 
                          (response_ready || io_master_rvalid) : 1'b0;
    assign i_lsu_bresp  = (current_master == 1'b1 && current_is_write) ? 
                          (response_ready ? captured_bresp : io_master_bresp) : 2'b00;
    assign i_lsu_bvalid = (current_master == 1'b1 && current_is_write) ? 
                          (response_ready || io_master_bvalid) : 1'b0;
endmodule

import "DPI-C" function void NPCTRAP(input int unsigned pc, input int x10);

module ysyx_24080018(
  input           clock,
  input           reset,

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

wire ifu_idu_valid,idu_ifu_ready;
wire idu_exu_valid,exu_idu_ready;
wire exu_lsu_valid,lsu_exu_ready;
wire lsu_wbu_valid,wbu_lsu_ready;

wire idu_ebreak, exu_ebreak, lsu_ebreak;

wire [31:0] ifu_pc,idu_pc,exu_pc,lsu_pc;
wire [31:0] ifu_inst;

wire [ 4:0] idu_rd,idu_rs1,idu_rs2;
wire        idu_lui,idu_auipc,idu_jal,idu_jalr;
wire [31:0] idu_imm;
wire [11:0] idu_csr_imm;
wire [ 3:0] idu_alu_cnt;
wire [ 3:0] idu_pc_cnt;
wire [ 3:0] idu_lsu_cnt;
wire [ 2:0] idu_csr_cnt;
wire [ 5:0] idu_ins_cnt;
wire        idu_wbu_cnt;
wire        idu_jal_redirect;
wire [31:0] idu_jal_target;

wire [31:0] wbu_rdata1, wbu_rdata2;
wire [ 4:0] exu_waddr;
wire [31:0] exu_wdata;
wire        exu_br_taken;
wire [31:0] exu_br_target;
wire        exu_wbu_cnt;
wire [ 2:0] exu_csr_cnt;
wire [ 3:0] exu_lsu_cnt;
wire [31:0] exu_lsu_wdata, exu_lsu_waddr, exu_lsu_raddr;
wire [ 4:0] exu_raddr1, exu_raddr2;
wire [ 4:0] lsu_raddr1, lsu_raddr2, lsu_waddr;
wire [31:0] lsu_wdata;
wire        lsu_wbu_cnt;
wire        lsu_bypass_valid;
wire        lsu_load_pending;
wire [ 4:0] lsu_load_waddr;

wire        io_ifu_arready;
wire        io_ifu_arvalid;
wire [31:0] io_ifu_araddr ;
wire        io_ifu_rready ;
wire        io_ifu_rvalid ;
wire [ 1:0] io_ifu_rresp  ;
wire [31:0] io_ifu_rdata  ;
wire        io_lsu_awready;
wire        io_lsu_awvalid;
wire [31:0] io_lsu_awaddr ;
wire        io_lsu_wready ;
wire        io_lsu_wvalid ;
wire [31:0] io_lsu_wdata  ;
wire [ 3:0] io_lsu_wstrb  ;
wire        io_lsu_bready ;
wire        io_lsu_bvalid ;
wire [ 1:0] io_lsu_bresp  ;
wire        io_lsu_arready;
wire        io_lsu_arvalid;
wire [31:0] io_lsu_araddr ;
wire        io_lsu_rready ;
wire        io_lsu_rvalid ;
wire [ 1:0] io_lsu_rresp  ;
wire [31:0] io_lsu_rdata  ;

ysyx_24080018_IFU ifu(
  .clock          (clock        ),
  .reset          (reset        ),
  .ifu_idu_valid  (ifu_idu_valid),
  .idu_ifu_ready  (idu_ifu_ready),
  .o_inst         (ifu_inst     ),
  .o_pc           (ifu_pc       ),

  .i_br_taken     (exu_br_taken ),
  .i_br_target    (exu_br_target),
  .i_jal_redirect (idu_jal_redirect),
  .i_jal_target   (idu_jal_target),

  .o_ifu_araddr   (io_ifu_araddr ),
  .o_ifu_arvalid  (io_ifu_arvalid),
  .i_ifu_arready  (io_ifu_arready),
  .i_ifu_rdata    (io_ifu_rdata  ),
  .i_ifu_rresp    (io_ifu_rresp  ),
  .i_ifu_rvalid   (io_ifu_rvalid ),
  .o_ifu_rready   (io_ifu_rready )
);

ysyx_24080018_IDU idu(
  .clock         (clock        ),
  .reset         (reset        ),
  .ifu_idu_valid (ifu_idu_valid),
  .idu_ifu_ready (idu_ifu_ready),
  .idu_exu_valid (idu_exu_valid),
  .exu_idu_ready (exu_idu_ready),
  .i_br_taken    (exu_br_taken ),
  .i_inst        (ifu_inst     ),
  .o_lui         (idu_lui      ),
  .o_auipc       (idu_auipc    ),
  .o_jal         (idu_jal      ),
  .o_jalr        (idu_jalr     ),
  .ebreak        (idu_ebreak   ),
  .i_pc          (ifu_pc       ),
  .o_pc          (idu_pc       ),
  .o_rs1         (idu_rs1      ),
  .o_rs2         (idu_rs2      ),
  .o_rd          (idu_rd       ),
  .o_imm         (idu_imm      ),
  .o_csr_imm     (idu_csr_imm  ),
  .o_alu_cnt     (idu_alu_cnt  ),
  .o_pc_cnt      (idu_pc_cnt   ),
  .o_lsu_cnt     (idu_lsu_cnt  ),
  .o_csr_cnt     (idu_csr_cnt  ),
  .o_ins_cnt     (idu_ins_cnt  ),
  .o_wbu_cnt     (idu_wbu_cnt  ),
  .o_jal_redirect(idu_jal_redirect),
  .o_jal_target  (idu_jal_target)
);

ysyx_24080018_EXU exu(
  .clock         (clock        ),
  .reset         (reset        ),
  .idu_exu_valid (idu_exu_valid),
  .exu_idu_ready (exu_idu_ready),
  .exu_lsu_valid (exu_lsu_valid),
  .lsu_exu_ready (lsu_exu_ready),
  .i_auipc       (idu_auipc    ),
  .i_lui         (idu_lui      ),
  .i_jal         (idu_jal      ),
  .i_jalr        (idu_jalr     ),
  .i_ebreak      (idu_ebreak   ),
  .i_pc          (idu_pc       ),
  .o_pc          (exu_pc       ),
  .i_imm         (idu_imm      ),
  .i_csr_imm     (idu_csr_imm  ),
  .i_rdata1      (wbu_rdata1   ),
  .i_rdata2      (wbu_rdata2   ),
  .i_waddr       (idu_rd       ),
  .i_rs1         (idu_rs1      ),
  .i_rs2         (idu_rs2      ),
  .o_waddr       (exu_waddr    ),
  .o_alu_result  (exu_wdata    ),
  .o_br_taken    (exu_br_taken ),
  .o_br_target   (exu_br_target),
  .o_ebreak      (exu_ebreak   ),
  .i_load_pending(lsu_load_pending),
  .i_load_waddr  (lsu_load_waddr),
  .i_bypass_valid(lsu_bypass_valid),
  .i_bypass_waddr(lsu_waddr     ),
  .i_bypass_wdata(lsu_wdata     ),
  .i_ins_cnt     (idu_ins_cnt  ),
  .i_pc_cnt      (idu_pc_cnt   ),
  .i_alu_cnt     (idu_alu_cnt  ),
  .i_csr_cnt     (idu_csr_cnt  ),
  .i_lsu_cnt     (idu_lsu_cnt  ),
  .i_wbu_cnt     (idu_wbu_cnt  ),
  .o_wbu_cnt     (exu_wbu_cnt  ),
  .o_csr_cnt     (exu_csr_cnt  ),
  .o_lsu_cnt     (exu_lsu_cnt  ),
  .o_lsu_wdata   (exu_lsu_wdata),
  .o_lsu_waddr   (exu_lsu_waddr),
  .o_lsu_raddr   (exu_lsu_raddr),
  .o_raddr1      (exu_raddr1   ),
  .o_raddr2      (exu_raddr2   )
);

ysyx_24080018_LSU lsu(
  .clock         (clock         ),
  .reset         (reset         ),
  .exu_lsu_valid (exu_lsu_valid ),
  .lsu_exu_ready (lsu_exu_ready ),
  .lsu_wbu_valid (lsu_wbu_valid ),
  .wbu_lsu_ready (wbu_lsu_ready ),
  .i_raddr1      (exu_raddr1    ),
  .i_raddr2      (exu_raddr2    ),
  .i_waddr       (exu_waddr     ),
  .i_wdata       (exu_wdata     ),
  .i_pc          (exu_pc        ),
  .i_ebreak      (exu_ebreak    ),
  .i_wbu_cnt     (exu_wbu_cnt   ),
  .i_lsu_cnt     (exu_lsu_cnt   ),
  .i_lsu_wdata   (exu_lsu_wdata ),
  .i_lsu_waddr   (exu_lsu_waddr ),
  .i_lsu_raddr   (exu_lsu_raddr ),
  .o_raddr1      (lsu_raddr1    ),
  .o_raddr2      (lsu_raddr2    ),
  .o_waddr       (lsu_waddr     ),
  .o_wdata       (lsu_wdata     ),
  .o_pc          (lsu_pc        ),
  .o_ebreak      (lsu_ebreak    ),
  .o_wbu_cnt     (lsu_wbu_cnt   ),
  .o_bypass_valid(lsu_bypass_valid),
  .o_load_pending(lsu_load_pending),
  .o_load_waddr  (lsu_load_waddr),
  .o_lsu_awaddr  (io_lsu_awaddr ),
  .o_lsu_awvalid (io_lsu_awvalid),
  .i_lsu_awready (io_lsu_awready),
  .o_lsu_araddr  (io_lsu_araddr ),
  .o_lsu_arvalid (io_lsu_arvalid),
  .i_lsu_arready (io_lsu_arready),
  .i_lsu_rdata   (io_lsu_rdata  ),
  .i_lsu_rresp   (io_lsu_rresp  ),
  .i_lsu_rvalid  (io_lsu_rvalid ),
  .o_lsu_rready  (io_lsu_rready ),
  .o_lsu_wdata   (io_lsu_wdata  ),
  .o_lsu_wstrb   (io_lsu_wstrb  ),
  .o_lsu_wvalid  (io_lsu_wvalid ),
  .i_lsu_wready  (io_lsu_wready ),
  .i_lsu_bresp   (io_lsu_bresp  ),
  .i_lsu_bvalid  (io_lsu_bvalid ),
  .o_lsu_bready  (io_lsu_bready )
);

ysyx_24080018_WBU wbu(
  .clock         (clock        ),
  .reset         (reset        ),
  .lsu_wbu_valid (lsu_wbu_valid),
  .wbu_lsu_ready (wbu_lsu_ready),
  .rdata1        (wbu_rdata1   ),
  .rdata2        (wbu_rdata2   ),
  .i_raddr1      (idu_rs1      ),
  .i_raddr2      (idu_rs2      ),
  .i_waddr       (lsu_waddr    ),
  .i_wdata       (lsu_wdata    ),
  .i_pc          (lsu_pc       ),
  .ebreak        (lsu_ebreak   ),
  .i_wbu_cnt     (lsu_wbu_cnt  )
);

ysyx_24080018_arbiter arbiter(
  .clock         (clock        ),
  .reset         (reset        ),

  .o_ifu_araddr  (io_ifu_araddr ),
  .o_ifu_arvalid (io_ifu_arvalid),
  .i_ifu_arready (io_ifu_arready),
  .i_ifu_rdata   (io_ifu_rdata  ),
  .i_ifu_rresp   (io_ifu_rresp  ),
  .i_ifu_rvalid  (io_ifu_rvalid ),
  .o_ifu_rready  (io_ifu_rready ),

  .o_lsu_awaddr  (io_lsu_awaddr ),
  .o_lsu_awvalid (io_lsu_awvalid),
  .i_lsu_awready (io_lsu_awready),
  .o_lsu_araddr  (io_lsu_araddr ),
  .o_lsu_arvalid (io_lsu_arvalid),
  .i_lsu_arready (io_lsu_arready),
  .i_lsu_rdata   (io_lsu_rdata  ),
  .i_lsu_rresp   (io_lsu_rresp  ),
  .i_lsu_rvalid  (io_lsu_rvalid ),
  .o_lsu_rready  (io_lsu_rready ),
  .o_lsu_wdata   (io_lsu_wdata  ),
  .o_lsu_wstrb   (io_lsu_wstrb  ),
  .o_lsu_wvalid  (io_lsu_wvalid ),
  .i_lsu_wready  (io_lsu_wready ),
  .i_lsu_bresp   (io_lsu_bresp  ),
  .i_lsu_bvalid  (io_lsu_bvalid ),
  .o_lsu_bready  (io_lsu_bready ),

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
  input wire         clock,
  input wire         reset,

  output reg         ifu_idu_valid,
  input wire         idu_ifu_ready,

  // 来自 EXU 的跳转信号
  input wire         i_br_taken,
  input wire [31:0]  i_br_target,
  input wire         i_jal_redirect,
  input wire [31:0]  i_jal_target,

  output reg [31:0]  o_ifu_araddr,
  output reg         o_ifu_arvalid,
  input wire         i_ifu_arready,
  input wire [31:0]  i_ifu_rdata,
  input wire [ 1:0]  i_ifu_rresp,
  input wire         i_ifu_rvalid,
  output reg         o_ifu_rready,

  output reg [31:0]  o_inst,
  output reg [31:0]  o_pc
);

reg [31:0] pc;
// 跳转发生后，已取回但尚未送给 IDU 的指令需要丢弃
reg        flush_pending;
reg        req_pending;
reg [31:0] req_pc;

wire ifu_idu_handshake = ifu_idu_valid && idu_ifu_ready;
wire ar_handshake = o_ifu_arvalid && i_ifu_arready;
wire r_handshake  = i_ifu_rvalid  && o_ifu_rready;
// 本拍正在接收数据（ifu_idu_valid 下拍才更新，需要组合信号提前屏蔽重复取指）
wire inst_arriving = r_handshake;
wire redirect_taken = i_br_taken | i_jal_redirect;
wire [31:0] redirect_target = i_br_taken ? i_br_target : i_jal_target;

// PC 更新：跳转时加载目标地址，否则握手后 +4
always_ff @(posedge clock) begin
  if (reset) begin
    pc <= 32'h80000000;
  end else if (redirect_taken) begin
    pc <= redirect_target;
  end else if (ifu_idu_handshake) begin
    pc <= pc + 32'd4;
  end
end

// AR 通道：跳转时立即发起新地址的取指请求
always_ff @(posedge clock) begin
  if (reset) begin
    o_ifu_arvalid <= 1'b0;
    o_ifu_araddr  <= 32'h80000000;
  end else if (redirect_taken) begin
    // 跳转：取消当前未完成的请求，发起跳转目标地址请求
    o_ifu_arvalid <= 1'b1;
    o_ifu_araddr  <= redirect_target;
  end else if (ar_handshake) begin
    o_ifu_arvalid <= 1'b0;
  end else if (~o_ifu_arvalid && ~req_pending && ifu_idu_handshake) begin
    o_ifu_arvalid <= 1'b1;
    o_ifu_araddr  <= pc + 4;
  end else if (~o_ifu_arvalid && ~req_pending && ~ifu_idu_valid && ~inst_arriving) begin
    o_ifu_arvalid <= 1'b1;
    o_ifu_araddr  <= pc;
  end
end

// flush_pending：跳转发生后，下一条取回的指令需要丢弃
always_ff @(posedge clock) begin
  if (reset) begin
    flush_pending <= 1'b0;
  end else if (redirect_taken) begin
    // 跳转时若存在已发出但未返回的旧请求，也需要丢弃其响应
    flush_pending <= o_ifu_arvalid | req_pending;
  end else if (r_handshake) begin
    flush_pending <= 1'b0;
  end
end

always_ff @(posedge clock) begin
  if (reset) begin
    req_pending <= 1'b0;
    req_pc      <= 32'h80000000;
  end else begin
    if (ar_handshake) begin
      req_pending <= 1'b1;
      req_pc      <= o_ifu_araddr;
    end
    if (r_handshake) begin
      req_pending <= 1'b0;
    end
  end
end

// 指令寄存器和 valid 控制
always_ff @(posedge clock) begin
  if (reset) begin
    ifu_idu_valid <= 1'b0;
    o_inst        <= 32'h0;
    o_pc          <= 32'h80000000;
    o_ifu_rready  <= 1'b1;
  end else begin
    o_ifu_rready <= 1'b1;
    if (redirect_taken) begin
      // 跳转：丢弃已锁存的指令
      ifu_idu_valid <= 1'b0;
    end else if (r_handshake && (i_ifu_rresp == 2'b00)) begin
      if (flush_pending) begin
        // 这条取回的指令是跳转前预取的，丢弃
        ifu_idu_valid <= 1'b0;
      end else begin
        o_inst        <= i_ifu_rdata;
        o_pc          <= req_pc;
        ifu_idu_valid <= 1'b1;
      end
    end else if (ifu_idu_handshake) begin
      ifu_idu_valid <= 1'b0;
    end
  end
end

endmodule

module ysyx_24080018_IDU (
  input wire        clock,
  input wire        reset,

  input wire        ifu_idu_valid,
  output reg        idu_ifu_ready,
  output reg        idu_exu_valid,
  input wire        exu_idu_ready,

  input wire        i_br_taken,

  input wire [31:0] i_inst,
  input wire [31:0] i_pc,

  output reg        o_lui,
  output reg        o_jalr,
  output reg        o_auipc,
  output reg        o_jal,
  output reg        ebreak,

  output reg [31:0] o_pc,
  output reg [ 4:0] o_rs1,
  output reg [ 4:0] o_rs2,
  output reg [ 4:0] o_rd,
  output reg [31:0] o_imm,
  output reg [11:0] o_csr_imm,
  output reg [ 3:0] o_alu_cnt,
  output reg [ 3:0] o_pc_cnt,
  output reg [ 3:0] o_lsu_cnt,
  output reg [ 2:0] o_csr_cnt,
  output reg [ 5:0] o_ins_cnt,
  output reg        o_wbu_cnt,
  output wire       o_jal_redirect,
  output wire [31:0] o_jal_target
);

wire [ 6:0] opcode;
wire [ 2:0] fun3;
wire [ 6:0] fun7;
wire [ 4:0] rs1, rs2, rd;
wire [31:0] imm;
wire [11:0] csr_imm;
wire        auipc, lui, load, jal, jalr, ecall, mret;
wire        UType, JType, BType, IType, SType, RType, IcsrType;
wire        I_imm;
wire        is_ebreak;
wire        idu_ifu_handshake, idu_exu_handshake;

assign idu_ifu_handshake = ifu_idu_valid  && idu_ifu_ready;
assign idu_exu_handshake = idu_exu_valid  && exu_idu_ready;

assign opcode = i_inst[ 6: 0];
assign   fun3 = i_inst[14:12];
assign   fun7 = i_inst[31:25];
assign    rd  = i_inst[11: 7];
assign   rs1  = i_inst[19:15];
assign   rs2  = i_inst[24:20];

assign auipc    = (opcode == 7'b0010111);
assign lui      = (opcode == 7'b0110111);
assign UType    = auipc | lui;
assign JType    = (opcode == 7'b1101111);
assign jal      = JType;
assign jalr     = (opcode == 7'b1100111);
assign load     = (opcode == 7'b0000011);
assign I_imm    = (opcode == 7'b0010011);
assign IType    = jalr | load | I_imm;
assign BType    = (opcode == 7'b1100011);
assign SType    = (opcode == 7'b0100011);
assign RType    = (opcode == 7'b0110011);
assign IcsrType = (opcode == 7'b1110011);
assign is_ebreak= (i_inst == 32'b00000000000100000000000001110011);
assign ecall    = (i_inst == 32'b00000000000000000000000001110011);
assign mret     = (i_inst == 32'b00110000001000000000000001110011);

assign imm = ({32{JType}} & {{12{i_inst[31]}}, i_inst[19:12], i_inst[20], i_inst[30:21], 1'b0}) |
             ({32{UType}} & {i_inst[31:12], 12'b0})                                              |
             ({32{BType}} & {{19{i_inst[31]}}, i_inst[31], i_inst[7], i_inst[30:25], i_inst[11:8], 1'b0}) |
             ({32{SType}} & {{20{i_inst[31]}}, i_inst[31:25], i_inst[11:7]})                     |
             ({32{IType}} & {{20{i_inst[31]}}, i_inst[31:20]});

assign csr_imm = IcsrType ? i_inst[31:20] : 12'b0;

wire [3:0] alu_cnt;
assign alu_cnt = RType  ? ((fun3 == 3'b000) ? ((fun7 == 7'b0100000) ? 4'b0010 : 4'b0001) :
                            (fun3 == 3'b010) ? 4'b0011 : (fun3 == 3'b011) ? 4'b0100 :
                            (fun3 == 3'b111) ? 4'b0101 : (fun3 == 3'b110) ? 4'b0110 :
                            (fun3 == 3'b100) ? 4'b0111 : (fun3 == 3'b001) ? 4'b1000 :
                            (fun3 == 3'b101) ? ((fun7 == 7'b0100000) ? 4'b1010 : 4'b1001) : 4'b0000) :
               I_imm   ? ((fun3 == 3'b000) ? 4'b0001 : (fun3 == 3'b010) ? 4'b0011 :
                            (fun3 == 3'b011) ? 4'b0100 : (fun3 == 3'b111) ? 4'b0101 :
                            (fun3 == 3'b110) ? 4'b0110 : (fun3 == 3'b100) ? 4'b0111 :
                            (fun3 == 3'b001) ? 4'b1000 :
                            (fun3 == 3'b101) ? ((fun7 == 7'b0100000) ? 4'b1010 : 4'b1001) : 4'b0000) :
               (jalr | jal | auipc | lui) ? 4'b0001 :
               IcsrType ? 4'b0001 :
               4'b0000;

wire [3:0] pc_cnt;
assign pc_cnt = BType ? ((fun3 == 3'b000) ? 4'b0001 : (fun3 == 3'b001) ? 4'b0010 :
                          (fun3 == 3'b100) ? 4'b0011 : (fun3 == 3'b101) ? 4'b0100 :
                          (fun3 == 3'b110) ? 4'b0101 : (fun3 == 3'b111) ? 4'b0110 : 4'b0000) :
               jal   ? 4'b0111 :
               jalr  ? 4'b1000 :
               mret  ? 4'b1001 :
               ecall ? 4'b1010 :
               4'b0000;

wire [3:0] lsu_cnt;
assign lsu_cnt = SType ? ((fun3 == 3'b000) ? 4'b0001 : (fun3 == 3'b001) ? 4'b0010 :
                           (fun3 == 3'b010) ? 4'b0011 : 4'b0000) :
                load  ? ((fun3 == 3'b000) ? 4'b0100 : (fun3 == 3'b001) ? 4'b0101 :
                          (fun3 == 3'b010) ? 4'b0110 : (fun3 == 3'b100) ? 4'b0111 :
                          (fun3 == 3'b101) ? 4'b1000 : 4'b0000) :
                4'b0000;

wire [2:0] csr_cnt;
assign csr_cnt = IcsrType ? ((fun3 == 3'b001) ? 3'b001 :
                             (fun3 == 3'b010) ? 3'b010 :
                             is_ebreak        ? 3'b011 :
                             ecall            ? 3'b100 :
                             mret             ? 3'b101 : 3'b000) : 3'b000;

wire [5:0] ins_cnt;
assign ins_cnt = {UType, JType, BType, IType, SType, RType};

wire wbu_cnt;
assign wbu_cnt = UType | JType | IType | RType | (csr_cnt == 3'b001) | (csr_cnt == 3'b010);
assign o_jal_redirect = idu_ifu_handshake && jal;
assign o_jal_target   = i_pc + imm;

// 握手：只要 IDU 没有待发送给 EXU 的数据，就可以接收 IFU 的数据
always_ff @(posedge clock) begin
  if (reset) begin
    idu_ifu_ready <= 1'b1;
  end else begin
    if (i_br_taken)
      idu_ifu_ready <= 1'b1;
    else if (idu_exu_handshake)
      idu_ifu_ready <= 1'b1;
    else if (idu_ifu_handshake)
      idu_ifu_ready <= 1'b0;
  end
end

// 流水线寄存器：锁存译码结果
always_ff @(posedge clock) begin
  if (reset) begin
    idu_exu_valid <= 1'b0;
    o_pc          <= 32'h80000000;
    o_rs1         <= 5'b0;
    o_rs2         <= 5'b0;
    o_rd          <= 5'b0;
    o_imm         <= 32'b0;
    o_csr_imm     <= 12'b0;
    o_alu_cnt     <= 4'b0;
    o_pc_cnt      <= 4'b0;
    o_lsu_cnt     <= 4'b0;
    o_csr_cnt     <= 3'b0;
    o_ins_cnt     <= 6'b0;
    o_wbu_cnt     <= 1'b0;
    o_lui         <= 1'b0;
    o_auipc       <= 1'b0;
    o_jal         <= 1'b0;
    o_jalr        <= 1'b0;
    ebreak        <= 1'b0;
  end else begin
    if (i_br_taken) begin
      // 跳转：丢弃 IDU 中已译码但未送出的指令
      idu_exu_valid <= 1'b0;
      ebreak        <= 1'b0;
    end else if (idu_ifu_handshake) begin
      idu_exu_valid <= 1'b1;
      o_pc          <= i_pc;
      o_rs1         <= rs1;
      o_rs2         <= rs2;
      o_rd          <= rd;
      o_imm         <= imm;
      o_csr_imm     <= csr_imm;
      o_alu_cnt     <= alu_cnt;
      o_pc_cnt      <= pc_cnt;
      o_lsu_cnt     <= lsu_cnt;
      o_csr_cnt     <= csr_cnt;
      o_ins_cnt     <= ins_cnt;
      o_wbu_cnt     <= wbu_cnt;
      o_lui         <= lui;
      o_auipc       <= auipc;
      o_jal         <= jal;
      o_jalr        <= jalr;
      ebreak        <= is_ebreak;
    end else if (idu_exu_handshake) begin
      idu_exu_valid <= 1'b0;
      ebreak        <= 1'b0;
    end
  end
end

endmodule

module ysyx_24080018_EXU(
  input wire        clock,
  input wire        reset,

  input wire        idu_exu_valid,
  output reg        exu_idu_ready,
  output reg        exu_lsu_valid,
  input wire        lsu_exu_ready,

  input wire        i_auipc,
  input wire        i_lui,
  input wire        i_jal,
  input wire        i_jalr,
  input wire        i_ebreak,

  input wire [31:0] i_pc,
  output reg [31:0] o_pc,
  input wire [31:0] i_imm,
  input wire [11:0] i_csr_imm,
  input wire [31:0] i_rdata1,
  input wire [31:0] i_rdata2,
  input wire [ 4:0] i_waddr,
  input wire [ 4:0] i_rs1,
  input wire [ 4:0] i_rs2,
  output reg [ 4:0] o_waddr,
  output reg [31:0] o_alu_result,
  output reg        o_br_taken,
  output reg [31:0] o_br_target,
  output reg        o_ebreak,
  input wire        i_load_pending,
  input wire [ 4:0] i_load_waddr,
  input wire        i_bypass_valid,
  input wire [ 4:0] i_bypass_waddr,
  input wire [31:0] i_bypass_wdata,

  input wire [ 5:0] i_ins_cnt,
  input wire [ 3:0] i_pc_cnt,
  input wire [ 3:0] i_alu_cnt,
  input wire [ 2:0] i_csr_cnt,
  input wire [ 3:0] i_lsu_cnt,
  input wire        i_wbu_cnt,
  output reg        o_wbu_cnt,
  output reg [ 2:0] o_csr_cnt,
  output reg [ 3:0] o_lsu_cnt,

  output reg [31:0] o_lsu_wdata,
  output reg [31:0] o_lsu_waddr,
  output reg [31:0] o_lsu_raddr,
  output reg [ 4:0] o_raddr1,
  output reg [ 4:0] o_raddr2
);

wire exu_lsu_handshake, idu_exu_handshake;
assign idu_exu_handshake = idu_exu_valid && exu_idu_ready;
assign exu_lsu_handshake = exu_lsu_valid && lsu_exu_ready;

wire UType, JType, BType, IType, SType, RType;
assign {UType,JType,BType,IType,SType,RType} = i_ins_cnt;

wire load_use_hazard = i_load_pending &&
                      (((i_load_waddr == i_rs1) && (i_rs1 != 5'b0)) ||
                       ((i_load_waddr == i_rs2) && (i_rs2 != 5'b0)));
wire bypass_valid = i_bypass_valid && (i_bypass_waddr != 5'b0);
wire [31:0] src1_data = (bypass_valid && (i_bypass_waddr == i_rs1)) ? i_bypass_wdata : i_rdata1;
wire [31:0] src2_data = (bypass_valid && (i_bypass_waddr == i_rs2)) ? i_bypass_wdata : i_rdata2;

localparam [11:0] CSR_MSTATUS = 12'h300;
localparam [11:0] CSR_MTVEC   = 12'h305;
localparam [11:0] CSR_MEPC    = 12'h341;
localparam [11:0] CSR_MCAUSE  = 12'h342;
localparam [11:0] CSR_MCYCLE  = 12'hb00;
localparam [11:0] CSR_MCYCLEH = 12'hb80;
localparam [11:0] CSR_MVENDORID = 12'hf11;
localparam [11:0] CSR_MARCHID   = 12'hf12;
localparam [31:0] CSR_MVENDORID_VALUE = 32'h79737978;
localparam [31:0] CSR_MARCHID_VALUE   = 32'h016f6e92;

reg [31:0] csr_mtvec;
reg [31:0] csr_mepc;
reg [31:0] csr_mstatus;
reg [31:0] csr_mcause;
reg [63:0] csr_mcycle;

reg [31:0] csr_direct_rdata;
always_comb begin
  unique case (i_csr_imm)
    CSR_MSTATUS   : csr_direct_rdata = csr_mstatus;
    CSR_MTVEC     : csr_direct_rdata = csr_mtvec;
    CSR_MEPC      : csr_direct_rdata = csr_mepc;
    CSR_MCAUSE    : csr_direct_rdata = csr_mcause;
    CSR_MCYCLE    : csr_direct_rdata = csr_mcycle[31:0];
    CSR_MCYCLEH   : csr_direct_rdata = csr_mcycle[63:32];
    CSR_MVENDORID : csr_direct_rdata = CSR_MVENDORID_VALUE;
    CSR_MARCHID   : csr_direct_rdata = CSR_MARCHID_VALUE;
    default       : csr_direct_rdata = 32'b0;
  endcase
end

wire csr_is_csrrw = (i_csr_cnt == 3'b001);
wire csr_is_csrrs = (i_csr_cnt == 3'b010);
wire csr_is_ecall = (i_csr_cnt == 3'b100);
wire csr_is_mret  = (i_csr_cnt == 3'b101);
wire csr_write_en = csr_is_csrrw || (csr_is_csrrs && (i_rs1 != 5'b0));
wire [31:0] csr_rdata = csr_is_mret  ? csr_mepc  :
                        csr_is_ecall ? csr_mtvec :
                                       csr_direct_rdata;
wire [31:0] csr_write_data = csr_is_csrrs ? (csr_direct_rdata | src1_data) :
                                            src1_data;

reg [31:0] csr_mtvec_next;
reg [31:0] csr_mepc_next;
reg [31:0] csr_mstatus_next;
reg [31:0] csr_mcause_next;
reg [63:0] csr_mcycle_next;

wire [31:0] alu_a,alu_b;
assign alu_a = (i_lui                    ) ? 32'b0      :
               (i_jalr | i_auipc | i_jal ) ? i_pc       :
               (csr_is_csrrw | csr_is_csrrs) ? csr_rdata :
               src1_data;

assign alu_b = (  i_jal | i_jalr         ) ? 32'd4      :
               (  csr_is_csrrw | csr_is_csrrs) ? 32'b0  :
               (  UType | JType | IType  ) ? i_imm      :
               (  RType | SType | BType  ) ? src2_data:
               32'b0;

wire _br_taken;
assign _br_taken = ( i_pc_cnt == 4'b0001 ) ? ($signed(src1_data) == $signed(src2_data)) :
                   ( i_pc_cnt == 4'b0010 ) ? ($signed(src1_data) != $signed(src2_data)) :
                   ( i_pc_cnt == 4'b0011 ) ? ($signed(src1_data) <  $signed(src2_data)) :
                   ( i_pc_cnt == 4'b0100 ) ? ($signed(src1_data) >= $signed(src2_data)) :
                   ( i_pc_cnt == 4'b0101 ) ? (        src1_data  <          src2_data ) :
                   ( i_pc_cnt == 4'b0110 ) ? (        src1_data  >=         src2_data ) :
                   ( i_pc_cnt == 4'b0111 ) ? 1'b1 : // jal
                   ( i_pc_cnt == 4'b1000 ) ? 1'b1 : // jalr
                   1'b0;
wire exu_redirect_taken = (((i_pc_cnt >= 4'b0001) && (i_pc_cnt <= 4'b0110)) || (i_pc_cnt == 4'b1000)) && _br_taken;
wire csr_redirect_taken = csr_is_mret || csr_is_ecall;

wire [31:0] br_target_calc;
assign br_target_calc = (i_pc_cnt == 4'b1000) ? ((src1_data + i_imm) & ~32'h1) : // jalr
                        (i_pc_cnt == 4'b1001) ? csr_mepc                        : // mret
                        (i_pc_cnt == 4'b1010) ? csr_mtvec                       : // ecall
                                                (i_pc + i_imm);                   // jal / branch

wire  [63:0]  shift_temp ;
assign shift_temp = ({{32{alu_a[31]}}, alu_a} >>  alu_b[4:0]);

wire  [31:0]  _alu_result;
                     // + (add/addi/jalr)
assign _alu_result = ( i_alu_cnt === 4'b0001 ) ? (         alu_a  +        alu_b ):
                     // - (sub)
                     ( i_alu_cnt === 4'b0010 ) ? (         alu_a  -        alu_b ):
                     // sign< (slt/slti)
                     ( i_alu_cnt === 4'b0011 ) ? (($signed(alu_a) <$signed(alu_b))? 32'd1:32'd0 ):
                     // unsign< (sltu/sltiu)
                     ( i_alu_cnt === 4'b0100 ) ? ((        alu_a  <        alu_b )? 32'd1:32'd0 ):
                     // & (and/andi)
                     ( i_alu_cnt === 4'b0101 ) ? (         alu_a  &        alu_b ):
                     // | (or/ori)
                     ( i_alu_cnt === 4'b0110 ) ? (         alu_a  |        alu_b ):
                     // ^ (xor/xori)
                     ( i_alu_cnt === 4'b0111 ) ? (         alu_a  ^        alu_b ):
                     // <<0 (sll/slli)
                     ( i_alu_cnt === 4'b1000 ) ? (         alu_a <<    alu_b[4:0]):
                     // 0>> (srl/srli)
                     ( i_alu_cnt === 4'b1001 ) ? (         alu_a >>    alu_b[4:0]):
                     // sign>> (sra/srai)
                     ( i_alu_cnt === 4'b1010 ) ? ( shift_temp[31:0] ):
                     32'b0;

always_comb begin
  csr_mtvec_next   = csr_mtvec;
  csr_mepc_next    = csr_mepc;
  csr_mstatus_next = csr_mstatus;
  csr_mcause_next  = csr_mcause;
  csr_mcycle_next  = csr_mcycle + 64'd1;

  if (idu_exu_handshake) begin
    if (csr_write_en) begin
      unique case (i_csr_imm)
        CSR_MSTATUS : csr_mstatus_next = csr_write_data;
        CSR_MTVEC   : csr_mtvec_next   = csr_write_data;
        CSR_MEPC    : csr_mepc_next    = csr_write_data;
        CSR_MCAUSE  : csr_mcause_next  = csr_write_data;
        CSR_MCYCLE  : csr_mcycle_next  = {csr_mcycle[63:32], csr_write_data};
        CSR_MCYCLEH : csr_mcycle_next  = {csr_write_data, csr_mcycle[31:0]};
        default     : ;
      endcase
    end

    if (csr_is_ecall) begin
      csr_mepc_next           = i_pc;
      csr_mcause_next         = 32'd11;
      csr_mstatus_next[7]     = csr_mstatus[3];
      csr_mstatus_next[3]     = 1'b0;
      csr_mstatus_next[12:11] = 2'b11;
    end else if (csr_is_mret) begin
      csr_mstatus_next[3]     = csr_mstatus[7];
      csr_mstatus_next[7]     = 1'b1;
      csr_mstatus_next[12:11] = 2'b00;
    end
  end
end

always_ff @(posedge clock) begin
  if (reset) begin
    csr_mtvec   <= 32'b0;
    csr_mepc    <= 32'b0;
    csr_mstatus <= 32'h00001800;
    csr_mcause  <= 32'b0;
    csr_mcycle  <= 64'b0;
  end else begin
    csr_mtvec   <= csr_mtvec_next;
    csr_mepc    <= csr_mepc_next;
    csr_mstatus <= csr_mstatus_next;
    csr_mcause  <= csr_mcause_next;
    csr_mcycle  <= csr_mcycle_next;
  end
end

// EXU 握手状态机：exu_idu_ready 表示 EXU 可以接收新指令
always_ff @(posedge clock) begin
  if (reset) begin
    exu_idu_ready <= 1'b1;
  end else begin
    if (idu_exu_handshake)
      exu_idu_ready <= 1'b0;
    else if (~exu_lsu_valid && lsu_exu_ready && ~load_use_hazard)
      exu_idu_ready <= 1'b1;
  end
end

// 流水线寄存器：锁存 EXU 计算结果传给 LSU
always_ff @(posedge clock) begin
  if (reset) begin
    exu_lsu_valid <= 1'b0;
    o_pc          <= 32'h80000000;
    o_waddr       <= 5'b0;
    o_alu_result  <= 32'b0;
    o_br_taken    <= 1'b0;
    o_br_target   <= 32'b0;
    o_ebreak      <= 1'b0;
    o_wbu_cnt     <= 1'b0;
    o_csr_cnt     <= 3'b0;
    o_lsu_cnt     <= 4'b0;
    o_lsu_wdata   <= 32'b0;
    o_lsu_waddr   <= 32'b0;
    o_lsu_raddr   <= 32'b0;
    o_raddr1      <= 5'b0;
    o_raddr2      <= 5'b0;
  end else begin
    // o_br_taken 只脉冲一拍，下一拍立即清零
    o_br_taken <= 1'b0;
    if (idu_exu_handshake) begin
      exu_lsu_valid <= 1'b1;
      o_pc          <= i_pc;
      o_waddr       <= i_waddr;
      o_alu_result  <= _alu_result;
      o_wbu_cnt     <= i_wbu_cnt;
      o_br_target   <= br_target_calc;
      o_ebreak      <= i_ebreak;
      o_csr_cnt     <= i_csr_cnt;
      o_lsu_cnt     <= i_lsu_cnt;
      // store: waddr = rs1 + imm, wdata = rs2
      o_lsu_waddr   <= src1_data + i_imm;
      o_lsu_wdata   <= src2_data;
      // load: raddr = rs1 + imm
      o_lsu_raddr   <= src1_data + i_imm;
      o_raddr1      <= i_rs1;
      o_raddr2      <= i_rs2;
      o_br_taken    <= exu_redirect_taken || csr_redirect_taken;
    end else if (exu_lsu_handshake) begin
      exu_lsu_valid <= 1'b0;
    end
  end
end

endmodule

module ysyx_24080018_LSU(
  input wire        clock,
  input wire        reset,

  input wire        exu_lsu_valid,
  output reg        lsu_exu_ready,
  output reg        lsu_wbu_valid,
  input wire        wbu_lsu_ready,

  input wire [ 4:0] i_raddr1,
  input wire [ 4:0] i_raddr2,
  input wire [ 4:0] i_waddr,
  input wire [31:0] i_wdata,
  input wire [31:0] i_pc,
  input wire        i_ebreak,
  input wire        i_wbu_cnt,
  input wire [ 3:0] i_lsu_cnt,
  input wire [31:0] i_lsu_wdata,
  input wire [31:0] i_lsu_waddr,
  input wire [31:0] i_lsu_raddr,

  output reg [ 4:0] o_raddr1,
  output reg [ 4:0] o_raddr2,
  output reg [ 4:0] o_waddr,
  output reg [31:0] o_wdata,
  output reg [31:0] o_pc,
  output reg        o_ebreak,
  output reg        o_wbu_cnt,
  output wire       o_bypass_valid,
  output wire       o_load_pending,
  output wire [ 4:0] o_load_waddr,

  output reg [31:0] o_lsu_awaddr ,
  output reg        o_lsu_awvalid,
  input wire        i_lsu_awready,

  output reg [31:0] o_lsu_araddr ,
  output reg        o_lsu_arvalid,
  input wire        i_lsu_arready,

  input wire [31:0] i_lsu_rdata  ,
  input wire [ 1:0] i_lsu_rresp  ,
  input wire        i_lsu_rvalid ,
  output reg        o_lsu_rready ,

  output reg [31:0] o_lsu_wdata  ,
  output reg [ 3:0] o_lsu_wstrb  ,
  output reg        o_lsu_wvalid ,
  input wire        i_lsu_wready ,

  input wire [ 1:0] i_lsu_bresp  ,
  input wire        i_lsu_bvalid ,
  output reg        o_lsu_bready

);

wire lsu_wbu_handshake, exu_lsu_handshake;
assign lsu_wbu_handshake = lsu_wbu_valid && wbu_lsu_ready;
assign exu_lsu_handshake = exu_lsu_valid && lsu_exu_ready;

// 判断是否为 store/load 操作
wire is_store = (i_lsu_cnt >= 4'b0001) && (i_lsu_cnt <= 4'b0011);
wire is_load  = (i_lsu_cnt >= 4'b0100) && (i_lsu_cnt <= 4'b1000);
wire is_mem   = is_store | is_load;
assign o_bypass_valid = ~lsu_exu_ready && o_wbu_cnt && ~(latched_lsu_cnt >= 4'b0100 && latched_lsu_cnt <= 4'b1000);
assign o_load_pending = ~lsu_exu_ready && (latched_lsu_cnt >= 4'b0100) && (latched_lsu_cnt <= 4'b1000);
assign o_load_waddr   = o_waddr;

// 锁存来自 EXU 的操作信息（等待 AXI 完成期间保持稳定）
reg [31:0] latched_addr;
reg [ 3:0] latched_lsu_cnt;

// 读回的数据
reg [31:0] temp;

// 用于 byte/half 选择的地址来自锁存地址
wire [31:0] i_lsu_addr = latched_addr;

wire [31:0] store_wdata;
assign store_wdata = (i_lsu_cnt == 4'b0001) ?
                     ((i_lsu_waddr[1:0] == 2'd0) ? {24'b0, i_lsu_wdata[ 7:0]} :
                      (i_lsu_waddr[1:0] == 2'd1) ? {16'b0, i_lsu_wdata[ 7:0],  8'b0} :
                      (i_lsu_waddr[1:0] == 2'd2) ? { 8'b0, i_lsu_wdata[ 7:0], 16'b0} :
                                                    {        i_lsu_wdata[ 7:0], 24'b0}) :
                     (i_lsu_cnt == 4'b0010) ?
                     (i_lsu_waddr[1] ? {i_lsu_wdata[15:0], 16'b0} :
                                       {16'b0, i_lsu_wdata[15:0]}) :
                     (i_lsu_cnt == 4'b0011) ? i_lsu_wdata :
                     32'b0;

wire [3:0] wmask_half, wmask_byte;
assign wmask_half  = (latched_addr[1]   == 1'b0) ? 4'h3 : 4'hc;
assign wmask_byte  = (latched_addr[1:0] == 2'd0) ? 4'h1 :
                     (latched_addr[1:0] == 2'd1) ? 4'h2 :
                     (latched_addr[1:0] == 2'd2) ? 4'h4 :
                     (latched_addr[1:0] == 2'd3) ? 4'h8 :
                     4'h0;
assign o_lsu_wstrb = (latched_lsu_cnt == 4'b0001) ? wmask_byte : // sb
                     (latched_lsu_cnt == 4'b0010) ? wmask_half : // sh
                     (latched_lsu_cnt == 4'b0011) ? 4'hf       : // sw
                     4'd0;

reg [7:0] byte_sel;
always_comb begin
  unique case (i_lsu_addr[1:0])
    2'b00 : byte_sel = temp[ 7: 0];
    2'b01 : byte_sel = temp[15: 8];
    2'b10 : byte_sel = temp[23:16];
    2'b11 : byte_sel = temp[31:24];
  endcase
end

reg [15:0] half_sel;
always_comb begin
  unique case (i_lsu_addr[1])
    1'b0 : half_sel = temp[15: 0];
    1'b1 : half_sel = temp[31:16];
  endcase
end

wire [31:0] lsu_rdata;
assign lsu_rdata = (latched_lsu_cnt == 4'b0100) ? {{24{byte_sel[ 7]}}, byte_sel} : // lb
                   (latched_lsu_cnt == 4'b0101) ? {{16{half_sel[15]}}, half_sel} : // lh
                   (latched_lsu_cnt == 4'b0110) ? temp                           : // lw
                   (latched_lsu_cnt == 4'b0111) ? {24'b0, byte_sel}              : // lbu
                   (latched_lsu_cnt == 4'b1000) ? {16'b0, half_sel}              : // lhu
                   32'b0;

// AXI 握手信号
wire ar_handshake = o_lsu_arvalid && i_lsu_arready;
wire r_handshake  = i_lsu_rvalid  && o_lsu_rready;
wire aw_handshake = o_lsu_awvalid && i_lsu_awready;
wire w_handshake  = o_lsu_wvalid  && i_lsu_wready;
wire b_handshake  = i_lsu_bvalid  && o_lsu_bready;

// store 时跟踪 AW/W 两个通道是否都完成
reg aw_done, w_done;

// LSU 状态机
typedef enum logic [2:0] {
  LSU_IDLE,
  LSU_LOAD_AR,
  LSU_LOAD_R,
  LSU_STORE_AW,
  LSU_STORE_B,
  LSU_DONE,
  LSU_WAIT_WBU
} lsu_state_t;

lsu_state_t state;

always_ff @(posedge clock) begin
  if (reset) begin
    state           <= LSU_IDLE;
    lsu_exu_ready   <= 1'b1;
    lsu_wbu_valid   <= 1'b0;
    o_lsu_arvalid   <= 1'b0;
    o_lsu_araddr    <= 32'b0;
    o_lsu_rready    <= 1'b0;
    o_lsu_awvalid   <= 1'b0;
    o_lsu_awaddr    <= 32'b0;
    o_lsu_wvalid    <= 1'b0;
    o_lsu_wdata     <= 32'b0;
    o_lsu_bready    <= 1'b0;
    latched_addr    <= 32'b0;
    latched_lsu_cnt <= 4'b0;
    aw_done         <= 1'b0;
    w_done          <= 1'b0;
    temp            <= 32'b0;
    o_raddr1        <= 5'b0;
    o_raddr2        <= 5'b0;
    o_waddr         <= 5'b0;
    o_wdata         <= 32'b0;
    o_pc            <= 32'h80000000;
    o_ebreak        <= 1'b0;
    o_wbu_cnt       <= 1'b0;
  end else begin
    unique case (state)
      LSU_IDLE: begin
        if (exu_lsu_handshake) begin
          lsu_exu_ready   <= 1'b0;
          latched_addr    <= is_load ? i_lsu_raddr : i_lsu_waddr;
          latched_lsu_cnt <= i_lsu_cnt;
          o_raddr1        <= i_raddr1;
          o_raddr2        <= i_raddr2;
          o_waddr         <= i_waddr;
          o_wdata         <= i_wdata;
          o_pc            <= i_pc;
          o_ebreak        <= i_ebreak;
          o_wbu_cnt       <= i_wbu_cnt;
          if (is_load) begin
            o_lsu_araddr  <= {i_lsu_raddr[31:2], 2'b00};
            o_lsu_arvalid <= 1'b1;
            o_lsu_rready  <= 1'b1;
            state         <= LSU_LOAD_AR;
          end else if (is_store) begin
            o_lsu_awaddr  <= {i_lsu_waddr[31:2], 2'b00};
            o_lsu_awvalid <= 1'b1;
            o_lsu_wvalid  <= 1'b1;
            o_lsu_wdata   <= store_wdata;
            aw_done       <= 1'b0;
            w_done        <= 1'b0;
            state         <= LSU_STORE_AW;
          end else begin
            // 非访存指令：等一拍让输出寄存器稳定后再通知 WBU
            state         <= LSU_DONE;
          end
        end else if (lsu_wbu_handshake)
          lsu_wbu_valid <= 1'b0;
      end
      LSU_LOAD_AR: begin
        if (ar_handshake) begin
          o_lsu_arvalid <= 1'b0;
          state         <= LSU_LOAD_R;
        end
      end
      LSU_LOAD_R: begin
        if (r_handshake) begin
          temp          <= i_lsu_rdata;
          o_lsu_rready  <= 1'b0;
          state         <= LSU_DONE;
        end
      end
      LSU_STORE_AW: begin
        if (aw_handshake) begin
          o_lsu_awvalid <= 1'b0;
          aw_done       <= 1'b1;
        end
        if (w_handshake) begin
          o_lsu_wvalid  <= 1'b0;
          w_done        <= 1'b1;
        end
        // 用 flag 判断两个通道是否都完成，避免寄存器更新延迟问题
        if ((aw_handshake || aw_done) && (w_handshake || w_done)) begin
          o_lsu_bready <= 1'b1;
          state        <= LSU_STORE_B;
        end
      end
      LSU_STORE_B: begin
        if (b_handshake) begin
          o_lsu_bready <= 1'b0;
          state        <= LSU_DONE;
        end
      end
      LSU_DONE: begin
        // load 指令：将读回数据写入 o_wdata
        if (latched_lsu_cnt >= 4'b0100)
          o_wdata <= lsu_rdata;
        lsu_wbu_valid <= 1'b1;
        state         <= LSU_WAIT_WBU;
      end
      LSU_WAIT_WBU: begin
        if (lsu_wbu_handshake) begin
          lsu_wbu_valid <= 1'b0;
          lsu_exu_ready <= 1'b1;
          state         <= LSU_IDLE;
        end
      end
    endcase
  end
end

endmodule

module ysyx_24080018_WBU(
  input wire        clock,
  input wire        reset,

  input wire        lsu_wbu_valid,
  output reg        wbu_lsu_ready,

  output wire [31:0] rdata1,
  output wire [31:0] rdata2,

  input wire [ 4:0] i_raddr1,
  input wire [ 4:0] i_raddr2,
  input wire [ 4:0] i_waddr,
  input wire [31:0] i_wdata,
  input wire [31:0] i_pc,
  input wire        ebreak,
  input wire        i_wbu_cnt
);

  reg [31:0] rf [32];

  assign rdata1 = (i_raddr1 == 5'b0) ? 32'b0 :
                  (wen && i_waddr == i_raddr1) ? i_wdata :
                  rf[i_raddr1];
  assign rdata2 = (i_raddr2 == 5'b0) ? 32'b0 :
                  (wen && i_waddr == i_raddr2) ? i_wdata :
                  rf[i_raddr2];

  wire wen;
  assign wen = i_wbu_cnt && lsu_wbu_valid;

  always_comb begin
    if(ebreak) begin
      NPCTRAP(i_pc,rf[10]);
    end
  end
  always_ff @(posedge clock) begin
    if(reset) begin
      wbu_lsu_ready <= 1'b1;
      for(integer i = 1; i < 32; i = i + 1) begin
        rf[i] <= 32'b0;
      end
    end else begin
      if(wbu_lsu_ready && lsu_wbu_valid ) begin
        if(wen && (i_waddr != 5'b0)) begin
          rf[i_waddr] <= i_wdata;
        end
      end
    end
  end
endmodule

module ysyx_24080018_arbiter(
    input            clock,
    input            reset,

    input     [31:0] o_ifu_araddr  ,
    input            o_ifu_arvalid ,
    output           i_ifu_arready ,
    output    [31:0] i_ifu_rdata   ,
    output    [ 1:0] i_ifu_rresp   ,
    output           i_ifu_rvalid  ,
    input            o_ifu_rready  ,

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
    typedef enum logic [2:0] {
      IDLE    = 3'b001,
      IFU_RD  = 3'b010,
      LSU_WR  = 3'b011,
      LSU_RD  = 3'b100,
      RESP    = 3'b101
    } state_e;
    state_e cstate,nstate;

    // 当前事务信息（寄存器，在状态转移时锁存）
    reg        current_master;
    reg        current_is_write;
    reg [31:0] current_addr;

    // LSU_WR 状态下独立跟踪 AW/W 通道是否完成
    reg arb_aw_done, arb_w_done;

    always @(posedge clock) begin
        if (reset) begin
            cstate           <= IDLE;
            current_master   <= 1'b0;
            current_is_write <= 1'b0;
            current_addr     <= 32'b0;
            arb_aw_done      <= 1'b0;
            arb_w_done       <= 1'b0;
        end else begin
            cstate <= nstate;
            // 进入 LSU_WR 时清零完成标志
            if (cstate == IDLE && o_lsu_awvalid)
                {arb_aw_done, arb_w_done} <= 2'b00;
            // 在 LSU_WR 状态下分别记录 AW/W 握手完成
            if (cstate == LSU_WR) begin
                if (io_master_awready) arb_aw_done <= 1'b1;
                if (io_master_wready)  arb_w_done  <= 1'b1;
            end
            // 在离开 IDLE 时锁存事务信息
            if (cstate == IDLE) begin
                if (o_ifu_arvalid) begin
                    current_master   <= 1'b0;
                    current_is_write <= 1'b0;
                    current_addr     <= o_ifu_araddr;
                end else if (o_lsu_awvalid) begin
                    current_master   <= 1'b1;
                    current_is_write <= 1'b1;
                    current_addr     <= o_lsu_awaddr;
                end else if (o_lsu_arvalid) begin
                    current_master   <= 1'b1;
                    current_is_write <= 1'b0;
                    current_addr     <= o_lsu_araddr;
                end
            end
        end
    end

    always_comb begin
        nstate = cstate;
        case (cstate)
            IDLE: begin
                if (o_ifu_arvalid)
                    nstate = IFU_RD;
                else if (o_lsu_awvalid)
                    nstate = LSU_WR;
                else if (o_lsu_arvalid)
                    nstate = LSU_RD;
            end
            IFU_RD: begin
                if (io_master_arready)
                    nstate = RESP;
            end
            LSU_WR: begin
                // AW/W 通道独立握手，两者都完成才转 RESP
                if ((io_master_awready || arb_aw_done) && (io_master_wready || arb_w_done))
                    nstate = RESP;
            end
            LSU_RD: begin
                if (io_master_arready)
                    nstate = RESP;
            end
            RESP: begin
                if ((!current_is_write && io_master_rvalid && io_master_rready) ||
                    ( current_is_write && io_master_bvalid && io_master_bready))
                    nstate = IDLE;
            end
            default: nstate = IDLE;
        endcase
    end
    // ===== 输出信号 =====
    // AR 通道：IFU_RD/LSU_RD 状态时发出读请求
    assign io_master_araddr  = current_addr;
    assign io_master_arvalid = (cstate == IFU_RD || cstate == LSU_RD);
    assign io_master_rready  = (cstate == RESP && !current_is_write);

    // AW/W 通道：LSU_WR 状态时发出写请求，握手完成后撤销 valid
    assign io_master_awaddr  = current_addr;
    assign io_master_awvalid = (cstate == LSU_WR) && !arb_aw_done;
    assign io_master_wdata   = o_lsu_wdata;
    assign io_master_wstrb   = o_lsu_wstrb;
    assign io_master_wvalid  = (cstate == LSU_WR) && !arb_w_done;

    // B 通道：RESP 且写操作时，透传 LSU 的 bready
    assign io_master_bready  = (cstate == RESP && current_is_write) ? o_lsu_bready : 1'b0;

    // 到 IFU 的接口
    // arready：IFU_RD 状态时表示仲裁器已接受请求
    assign i_ifu_arready = (cstate == IFU_RD);
    // rdata/rresp/rvalid：RESP 状态且当前是 IFU 读时，直通 master 响应
    assign i_ifu_rdata   = io_master_rdata;
    assign i_ifu_rresp   = io_master_rresp;
    assign i_ifu_rvalid  = (cstate == RESP && !current_is_write && current_master == 1'b0)
                           && io_master_rvalid;

    // 到 LSU 的接口
    assign i_lsu_awready = (cstate == LSU_WR) ? io_master_awready : 1'b0;
    assign i_lsu_wready  = (cstate == LSU_WR) ? io_master_wready  : 1'b0;
    assign i_lsu_arready = (cstate == LSU_RD) ? io_master_arready : 1'b0;
    assign i_lsu_rdata   = io_master_rdata;
    assign i_lsu_rresp   = io_master_rresp;
    assign i_lsu_rvalid  = (cstate == RESP && !current_is_write && current_master == 1'b1)
                           && io_master_rvalid;
    assign i_lsu_bresp   = io_master_bresp;
    assign i_lsu_bvalid  = (cstate == RESP && current_is_write) && io_master_bvalid;
endmodule

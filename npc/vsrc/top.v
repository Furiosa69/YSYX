import "DPI-C" function void NPCTRAP(input int unsigned pc, input int x10);
import "DPI-C" function void pmem_write(input int unsigned addr, input int unsigned data, input int size);
import "DPI-C" function int unsigned pmem_read(input int unsigned addr, input int size);

module top(
	input 			  clk,
	input 			  reset 
);

wire [31:0] ifu_pc;
wire [31:0] inst;
wire [ 3:0] lsu_cnt;
wire        mem_cnt;
wire [ 3:0] alu_cnt;
wire [ 5:0] ins_cnt;
wire [ 2:0] csr_cnt;
wire [ 3:0] pc_cnt;
wire [ 4:0] raddr1,raddr2,waddr;
wire [31:0] rdata1,rdata2,wdata;
wire [31:0] addr_load,addr_store;
wire [31:0] data_load,data_store;
wire [31:0] imm;
wire [11:0] csr_imm;
wire [31:0] csr_data;
wire 				br_taken;
wire 				auipc,lui,ebreak,load,jalr,jal;
assign data_store = rdata2;
assign addr_store = rdata1 + imm;
assign addr_load  = rdata1 + imm;

IFU ifu_t0(
	.clk(clk),
	.reset(reset),
	.inst(inst),
	.pc_out(ifu_pc),
	.imm(imm),
	.br_taken(br_taken),
	.ret(rdata1),
	.csr_data(csr_data),
	.pc_cnt(pc_cnt)
);

IDU idu_t0(
	.inst(inst),
	.lsu_cnt(lsu_cnt),
	.mem_cnt(mem_cnt),
	.alu_cnt(alu_cnt),
	.ins_cnt(ins_cnt),
	.csr_cnt(csr_cnt),
	.pc_cnt(pc_cnt),
	.auipc(auipc),
	.lui(lui),
	.ebreak(ebreak),
	.jalr(jalr),
	.jal(jal),
	.load(load),
	.rd(waddr),
	.rs1(raddr1),
	.rs2(raddr2),
	.csr_imm(csr_imm),
	.imm(imm)
);

EXU exu_t0(
	.pc_in(ifu_pc),
	.pc_cnt(pc_cnt),
	.alu_cnt(alu_cnt),
	.ins_cnt(ins_cnt),
	.csr_cnt(csr_cnt),
	.auipc(auipc),
	.lui(lui),
	.load(load),
	.jalr(jalr),
	.jal(jal),
	.imm(imm),
	.csr_data(csr_data),
	.alu_result(wdata),
	.br_taken(br_taken),
	.rdata1(rdata1),
	.rdata2(rdata2),
	.data_load(data_load)
);

GPR gpr_t0(
	.clk(clk),
	.reset(reset),
	.pc_in(ifu_pc),
	.mem_cnt(mem_cnt),
	.ebreak(ebreak),
	.raddr1(raddr1),
	.raddr2(raddr2),
	.rdata1(rdata1),
	.rdata2(rdata2),
	.waddr(waddr),
	.wdata(wdata)
);

LSU lsu_t0(
	.lsu_cnt(lsu_cnt),
	.data_load(data_load),
	.data_store(data_store),
	.addr_load(addr_load),
	.addr_store(addr_store)
);

CSR csr_t0(
	.clk(clk),
	.reset(reset),
	.pc_in(ifu_pc),
	.csr_cnt(csr_cnt),
	.csr_imm(csr_imm),
	.wdata(rdata1),
	.rdata(csr_data)
);

endmodule

	

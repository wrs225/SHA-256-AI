/*
Large Language Model Descriptor
module wb_to_li_converter #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32,
    parameter FIFO_DEPTH = 4
) (
    input wb_clk_i,
    input wb_rst_i,
    input wbs_stb_i,
    input wbs_cyc_i,
    input wbs_we_i,
    input [3:0] wbs_sel_i,
    input [DATA_WIDTH-1:0] wbs_dat_i,
    input [ADDR_WIDTH-1:0] wbs_adr_i,
    output logic wbs_ack_o,
    output logic [DATA_WIDTH-1:0] wbs_dat_o,
    // Latency Insensitive Send Interface
    output logic [DATA_WIDTH+ADDR_WIDTH+1-1:0] send_msg,
    output logic send_val,
    input send_rdy,
    // Latency Insensitive Receive Interface
    input [DATA_WIDTH+ADDR_WIDTH+1-1:0] recv_msg,
    input recv_val,
    output logic recv_rdy
);

This module, wb_to_li_converter, is a Wishbone to Latency Insensitive interface converter. It is designed to interface with a RISC-V CPU and a SHA-256 Accelerator. The module takes in signals from the Wishbone interface, including data, address, and control signals, and converts them into a format suitable for the Latency Insensitive interface. The module also receives data from the Latency Insensitive interface and converts it back into a format suitable for the Wishbone interface. The module uses a FIFO to buffer transactions and handle backpressure from the Latency Insensitive interface. The depth of the FIFO can be configured using the FIFO_DEPTH parameter. The data and address widths can also be configured using the DATA_WIDTH and ADDR_WIDTH parameters, respectively.

*/


// I changed the name to WbToLiConverter so it works with PyMTL. I think it is a trivial change to get the two tools to work.
module WbToLiConverter #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32,
    parameter FIFO_DEPTH = 4
) (
    input wb_clk_i,
    input wb_rst_i,
    input wbs_stb_i,
    input wbs_cyc_i,
    input wbs_we_i,
    input [3:0] wbs_sel_i,
    input [DATA_WIDTH-1:0] wbs_dat_i,
    input [ADDR_WIDTH-1:0] wbs_adr_i,
    output logic wbs_ack_o,
    output logic [DATA_WIDTH-1:0] wbs_dat_o,
    // Latency Insensitive Send Interface
    output logic [DATA_WIDTH+ADDR_WIDTH+1-1:0] send_msg,
    output logic send_val,
    input send_rdy,
    // Latency Insensitive Receive Interface
    input [DATA_WIDTH+ADDR_WIDTH+1-1:0] recv_msg,
    input recv_val,
    output logic recv_rdy
);

    // Define the FIFO entry type
    typedef struct packed {
        logic [DATA_WIDTH+ADDR_WIDTH+1-1:0] msg;
        logic valid;
    } fifo_entry_t;

    // FIFO variables
    fifo_entry_t fifo [0:FIFO_DEPTH-1];
    int fifo_head;
    int fifo_tail;
    logic fifo_empty;
    logic fifo_full;

    // FSM states
    typedef enum logic [1:0] {IDLE, SEND, RECEIVE, WAIT} state_t;
    state_t state;

    // FSM logic
    always_ff @(posedge wb_clk_i or posedge wb_rst_i) begin
        if (wb_rst_i) begin
            fifo_head <= 0;
            fifo_tail <= 0;
            fifo_empty <= 1;
            fifo_full <= 0;
            state <= IDLE;
        end else begin
            case (state)
                IDLE: begin
                    if (wbs_stb_i && wbs_cyc_i && !fifo_full) begin
                        // Push transaction into FIFO
                        fifo[fifo_tail].msg <= {wbs_we_i, wbs_adr_i, wbs_dat_i};
                        fifo[fifo_tail].valid <= 1;
                        fifo_tail <= (fifo_tail + 1) % FIFO_DEPTH;
                        fifo_empty <= 0;
                        fifo_full <= (fifo_tail == fifo_head);
                        state <= SEND;
                    end
                end
                SEND: begin
                    if (send_rdy && !fifo_empty) begin
                        // Pop transaction from FIFO
                        fifo_head <= (fifo_head + 1) % FIFO_DEPTH;
                        fifo_full <= 0;
                        fifo_empty <= (fifo_head == fifo_tail);
                        state <= RECEIVE;
                    end
                end
                RECEIVE: begin
                    if (recv_val) begin
                        // Receive data from LI interface
                        wbs_dat_o <= recv_msg[DATA_WIDTH-1:0];
                        state <= WAIT;
                    end
                end
                WAIT: begin
                    if (wbs_stb_i && wbs_cyc_i && !wbs_we_i) begin
                        // Wait for Wishbone to acknowledge the data
                        wbs_ack_o <= 1;
                        state <= IDLE;
                    end else begin
                        wbs_ack_o <= 0;
                    end
                end
            endcase
        end
    end

    // Assignments for LI interface
    assign send_msg = fifo[fifo_head].msg;
    assign send_val = !fifo_empty;
    assign recv_rdy = (state == RECEIVE);

endmodule
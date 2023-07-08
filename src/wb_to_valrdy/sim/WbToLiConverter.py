from pymtl3 import *
from pymtl3.passes.backends.verilog import *

class WbToLiConverter( VerilogPlaceholder, Component ):
  def construct( s, DATA_WIDTH=32, ADDR_WIDTH=32, FIFO_DEPTH=4 ):

    #Added by me
    s.set_metadata(VerilogTranslationPass.explicit_module_name, 'wbtoliconverter' )

    # Wishbone interface
    s.wb_clk_i  = InPort ( 1 )
    s.wb_rst_i  = InPort ( 1 )
    s.wbs_stb_i = InPort ( 1 )
    s.wbs_cyc_i = InPort ( 1 )
    s.wbs_we_i  = InPort ( 1 )
    s.wbs_sel_i = InPort ( 4 )
    s.wbs_dat_i = InPort ( DATA_WIDTH )
    s.wbs_adr_i = InPort ( ADDR_WIDTH )
    s.wbs_ack_o = OutPort( 1 )
    s.wbs_dat_o = OutPort( DATA_WIDTH )

    # Latency Insensitive Send Interface
    s.send_msg  = OutPort( DATA_WIDTH+ADDR_WIDTH+1 )
    s.send_val  = OutPort( 1 )
    s.send_rdy  = InPort ( 1 )

    # Latency Insensitive Receive Interface
    s.recv_msg  = InPort ( DATA_WIDTH+ADDR_WIDTH+1 )
    s.recv_val  = InPort ( 1 )
    s.recv_rdy  = OutPort( 1 )

    # Verilog import setup
    s.set_metadata( VerilogPlaceholderPass.params, {
      'DATA_WIDTH' : DATA_WIDTH,
      'ADDR_WIDTH' : ADDR_WIDTH,
      'FIFO_DEPTH' : FIFO_DEPTH,
    })
    s.set_metadata( VerilogPlaceholderPass.has_clk, True )
    s.set_metadata( VerilogPlaceholderPass.has_reset, True )

    #This is not needed in newer versions of pyMTL
    """
    s.add_metadata( VerilogPlaceholderPass.port_map, {
      'wb_clk_i'  : 'wb_clk_i',
      'wb_rst_i'  : 'wb_rst_i',
      'wbs_stb_i' : 'wbs_stb_i',
      'wbs_cyc_i' : 'wbs_cyc_i',
      'wbs_we_i'  : 'wbs_we_i',
      'wbs_sel_i' : 'wbs_sel_i',
      'wbs_dat_i' : 'wbs_dat_i',
      'wbs_adr_i' : 'wbs_adr_i',
      'wbs_ack_o' : 'wbs_ack_o',
      'wbs_dat_o' : 'wbs_dat_o',
      'send_msg'  : 'send_msg',
      'send_val'  : 'send_val',
      'send_rdy'  : 'send_rdy',
      'recv_msg'  : 'recv_msg',
      'recv_val'  : 'recv_val',
      'recv_rdy'  : 'recv_rdy',
    })
    """
wbtoliconerter = WbToLiConverter
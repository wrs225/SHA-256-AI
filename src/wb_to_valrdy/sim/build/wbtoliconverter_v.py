
#=========================================================================
# Vwbtoliconverter_v.py
#=========================================================================
"""Provide a template of PyMTL wrapper to import verilated models.

This wrapper makes a Verilator-generated C++ model appear as if it were a
normal PyMTL model. This template is based on PyMTL v2.
"""

import os

from cffi import FFI

from pymtl3.datatypes import *
from pymtl3.dsl import Component, connect, InPort, OutPort, Wire, update, update_ff

#-------------------------------------------------------------------------
# wbtoliconverter
#-------------------------------------------------------------------------

class wbtoliconverter( Component ):
  id_ = 0

  def __init__( s, *args, **kwargs ):
    s._finalization_count = 0

    # initialize FFI, define the exposed interface
    s.ffi = FFI()
    s.ffi.cdef("""
      typedef struct {

        // Exposed port interface
        unsigned int * recv_msg;        
        unsigned char * recv_rdy;        
        unsigned char * recv_val;        
        unsigned int * send_msg;        
        unsigned char * send_rdy;        
        unsigned char * send_val;        
        unsigned char * wb_clk_i;        
        unsigned char * wb_rst_i;        
        unsigned char * wbs_ack_o;        
        unsigned int * wbs_adr_i;        
        unsigned char * wbs_cyc_i;        
        unsigned long * wbs_dat_i;        
        unsigned long * wbs_dat_o;        
        unsigned char * wbs_sel_i;        
        unsigned char * wbs_stb_i;        
        unsigned char * wbs_we_i;

        // Verilator model
        void * model;

      } Vwbtoliconverter_t;

      Vwbtoliconverter_t * create_model( const char * );
      void destroy_model( Vwbtoliconverter_t *);
      void comb_eval( Vwbtoliconverter_t * );
      void seq_eval( Vwbtoliconverter_t * );
      void assert_en( bool en );
      

    """)

    # Print the modification time stamp of the shared lib
    # print 'Modification time of {}: {}'.format(
    #   'libwbtoliconverter_v.so', os.path.getmtime( './libwbtoliconverter_v.so' ) )

    # Import the shared library containing the model. We defer
    # construction to the elaborate_logic function to allow the user to
    # set the vcd_file.
    s._ffi_inst = s.ffi.dlopen('./libwbtoliconverter_v.so')

    # increment instance count
    wbtoliconverter.id_ += 1

  def finalize( s ):
    """Finalize the imported component.

    This method closes the shared library opened through CFFI. If an imported
    component is not finalized explicitly (i.e. if you rely on GC to collect a
    no longer used imported component), importing a component with the same
    name before all previous imported components are GCed might lead to
    confusing behaviors. This is because once opened, the shared lib
    is cached by the OS until the OS reference counter for this lib reaches
    0 (you can decrement the reference counter by calling `dl_close()` syscall).

    Fortunately real designs tend to always have the same shared lib corresponding
    to the components with the same name. If you are doing translation testing and
    use the same component class name even if they refer to different designs,
    you might need to call `imported_object.finalize()` at the end of each test
    to ensure correct behaviors.
    """
    assert s._finalization_count == 0,      'Imported component can only be finalized once!'
    s._finalization_count += 1
    s._ffi_inst.destroy_model( s._ffi_m )
    s.ffi.dlclose( s._ffi_inst )
    s.ffi = None
    s._ffi_inst = None

  def __del__( s ):
    if s._finalization_count == 0:
      s._finalization_count += 1
      s._ffi_inst.destroy_model( s._ffi_m )
      s.ffi.dlclose( s._ffi_inst )
      s.ffi = None
      s._ffi_inst = None

  def construct( s, *args, **kwargs ):
    # Set up the VCD file name
    verilator_vcd_file = ""
    if 0:
      if False:
        verilator_vcd_file = ".verilator1.vcd"
      else:
        verilator_vcd_file = "wbtoliconverter.verilator1.vcd"

    # Convert string to `bytes` which is required by CFFI on python 3
    verilator_vcd_file = verilator_vcd_file.encode('ascii')

    # Construct the model
    s._ffi_m = s._ffi_inst.create_model( s.ffi.new("char[]", verilator_vcd_file) )

    # Buffer for line tracing
    s._line_trace_str = s.ffi.new('char[512]')
    s._convert_string = s.ffi.string

    # Use non-attribute varialbe to reduce CPython bytecode count
    _ffi_m = s._ffi_m
    _ffi_inst_comb_eval = s._ffi_inst.comb_eval
    _ffi_inst_seq_eval  = s._ffi_inst.seq_eval

    # declare the port interface
    s.recv_msg = InPort( Bits97 )
    s.recv_rdy = OutPort( Bits1 )
    s.recv_val = InPort( Bits1 )
    s.send_msg = OutPort( Bits97 )
    s.send_rdy = InPort( Bits1 )
    s.send_val = OutPort( Bits1 )
    s.wb_clk_i = InPort( Bits1 )
    s.wb_rst_i = InPort( Bits1 )
    s.wbs_ack_o = OutPort( Bits1 )
    s.wbs_adr_i = InPort( Bits32 )
    s.wbs_cyc_i = InPort( Bits1 )
    s.wbs_dat_i = InPort( Bits64 )
    s.wbs_dat_o = OutPort( Bits64 )
    s.wbs_sel_i = InPort( Bits4 )
    s.wbs_stb_i = InPort( Bits1 )
    s.wbs_we_i = InPort( Bits1 )

    # update blocks that converts ffi interface to/from pymtl ports
    
    s.s_DOT_recv_msg = Wire( Bits97 )
    @update
    def isignal_s_DOT_recv_msg():
      s.s_DOT_recv_msg @= s.recv_msg
    
    s.s_DOT_recv_val = Wire( Bits1 )
    @update
    def isignal_s_DOT_recv_val():
      s.s_DOT_recv_val @= s.recv_val
    
    s.s_DOT_send_rdy = Wire( Bits1 )
    @update
    def isignal_s_DOT_send_rdy():
      s.s_DOT_send_rdy @= s.send_rdy
    
    s.s_DOT_wb_clk_i = Wire( Bits1 )
    @update
    def isignal_s_DOT_wb_clk_i():
      s.s_DOT_wb_clk_i @= s.wb_clk_i
    
    s.s_DOT_wb_rst_i = Wire( Bits1 )
    @update
    def isignal_s_DOT_wb_rst_i():
      s.s_DOT_wb_rst_i @= s.wb_rst_i
    
    s.s_DOT_wbs_adr_i = Wire( Bits32 )
    @update
    def isignal_s_DOT_wbs_adr_i():
      s.s_DOT_wbs_adr_i @= s.wbs_adr_i
    
    s.s_DOT_wbs_cyc_i = Wire( Bits1 )
    @update
    def isignal_s_DOT_wbs_cyc_i():
      s.s_DOT_wbs_cyc_i @= s.wbs_cyc_i
    
    s.s_DOT_wbs_dat_i = Wire( Bits64 )
    @update
    def isignal_s_DOT_wbs_dat_i():
      s.s_DOT_wbs_dat_i @= s.wbs_dat_i
    
    s.s_DOT_wbs_sel_i = Wire( Bits4 )
    @update
    def isignal_s_DOT_wbs_sel_i():
      s.s_DOT_wbs_sel_i @= s.wbs_sel_i
    
    s.s_DOT_wbs_stb_i = Wire( Bits1 )
    @update
    def isignal_s_DOT_wbs_stb_i():
      s.s_DOT_wbs_stb_i @= s.wbs_stb_i
    
    s.s_DOT_wbs_we_i = Wire( Bits1 )
    @update
    def isignal_s_DOT_wbs_we_i():
      s.s_DOT_wbs_we_i @= s.wbs_we_i
    
    s.s_DOT_recv_rdy = Wire( Bits1 )
    @update
    def osignal_s_DOT_recv_rdy():
      s.recv_rdy @= s.s_DOT_recv_rdy
    
    s.s_DOT_send_msg = Wire( Bits97 )
    @update
    def osignal_s_DOT_send_msg():
      s.send_msg @= s.s_DOT_send_msg
    
    s.s_DOT_send_val = Wire( Bits1 )
    @update
    def osignal_s_DOT_send_val():
      s.send_val @= s.s_DOT_send_val
    
    s.s_DOT_wbs_ack_o = Wire( Bits1 )
    @update
    def osignal_s_DOT_wbs_ack_o():
      s.wbs_ack_o @= s.s_DOT_wbs_ack_o
    
    s.s_DOT_wbs_dat_o = Wire( Bits64 )
    @update
    def osignal_s_DOT_wbs_dat_o():
      s.wbs_dat_o @= s.s_DOT_wbs_dat_o

    @update
    def comb_upblk():

      # Set inputs
      
      x = _ffi_m.recv_msg
      x[0] = int(s.s_DOT_recv_msg[0:32])
      x[1] = int(s.s_DOT_recv_msg[32:64])
      x[2] = int(s.s_DOT_recv_msg[64:96])
      x[3] = int(s.s_DOT_recv_msg[96:97])
      
      _ffi_m.recv_val[0] = int(s.s_DOT_recv_val)
      
      _ffi_m.send_rdy[0] = int(s.s_DOT_send_rdy)
      
      _ffi_m.wb_clk_i[0] = int(s.s_DOT_wb_clk_i)
      
      _ffi_m.wb_rst_i[0] = int(s.s_DOT_wb_rst_i)
      
      _ffi_m.wbs_adr_i[0] = int(s.s_DOT_wbs_adr_i)
      
      _ffi_m.wbs_cyc_i[0] = int(s.s_DOT_wbs_cyc_i)
      
      _ffi_m.wbs_dat_i[0] = int(s.s_DOT_wbs_dat_i)
      
      _ffi_m.wbs_sel_i[0] = int(s.s_DOT_wbs_sel_i)
      
      _ffi_m.wbs_stb_i[0] = int(s.s_DOT_wbs_stb_i)
      
      _ffi_m.wbs_we_i[0] = int(s.s_DOT_wbs_we_i)

      _ffi_inst_comb_eval( _ffi_m )

      # Write all outputs
      
      s.s_DOT_recv_rdy @= _ffi_m.recv_rdy[0]
      
      x = _ffi_m.send_msg
      s.s_DOT_send_msg[0:32] @= x[0]
      s.s_DOT_send_msg[32:64] @= x[1]
      s.s_DOT_send_msg[64:96] @= x[2]
      s.s_DOT_send_msg[96:97] @= x[3]
      
      s.s_DOT_send_val @= _ffi_m.send_val[0]
      
      s.s_DOT_wbs_ack_o @= _ffi_m.wbs_ack_o[0]
      
      s.s_DOT_wbs_dat_o @= _ffi_m.wbs_dat_o[0]

    @update_ff
    def seq_upblk():
      # seq_eval will automatically tick clock in C land
      _ffi_inst_seq_eval( _ffi_m )

  def assert_en( s, en ):
    # TODO: for verilator, any assertion failure will cause the C simulator
    # to abort, which results in a Python internal error. A better approach
    # is to throw a Python exception at the time of assertion failure.
    # Verilator allows user-defined `stop` function which is called when
    # the simulation is expected to stop due to various reasons. We might
    # be able to raise a Python exception through Python C API (although
    # at this moment I'm not sure if the C API's are compatible between
    # PyPy and CPython).
    assert isinstance( en, bool )
    s._ffi_inst.assert_en( en )

  def line_trace( s ):
    if 0:
      s._ffi_inst.trace( s._ffi_m, s._line_trace_str )
      return s._convert_string( s._line_trace_str ).decode('ascii')
    else:
      return f' recv_msg={s.recv_msg}, recv_rdy={s.recv_rdy}, recv_val={s.recv_val}, send_msg={s.send_msg}, send_rdy={s.send_rdy}, send_val={s.send_val}, wb_clk_i={s.wb_clk_i}, wb_rst_i={s.wb_rst_i}, wbs_ack_o={s.wbs_ack_o}, wbs_adr_i={s.wbs_adr_i}, wbs_cyc_i={s.wbs_cyc_i}, wbs_dat_i={s.wbs_dat_i}, wbs_dat_o={s.wbs_dat_o}, wbs_sel_i={s.wbs_sel_i}, wbs_stb_i={s.wbs_stb_i}, wbs_we_i={s.wbs_we_i},'

  def internal_line_trace( s ):
    return ''

import pytest
from pymtl3 import *
from pymtl3.stdlib.test_utils import run_test_vector_sim #PyMTL has changed a decent bit since 2021, so I needed to slightly change the package.
from sim.WbToLiConverter import WbToLiConverter
import random


def test_WbToLiConverter():
  DATA_WIDTH = 32
  ADDR_WIDTH = 32
  FIFO_DEPTH = 4

  model = WbToLiConverter( DATA_WIDTH, ADDR_WIDTH, FIFO_DEPTH )

  test_vectors = [
    ("wb_clk_i wb_rst_i wbs_stb_i wbs_cyc_i wbs_we_i wbs_sel_i wbs_dat_i wbs_adr_i wbs_ack_o wbs_dat_o send_msg send_val send_rdy recv_msg recv_val recv_rdy"),
    [ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ], # Reset
    [ 1, 0, 1, 1, 1, 0b1111, 0xDEADBEEF, 0x1000, 0, 0, 0, 0, 0, 0, 0, 0 ], # Write request
    [ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0x1000DEADBEEF, 1, 1, 0, 0, 0 ], # Write acknowledge
    [ 1, 0, 1, 1, 0, 0b1111, 0, 0x1000, 0, 0, 0, 0, 0, 0, 0, 0 ], # Read request
    [ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0xDEADBEEF, 0x100000000000, 1, 1, 0, 0, 0 ], # Read acknowledge
    [ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x1000DEADBEEF, 1, 1 ], # Receive data
  ]

  run_test_vector_sim(model, test_vectors)


def test_WbToLiConverter_second():
  DATA_WIDTH = 32
  ADDR_WIDTH = 32
  FIFO_DEPTH = 4

  model = WbToLiConverter( DATA_WIDTH, ADDR_WIDTH, FIFO_DEPTH )

  test_vectors = [
    ("wb_clk_i wb_rst_i wbs_stb_i wbs_cyc_i wbs_we_i wbs_sel_i wbs_dat_i wbs_adr_i wbs_ack_o wbs_dat_o send_msg send_val send_rdy recv_msg recv_val recv_rdy"),
    [ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ], # Reset
    [ 1, 0, 1, 1, 1, 0b1111, 0xDEADBEEF, 0x1000, 0, 0, 0, 0, 0, 0, 0, 0 ], # Write request
    [ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0x1000DEADBEEF, 1, 1, 0, 0, 0 ], # Write acknowledge
    [ 1, 0, 1, 1, 0, 0b1111, 0, 0x1000, 0, 0, 0, 0, 0, 0, 0, 0 ], # Read request
    [ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0xDEADBEEF, 0x100000000000, 1, 1, 0, 0, 0 ], # Read acknowledge
    [ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x1000DEADBEEF, 1, 1 ], # Receive data
    [ 1, 0, 1, 1, 1, 0b1111, 0xBEEFCAFE, 0x2000, 0, 0, 0, 0, 0, 0, 0, 0 ], # Write request
    [ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0x2000BEEFCAFE, 1, 1, 0, 0, 0 ], # Write acknowledge
    [ 1, 0, 1, 1, 0, 0b1111, 0, 0x2000, 0, 0, 0, 0, 0, 0, 0, 0 ], # Read request
    [ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0xBEEFCAFE, 0x200000000000, 1, 1, 0, 0, 0 ], # Read acknowledge
    [ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x2000BEEFCAFE, 1, 1 ], # Receive data
  ]

  run_test_vector_sim(model, test_vectors)

def test_WbToLiConverter_write():
  DATA_WIDTH = 32
  ADDR_WIDTH = 32
  FIFO_DEPTH = 4

  model = WbToLiConverter( DATA_WIDTH, ADDR_WIDTH, FIFO_DEPTH )

  test_vectors = [
    ("wb_clk_i wb_rst_i wbs_stb_i wbs_cyc_i wbs_we_i wbs_sel_i wbs_dat_i wbs_adr_i wbs_ack_o wbs_dat_o send_msg send_val send_rdy recv_msg recv_val recv_rdy"),
    [ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ], # Reset
    [ 1, 0, 1, 1, 1, 0b1111, 0xCAFEBABE, 0x3000, 0, 0, 0, 0, 0, 0, 0, 0 ], # Write request
    [ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0x3000CAFEBABE, 1, 1, 0, 0, 0 ], # Write acknowledge
  ]

  run_test_vector_sim(model, test_vectors)

def test_WbToLiConverter_read():
  DATA_WIDTH = 32
  ADDR_WIDTH = 32
  FIFO_DEPTH = 4

  model = WbToLiConverter( DATA_WIDTH, ADDR_WIDTH, FIFO_DEPTH )

  test_vectors = [
    ("wb_clk_i wb_rst_i wbs_stb_i wbs_cyc_i wbs_we_i wbs_sel_i wbs_dat_i wbs_adr_i wbs_ack_o wbs_dat_o send_msg send_val send_rdy recv_msg recv_val recv_rdy"),
    [ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ], # Reset
    [ 1, 0, 1, 1, 0, 0b1111, 0, 0x3000, 0, 0, 0, 0, 0, 0, 0, 0 ], # Read request
    [ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0xCAFEBABE, 0x300000000000, 1, 1, 0, 0, 0 ], # Read acknowledge
  ]

  run_test_vector_sim(model, test_vectors)

def test_WbToLiConverter_receive():
  DATA_WIDTH = 32
  ADDR_WIDTH = 32
  FIFO_DEPTH = 4

  model = WbToLiConverter( DATA_WIDTH, ADDR_WIDTH, FIFO_DEPTH )

  test_vectors = [
    ("wb_clk_i wb_rst_i wbs_stb_i wbs_cyc_i wbs_we_i wbs_sel_i wbs_dat_i wbs_adr_i wbs_ack_o wbs_dat_o send_msg send_val send_rdy recv_msg recv_val recv_rdy"),
    [ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ], # Reset
    [ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x3000CAFEBABE, 1, 1 ], # Receive data
  ]

  run_test_vector_sim(model, test_vectors)

def test_WbToLiConverter_reset():
  DATA_WIDTH = 32
  ADDR_WIDTH = 32
  FIFO_DEPTH = 4

  model = WbToLiConverter( DATA_WIDTH, ADDR_WIDTH, FIFO_DEPTH )

  test_vectors = [
    ("wb_clk_i wb_rst_i wbs_stb_i wbs_cyc_i wbs_we_i wbs_sel_i wbs_dat_i wbs_adr_i wbs_ack_o wbs_dat_o send_msg send_val send_rdy recv_msg recv_val recv_rdy"),
    [ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ], # Reset
  ]

  run_test_vector_sim(model, test_vectors)

def test_WbToLiConverter_random():
  for _ in range(10): # Generate 10 random tests
    DATA_WIDTH = random.choice([16, 32, 64])
    ADDR_WIDTH = random.choice([16, 32, 64])
    FIFO_DEPTH = random.choice([2, 4, 8, 16])

    model = WbToLiConverter( DATA_WIDTH, ADDR_WIDTH, FIFO_DEPTH )

    # Generate random values for write, read, and receive operations
    write_val = random.randint(0, 2**DATA_WIDTH - 1)
    write_addr = random.randint(0, 2**ADDR_WIDTH - 1)
    read_addr = random.randint(0, 2**ADDR_WIDTH - 1)
    recv_val = random.randint(0, 2**DATA_WIDTH - 1)

    test_vectors = [
      ("wb_clk_i wb_rst_i wbs_stb_i wbs_cyc_i wbs_we_i wbs_sel_i wbs_dat_i wbs_adr_i wbs_ack_o wbs_dat_o send_msg send_val send_rdy recv_msg recv_val recv_rdy"),
      [ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ], # Reset
      [ 1, 0, 1, 1, 1, 0b1111, write_val, write_addr, 0, 0, 0, 0, 0, 0, 0, 0 ], # Write request
      [ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, (write_addr << DATA_WIDTH) | write_val, 1, 1, 0, 0, 0 ], # Write acknowledge
      [ 1, 0, 1, 1, 0, 0b1111, 0, read_addr, 0, 0, 0, 0, 0, 0, 0, 0 ], # Read request
      [ 1, 0, 0, 0, 0, 0, 0, 0, 1, write_val, (read_addr << DATA_WIDTH), 1, 1, 0, 0, 0 ], # Read acknowledge
      [ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, recv_val, 1, 1 ], # Receive data
    ]

    run_test_vector_sim(model, test_vectors)


Following files shows the different for “loop unroll”:
loop_unroll_dump_noinline.txt -> compiler did loop unroll (no loops), although with told him not to do it.

  for(i=0;i<2;i++)
  {    
    for(k=0;k<4;k++)
    { 
    }
  }


loop_unroll_dump.txt -> we pass, as arguments, the loop numbers so compiler did not do “unrolling”
  for(i=0;i<outer;i++)
  {    
    for(k=0;k<inner;k++)
    { 
    }
  }

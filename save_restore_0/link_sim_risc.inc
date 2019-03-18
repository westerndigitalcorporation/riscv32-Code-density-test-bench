/*======================================================================*/
/* dcp processor linker script (CPU : riscv32imc)                       */
/*======================================================================*/
/* This is the linker script used when building dcp processor code. */

/*^skipLineStart^*/
/* Refrain yourself from modifying the ^****...^ keywords unless you want to break your head */

/* 
    These lines are left just for SABA to create softmap.h file. Lines from skipLineStart to 
    skipLineEnd will be ripped off in GCC (riscv) linker file. First section of register and 
    memory origins are auto created by SABA from asic_defs and mem_base_auto_defs files.
    You can play with USER ASSIGNED MEMORY to break the memory sections into different regions which
    goes to softmap.h files automatically!!!
    ###############################################################################
    #
    # Common linker command file, processed last
    # (may depend on symbols defined in other files)
    #
    ###############################################################################


    # Globals --------------------------------------------------------------
    

    # ----------------------------------------------------------------------
    # ---------------------------- Memory defintion ------------------------
    # ----------------------------------------------------------------------
*/

  
 MEMORY { NIL : ORIGIN = 0,  LENGTH = 1  }
    MEMORY { FILES : ORIGIN = 0xFE000000,  LENGTH = 64K  }  /*# placed "way out there" to avoid debugger complaint about overlapping sections when debugging ROM and RAM together*/
    MEMORY { TOOLS : ORIGIN = 0xFE200000,  LENGTH = 64K  }


/*
    //ROM_SLOWVARS_START=0x80040000;
    //ROM_SLOWVARS_END=0x80040000;
    //ROM_SLOWVARS_SIZE=0x00000000;
    //ROM_MAX_VARS_SLOW_RGN=0x80040000;
    //ROM_DFLTVARS_START=0xc0c00050;
    //ROM_DFLTVARS_END=0xc0c01180;
    //ROM_DFLTVARS_SIZE=0x00001130;
    //ROM_MAX_VARS_SPR_RGN=0xc0c01180;
    //ROM_DMAVARS_START=0x80042f00;
    //ROM_DMAVARS_END=0x80042fc8;
    //ROM_DMAVARS_SIZE=0x000000c8;
    //ROM_MAX_VARS_DMA_RGN=0x80042fc8;
    //_SDA_BASE_=0xc0c010bc;
    // <EoF>
    //
    // Created automatically; DO NOT EDIT MANUALLY!
    // Created automatically; DO NOT EDIT MANUALLY!
    // Created automatically; DO NOT EDIT MANUALLY!
    //    
*/
    
/*----------------------------------------------------------------------*/
/* Setup                                                                */
/*----------------------------------------------------------------------*/

/* The OUTPUT_ARCH command specifies the machine architecture where the
   argument is one of the names used in the BFD library. More
   specifically one of the entires in bfd/cpu-mips.c */

OUTPUT_ARCH( "riscv" )
ENTRY(_start)

/* attributes
	- ‘r’ : Read-only section
	- ‘w’ : Read/write section
	- ‘x’ : Executable section
	- ‘a’ : Allocatable section
	- ‘i’ : Initialized section
	- ‘l’ : Same as ‘I’
	- ‘!’ : Invert the sense of any of the attributes that follow
 */

/*^SharedGlobals^*/


MEMORY
{
	ROM (rxai!w) : ORIGIN = 0x80008000 LENGTH = 84K
	DCCM (wxa!ri) : ORIGIN = 0xE0000000 LENGTH = 40K
    NOT_MAPPED(r) : ORIGIN = 0xE0018000 LENGTH = 32K
}

/*----------------------------------------------------------------------*/
/* Sections                                                             */
/*----------------------------------------------------------------------*/

SECTIONS
{
  .text.init	:
  {
	*(.text.init)
  } > ROM
  
  .text :
  {
    *(.text.unlikely .text.unlikely.*)
    *(.text.startup .text.startup.*)
    *(.text .text.*)
    *(.gnu.linkonce.t.*)
  } > ROM
  
  .rodata	:
  {
    *(.rdata)
    *(.rodata .rodata.*)
    *(.gnu.linkonce.r.*)
  } > ROM
  
  rv_vector_table : ALIGN(1K)
  {
     KEEP(*(rv_vector_table))
  } > DCCM
  
  .data	:
  {
	*(.data .data.*)
    *(.gnu.linkonce.d.*)
  } > DCCM

  .sdata	:
  {
	. = ALIGN(8);
    __global_pointer$ = . + 0x800;
    *(.sdata .sdata.*)
    *(.gnu.linkonce.s.*)
    . = ALIGN(8);
    *(.srodata.cst16)
    *(.srodata.cst8)
    *(.srodata.cst4)
    *(.srodata.cst2)
    *(.srodata .srodata.*)
  } > DCCM
  
  .sbss : {
    *(.sbss .sbss.* .gnu.linkonce.sb.*)
    *(.scommon)
  } > DCCM
  .bss : 
  { 
	*(.bss)
  } > DCCM
  
  .tdata :
  {
    _tls_data = .;
    *(.tdata.begin)
    *(.tdata)
    *(.tdata.end)
  } > DCCM
  .tbss :
  {
    *(.tbss)
    *(.tbss.end)
  } > DCCM
  . = ALIGN(8);
  _end = .;.mysection :
  {
	  G_ROM_dieMappingTable = 0x80057954;
	  G_ROM_plcb = 0xd0000800;
	  G_ROM_plItfInfo = 0x80057994;
	  G_ROM_clks = 0xd0000840;
	  G_ROM_fgi = 0x80057904;
	  G_PeriodTime = 0xd0000c50;
	  G_sLdpcParameters_EX2_BC_skip = 0x7fff4cb4;
	  G_sLdpcParameters_EX2_all_column = 0x7fff3a78;
	  G_sLdpcParameters_EX3_BC_skip = 0x7fff283c;
	  G_sLdpcParameters_EX3_all_column = 0x7fff03c4;
      
      f_waitFor = 0x7ffe0200;
	  _start_rom = 0x7ffe0de8;

  }
  
  __stack_size = DEFINED(__stack_size) ? __stack_size : 4K;
  .stack :
  {
	_heap_end = .;
	. = . + __stack_size;
	_sp = .;
  } > DCCM
  
  /* sections for botCreation only not required to keep in the RAM section, so it is mapped to 
    dummp address */
    
  Tool_Constants (COPY) : ALIGN(4)
  {
    KEEP(*(Tool_Constants))
  } > NOT_MAPPED
  
  Tool_Constants_MapData (COPY) : ALIGN(4)
  {
    KEEP(*(Tool_Constants_MapData))
  } > NOT_MAPPED

  file81 (COPY) : ALIGN(4)
  {
    KEEP(*(file81))
  } > NOT_MAPPED
  

  .mysection :
  {
	  G_ROM_dieMappingTable = 0x80057954;
	  G_ROM_plcb = 0xd0000800;
	  G_ROM_plItfInfo = 0x80057994;
	  G_ROM_clks = 0xd0000840;
	  G_ROM_fgi = 0x80057904;
	  G_PeriodTime = 0xd0000c50;
	  G_sLdpcParameters_EX2_BC_skip = 0x7fff4cb4;
	  G_sLdpcParameters_EX2_all_column = 0x7fff3a78;
	  G_sLdpcParameters_EX3_BC_skip = 0x7fff283c;
	  G_sLdpcParameters_EX3_all_column = 0x7fff03c4;
      
      f_waitFor = 0x7ffe0200;
	  _start_rom = 0x7ffe0de8;
	
	G_dpFlb_fwSeqStart                                                      =   0xe0018000;
    G_dpFlb_seqChainer                                                      =   0xe0018004;
    G_dpFlb_routUpdateTimeoutToMax                                          =   0xe0018080;
    G_dpFlb_routQuitProgHandling                                            =   0xe001808c;
    G_dpFlb_routReadXfer                                                    =   0xe00180d8;
    G_dpFlb_routEnterUserE2Mode                                             =   0xe0018158;
    G_dpFlb_routFastCommitCommand                                           =   0xe0018164;
    G_dpFlb_routEnterTestMode                                               =   0xe00181c8;
    G_dpFlb_routCommitCommand                                               =   0xe00181d8;
    G_dpFlb_routSetParam                                                    =   0xe0018234;
    G_dpFlb_routSetParamAddress                                             =   0xe001825c;
    G_dpFlb_routSetFeature                                                  =   0xe0018288;
    G_dpFlb_routLockParameter                                               =   0xe001830c;
    G_dpFlb_routSetParamBroadcast                                           =   0xe0018320;
    G_dpFlb_routCheckDieStatus                                              =   0xe0018348;
    G_dpFlb_routDieStateStatusOpCmd70                                       =   0xe0018348;
    G_dpFlb_routDieStateStatusOpCmd71                                       =   0xe0018380;
    G_dpFlb_routDieStateStatusOpCmd72                                       =   0xe00183b8;
    G_dpFlb_routDieStateStatusOpCmd73                                       =   0xe00183f0;
    G_dpFlb_routDieStateStatusOpCmd74                                       =   0xe0018428;
    G_dpFlb_routDieStateStatusOpCmd75                                       =   0xe0018460;
    G_dpFlb_routDieStateStatusOpCmd77                                       =   0xe001846c;
    G_dpFlb_routDieStateStatusOpCmd7A                                       =   0xe0018478;
    G_dpFlb_routDieStateStatusOpCmd7B                                       =   0xe0018494;
    G_dpFlb_routDieStateStatusOpCmd7C                                       =   0xe00184b0;
    G_dpFlb_seqErase                                                        =   0xe001850c;
    G_dpFlb_seqProgram                                                      =   0xe0018578;
    G_dpFlb_seqCommit                                                       =   0xe00186fc;
    G_dpFlb_seqValidateDieState                                             =   0xe0018780;
    G_dpFlb_seqReadSenseSlcMult                                             =   0xe00188d8;
    G_dpFlb_seqReadSenseTlcMult                                             =   0xe0018970;
    G_dpFlb_seqReadTransfer                                                 =   0xe0018a18;
    G_dpFlb_seqReadSenseSingle                                              =   0xe0018ae4;
    G_dpFlb_seqPureTransfer                                                 =   0xe0018b74;
    G_dpFlb_seqPollCacheRdy                                                 =   0xe0018c20;
    G_dpFlb_seqUpdateFeatures                                               =   0xe0018c4c;
    G_dpFlb_seqGetFeature                                                   =   0xe0018d58;
    G_dpFlb_seqGetParameter                                                 =   0xe0018dd8;
    G_dpFlb_seqReadTransferExt                                              =   0xe0018e60;
    G_dpFlb_seqUpdateParameter                                              =   0xe0018f74;
    G_dpFlb_seqEnterUser2eMode                                              =   0xe0018f90;
    G_dpFlb_seqEnableUserRomAccess                                          =   0xe0018f9c;
    G_dpFlb_seqReportStatus                                                 =   0xe0018fb8;
    G_dpFlb_seqGetTemperatureCode                                           =   0xe0019050;
    G_dpFlb_seqSetParamBroadcast                                            =   0xe00190e0;
    G_dpFlb_seqResetFeaturesBroadcast                                       =   0xe00190f4;
    G_dpFlb_seqFailStatus                                                   =   0xe0019138;
    G_dpFlb_seqEnterTestMode                                                =   0xe001915c;
    G_dpFlb_seqCheckQuitProg                                                =   0xe0019168;
    G_dpFlb_seqEmpty                                                        =   0xe00191bc;
    G_dpFlb_fwSeqEnd                                                        =   0xe00191dc;
    
    
    __LBL__FSC_ERROR_HANDLING_END_                                          =   0xe001806c;
    __LBL__FSC_BAC_XFER_COMPLETED_END_                                      =   0xe0018038;
    __LBL__FSC_ENTRANCE_POINT_END_                                          =   0xe0018048;
    __LBL__FUM_PATCH_TO_END_                                                =   0xe0018084;
    __LBL__FPQ_QUIT_PROG_COMPLETED_END_                                     =   0xe00180d4;
    __LBL__FPQ_QUIT_PROG_DETECTED_END_                                      =   0xe00180a4;
    __LBL__FRX_FDMA_RUNNING_END_                                            =   0xe00180f4;
    __LBL__FRX_PATCH_TM_FDMA_SETUP_READ_END_                                =   0xe00180ec;
    __LBL__FRX_POLL_CR_END_                                                 =   0xe001811c;
    __LBL__FRX_PATCH_TM_INIT_END_                                           =   0xe001812c;
    __LBL__FRX_AUTORELEASE_POLLED_END_                                      =   0xe0018140;
    __LBL__FFC_PATCH_TWB_IN_FAST_COMMIT_END_                                =   0xe0018170;
    __LBL__FFC_BUSY_MISSED_END_                                             =   0xe001818c;
    __LBL__FFC_BUSY_DETECTED_END_                                           =   0xe0018198;
    __LBL__FFC_ERROR_HANDLING_END_                                          =   0xe00181b0;
    __LBL__FFC_COMPLETED_END_                                               =   0xe00181c0;
    __LBL__FCC_BUSY_DETECTED_END_                                           =   0xe0018204;
    __LBL__FCC_BUSY_MISSED_END_                                             =   0xe00181f8;
    __LBL__FCC_ERROR_HANDLING_END_                                          =   0xe001821c;
    __LBL__FCC_COMPLETED_END_                                               =   0xe001822c;
    __LBL__FSP_PATCH_TWHWP_BEFORE_DATA_IN_SET_PARAM_END_                    =   0xe0018244;
    __LBL__FSP_PATCH_TWHWP_AFTER_DATA_IN_SET_PARAM_END_                     =   0xe0018254;
    __LBL__FSA_PATCH_TWHRX_IN_TM_BEFORE_5F_IN_SET_PARAM_ADDR_END_           =   0xe001826c;
    __LBL__FSA_PATCH_TWHRX_IN_TM_AFTER_5F_IN_SET_PARAM_ADDR_END_            =   0xe001827c;
    __LBL__FSA_PATCH_TWHWP_IN_SET_PARAM_ADDR_END_                           =   0xe0018284;
    __LBL__FSF_PATCH_TM_INIT_END_                                           =   0xe0018294;
    __LBL__FSF_PATCH_TM_POLLING_END_                                        =   0xe001829c;
    __LBL__FSF_PATCH_TADL_BEFORE_DATA_END_                                  =   0xe00182a0;
    __LBL__FSF_PATCH_TM_SCENARIO_SWITCH_END_                                =   0xe00182a4;
    __LBL__FSF_TOGGLE_MODE_SCENARIO_END_                                    =   0xe00182c0;
    __LBL__FSF_LEGACY_SCENARIO_END_                                         =   0xe00182ac;
    __LBL__FSF_EXIT_END_                                                    =   0xe0018308;
    __LBL__FSF_FDMA_SETTLED_END_                                            =   0xe00182e4;
    __LBL__FSF_PATCH_TM_FDMA_SETUP_WRITE_END_                               =   0xe00182dc;
    __LBL__FSB_PATCH_TWHWP_BEFORE_DATA_IN_SET_PARAM_BROAD_END_              =   0xe0018330;
    __LBL__FSB_PATCH_TWHWP_AFTER_DATA_IN_SET_PARAM_BROAD_END_               =   0xe0018340;
    __LBL__F7X_70_CACHE_POLLLING_STAGE_END_                                 =   0xe0018360;
    __LBL__F7X_STATUS_POLLED_END_                                           =   0xe00184c0;
    __LBL__F7X_F70_READ_STAGE_END_                                          =   0xe0018370;
    __LBL__F7X_STATUS_VIOLATION_ERROR_HANDLING_END_                         =   0xe00184f4;
    __LBL__F7X_71_CACHE_POLLLING_STAGE_END_                                 =   0xe0018398;
    __LBL__F7X_F71_READ_STAGE_END_                                          =   0xe00183a8;
    __LBL__F7X_72_CACHE_POLLLING_STAGE_END_                                 =   0xe00183d0;
    __LBL__F7X_F72_READ_STAGE_END_                                          =   0xe00183e0;
    __LBL__F7X_73_CACHE_POLLLING_STAGE_END_                                 =   0xe0018408;
    __LBL__F7X_F73_READ_STAGE_END_                                          =   0xe0018418;
    __LBL__F7X_74_CACHE_POLLLING_STAGE_END_                                 =   0xe0018440;
    __LBL__F7X_F74_READ_STAGE_END_                                          =   0xe0018450;
    __LBL__F7X_COMPLETED_END_                                               =   0xe0018508;
    __LBL__F7X_REGULAR_ERROR_HANDLING_END_                                  =   0xe0018504;
    __LBL__FER_EXIT_END_                                                    =   0xe0018570;
    __LBL__FER_PLANE_LOOP_END_                                              =   0xe001854c;
    __LBL__FPG_FDMA_SETTLED_END_                                            =   0xe00185b4;
    __LBL__FPG_PATCH_TM_FDMA_SETUP_WRITE_END_                               =   0xe00185ac;
    __LBL__FPG_PLANE_LOOP_END_                                              =   0xe00185c4;
    __LBL__FPG_EXIT_END_                                                    =   0xe00186f4;
    __LBL__FPG_QPROG_HANDLED_END_                                           =   0xe0018608;
    __LBL__FPG_QUIT_PROGRAM_DETECTION_NON_FORCED_END_                       =   0xe0018600;
    __LBL__FPG_PATCH_TM_INIT_END_                                           =   0xe001863c;
    __LBL__FPG_PATCH_TM_POLLING_END_                                        =   0xe0018644;
    __LBL__FPG_PATCH_TWHW_TADL_AFTER_LAST_ADDR_END_                         =   0xe0018648;
    __LBL__FPG_XFER_COMPLETED_END_                                          =   0xe001867c;
    __LBL__FPG_CHUNK_LOOP_END_                                              =   0xe0018654;
    __LBL__FPG_COMMIT_COMMAND_HANDLED_END                                   =   0xe00186ec;
    __LBL__FPG_START_MSG_HANDLED_END_                                       =   0xe00186b0;
    __LBL__FPG_COMMIT_TESTED_END_                                           =   0xe00186e4;
    __LBL__FCO_WAIT_RDY_BEFORE_COMPLETED_END_                               =   0xe0018748;
    __LBL__FCO_COMPLETED_END_                                               =   0xe0018778;
    __LBL__FCD_READY_LINE_POLLED_END_                                       =   0xe00187d0;
    __LBL__FCD_ERROR_DETECTION_END_                                         =   0xe00188c8;
    __LBL__FCD_DIE_STATUS_PROCESSED_END_                                    =   0xe0018844;
    __LBL__FCD_VDET_PROCESSED_END_                                          =   0xe0018874;
    __LBL__FCD_DIE_RESET_PROCESSED_END_                                     =   0xe00188c4;
    __LBL_FCD_WRITE_PROTECT_DISABLED_END_                                   =   0xe00188c4;
    __LBL__FSS_ERROR_DETECTED_END_                                          =   0xe0018960;
    __LBL__FSS_DIE_SELECT_POLL_TRUE_READY__END_                             =   0xe0018924;
    __LBL__FST_ERROR_DETECTED_END_                                          =   0xe0018a08;
    __LBL__FST_DIE_SELECT_POLL_TRUE_READY__END_                             =   0xe00189bc;
    __LBL__FRT_FDMA_SETTLED_END_                                            =   0xe0018a44;
    __LBL__FRT_CACHE_HANDLED_END_                                           =   0xe0018a94;
    __LBL__FRT_ERROR_HANDLING_END_                                          =   0xe0018ad0;
    __LBL__FRT_MAIN_LOOP_END_                                               =   0xe0018a9c;
    __LBL__FSG_ERROR_HANDLING_END_                                          =   0xe0018b64;
    __LBL__FSG_DIE_SELECT_POLL_TRUE_READY__END_                             =   0xe0018b30;
    __LBL__FXT_PATCH_TM_FDMA_SETUP_READ_END_                                =   0xe0018bd4;
    __LBL__FXT_ERROR_HANDLING_END_                                          =   0xe0018c0c;
    __LBL__FXT_BAC_XFER_COMPLETED_END_                                      =   0xe0018c0c;
    __LBL__FUF_ERROR_HANDLING_END_                                          =   0xe0018d3c;
    __LBL__FUF_READY_STATUS_POLLED_END_                                     =   0xe0018c98;
    __LBL__FUF_SEND_PARAMS_STAGE_END_                                       =   0xe0018ca4;
    __LBL__FUF_SEND_PARAMS_STAGE_COMPLETED_END_                             =   0xe0018cc0;
    __LBL__FUF_SET_PARAM_LOOP_END_                                          =   0xe0018cac;
    __LBL__FUF_SEND_FEATURES_STAGE_END_                                     =   0xe0018cc0;
    __LBL__FUF_SEND_FEATURES_STAGE_COMPLETED_END_                           =   0xe0018d24;
    __LBL__FUF_SET_FEATURE_LOOP_END_                                        =   0xe0018cc8;
    __LBL__FUF_VDET_SCENARIO_SUPPORT_END_                                   =   0xe0018d08;
    __LBL__FUF_FEATURE_PROCEEEDED_END_                                      =   0xe0018d0c;
    __LBL__FUF_PATCH_TFEAT_AFTER_SET_FEATURE_END_                           =   0xe0018d08;
    __LBL__FUF_SEND_PREFIX_STAGE_END_                                       =   0xe0018d24;
    __LBL__FUF_SEND_PREFIX_STAGE_COMPLETED_END_                             =   0xe0018d3c;
    __LBL__FUF_SEND_PREFIX_LOOP_END_                                        =   0xe0018d2c;
    __LBL__FUF_NORMAL_COMPLETION__END_                                      =   0xe0018d50;
    __LBL__FGF_PATCH_TM_FDMA_SETUP_READ_END_                                =   0xe0018d70;
    __LBL__FGF_PATCH_TM_INIT_END_                                           =   0xe0018d84;
    __LBL__FGF_ERROR_HANDLING_END_                                          =   0xe0018dd0;
    __LBL__FGF_PATCH_TRR_AFTER_LAST_ADDR_END_                               =   0xe0018da4;
    __LBL__FGF_PATCH_TM_SCENARIO_SWITCH_END_                                =   0xe0018dac;
    __LBL__FGP_EXIT_END_                                                    =   0xe0018e58;
    __LBL__FGP_PATCH_TM_FDMA_SETUP_READ_END_                                =   0xe0018e2c;
    __LBL__FTE_FDMA_SETTLED_END_                                            =   0xe0018e8c;
    __LBL__FTE_CACHE_HANDLED_END_                                           =   0xe0018ee8;
    __LBL__FTE_ERROR_HANDLING_END_                                          =   0xe0018f60;
    __LBL__FTE_MAIN_LOOP_END_                                               =   0xe0018ef0;
    __LBL__FTE_BAC_XFER_COMPLETED_END_                                      =   0xe0018f48;
    __LBL__FRS_CACHE_RDY_POLLED_END_                                        =   0xe0019018;
    __LBL__FRS_REPORT_STATUS_END_                                           =   0xe0019038;
    __LBL__FTC_EXIT_END_                                                    =   0xe00190d8;
    __LBL__FTC_PATCH_TWAR_AFTER_BURST_STARTED__END_                         =   0xe00190ac;
    __LBL__FRB_SEND_CMD_89__END_                                            =   0xe0019100;
    __LBL__FRB_PATCH_TWB_AFTER_CMD_89__END_                                 =   0xe0019110;
    __LBL__FRB_EXIT_END_                                                    =   0xe0019130;
    __LBL__FCQ_COMPLETED_END_                                               =   0xe00191b4;
        
    
  }
  
}

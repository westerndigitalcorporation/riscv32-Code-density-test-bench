
out:     file format elf32-littleriscv


Disassembly of section .text:

00010074 <_start>:
   10074:	00002197          	auipc	gp,0x2
   10078:	06c18193          	addi	gp,gp,108 # 120e0 <__global_pointer$>
   1007c:	80c18513          	addi	a0,gp,-2036 # 118ec <_edata>
   10080:	82818613          	addi	a2,gp,-2008 # 11908 <_end>
   10084:	8e09                	sub	a2,a2,a0
   10086:	4581                	li	a1,0
   10088:	2c35                	jal	102c4 <memset>
   1008a:	00000517          	auipc	a0,0x0
   1008e:	19450513          	addi	a0,a0,404 # 1021e <__libc_fini_array>
   10092:	229d                	jal	101f8 <atexit>
   10094:	2ac1                	jal	10264 <__libc_init_array>
   10096:	4502                	lw	a0,0(sp)
   10098:	004c                	addi	a1,sp,4
   1009a:	4601                	li	a2,0
   1009c:	2a3d                	jal	101da <main>
   1009e:	a295                	j	10202 <exit>

000100a0 <_fini>:
   100a0:	8082                	ret

000100a2 <deregister_tm_clones>:
   100a2:	6549                	lui	a0,0x12
   100a4:	67c9                	lui	a5,0x12
   100a6:	8e050713          	addi	a4,a0,-1824 # 118e0 <__TMC_END__>
   100aa:	8e078793          	addi	a5,a5,-1824 # 118e0 <__TMC_END__>
   100ae:	00e78b63          	beq	a5,a4,100c4 <deregister_tm_clones+0x22>
   100b2:	00000337          	lui	t1,0x0
   100b6:	00030313          	mv	t1,t1
   100ba:	00030563          	beqz	t1,100c4 <deregister_tm_clones+0x22>
   100be:	8e050513          	addi	a0,a0,-1824
   100c2:	8302                	jr	t1
   100c4:	8082                	ret

000100c6 <register_tm_clones>:
   100c6:	67c9                	lui	a5,0x12
   100c8:	6549                	lui	a0,0x12
   100ca:	8e078593          	addi	a1,a5,-1824 # 118e0 <__TMC_END__>
   100ce:	8e050793          	addi	a5,a0,-1824 # 118e0 <__TMC_END__>
   100d2:	8d9d                	sub	a1,a1,a5
   100d4:	8589                	srai	a1,a1,0x2
   100d6:	4789                	li	a5,2
   100d8:	02f5c5b3          	div	a1,a1,a5
   100dc:	c991                	beqz	a1,100f0 <register_tm_clones+0x2a>
   100de:	00000337          	lui	t1,0x0
   100e2:	00030313          	mv	t1,t1
   100e6:	00030563          	beqz	t1,100f0 <register_tm_clones+0x2a>
   100ea:	8e050513          	addi	a0,a0,-1824
   100ee:	8302                	jr	t1
   100f0:	8082                	ret

000100f2 <__do_global_dtors_aux>:
   100f2:	80c1c703          	lbu	a4,-2036(gp) # 118ec <_edata>
   100f6:	eb0d                	bnez	a4,10128 <__do_global_dtors_aux+0x36>
   100f8:	1141                	addi	sp,sp,-16
   100fa:	c422                	sw	s0,8(sp)
   100fc:	c606                	sw	ra,12(sp)
   100fe:	843e                	mv	s0,a5
   10100:	374d                	jal	100a2 <deregister_tm_clones>
   10102:	000007b7          	lui	a5,0x0
   10106:	00078793          	mv	a5,a5
   1010a:	cb81                	beqz	a5,1011a <__do_global_dtors_aux+0x28>
   1010c:	6541                	lui	a0,0x10
   1010e:	4ac50513          	addi	a0,a0,1196 # 104ac <__EH_FRAME_BEGIN__>
   10112:	ffff0097          	auipc	ra,0xffff0
   10116:	eee080e7          	jalr	-274(ra) # 0 <_start-0x10074>
   1011a:	4785                	li	a5,1
   1011c:	80f18623          	sb	a5,-2036(gp) # 118ec <_edata>
   10120:	40b2                	lw	ra,12(sp)
   10122:	4422                	lw	s0,8(sp)
   10124:	0141                	addi	sp,sp,16
   10126:	8082                	ret
   10128:	8082                	ret

0001012a <frame_dummy>:
   1012a:	000007b7          	lui	a5,0x0
   1012e:	00078793          	mv	a5,a5
   10132:	cf99                	beqz	a5,10150 <frame_dummy+0x26>
   10134:	65c9                	lui	a1,0x12
   10136:	6541                	lui	a0,0x10
   10138:	1141                	addi	sp,sp,-16
   1013a:	8f058593          	addi	a1,a1,-1808 # 118f0 <object.5183>
   1013e:	4ac50513          	addi	a0,a0,1196 # 104ac <__EH_FRAME_BEGIN__>
   10142:	c606                	sw	ra,12(sp)
   10144:	ffff0097          	auipc	ra,0xffff0
   10148:	ebc080e7          	jalr	-324(ra) # 0 <_start-0x10074>
   1014c:	40b2                	lw	ra,12(sp)
   1014e:	0141                	addi	sp,sp,16
   10150:	bf9d                	j	100c6 <register_tm_clones>

00010152 <test>:
   10152:	1141                	addi	sp,sp,-16
   10154:	c622                	sw	s0,12(sp)
   10156:	0800                	addi	s0,sp,16
   10158:	f00807b7          	lui	a5,0xf0080
   1015c:	0f878713          	addi	a4,a5,248 # f00800f8 <__global_pointer$+0xf006e018>
   10160:	f00197b7          	lui	a5,0xf0019
   10164:	f1478793          	addi	a5,a5,-236 # f0018f14 <__global_pointer$+0xf0006e34>
   10168:	4318                	lw	a4,0(a4)
   1016a:	c398                	sw	a4,0(a5)
   1016c:	f00807b7          	lui	a5,0xf0080
   10170:	0fc78713          	addi	a4,a5,252 # f00800fc <__global_pointer$+0xf006e01c>
   10174:	f00197b7          	lui	a5,0xf0019
   10178:	f1478793          	addi	a5,a5,-236 # f0018f14 <__global_pointer$+0xf0006e34>
   1017c:	4318                	lw	a4,0(a4)
   1017e:	c398                	sw	a4,0(a5)
   10180:	f00807b7          	lui	a5,0xf0080
   10184:	10078713          	addi	a4,a5,256 # f0080100 <__global_pointer$+0xf006e020>
   10188:	f00197b7          	lui	a5,0xf0019
   1018c:	f1478793          	addi	a5,a5,-236 # f0018f14 <__global_pointer$+0xf0006e34>
   10190:	4318                	lw	a4,0(a4)
   10192:	c398                	sw	a4,0(a5)
   10194:	f00807b7          	lui	a5,0xf0080
   10198:	10478713          	addi	a4,a5,260 # f0080104 <__global_pointer$+0xf006e024>
   1019c:	f00197b7          	lui	a5,0xf0019
   101a0:	f1478793          	addi	a5,a5,-236 # f0018f14 <__global_pointer$+0xf0006e34>
   101a4:	4318                	lw	a4,0(a4)
   101a6:	c398                	sw	a4,0(a5)
   101a8:	f00807b7          	lui	a5,0xf0080
   101ac:	10878713          	addi	a4,a5,264 # f0080108 <__global_pointer$+0xf006e028>
   101b0:	f00197b7          	lui	a5,0xf0019
   101b4:	f1478793          	addi	a5,a5,-236 # f0018f14 <__global_pointer$+0xf0006e34>
   101b8:	4318                	lw	a4,0(a4)
   101ba:	c398                	sw	a4,0(a5)
   101bc:	f00807b7          	lui	a5,0xf0080
   101c0:	10c78713          	addi	a4,a5,268 # f008010c <__global_pointer$+0xf006e02c>
   101c4:	f00197b7          	lui	a5,0xf0019
   101c8:	f1478793          	addi	a5,a5,-236 # f0018f14 <__global_pointer$+0xf0006e34>
   101cc:	4318                	lw	a4,0(a4)
   101ce:	c398                	sw	a4,0(a5)
   101d0:	4781                	li	a5,0
   101d2:	853e                	mv	a0,a5
   101d4:	4432                	lw	s0,12(sp)
   101d6:	0141                	addi	sp,sp,16
   101d8:	8082                	ret

000101da <main>:
   101da:	1101                	addi	sp,sp,-32
   101dc:	ce06                	sw	ra,28(sp)
   101de:	cc22                	sw	s0,24(sp)
   101e0:	1000                	addi	s0,sp,32
   101e2:	fea42623          	sw	a0,-20(s0)
   101e6:	feb42423          	sw	a1,-24(s0)
   101ea:	37a5                	jal	10152 <test>
   101ec:	4781                	li	a5,0
   101ee:	853e                	mv	a0,a5
   101f0:	40f2                	lw	ra,28(sp)
   101f2:	4462                	lw	s0,24(sp)
   101f4:	6105                	addi	sp,sp,32
   101f6:	8082                	ret

000101f8 <atexit>:
   101f8:	85aa                	mv	a1,a0
   101fa:	4681                	li	a3,0
   101fc:	4601                	li	a2,0
   101fe:	4501                	li	a0,0
   10200:	a2b5                	j	1036c <__register_exitproc>

00010202 <exit>:
   10202:	1141                	addi	sp,sp,-16
   10204:	4581                	li	a1,0
   10206:	c422                	sw	s0,8(sp)
   10208:	c606                	sw	ra,12(sp)
   1020a:	842a                	mv	s0,a0
   1020c:	22c9                	jal	103ce <__call_exitprocs>
   1020e:	67c9                	lui	a5,0x12
   10210:	8e47a503          	lw	a0,-1820(a5) # 118e4 <_global_impure_ptr>
   10214:	5d5c                	lw	a5,60(a0)
   10216:	c391                	beqz	a5,1021a <exit+0x18>
   10218:	9782                	jalr	a5
   1021a:	8522                	mv	a0,s0
   1021c:	2cb9                	jal	1047a <_exit>

0001021e <__libc_fini_array>:
   1021e:	1101                	addi	sp,sp,-32
   10220:	67c5                	lui	a5,0x11
   10222:	6745                	lui	a4,0x11
   10224:	cc22                	sw	s0,24(sp)
   10226:	4b470713          	addi	a4,a4,1204 # 114b4 <__init_array_end>
   1022a:	4b878413          	addi	s0,a5,1208 # 114b8 <__fini_array_end>
   1022e:	8c19                	sub	s0,s0,a4
   10230:	ca26                	sw	s1,20(sp)
   10232:	c84a                	sw	s2,16(sp)
   10234:	c64e                	sw	s3,12(sp)
   10236:	ce06                	sw	ra,28(sp)
   10238:	8409                	srai	s0,s0,0x2
   1023a:	4481                	li	s1,0
   1023c:	4b878913          	addi	s2,a5,1208
   10240:	59f1                	li	s3,-4
   10242:	00941963          	bne	s0,s1,10254 <__libc_fini_array+0x36>
   10246:	4462                	lw	s0,24(sp)
   10248:	40f2                	lw	ra,28(sp)
   1024a:	44d2                	lw	s1,20(sp)
   1024c:	4942                	lw	s2,16(sp)
   1024e:	49b2                	lw	s3,12(sp)
   10250:	6105                	addi	sp,sp,32
   10252:	b5b9                	j	100a0 <_fini>
   10254:	033487b3          	mul	a5,s1,s3
   10258:	0485                	addi	s1,s1,1
   1025a:	97ca                	add	a5,a5,s2
   1025c:	ffc7a783          	lw	a5,-4(a5)
   10260:	9782                	jalr	a5
   10262:	b7c5                	j	10242 <__libc_fini_array+0x24>

00010264 <__libc_init_array>:
   10264:	1141                	addi	sp,sp,-16
   10266:	c422                	sw	s0,8(sp)
   10268:	c226                	sw	s1,4(sp)
   1026a:	6445                	lui	s0,0x11
   1026c:	64c5                	lui	s1,0x11
   1026e:	4b048793          	addi	a5,s1,1200 # 114b0 <__frame_dummy_init_array_entry>
   10272:	4b040413          	addi	s0,s0,1200 # 114b0 <__frame_dummy_init_array_entry>
   10276:	8c1d                	sub	s0,s0,a5
   10278:	c04a                	sw	s2,0(sp)
   1027a:	c606                	sw	ra,12(sp)
   1027c:	8409                	srai	s0,s0,0x2
   1027e:	4b048493          	addi	s1,s1,1200
   10282:	4901                	li	s2,0
   10284:	02891663          	bne	s2,s0,102b0 <__libc_init_array+0x4c>
   10288:	64c5                	lui	s1,0x11
   1028a:	3d19                	jal	100a0 <_fini>
   1028c:	6445                	lui	s0,0x11
   1028e:	4b048793          	addi	a5,s1,1200 # 114b0 <__frame_dummy_init_array_entry>
   10292:	4b440413          	addi	s0,s0,1204 # 114b4 <__init_array_end>
   10296:	8c1d                	sub	s0,s0,a5
   10298:	8409                	srai	s0,s0,0x2
   1029a:	4b048493          	addi	s1,s1,1200
   1029e:	4901                	li	s2,0
   102a0:	00891d63          	bne	s2,s0,102ba <__libc_init_array+0x56>
   102a4:	40b2                	lw	ra,12(sp)
   102a6:	4422                	lw	s0,8(sp)
   102a8:	4492                	lw	s1,4(sp)
   102aa:	4902                	lw	s2,0(sp)
   102ac:	0141                	addi	sp,sp,16
   102ae:	8082                	ret
   102b0:	409c                	lw	a5,0(s1)
   102b2:	0905                	addi	s2,s2,1
   102b4:	0491                	addi	s1,s1,4
   102b6:	9782                	jalr	a5
   102b8:	b7f1                	j	10284 <__libc_init_array+0x20>
   102ba:	409c                	lw	a5,0(s1)
   102bc:	0905                	addi	s2,s2,1
   102be:	0491                	addi	s1,s1,4
   102c0:	9782                	jalr	a5
   102c2:	bff9                	j	102a0 <__libc_init_array+0x3c>

000102c4 <memset>:
   102c4:	433d                	li	t1,15
   102c6:	872a                	mv	a4,a0
   102c8:	02c37363          	bleu	a2,t1,102ee <memset+0x2a>
   102cc:	00f77793          	andi	a5,a4,15
   102d0:	efbd                	bnez	a5,1034e <memset+0x8a>
   102d2:	e5ad                	bnez	a1,1033c <memset+0x78>
   102d4:	ff067693          	andi	a3,a2,-16
   102d8:	8a3d                	andi	a2,a2,15
   102da:	96ba                	add	a3,a3,a4
   102dc:	c30c                	sw	a1,0(a4)
   102de:	c34c                	sw	a1,4(a4)
   102e0:	c70c                	sw	a1,8(a4)
   102e2:	c74c                	sw	a1,12(a4)
   102e4:	0741                	addi	a4,a4,16
   102e6:	fed76be3          	bltu	a4,a3,102dc <memset+0x18>
   102ea:	e211                	bnez	a2,102ee <memset+0x2a>
   102ec:	8082                	ret
   102ee:	40c306b3          	sub	a3,t1,a2
   102f2:	068a                	slli	a3,a3,0x2
   102f4:	00000297          	auipc	t0,0x0
   102f8:	9696                	add	a3,a3,t0
   102fa:	00a68067          	jr	10(a3)
   102fe:	00b70723          	sb	a1,14(a4)
   10302:	00b706a3          	sb	a1,13(a4)
   10306:	00b70623          	sb	a1,12(a4)
   1030a:	00b705a3          	sb	a1,11(a4)
   1030e:	00b70523          	sb	a1,10(a4)
   10312:	00b704a3          	sb	a1,9(a4)
   10316:	00b70423          	sb	a1,8(a4)
   1031a:	00b703a3          	sb	a1,7(a4)
   1031e:	00b70323          	sb	a1,6(a4)
   10322:	00b702a3          	sb	a1,5(a4)
   10326:	00b70223          	sb	a1,4(a4)
   1032a:	00b701a3          	sb	a1,3(a4)
   1032e:	00b70123          	sb	a1,2(a4)
   10332:	00b700a3          	sb	a1,1(a4)
   10336:	00b70023          	sb	a1,0(a4)
   1033a:	8082                	ret
   1033c:	0ff5f593          	andi	a1,a1,255
   10340:	00859693          	slli	a3,a1,0x8
   10344:	8dd5                	or	a1,a1,a3
   10346:	01059693          	slli	a3,a1,0x10
   1034a:	8dd5                	or	a1,a1,a3
   1034c:	b761                	j	102d4 <memset+0x10>
   1034e:	00279693          	slli	a3,a5,0x2
   10352:	00000297          	auipc	t0,0x0
   10356:	9696                	add	a3,a3,t0
   10358:	8286                	mv	t0,ra
   1035a:	fa8680e7          	jalr	-88(a3)
   1035e:	8096                	mv	ra,t0
   10360:	17c1                	addi	a5,a5,-16
   10362:	8f1d                	sub	a4,a4,a5
   10364:	963e                	add	a2,a2,a5
   10366:	f8c374e3          	bleu	a2,t1,102ee <memset+0x2a>
   1036a:	b7a5                	j	102d2 <memset+0xe>

0001036c <__register_exitproc>:
   1036c:	67c9                	lui	a5,0x12
   1036e:	8e47a703          	lw	a4,-1820(a5) # 118e4 <_global_impure_ptr>
   10372:	832a                	mv	t1,a0
   10374:	14872783          	lw	a5,328(a4)
   10378:	e789                	bnez	a5,10382 <__register_exitproc+0x16>
   1037a:	14c70793          	addi	a5,a4,332
   1037e:	14f72423          	sw	a5,328(a4)
   10382:	43d8                	lw	a4,4(a5)
   10384:	487d                	li	a6,31
   10386:	557d                	li	a0,-1
   10388:	04e84263          	blt	a6,a4,103cc <__register_exitproc+0x60>
   1038c:	00271893          	slli	a7,a4,0x2
   10390:	02030963          	beqz	t1,103c2 <__register_exitproc+0x56>
   10394:	01178533          	add	a0,a5,a7
   10398:	08c52423          	sw	a2,136(a0)
   1039c:	1887a803          	lw	a6,392(a5)
   103a0:	4605                	li	a2,1
   103a2:	00e61633          	sll	a2,a2,a4
   103a6:	00c86833          	or	a6,a6,a2
   103aa:	1907a423          	sw	a6,392(a5)
   103ae:	10d52423          	sw	a3,264(a0)
   103b2:	4689                	li	a3,2
   103b4:	00d31763          	bne	t1,a3,103c2 <__register_exitproc+0x56>
   103b8:	18c7a683          	lw	a3,396(a5)
   103bc:	8e55                	or	a2,a2,a3
   103be:	18c7a623          	sw	a2,396(a5)
   103c2:	0705                	addi	a4,a4,1
   103c4:	c3d8                	sw	a4,4(a5)
   103c6:	97c6                	add	a5,a5,a7
   103c8:	c78c                	sw	a1,8(a5)
   103ca:	4501                	li	a0,0
   103cc:	8082                	ret

000103ce <__call_exitprocs>:
   103ce:	7179                	addi	sp,sp,-48
   103d0:	67c9                	lui	a5,0x12
   103d2:	ce4e                	sw	s3,28(sp)
   103d4:	8e47a983          	lw	s3,-1820(a5) # 118e4 <_global_impure_ptr>
   103d8:	cc52                	sw	s4,24(sp)
   103da:	ca56                	sw	s5,20(sp)
   103dc:	c85a                	sw	s6,16(sp)
   103de:	d606                	sw	ra,44(sp)
   103e0:	d422                	sw	s0,40(sp)
   103e2:	d226                	sw	s1,36(sp)
   103e4:	d04a                	sw	s2,32(sp)
   103e6:	c65e                	sw	s7,12(sp)
   103e8:	8aaa                	mv	s5,a0
   103ea:	8a2e                	mv	s4,a1
   103ec:	4b05                	li	s6,1
   103ee:	1489a483          	lw	s1,328(s3)
   103f2:	c881                	beqz	s1,10402 <__call_exitprocs+0x34>
   103f4:	40c0                	lw	s0,4(s1)
   103f6:	fff40913          	addi	s2,s0,-1
   103fa:	040a                	slli	s0,s0,0x2
   103fc:	9426                	add	s0,s0,s1
   103fe:	00095d63          	bgez	s2,10418 <__call_exitprocs+0x4a>
   10402:	50b2                	lw	ra,44(sp)
   10404:	5422                	lw	s0,40(sp)
   10406:	5492                	lw	s1,36(sp)
   10408:	5902                	lw	s2,32(sp)
   1040a:	49f2                	lw	s3,28(sp)
   1040c:	4a62                	lw	s4,24(sp)
   1040e:	4ad2                	lw	s5,20(sp)
   10410:	4b42                	lw	s6,16(sp)
   10412:	4bb2                	lw	s7,12(sp)
   10414:	6145                	addi	sp,sp,48
   10416:	8082                	ret
   10418:	000a0963          	beqz	s4,1042a <__call_exitprocs+0x5c>
   1041c:	10442783          	lw	a5,260(s0)
   10420:	01478563          	beq	a5,s4,1042a <__call_exitprocs+0x5c>
   10424:	197d                	addi	s2,s2,-1
   10426:	1471                	addi	s0,s0,-4
   10428:	bfd9                	j	103fe <__call_exitprocs+0x30>
   1042a:	40d8                	lw	a4,4(s1)
   1042c:	405c                	lw	a5,4(s0)
   1042e:	177d                	addi	a4,a4,-1
   10430:	03271663          	bne	a4,s2,1045c <__call_exitprocs+0x8e>
   10434:	0124a223          	sw	s2,4(s1)
   10438:	d7f5                	beqz	a5,10424 <__call_exitprocs+0x56>
   1043a:	1884a683          	lw	a3,392(s1)
   1043e:	012b1733          	sll	a4,s6,s2
   10442:	0044ab83          	lw	s7,4(s1)
   10446:	8ef9                	and	a3,a3,a4
   10448:	ee89                	bnez	a3,10462 <__call_exitprocs+0x94>
   1044a:	9782                	jalr	a5
   1044c:	40d8                	lw	a4,4(s1)
   1044e:	1489a783          	lw	a5,328(s3)
   10452:	f9771ee3          	bne	a4,s7,103ee <__call_exitprocs+0x20>
   10456:	fcf487e3          	beq	s1,a5,10424 <__call_exitprocs+0x56>
   1045a:	bf51                	j	103ee <__call_exitprocs+0x20>
   1045c:	00042223          	sw	zero,4(s0)
   10460:	bfe1                	j	10438 <__call_exitprocs+0x6a>
   10462:	18c4a683          	lw	a3,396(s1)
   10466:	08442583          	lw	a1,132(s0)
   1046a:	8f75                	and	a4,a4,a3
   1046c:	e701                	bnez	a4,10474 <__call_exitprocs+0xa6>
   1046e:	8556                	mv	a0,s5
   10470:	9782                	jalr	a5
   10472:	bfe9                	j	1044c <__call_exitprocs+0x7e>
   10474:	852e                	mv	a0,a1
   10476:	9782                	jalr	a5
   10478:	bfd1                	j	1044c <__call_exitprocs+0x7e>

0001047a <_exit>:
   1047a:	4581                	li	a1,0
   1047c:	4601                	li	a2,0
   1047e:	4681                	li	a3,0
   10480:	4701                	li	a4,0
   10482:	4781                	li	a5,0
   10484:	05d00893          	li	a7,93
   10488:	00000073          	ecall
   1048c:	00055b63          	bgez	a0,104a2 <_exit+0x28>
   10490:	1141                	addi	sp,sp,-16
   10492:	c422                	sw	s0,8(sp)
   10494:	842a                	mv	s0,a0
   10496:	c606                	sw	ra,12(sp)
   10498:	40800433          	neg	s0,s0
   1049c:	2021                	jal	104a4 <__errno>
   1049e:	c100                	sw	s0,0(a0)
   104a0:	a001                	j	104a0 <_exit+0x26>
   104a2:	a001                	j	104a2 <_exit+0x28>

000104a4 <__errno>:
   104a4:	8081a503          	lw	a0,-2040(gp) # 118e8 <_impure_ptr>
   104a8:	8082                	ret

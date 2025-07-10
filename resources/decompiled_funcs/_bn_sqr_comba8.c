unsigned __int64 __cdecl bn_sqr_comba8(int a1, unsigned int *a2)
{
  unsigned __int64 v3; // kr00_8
  unsigned int v4; // edx
  unsigned __int64 v5; // rax
  bool v6; // cf
  BOOL v7; // ebx
  int v8; // ecx
  unsigned int v9; // ebp
  int v10; // ebx
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // kr10_8
  int v13; // ecx
  unsigned __int64 v14; // rax
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // kr20_8
  int v19; // ebp
  unsigned __int64 v20; // rax
  int v21; // ebp
  unsigned int v22; // ecx
  int v23; // ebx
  unsigned int v24; // ebp
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // kr30_8
  int v27; // ebx
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // kr38_8
  int v30; // ebx
  unsigned __int64 v31; // rax
  unsigned int v32; // ebp
  int v33; // ebx
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // kr48_8
  int v36; // ecx
  unsigned __int64 v37; // rax
  unsigned __int64 v38; // kr50_8
  int v39; // ecx
  unsigned __int64 v40; // rax
  int v41; // ecx
  unsigned int v42; // ebx
  int v43; // ebp
  int v44; // ecx
  unsigned __int64 v45; // rax
  unsigned __int64 v46; // kr60_8
  int v47; // ebp
  unsigned __int64 v48; // rax
  unsigned __int64 v49; // kr68_8
  int v50; // ebp
  unsigned __int64 v51; // rax
  unsigned __int64 v52; // kr70_8
  int v53; // ebp
  unsigned __int64 v54; // rax
  unsigned int v55; // ecx
  int v56; // ebp
  unsigned __int64 v57; // rax
  unsigned __int64 v58; // kr80_8
  int v59; // ebx
  unsigned __int64 v60; // rax
  unsigned __int64 v61; // kr88_8
  int v62; // ebx
  unsigned __int64 v63; // rax
  unsigned __int64 v64; // kr90_8
  int v65; // ebx
  unsigned __int64 v66; // rax
  int v67; // ebx
  int v68; // ecx
  unsigned int v69; // ebp
  int v70; // ebx
  unsigned __int64 v71; // rax
  unsigned __int64 v72; // krA0_8
  int v73; // ecx
  unsigned __int64 v74; // rax
  unsigned __int64 v75; // krA8_8
  int v76; // ecx
  unsigned __int64 v77; // rax
  unsigned __int64 v78; // krB0_8
  int v79; // ecx
  unsigned __int64 v80; // rax
  unsigned int v81; // ebx
  int v82; // ecx
  unsigned __int64 v83; // rax
  unsigned __int64 v84; // krC0_8
  int v85; // ebp
  unsigned __int64 v86; // rax
  unsigned __int64 v87; // krC8_8
  int v88; // ebp
  unsigned __int64 v89; // rax
  int v90; // ebp
  unsigned int v91; // ecx
  int v92; // ebx
  int v93; // ebp
  unsigned __int64 v94; // rax
  unsigned __int64 v95; // krD8_8
  int v96; // ebx
  unsigned __int64 v97; // rax
  unsigned __int64 v98; // krE0_8
  int v99; // ebx
  unsigned __int64 v100; // rax
  unsigned int v101; // ebp
  int v102; // ebx
  unsigned __int64 v103; // rax
  unsigned __int64 v104; // krF0_8
  int v105; // ecx
  unsigned __int64 v106; // rax
  int v107; // ecx
  unsigned int v108; // ebx
  int v109; // ebp
  unsigned int v110; // ecx
  unsigned __int64 v111; // rax
  unsigned __int64 v112; // kr100_8
  int v113; // ebp
  unsigned __int64 v114; // rax
  unsigned int v115; // ecx
  int v116; // ebp
  unsigned __int64 v117; // rax
  BOOL v118; // ebx
  unsigned int v119; // ebp
  int v120; // kr110_4
  unsigned __int64 result; // rax

  v3 = *a2 * (unsigned __int64)*a2;
  v4 = *a2;
  *(_DWORD *)a1 = v3;
  v5 = v4 * (unsigned __int64)a2[1];
  v6 = __CFADD__(v5, v5);
  v5 *= 2LL;
  v7 = v6;
  v6 = __CFADD__(v5, HIDWORD(v3));
  v9 = (v5 + HIDWORD(v3)) >> 32;
  v8 = v5 + HIDWORD(v3);
  LODWORD(v5) = a2[2];
  v10 = v6 + v7;
  *(_DWORD *)(a1 + 4) = v8;
  v11 = *a2 * (unsigned __int64)(unsigned int)v5;
  v6 = __CFADD__(v11, v11);
  v11 *= 2LL;
  v12 = v11 + __PAIR64__(v10, v9);
  v13 = __CFADD__(v11, __PAIR64__(v10, v9)) + v6;
  v14 = a2[1] * (unsigned __int64)a2[1];
  v6 = __CFADD__(v14, v12);
  v15 = (v14 + v12) >> 32;
  HIDWORD(v14) = *a2;
  v16 = v6 + v13;
  *(_DWORD *)(a1 + 8) = v14 + v12;
  v17 = HIDWORD(v14) * (unsigned __int64)a2[3];
  v6 = __CFADD__(v17, v17);
  v17 *= 2LL;
  v18 = v17 + __PAIR64__(v16, v15);
  v19 = __CFADD__(v17, __PAIR64__(v16, v15)) + v6;
  v20 = a2[1] * (unsigned __int64)a2[2];
  v6 = __CFADD__(v20, v20);
  v20 *= 2LL;
  v21 = v6 + v19;
  v6 = __CFADD__(v20, v18);
  v22 = (v20 + v18) >> 32;
  v23 = v20 + v18;
  LODWORD(v20) = a2[4];
  v24 = v6 + v21;
  *(_DWORD *)(a1 + 12) = v23;
  v25 = *a2 * (unsigned __int64)(unsigned int)v20;
  v6 = __CFADD__(v25, v25);
  v25 *= 2LL;
  v26 = v25 + __PAIR64__(v24, v22);
  v27 = __CFADD__(v25, __PAIR64__(v24, v22)) + v6;
  v28 = a2[1] * (unsigned __int64)a2[3];
  v6 = __CFADD__(v28, v28);
  v28 *= 2LL;
  v29 = v28 + v26;
  v30 = __CFADD__(v28, v26) + v6 + v27;
  v31 = a2[2] * (unsigned __int64)a2[2];
  v6 = __CFADD__(v31, v29);
  v32 = (v31 + v29) >> 32;
  HIDWORD(v31) = *a2;
  v33 = v6 + v30;
  *(_DWORD *)(a1 + 16) = v31 + v29;
  v34 = HIDWORD(v31) * (unsigned __int64)a2[5];
  v6 = __CFADD__(v34, v34);
  v34 *= 2LL;
  v35 = v34 + __PAIR64__(v33, v32);
  v36 = __CFADD__(v34, __PAIR64__(v33, v32)) + v6;
  v37 = a2[1] * (unsigned __int64)a2[4];
  v6 = __CFADD__(v37, v37);
  v37 *= 2LL;
  v38 = v37 + v35;
  v39 = __CFADD__(v37, v35) + v6 + v36;
  v40 = a2[2] * (unsigned __int64)a2[3];
  v6 = __CFADD__(v40, v40);
  v40 *= 2LL;
  v41 = v6 + v39;
  v6 = __CFADD__(v40, v38);
  v42 = (v40 + v38) >> 32;
  v43 = v40 + v38;
  LODWORD(v40) = a2[6];
  v44 = v6 + v41;
  *(_DWORD *)(a1 + 20) = v43;
  v45 = *a2 * (unsigned __int64)(unsigned int)v40;
  v6 = __CFADD__(v45, v45);
  v45 *= 2LL;
  v46 = v45 + __PAIR64__(v44, v42);
  v47 = __CFADD__(v45, __PAIR64__(v44, v42)) + v6;
  v48 = a2[1] * (unsigned __int64)a2[5];
  v6 = __CFADD__(v48, v48);
  v48 *= 2LL;
  v49 = v48 + v46;
  v50 = __CFADD__(v48, v46) + v6 + v47;
  v51 = a2[2] * (unsigned __int64)a2[4];
  v6 = __CFADD__(v51, v51);
  v51 *= 2LL;
  v52 = v51 + v49;
  v53 = __CFADD__(v51, v49) + v6 + v50;
  v54 = a2[3] * (unsigned __int64)a2[3];
  v6 = __CFADD__(v54, v52);
  v55 = (v54 + v52) >> 32;
  HIDWORD(v54) = *a2;
  v56 = v6 + v53;
  *(_DWORD *)(a1 + 24) = v54 + v52;
  v57 = HIDWORD(v54) * (unsigned __int64)a2[7];
  v6 = __CFADD__(v57, v57);
  v57 *= 2LL;
  v58 = v57 + __PAIR64__(v56, v55);
  v59 = __CFADD__(v57, __PAIR64__(v56, v55)) + v6;
  v60 = a2[1] * (unsigned __int64)a2[6];
  v6 = __CFADD__(v60, v60);
  v60 *= 2LL;
  v61 = v60 + v58;
  v62 = __CFADD__(v60, v58) + v6 + v59;
  v63 = a2[2] * (unsigned __int64)a2[5];
  v6 = __CFADD__(v63, v63);
  v63 *= 2LL;
  v64 = v63 + v61;
  v65 = __CFADD__(v63, v61) + v6 + v62;
  v66 = a2[3] * (unsigned __int64)a2[4];
  v6 = __CFADD__(v66, v66);
  v66 *= 2LL;
  v67 = v6 + v65;
  v6 = __CFADD__(v66, v64);
  v69 = (v66 + v64) >> 32;
  v68 = v66 + v64;
  LODWORD(v66) = a2[7];
  v70 = v6 + v67;
  *(_DWORD *)(a1 + 28) = v68;
  v71 = a2[1] * (unsigned __int64)(unsigned int)v66;
  v6 = __CFADD__(v71, v71);
  v71 *= 2LL;
  v72 = v71 + __PAIR64__(v70, v69);
  v73 = __CFADD__(v71, __PAIR64__(v70, v69)) + v6;
  v74 = a2[2] * (unsigned __int64)a2[6];
  v6 = __CFADD__(v74, v74);
  v74 *= 2LL;
  v75 = v74 + v72;
  v76 = __CFADD__(v74, v72) + v6 + v73;
  v77 = a2[3] * (unsigned __int64)a2[5];
  v6 = __CFADD__(v77, v77);
  v77 *= 2LL;
  v78 = v77 + v75;
  v79 = __CFADD__(v77, v75) + v6 + v76;
  v80 = a2[4] * (unsigned __int64)a2[4];
  v6 = __CFADD__(v80, v78);
  v81 = (v80 + v78) >> 32;
  HIDWORD(v80) = a2[2];
  v82 = v6 + v79;
  *(_DWORD *)(a1 + 32) = v80 + v78;
  v83 = HIDWORD(v80) * (unsigned __int64)a2[7];
  v6 = __CFADD__(v83, v83);
  v83 *= 2LL;
  v84 = v83 + __PAIR64__(v82, v81);
  v85 = __CFADD__(v83, __PAIR64__(v82, v81)) + v6;
  v86 = a2[3] * (unsigned __int64)a2[6];
  v6 = __CFADD__(v86, v86);
  v86 *= 2LL;
  v87 = v86 + v84;
  v88 = __CFADD__(v86, v84) + v6 + v85;
  v89 = a2[4] * (unsigned __int64)a2[5];
  v6 = __CFADD__(v89, v89);
  v89 *= 2LL;
  v90 = v6 + v88;
  v6 = __CFADD__(v89, v87);
  v91 = (v89 + v87) >> 32;
  v92 = v89 + v87;
  LODWORD(v89) = a2[7];
  v93 = v6 + v90;
  *(_DWORD *)(a1 + 36) = v92;
  v94 = a2[3] * (unsigned __int64)(unsigned int)v89;
  v6 = __CFADD__(v94, v94);
  v94 *= 2LL;
  v95 = v94 + __PAIR64__(v93, v91);
  v96 = __CFADD__(v94, __PAIR64__(v93, v91)) + v6;
  v97 = a2[4] * (unsigned __int64)a2[6];
  v6 = __CFADD__(v97, v97);
  v97 *= 2LL;
  v98 = v97 + v95;
  v99 = __CFADD__(v97, v95) + v6 + v96;
  v100 = a2[5] * (unsigned __int64)a2[5];
  v6 = __CFADD__(v100, v98);
  v101 = (v100 + v98) >> 32;
  HIDWORD(v100) = a2[4];
  v102 = v6 + v99;
  *(_DWORD *)(a1 + 40) = v100 + v98;
  v103 = HIDWORD(v100) * (unsigned __int64)a2[7];
  v6 = __CFADD__(v103, v103);
  v103 *= 2LL;
  v104 = v103 + __PAIR64__(v102, v101);
  v105 = __CFADD__(v103, __PAIR64__(v102, v101)) + v6;
  v106 = a2[5] * (unsigned __int64)a2[6];
  v6 = __CFADD__(v106, v106);
  v106 *= 2LL;
  v107 = v6 + v105;
  v6 = __CFADD__(v106, v104);
  v108 = (v106 + v104) >> 32;
  v109 = v106 + v104;
  LODWORD(v106) = a2[7];
  v110 = v6 + v107;
  *(_DWORD *)(a1 + 44) = v109;
  v111 = a2[5] * (unsigned __int64)(unsigned int)v106;
  v6 = __CFADD__(v111, v111);
  v111 *= 2LL;
  v112 = v111 + __PAIR64__(v110, v108);
  v113 = __CFADD__(v111, __PAIR64__(v110, v108)) + v6;
  v114 = a2[6] * (unsigned __int64)a2[6];
  v6 = __CFADD__(v114, v112);
  v115 = (v114 + v112) >> 32;
  HIDWORD(v114) = a2[6];
  v116 = v6 + v113;
  *(_DWORD *)(a1 + 48) = v114 + v112;
  v117 = HIDWORD(v114) * (unsigned __int64)a2[7];
  v6 = __CFADD__(v117, v117);
  v117 *= 2LL;
  v118 = v6;
  v6 = __CFADD__(v117, __PAIR64__(v116, v115));
  v120 = v117 + v115;
  v119 = (v117 + __PAIR64__(v116, v115)) >> 32;
  LODWORD(v117) = a2[7];
  *(_DWORD *)(a1 + 52) = v120;
  result = (unsigned int)v117 * (unsigned __int64)(unsigned int)v117;
  *(_QWORD *)(a1 + 56) = result + __PAIR64__((unsigned int)v6 + v118, v119);
  return result;
}

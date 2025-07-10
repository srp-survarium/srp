int __usercall _x86_DES_encrypt@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  unsigned int v4; // eax
  unsigned int v5; // edx
  int v6; // ebx
  int v7; // ecx
  unsigned int v8; // edx
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  unsigned int v13; // eax
  int v14; // ebx
  int v15; // ecx
  unsigned int v16; // edx
  int v17; // esi
  int v18; // esi
  int v19; // esi
  int v20; // esi
  unsigned int v21; // eax
  int v22; // ebx
  int v23; // ecx
  unsigned int v24; // edx
  int v25; // edi
  int v26; // edi
  int v27; // edi
  int v28; // edi
  unsigned int v29; // eax
  int v30; // ebx
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // esi
  int v34; // esi
  int v35; // esi
  int v36; // esi
  unsigned int v37; // eax
  int v38; // ebx
  int v39; // ecx
  unsigned int v40; // edx
  int v41; // edi
  int v42; // edi
  int v43; // edi
  int v44; // edi
  unsigned int v45; // eax
  int v46; // ebx
  int v47; // ecx
  unsigned int v48; // edx
  int v49; // esi
  int v50; // esi
  int v51; // esi
  int v52; // esi
  unsigned int v53; // eax
  int v54; // ebx
  int v55; // ecx
  unsigned int v56; // edx
  int v57; // edi
  int v58; // edi
  int v59; // edi
  int v60; // edi
  unsigned int v61; // eax
  int v62; // ebx
  int v63; // ecx
  unsigned int v64; // edx
  int v65; // esi
  int v66; // esi
  int v67; // esi
  int v68; // esi
  unsigned int v69; // eax
  int v70; // ebx
  int v71; // ecx
  unsigned int v72; // edx
  int v73; // edi
  int v74; // edi
  int v75; // edi
  int v76; // edi
  unsigned int v77; // eax
  int v78; // ebx
  int v79; // ecx
  unsigned int v80; // edx
  int v81; // esi
  int v82; // esi
  int v83; // esi
  int v84; // esi
  unsigned int v85; // eax
  int v86; // ebx
  int v87; // ecx
  unsigned int v88; // edx
  int v89; // edi
  int v90; // edi
  int v91; // edi
  int v92; // edi
  unsigned int v93; // eax
  int v94; // ebx
  int v95; // ecx
  unsigned int v96; // edx
  int v97; // esi
  int v98; // esi
  int v99; // esi
  int v100; // esi
  unsigned int v101; // eax
  int v102; // ebx
  int v103; // ecx
  unsigned int v104; // edx
  int v105; // edi
  int v106; // edi
  int v107; // edi
  int v108; // edi
  unsigned int v109; // eax
  int v110; // ebx
  int v111; // ecx
  unsigned int v112; // edx
  int v113; // esi
  int v114; // esi
  int v115; // esi
  int v116; // esi
  unsigned int v117; // eax
  int v118; // ebx
  int v119; // ecx
  unsigned int v120; // edx
  int v121; // edi
  int v122; // edi
  int v123; // edi

  v4 = (a4 ^ *a1) & 0xFCFCFCFC;
  v5 = (a4 ^ a1[1]) & 0xCFCFCFCF;
  v6 = (unsigned __int8)v4;
  v7 = BYTE1(v4);
  v8 = __ROR4__(v5, 4);
  LOBYTE(v6) = v8;
  v9 = *(_DWORD *)(a2 + BYTE1(v4) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v4) ^ a3;
  LOBYTE(v7) = BYTE1(v8);
  v4 >>= 16;
  v10 = *(_DWORD *)(a2 + v6 + 256) ^ v9;
  LOBYTE(v6) = BYTE1(v4);
  v8 >>= 16;
  v11 = *(_DWORD *)(a2 + v7 + 768) ^ v10;
  LOBYTE(v7) = BYTE1(v8);
  v12 = *(_DWORD *)(a2 + (unsigned __int8)v8 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v4 + 1024)
      ^ *(_DWORD *)(a2 + v7 + 1792)
      ^ *(_DWORD *)(a2 + v6 + 1536)
      ^ v11;
  v13 = (v12 ^ a1[2]) & 0xFCFCFCFC;
  v14 = (unsigned __int8)v13;
  v15 = BYTE1(v13);
  v16 = __ROR4__((v12 ^ a1[3]) & 0xCFCFCFCF, 4);
  LOBYTE(v14) = v16;
  v17 = *(_DWORD *)(a2 + BYTE1(v13) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v13) ^ a4;
  LOBYTE(v15) = BYTE1(v16);
  v13 >>= 16;
  v18 = *(_DWORD *)(a2 + v14 + 256) ^ v17;
  LOBYTE(v14) = BYTE1(v13);
  v16 >>= 16;
  v19 = *(_DWORD *)(a2 + v15 + 768) ^ v18;
  LOBYTE(v15) = BYTE1(v16);
  v20 = *(_DWORD *)(a2 + (unsigned __int8)v16 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v13 + 1024)
      ^ *(_DWORD *)(a2 + v15 + 1792)
      ^ *(_DWORD *)(a2 + v14 + 1536)
      ^ v19;
  v21 = (v20 ^ a1[4]) & 0xFCFCFCFC;
  v22 = (unsigned __int8)v21;
  v23 = BYTE1(v21);
  v24 = __ROR4__((v20 ^ a1[5]) & 0xCFCFCFCF, 4);
  LOBYTE(v22) = v24;
  v25 = *(_DWORD *)(a2 + BYTE1(v21) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v21) ^ v12;
  LOBYTE(v23) = BYTE1(v24);
  v21 >>= 16;
  v26 = *(_DWORD *)(a2 + v22 + 256) ^ v25;
  LOBYTE(v22) = BYTE1(v21);
  v24 >>= 16;
  v27 = *(_DWORD *)(a2 + v23 + 768) ^ v26;
  LOBYTE(v23) = BYTE1(v24);
  v28 = *(_DWORD *)(a2 + (unsigned __int8)v24 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v21 + 1024)
      ^ *(_DWORD *)(a2 + v23 + 1792)
      ^ *(_DWORD *)(a2 + v22 + 1536)
      ^ v27;
  v29 = (v28 ^ a1[6]) & 0xFCFCFCFC;
  v30 = (unsigned __int8)v29;
  v31 = BYTE1(v29);
  v32 = __ROR4__((v28 ^ a1[7]) & 0xCFCFCFCF, 4);
  LOBYTE(v30) = v32;
  v33 = *(_DWORD *)(a2 + BYTE1(v29) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v29) ^ v20;
  LOBYTE(v31) = BYTE1(v32);
  v29 >>= 16;
  v34 = *(_DWORD *)(a2 + v30 + 256) ^ v33;
  LOBYTE(v30) = BYTE1(v29);
  v32 >>= 16;
  v35 = *(_DWORD *)(a2 + v31 + 768) ^ v34;
  LOBYTE(v31) = BYTE1(v32);
  v36 = *(_DWORD *)(a2 + (unsigned __int8)v32 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v29 + 1024)
      ^ *(_DWORD *)(a2 + v31 + 1792)
      ^ *(_DWORD *)(a2 + v30 + 1536)
      ^ v35;
  v37 = (v36 ^ a1[8]) & 0xFCFCFCFC;
  v38 = (unsigned __int8)v37;
  v39 = BYTE1(v37);
  v40 = __ROR4__((v36 ^ a1[9]) & 0xCFCFCFCF, 4);
  LOBYTE(v38) = v40;
  v41 = *(_DWORD *)(a2 + BYTE1(v37) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v37) ^ v28;
  LOBYTE(v39) = BYTE1(v40);
  v37 >>= 16;
  v42 = *(_DWORD *)(a2 + v38 + 256) ^ v41;
  LOBYTE(v38) = BYTE1(v37);
  v40 >>= 16;
  v43 = *(_DWORD *)(a2 + v39 + 768) ^ v42;
  LOBYTE(v39) = BYTE1(v40);
  v44 = *(_DWORD *)(a2 + (unsigned __int8)v40 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v37 + 1024)
      ^ *(_DWORD *)(a2 + v39 + 1792)
      ^ *(_DWORD *)(a2 + v38 + 1536)
      ^ v43;
  v45 = (v44 ^ a1[10]) & 0xFCFCFCFC;
  v46 = (unsigned __int8)v45;
  v47 = BYTE1(v45);
  v48 = __ROR4__((v44 ^ a1[11]) & 0xCFCFCFCF, 4);
  LOBYTE(v46) = v48;
  v49 = *(_DWORD *)(a2 + BYTE1(v45) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v45) ^ v36;
  LOBYTE(v47) = BYTE1(v48);
  v45 >>= 16;
  v50 = *(_DWORD *)(a2 + v46 + 256) ^ v49;
  LOBYTE(v46) = BYTE1(v45);
  v48 >>= 16;
  v51 = *(_DWORD *)(a2 + v47 + 768) ^ v50;
  LOBYTE(v47) = BYTE1(v48);
  v52 = *(_DWORD *)(a2 + (unsigned __int8)v48 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v45 + 1024)
      ^ *(_DWORD *)(a2 + v47 + 1792)
      ^ *(_DWORD *)(a2 + v46 + 1536)
      ^ v51;
  v53 = (v52 ^ a1[12]) & 0xFCFCFCFC;
  v54 = (unsigned __int8)v53;
  v55 = BYTE1(v53);
  v56 = __ROR4__((v52 ^ a1[13]) & 0xCFCFCFCF, 4);
  LOBYTE(v54) = v56;
  v57 = *(_DWORD *)(a2 + BYTE1(v53) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v53) ^ v44;
  LOBYTE(v55) = BYTE1(v56);
  v53 >>= 16;
  v58 = *(_DWORD *)(a2 + v54 + 256) ^ v57;
  LOBYTE(v54) = BYTE1(v53);
  v56 >>= 16;
  v59 = *(_DWORD *)(a2 + v55 + 768) ^ v58;
  LOBYTE(v55) = BYTE1(v56);
  v60 = *(_DWORD *)(a2 + (unsigned __int8)v56 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v53 + 1024)
      ^ *(_DWORD *)(a2 + v55 + 1792)
      ^ *(_DWORD *)(a2 + v54 + 1536)
      ^ v59;
  v61 = (v60 ^ a1[14]) & 0xFCFCFCFC;
  v62 = (unsigned __int8)v61;
  v63 = BYTE1(v61);
  v64 = __ROR4__((v60 ^ a1[15]) & 0xCFCFCFCF, 4);
  LOBYTE(v62) = v64;
  v65 = *(_DWORD *)(a2 + BYTE1(v61) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v61) ^ v52;
  LOBYTE(v63) = BYTE1(v64);
  v61 >>= 16;
  v66 = *(_DWORD *)(a2 + v62 + 256) ^ v65;
  LOBYTE(v62) = BYTE1(v61);
  v64 >>= 16;
  v67 = *(_DWORD *)(a2 + v63 + 768) ^ v66;
  LOBYTE(v63) = BYTE1(v64);
  v68 = *(_DWORD *)(a2 + (unsigned __int8)v64 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v61 + 1024)
      ^ *(_DWORD *)(a2 + v63 + 1792)
      ^ *(_DWORD *)(a2 + v62 + 1536)
      ^ v67;
  v69 = (v68 ^ a1[16]) & 0xFCFCFCFC;
  v70 = (unsigned __int8)v69;
  v71 = BYTE1(v69);
  v72 = __ROR4__((v68 ^ a1[17]) & 0xCFCFCFCF, 4);
  LOBYTE(v70) = v72;
  v73 = *(_DWORD *)(a2 + BYTE1(v69) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v69) ^ v60;
  LOBYTE(v71) = BYTE1(v72);
  v69 >>= 16;
  v74 = *(_DWORD *)(a2 + v70 + 256) ^ v73;
  LOBYTE(v70) = BYTE1(v69);
  v72 >>= 16;
  v75 = *(_DWORD *)(a2 + v71 + 768) ^ v74;
  LOBYTE(v71) = BYTE1(v72);
  v76 = *(_DWORD *)(a2 + (unsigned __int8)v72 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v69 + 1024)
      ^ *(_DWORD *)(a2 + v71 + 1792)
      ^ *(_DWORD *)(a2 + v70 + 1536)
      ^ v75;
  v77 = (v76 ^ a1[18]) & 0xFCFCFCFC;
  v78 = (unsigned __int8)v77;
  v79 = BYTE1(v77);
  v80 = __ROR4__((v76 ^ a1[19]) & 0xCFCFCFCF, 4);
  LOBYTE(v78) = v80;
  v81 = *(_DWORD *)(a2 + BYTE1(v77) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v77) ^ v68;
  LOBYTE(v79) = BYTE1(v80);
  v77 >>= 16;
  v82 = *(_DWORD *)(a2 + v78 + 256) ^ v81;
  LOBYTE(v78) = BYTE1(v77);
  v80 >>= 16;
  v83 = *(_DWORD *)(a2 + v79 + 768) ^ v82;
  LOBYTE(v79) = BYTE1(v80);
  v84 = *(_DWORD *)(a2 + (unsigned __int8)v80 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v77 + 1024)
      ^ *(_DWORD *)(a2 + v79 + 1792)
      ^ *(_DWORD *)(a2 + v78 + 1536)
      ^ v83;
  v85 = (v84 ^ a1[20]) & 0xFCFCFCFC;
  v86 = (unsigned __int8)v85;
  v87 = BYTE1(v85);
  v88 = __ROR4__((v84 ^ a1[21]) & 0xCFCFCFCF, 4);
  LOBYTE(v86) = v88;
  v89 = *(_DWORD *)(a2 + BYTE1(v85) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v85) ^ v76;
  LOBYTE(v87) = BYTE1(v88);
  v85 >>= 16;
  v90 = *(_DWORD *)(a2 + v86 + 256) ^ v89;
  LOBYTE(v86) = BYTE1(v85);
  v88 >>= 16;
  v91 = *(_DWORD *)(a2 + v87 + 768) ^ v90;
  LOBYTE(v87) = BYTE1(v88);
  v92 = *(_DWORD *)(a2 + (unsigned __int8)v88 + 1280)
      ^ *(_DWORD *)(a2 + (unsigned __int8)v85 + 1024)
      ^ *(_DWORD *)(a2 + v87 + 1792)
      ^ *(_DWORD *)(a2 + v86 + 1536)
      ^ v91;
  v93 = (v92 ^ a1[22]) & 0xFCFCFCFC;
  v94 = (unsigned __int8)v93;
  v95 = BYTE1(v93);
  v96 = __ROR4__((v92 ^ a1[23]) & 0xCFCFCFCF, 4);
  LOBYTE(v94) = v96;
  v97 = *(_DWORD *)(a2 + BYTE1(v93) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v93) ^ v84;
  LOBYTE(v95) = BYTE1(v96);
  v93 >>= 16;
  v98 = *(_DWORD *)(a2 + v94 + 256) ^ v97;
  LOBYTE(v94) = BYTE1(v93);
  v96 >>= 16;
  v99 = *(_DWORD *)(a2 + v95 + 768) ^ v98;
  LOBYTE(v95) = BYTE1(v96);
  v100 = *(_DWORD *)(a2 + (unsigned __int8)v96 + 1280)
       ^ *(_DWORD *)(a2 + (unsigned __int8)v93 + 1024)
       ^ *(_DWORD *)(a2 + v95 + 1792)
       ^ *(_DWORD *)(a2 + v94 + 1536)
       ^ v99;
  v101 = (v100 ^ a1[24]) & 0xFCFCFCFC;
  v102 = (unsigned __int8)v101;
  v103 = BYTE1(v101);
  v104 = __ROR4__((v100 ^ a1[25]) & 0xCFCFCFCF, 4);
  LOBYTE(v102) = v104;
  v105 = *(_DWORD *)(a2 + BYTE1(v101) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v101) ^ v92;
  LOBYTE(v103) = BYTE1(v104);
  v101 >>= 16;
  v106 = *(_DWORD *)(a2 + v102 + 256) ^ v105;
  LOBYTE(v102) = BYTE1(v101);
  v104 >>= 16;
  v107 = *(_DWORD *)(a2 + v103 + 768) ^ v106;
  LOBYTE(v103) = BYTE1(v104);
  v108 = *(_DWORD *)(a2 + (unsigned __int8)v104 + 1280)
       ^ *(_DWORD *)(a2 + (unsigned __int8)v101 + 1024)
       ^ *(_DWORD *)(a2 + v103 + 1792)
       ^ *(_DWORD *)(a2 + v102 + 1536)
       ^ v107;
  v109 = (v108 ^ a1[26]) & 0xFCFCFCFC;
  v110 = (unsigned __int8)v109;
  v111 = BYTE1(v109);
  v112 = __ROR4__((v108 ^ a1[27]) & 0xCFCFCFCF, 4);
  LOBYTE(v110) = v112;
  v113 = *(_DWORD *)(a2 + BYTE1(v109) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v109) ^ v100;
  LOBYTE(v111) = BYTE1(v112);
  v109 >>= 16;
  v114 = *(_DWORD *)(a2 + v110 + 256) ^ v113;
  LOBYTE(v110) = BYTE1(v109);
  v112 >>= 16;
  v115 = *(_DWORD *)(a2 + v111 + 768) ^ v114;
  LOBYTE(v111) = BYTE1(v112);
  v116 = *(_DWORD *)(a2 + (unsigned __int8)v112 + 1280)
       ^ *(_DWORD *)(a2 + (unsigned __int8)v109 + 1024)
       ^ *(_DWORD *)(a2 + v111 + 1792)
       ^ *(_DWORD *)(a2 + v110 + 1536)
       ^ v115;
  v117 = (v116 ^ a1[28]) & 0xFCFCFCFC;
  v118 = (unsigned __int8)v117;
  v119 = BYTE1(v117);
  v120 = __ROR4__((v116 ^ a1[29]) & 0xCFCFCFCF, 4);
  LOBYTE(v118) = v120;
  v121 = *(_DWORD *)(a2 + BYTE1(v117) + 512) ^ *(_DWORD *)(a2 + (unsigned __int8)v117) ^ v108;
  LOBYTE(v119) = BYTE1(v120);
  v117 >>= 16;
  v122 = *(_DWORD *)(a2 + v118 + 256) ^ v121;
  LOBYTE(v118) = BYTE1(v117);
  v120 >>= 16;
  v123 = *(_DWORD *)(a2 + v119 + 768) ^ v122;
  LOBYTE(v119) = BYTE1(v120);
  return (unsigned __int8)(((*(_DWORD *)(a2 + (unsigned __int8)v120 + 1280)
                           ^ *(_DWORD *)(a2 + (unsigned __int8)v117 + 1024)
                           ^ *(_DWORD *)(a2 + v119 + 1792)
                           ^ *(_DWORD *)(a2 + v118 + 1536)
                           ^ v123
                           ^ a1[30])
                          & 0xFCFCFCFC) >> 16);
}

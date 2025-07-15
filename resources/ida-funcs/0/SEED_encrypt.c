void __cdecl SEED_encrypt(const unsigned __int8 *s, unsigned __int8 *d, const seed_key_st *ks)
{
  int v4; // ecx
  unsigned int v6; // edx
  unsigned int v7; // edi
  unsigned int v8; // ebp
  unsigned int v9; // edx
  unsigned int v10; // esi
  unsigned int v11; // edi
  int v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // edi
  unsigned int v15; // edx
  unsigned int v16; // esi
  unsigned int v17; // edi
  int v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // edi
  unsigned int v21; // edx
  unsigned int v22; // esi
  unsigned int v23; // edi
  int v24; // ecx
  unsigned int v25; // esi
  unsigned int v26; // edi
  unsigned int v27; // edx
  unsigned int v28; // esi
  unsigned int v29; // edi
  int v30; // ecx
  unsigned int v31; // esi
  unsigned int v32; // edi
  unsigned int v33; // edx
  unsigned int v34; // esi
  unsigned int v35; // edi
  int v36; // ecx
  unsigned int v37; // esi
  unsigned int v38; // edi
  unsigned int v39; // edx
  unsigned int v40; // esi
  unsigned int v41; // edi
  int v42; // ecx
  unsigned int v43; // esi
  unsigned int v44; // edi
  unsigned int v45; // edx
  unsigned int v46; // esi
  unsigned int v47; // edi
  int v48; // ecx
  unsigned int v49; // esi
  unsigned int v50; // edi
  unsigned int v51; // ebx
  unsigned int v52; // esi
  unsigned int v53; // edx
  unsigned int v54; // esi
  unsigned int v55; // edi
  int v56; // ecx
  int v57; // [esp+10h] [ebp-10h]
  int v58; // [esp+10h] [ebp-10h]
  int v59; // [esp+10h] [ebp-10h]
  int v60; // [esp+10h] [ebp-10h]
  int v61; // [esp+10h] [ebp-10h]
  int v62; // [esp+10h] [ebp-10h]
  int v63; // [esp+10h] [ebp-10h]
  int v64; // [esp+10h] [ebp-10h]
  int v65; // [esp+14h] [ebp-Ch]
  int v66; // [esp+14h] [ebp-Ch]
  int v67; // [esp+14h] [ebp-Ch]
  int v68; // [esp+14h] [ebp-Ch]
  int v69; // [esp+14h] [ebp-Ch]
  int v70; // [esp+14h] [ebp-Ch]
  int v71; // [esp+14h] [ebp-Ch]
  int v72; // [esp+14h] [ebp-Ch]
  int v73; // [esp+18h] [ebp-8h]
  int v74; // [esp+18h] [ebp-8h]
  int v75; // [esp+18h] [ebp-8h]
  int v76; // [esp+18h] [ebp-8h]
  int v77; // [esp+18h] [ebp-8h]
  int v78; // [esp+18h] [ebp-8h]
  int v79; // [esp+18h] [ebp-8h]
  int v80; // [esp+18h] [ebp-8h]
  unsigned int v81; // [esp+24h] [ebp+4h]
  unsigned int v82; // [esp+24h] [ebp+4h]
  unsigned int v83; // [esp+24h] [ebp+4h]
  unsigned int v84; // [esp+24h] [ebp+4h]
  unsigned int v85; // [esp+24h] [ebp+4h]
  unsigned int v86; // [esp+24h] [ebp+4h]
  unsigned int v87; // [esp+24h] [ebp+4h]
  unsigned int v88; // [esp+24h] [ebp+4h]
  unsigned int v89; // [esp+24h] [ebp+4h]
  unsigned int v90; // [esp+24h] [ebp+4h]
  unsigned int v91; // [esp+24h] [ebp+4h]
  unsigned int v92; // [esp+24h] [ebp+4h]
  unsigned int v93; // [esp+24h] [ebp+4h]
  unsigned int v94; // [esp+24h] [ebp+4h]
  unsigned int v95; // [esp+24h] [ebp+4h]
  unsigned int v96; // [esp+2Ch] [ebp+Ch]
  unsigned int v97; // [esp+2Ch] [ebp+Ch]
  unsigned int v98; // [esp+2Ch] [ebp+Ch]
  unsigned int v99; // [esp+2Ch] [ebp+Ch]
  unsigned int v100; // [esp+2Ch] [ebp+Ch]
  unsigned int v101; // [esp+2Ch] [ebp+Ch]
  unsigned int v102; // [esp+2Ch] [ebp+Ch]
  unsigned int v103; // [esp+2Ch] [ebp+Ch]
  unsigned int v104; // [esp+2Ch] [ebp+Ch]
  unsigned int v105; // [esp+2Ch] [ebp+Ch]
  unsigned int v106; // [esp+2Ch] [ebp+Ch]
  unsigned int v107; // [esp+2Ch] [ebp+Ch]
  unsigned int v108; // [esp+2Ch] [ebp+Ch]
  unsigned int v109; // [esp+2Ch] [ebp+Ch]
  unsigned int v110; // [esp+2Ch] [ebp+Ch]

  v4 = s[11] | ((s[10] | ((s[9] | (s[8] << 8)) << 8)) << 8);
  v57 = s[15] | ((s[14] | ((s[13] | (s[12] << 8)) << 8)) << 8);
  v96 = v4 ^ ks->data[0];
  v6 = v57 ^ v96 ^ ks->data[1];
  v81 = dword_6D31F8[0][(unsigned __int8)v6]
      ^ dword_6D31F8[1][BYTE1(v6)]
      ^ dword_6D31F8[2][BYTE2(v6)]
      ^ dword_6D31F8[3][HIBYTE(v6)];
  v7 = dword_6D31F8[0][(unsigned __int8)(v81 + v96)]
     ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v81 + v96) >> 8)]
     ^ dword_6D31F8[2][(unsigned __int8)((v81 + v96) >> 16)]
     ^ dword_6D31F8[3][(v81 + v96) >> 24];
  v8 = dword_6D31F8[0][(unsigned __int8)(v7 + v81)]
     ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v7 + v81) >> 8)]
     ^ dword_6D31F8[2][(unsigned __int8)((v7 + v81) >> 16)]
     ^ dword_6D31F8[3][(v7 + v81) >> 24];
  v65 = (v8 + v7) ^ (s[3] | ((s[2] | ((s[1] | (*s << 8)) << 8)) << 8));
  v73 = v8 ^ (s[7] | ((s[6] | ((s[5] | (s[4] << 8)) << 8)) << 8));
  v9 = v73 ^ v65 ^ ks->data[2] ^ ks->data[3];
  v97 = v65 ^ ks->data[2];
  v82 = dword_6D31F8[0][(unsigned __int8)v9]
      ^ dword_6D31F8[1][BYTE1(v9)]
      ^ dword_6D31F8[2][BYTE2(v9)]
      ^ dword_6D31F8[3][HIBYTE(v9)];
  v10 = dword_6D31F8[0][(unsigned __int8)(v82 + v97)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v82 + v97) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v82 + v97) >> 16)]
      ^ dword_6D31F8[3][(v82 + v97) >> 24];
  v11 = dword_6D31F8[0][(unsigned __int8)(v10 + v82)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v10 + v82) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v10 + v82) >> 16)]
      ^ dword_6D31F8[3][(v10 + v82) >> 24];
  v58 = v11 ^ v57;
  v12 = (v11 + v10) ^ v4;
  v98 = v12 ^ ks->data[4];
  v83 = dword_6D31F8[0][(unsigned __int8)(v58 ^ v98 ^ LOBYTE(ks->data[5]))]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v58 ^ v98 ^ LOWORD(ks->data[5])) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v58 ^ v98 ^ ks->data[5]) >> 16)]
      ^ dword_6D31F8[3][(v58 ^ v98 ^ ks->data[5]) >> 24];
  v13 = dword_6D31F8[0][(unsigned __int8)(v83 + v98)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v83 + v98) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v83 + v98) >> 16)]
      ^ dword_6D31F8[3][(v83 + v98) >> 24];
  v14 = dword_6D31F8[0][(unsigned __int8)(v13 + v83)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v13 + v83) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v13 + v83) >> 16)]
      ^ dword_6D31F8[3][(v13 + v83) >> 24];
  v74 = v14 ^ v73;
  v66 = (v14 + v13) ^ v65;
  v15 = v74 ^ v66 ^ ks->data[6] ^ ks->data[7];
  v99 = v66 ^ ks->data[6];
  v84 = dword_6D31F8[0][(unsigned __int8)v15]
      ^ dword_6D31F8[1][BYTE1(v15)]
      ^ dword_6D31F8[2][BYTE2(v15)]
      ^ dword_6D31F8[3][HIBYTE(v15)];
  v16 = dword_6D31F8[0][(unsigned __int8)(v84 + v99)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v84 + v99) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v84 + v99) >> 16)]
      ^ dword_6D31F8[3][(v84 + v99) >> 24];
  v17 = dword_6D31F8[0][(unsigned __int8)(v16 + v84)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v16 + v84) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v16 + v84) >> 16)]
      ^ dword_6D31F8[3][(v16 + v84) >> 24];
  v59 = v17 ^ v58;
  v18 = (v17 + v16) ^ v12;
  v100 = v18 ^ ks->data[8];
  v85 = dword_6D31F8[0][(unsigned __int8)(v59 ^ v100 ^ LOBYTE(ks->data[9]))]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v59 ^ v100 ^ LOWORD(ks->data[9])) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v59 ^ v100 ^ ks->data[9]) >> 16)]
      ^ dword_6D31F8[3][(v59 ^ v100 ^ ks->data[9]) >> 24];
  v19 = dword_6D31F8[0][(unsigned __int8)(v85 + v100)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v85 + v100) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v85 + v100) >> 16)]
      ^ dword_6D31F8[3][(v85 + v100) >> 24];
  v20 = dword_6D31F8[0][(unsigned __int8)(v19 + v85)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v19 + v85) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v19 + v85) >> 16)]
      ^ dword_6D31F8[3][(v19 + v85) >> 24];
  v75 = v20 ^ v74;
  v67 = (v20 + v19) ^ v66;
  v21 = v75 ^ v67 ^ ks->data[10] ^ ks->data[11];
  v101 = v67 ^ ks->data[10];
  v86 = dword_6D31F8[0][(unsigned __int8)v21]
      ^ dword_6D31F8[1][BYTE1(v21)]
      ^ dword_6D31F8[2][BYTE2(v21)]
      ^ dword_6D31F8[3][HIBYTE(v21)];
  v22 = dword_6D31F8[0][(unsigned __int8)(v86 + v101)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v86 + v101) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v86 + v101) >> 16)]
      ^ dword_6D31F8[3][(v86 + v101) >> 24];
  v23 = dword_6D31F8[0][(unsigned __int8)(v22 + v86)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v22 + v86) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v22 + v86) >> 16)]
      ^ dword_6D31F8[3][(v22 + v86) >> 24];
  v60 = v23 ^ v59;
  v24 = (v23 + v22) ^ v18;
  v102 = v24 ^ ks->data[12];
  v87 = dword_6D31F8[0][(unsigned __int8)(v60 ^ v102 ^ LOBYTE(ks->data[13]))]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v60 ^ v102 ^ LOWORD(ks->data[13])) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v60 ^ v102 ^ ks->data[13]) >> 16)]
      ^ dword_6D31F8[3][(v60 ^ v102 ^ ks->data[13]) >> 24];
  v25 = dword_6D31F8[0][(unsigned __int8)(v87 + v102)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v87 + v102) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v87 + v102) >> 16)]
      ^ dword_6D31F8[3][(v87 + v102) >> 24];
  v26 = dword_6D31F8[0][(unsigned __int8)(v25 + v87)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v25 + v87) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v25 + v87) >> 16)]
      ^ dword_6D31F8[3][(v25 + v87) >> 24];
  v76 = v26 ^ v75;
  v68 = (v26 + v25) ^ v67;
  v27 = v76 ^ v68 ^ ks->data[14] ^ ks->data[15];
  v103 = v68 ^ ks->data[14];
  v88 = dword_6D31F8[0][(unsigned __int8)v27]
      ^ dword_6D31F8[1][BYTE1(v27)]
      ^ dword_6D31F8[2][BYTE2(v27)]
      ^ dword_6D31F8[3][HIBYTE(v27)];
  v28 = dword_6D31F8[0][(unsigned __int8)(v88 + v103)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v88 + v103) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v88 + v103) >> 16)]
      ^ dword_6D31F8[3][(v88 + v103) >> 24];
  v29 = dword_6D31F8[0][(unsigned __int8)(v28 + v88)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v28 + v88) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v28 + v88) >> 16)]
      ^ dword_6D31F8[3][(v28 + v88) >> 24];
  v61 = v29 ^ v60;
  v30 = (v29 + v28) ^ v24;
  v104 = v30 ^ ks->data[16];
  v89 = dword_6D31F8[0][(unsigned __int8)(v61 ^ v104 ^ LOBYTE(ks->data[17]))]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v61 ^ v104 ^ LOWORD(ks->data[17])) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v61 ^ v104 ^ ks->data[17]) >> 16)]
      ^ dword_6D31F8[3][(v61 ^ v104 ^ ks->data[17]) >> 24];
  v31 = dword_6D31F8[0][(unsigned __int8)(v89 + v104)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v89 + v104) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v89 + v104) >> 16)]
      ^ dword_6D31F8[3][(v89 + v104) >> 24];
  v32 = dword_6D31F8[0][(unsigned __int8)(v31 + v89)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v31 + v89) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v31 + v89) >> 16)]
      ^ dword_6D31F8[3][(v31 + v89) >> 24];
  v77 = v32 ^ v76;
  v69 = (v32 + v31) ^ v68;
  v33 = v77 ^ v69 ^ ks->data[18] ^ ks->data[19];
  v105 = v69 ^ ks->data[18];
  v90 = dword_6D31F8[0][(unsigned __int8)v33]
      ^ dword_6D31F8[1][BYTE1(v33)]
      ^ dword_6D31F8[2][BYTE2(v33)]
      ^ dword_6D31F8[3][HIBYTE(v33)];
  v34 = dword_6D31F8[0][(unsigned __int8)(v90 + v105)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v90 + v105) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v90 + v105) >> 16)]
      ^ dword_6D31F8[3][(v90 + v105) >> 24];
  v35 = dword_6D31F8[0][(unsigned __int8)(v34 + v90)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v34 + v90) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v34 + v90) >> 16)]
      ^ dword_6D31F8[3][(v34 + v90) >> 24];
  v62 = v35 ^ v61;
  v36 = (v35 + v34) ^ v30;
  v106 = v36 ^ ks->data[20];
  v91 = dword_6D31F8[0][(unsigned __int8)(v62 ^ v106 ^ LOBYTE(ks->data[21]))]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v62 ^ v106 ^ LOWORD(ks->data[21])) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v62 ^ v106 ^ ks->data[21]) >> 16)]
      ^ dword_6D31F8[3][(v62 ^ v106 ^ ks->data[21]) >> 24];
  v37 = dword_6D31F8[0][(unsigned __int8)(v91 + v106)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v91 + v106) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v91 + v106) >> 16)]
      ^ dword_6D31F8[3][(v91 + v106) >> 24];
  v38 = dword_6D31F8[0][(unsigned __int8)(v37 + v91)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v37 + v91) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v37 + v91) >> 16)]
      ^ dword_6D31F8[3][(v37 + v91) >> 24];
  v78 = v38 ^ v77;
  v70 = (v38 + v37) ^ v69;
  v39 = v78 ^ v70 ^ ks->data[22] ^ ks->data[23];
  v107 = v70 ^ ks->data[22];
  v92 = dword_6D31F8[0][(unsigned __int8)v39]
      ^ dword_6D31F8[1][BYTE1(v39)]
      ^ dword_6D31F8[2][BYTE2(v39)]
      ^ dword_6D31F8[3][HIBYTE(v39)];
  v40 = dword_6D31F8[0][(unsigned __int8)(v92 + v107)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v92 + v107) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v92 + v107) >> 16)]
      ^ dword_6D31F8[3][(v92 + v107) >> 24];
  v41 = dword_6D31F8[0][(unsigned __int8)(v40 + v92)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v40 + v92) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v40 + v92) >> 16)]
      ^ dword_6D31F8[3][(v40 + v92) >> 24];
  v63 = v41 ^ v62;
  v42 = (v41 + v40) ^ v36;
  v108 = v42 ^ ks->data[24];
  v93 = dword_6D31F8[0][(unsigned __int8)(v63 ^ v108 ^ LOBYTE(ks->data[25]))]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v63 ^ v108 ^ LOWORD(ks->data[25])) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v63 ^ v108 ^ ks->data[25]) >> 16)]
      ^ dword_6D31F8[3][(v63 ^ v108 ^ ks->data[25]) >> 24];
  v43 = dword_6D31F8[0][(unsigned __int8)(v93 + v108)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v93 + v108) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v93 + v108) >> 16)]
      ^ dword_6D31F8[3][(v93 + v108) >> 24];
  v44 = dword_6D31F8[0][(unsigned __int8)(v43 + v93)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v43 + v93) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v43 + v93) >> 16)]
      ^ dword_6D31F8[3][(v43 + v93) >> 24];
  v79 = v44 ^ v78;
  v71 = (v44 + v43) ^ v70;
  v45 = v79 ^ v71 ^ ks->data[26] ^ ks->data[27];
  v109 = v71 ^ ks->data[26];
  v94 = dword_6D31F8[0][(unsigned __int8)v45]
      ^ dword_6D31F8[1][BYTE1(v45)]
      ^ dword_6D31F8[2][BYTE2(v45)]
      ^ dword_6D31F8[3][HIBYTE(v45)];
  v46 = dword_6D31F8[0][(unsigned __int8)(v94 + v109)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v94 + v109) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v94 + v109) >> 16)]
      ^ dword_6D31F8[3][(v94 + v109) >> 24];
  v47 = dword_6D31F8[0][(unsigned __int8)(v46 + v94)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v46 + v94) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v46 + v94) >> 16)]
      ^ dword_6D31F8[3][(v46 + v94) >> 24];
  v64 = v47 ^ v63;
  v48 = (v47 + v46) ^ v42;
  v110 = v48 ^ ks->data[28];
  v95 = dword_6D31F8[0][(unsigned __int8)(v64 ^ v110 ^ LOBYTE(ks->data[29]))]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v64 ^ v110 ^ LOWORD(ks->data[29])) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v64 ^ v110 ^ ks->data[29]) >> 16)]
      ^ dword_6D31F8[3][(v64 ^ v110 ^ ks->data[29]) >> 24];
  v49 = dword_6D31F8[0][(unsigned __int8)(v95 + v110)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v95 + v110) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v95 + v110) >> 16)]
      ^ dword_6D31F8[3][(v95 + v110) >> 24];
  v50 = dword_6D31F8[0][(unsigned __int8)(v49 + v95)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v49 + v95) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v49 + v95) >> 16)]
      ^ dword_6D31F8[3][(v49 + v95) >> 24];
  v80 = v50 ^ v79;
  v72 = (v50 + v49) ^ v71;
  v51 = v72 ^ ks->data[30];
  v52 = v80 ^ v51 ^ ks->data[31];
  v53 = dword_6D31F8[0][(unsigned __int8)v52]
      ^ dword_6D31F8[1][BYTE1(v52)]
      ^ dword_6D31F8[2][BYTE2(v52)]
      ^ dword_6D31F8[3][HIBYTE(v52)];
  v54 = dword_6D31F8[0][(unsigned __int8)(v53 + v51)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v53 + v51) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v53 + v51) >> 16)]
      ^ dword_6D31F8[3][(v53 + v51) >> 24];
  v55 = dword_6D31F8[0][(unsigned __int8)(v54 + v53)]
      ^ dword_6D31F8[1][(unsigned __int8)((unsigned __int16)(v54 + v53) >> 8)]
      ^ dword_6D31F8[2][(unsigned __int8)((v54 + v53) >> 16)]
      ^ dword_6D31F8[3][(v54 + v53) >> 24];
  v56 = (v55 + v54) ^ v48;
  *d = HIBYTE(v56);
  d[3] = v56;
  d[1] = BYTE2(v56);
  d[4] = (v55 ^ v64) >> 24;
  d[7] = v55 ^ v64;
  d[5] = (v55 ^ v64) >> 16;
  d[6] = (unsigned __int16)(v55 ^ v64) >> 8;
  d[8] = HIBYTE(v72);
  d[9] = BYTE2(v72);
  d[10] = BYTE1(v72);
  d[11] = v72;
  d[12] = HIBYTE(v80);
  d[13] = BYTE2(v80);
  d[2] = BYTE1(v56);
  d[14] = BYTE1(v80);
  d[15] = v80;
}

int __cdecl whirlpool_block_mmx(__m64 *a1, __m64 *a2, int a3)
{
  __m64 *v3; // edi
  int v4; // ecx
  int v5; // edx
  __m64 m64_u64; // mm0
  __m64 v7; // mm1
  __m64 v8; // mm2
  __m64 v9; // mm3
  __m64 v10; // mm4
  __m64 v11; // mm5
  __m64 v12; // mm6
  __m64 v13; // mm7
  int v14; // esi
  __m64 v15; // mm0
  __m64 v16; // mm1
  __m64 v17; // mm2
  __m64 v18; // mm3
  __m64 v19; // mm4
  __m64 v20; // mm5
  __m64 v21; // mm6
  __m64 v22; // mm7
  __m64 v23; // mm1
  __m64 v24; // mm2
  __m64 v25; // mm3
  __m64 v26; // mm4
  __m64 v27; // mm5
  __m64 v28; // mm6
  __m64 v29; // mm7
  __m64 v30; // mm0
  __m64 v31; // mm2
  __m64 v32; // mm3
  __m64 v33; // mm4
  __m64 v34; // mm5
  __m64 v35; // mm6
  __m64 v36; // mm7
  __m64 v37; // mm0
  __m64 v38; // mm1
  __m64 v39; // mm3
  __m64 v40; // mm4
  __m64 v41; // mm5
  __m64 v42; // mm6
  __m64 v43; // mm7
  __m64 v44; // mm0
  __m64 v45; // mm1
  __m64 v46; // mm2
  __m64 v47; // mm4
  __m64 v48; // mm5
  __m64 v49; // mm6
  __m64 v50; // mm7
  __m64 v51; // mm0
  __m64 v52; // mm1
  __m64 v53; // mm2
  __m64 v54; // mm3
  __m64 v55; // mm5
  __m64 v56; // mm6
  __m64 v57; // mm7
  __m64 v58; // mm0
  __m64 v59; // mm1
  __m64 v60; // mm2
  __m64 v61; // mm3
  __m64 v62; // mm4
  __m64 v63; // mm6
  __m64 v64; // mm7
  __m64 v65; // mm0
  __m64 v66; // mm1
  __m64 v67; // mm2
  __m64 v68; // mm3
  __m64 v69; // mm4
  __m64 v70; // mm5
  __m64 v71; // mm7
  __m64 v72; // mm0
  __m64 v73; // mm1
  __m64 v74; // mm2
  __m64 v75; // mm3
  __m64 v76; // mm4
  __m64 v77; // mm0
  __m64 v78; // mm1
  __m64 v79; // mm2
  __m64 v80; // mm3
  __m64 v81; // mm4
  __m64 v82; // mm5
  __m64 v83; // mm6
  __m64 v84; // mm7
  __m64 v85; // mm1
  __m64 v86; // mm2
  __m64 v87; // mm3
  __m64 v88; // mm4
  __m64 v89; // mm5
  __m64 v90; // mm6
  __m64 v91; // mm7
  __m64 v92; // mm0
  __m64 v93; // mm2
  __m64 v94; // mm3
  __m64 v95; // mm4
  __m64 v96; // mm5
  __m64 v97; // mm6
  __m64 v98; // mm7
  __m64 v99; // mm0
  __m64 v100; // mm1
  __m64 v101; // mm3
  __m64 v102; // mm4
  __m64 v103; // mm5
  __m64 v104; // mm6
  __m64 v105; // mm7
  __m64 v106; // mm0
  __m64 v107; // mm1
  __m64 v108; // mm2
  __m64 v109; // mm4
  __m64 v110; // mm5
  __m64 v111; // mm6
  __m64 v112; // mm7
  __m64 v113; // mm0
  __m64 v114; // mm1
  __m64 v115; // mm2
  __m64 v116; // mm3
  __m64 v117; // mm5
  __m64 v118; // mm6
  __m64 v119; // mm7
  __m64 v120; // mm0
  __m64 v121; // mm1
  __m64 v122; // mm2
  __m64 v123; // mm3
  __m64 v124; // mm4
  __m64 v125; // mm6
  __m64 v126; // mm7
  __m64 v127; // mm0
  __m64 v128; // mm1
  __m64 v129; // mm2
  __m64 v130; // mm3
  __m64 v131; // mm4
  __m64 v132; // mm5
  __m64 v133; // mm7
  __m64 v134; // mm0
  __m64 v135; // mm1
  __m64 v136; // mm2
  __m64 v137; // mm3
  __m64 v138; // mm4
  __m64 v139; // mm5
  __m64 v140; // mm6
  int result; // eax
  __m64 v142; // [esp+0h] [ebp-A4h]
  __m64 v143; // [esp+8h] [ebp-9Ch]
  __m64 v144; // [esp+10h] [ebp-94h]
  __m64 v145; // [esp+18h] [ebp-8Ch]
  __m64 v146; // [esp+20h] [ebp-84h]
  __m64 v147; // [esp+28h] [ebp-7Ch]
  __m64 v148; // [esp+30h] [ebp-74h]
  __m64 v149; // [esp+38h] [ebp-6Ch]
  __m64 v150; // [esp+40h] [ebp-64h]
  __m64 v151; // [esp+48h] [ebp-5Ch]
  __m64 v152; // [esp+50h] [ebp-54h]
  __m64 v153; // [esp+58h] [ebp-4Ch]
  __m64 v154; // [esp+60h] [ebp-44h]
  __m64 v155; // [esp+68h] [ebp-3Ch]
  __m64 v156; // [esp+70h] [ebp-34h]
  __m64 v157; // [esp+78h] [ebp-2Ch]
  __m64 *v158; // [esp+84h] [ebp-20h]
  int v160; // [esp+8Ch] [ebp-18h]

  v3 = a2;
  v158 = a2;
  v4 = 0;
  v5 = 0;
  m64_u64 = (__m64)a1->m64_u64;
  v7 = a1[1];
  v8 = a1[2];
  v9 = a1[3];
  v10 = a1[4];
  v11 = a1[5];
  v12 = a1[6];
  v13 = a1[7];
  while ( 1 )
  {
    v142 = m64_u64;
    v143 = v7;
    v144 = v8;
    v145 = v9;
    v146 = v10;
    v147 = v11;
    v148 = v12;
    v149 = v13;
    v150 = _m_pxor(m64_u64, (__m64)v3->m64_u64);
    v151 = _m_pxor(v7, v3[1]);
    v152 = _m_pxor(v8, v3[2]);
    v153 = _m_pxor(v9, v3[3]);
    v154 = _m_pxor(v10, v3[4]);
    v155 = _m_pxor(v11, v3[5]);
    v156 = _m_pxor(v12, v3[6]);
    v157 = _m_pxor(v13, v3[7]);
    v14 = 0;
    v160 = 0;
    while ( 1 )
    {
      LOBYTE(v5) = v142.m64_i8[1];
      LOBYTE(v4) = v142.m64_i8[0];
      v15 = _m_pxor(
              *(__m64 *)((char *)&_L001table[2 * v14] + (_DWORD)&qword_7D11B2 - 8192434),
              *(__m64 *)&_L001table[4 * v4]);
      v16 = *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3);
      LOBYTE(v5) = v142.m64_i8[3];
      LOBYTE(v4) = v142.m64_i8[2];
      v17 = *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2);
      v18 = *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1);
      LOBYTE(v5) = v142.m64_i8[5];
      LOBYTE(v4) = v142.m64_i8[4];
      v19 = *(__m64 *)&_L001table[4 * v4 + 1];
      v20 = *(__m64 *)((char *)&_L001table[4 * v5] + 3);
      LOBYTE(v5) = v142.m64_i8[7];
      LOBYTE(v4) = v142.m64_i8[6];
      v21 = *(__m64 *)((char *)&_L001table[4 * v4] + 2);
      v22 = *(__m64 *)((char *)&_L001table[4 * v5] + 1);
      LOBYTE(v5) = v143.m64_i8[1];
      LOBYTE(v4) = v143.m64_i8[0];
      v23 = _m_pxor(v16, *(__m64 *)&_L001table[4 * v4]);
      v24 = _m_pxor(v17, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v143.m64_i8[3];
      LOBYTE(v4) = v143.m64_i8[2];
      v25 = _m_pxor(v18, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v26 = _m_pxor(v19, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v143.m64_i8[5];
      LOBYTE(v4) = v143.m64_i8[4];
      v27 = _m_pxor(v20, *(__m64 *)&_L001table[4 * v4 + 1]);
      v28 = _m_pxor(v21, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v143.m64_i8[7];
      LOBYTE(v4) = v143.m64_i8[6];
      v29 = _m_pxor(v22, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v30 = _m_pxor(v15, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v144.m64_i8[1];
      LOBYTE(v4) = v144.m64_i8[0];
      v31 = _m_pxor(v24, *(__m64 *)&_L001table[4 * v4]);
      v32 = _m_pxor(v25, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v144.m64_i8[3];
      LOBYTE(v4) = v144.m64_i8[2];
      v33 = _m_pxor(v26, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v34 = _m_pxor(v27, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v144.m64_i8[5];
      LOBYTE(v4) = v144.m64_i8[4];
      v35 = _m_pxor(v28, *(__m64 *)&_L001table[4 * v4 + 1]);
      v36 = _m_pxor(v29, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v144.m64_i8[7];
      LOBYTE(v4) = v144.m64_i8[6];
      v37 = _m_pxor(v30, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v38 = _m_pxor(v23, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v145.m64_i8[1];
      LOBYTE(v4) = v145.m64_i8[0];
      v39 = _m_pxor(v32, *(__m64 *)&_L001table[4 * v4]);
      v40 = _m_pxor(v33, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v145.m64_i8[3];
      LOBYTE(v4) = v145.m64_i8[2];
      v41 = _m_pxor(v34, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v42 = _m_pxor(v35, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v145.m64_i8[5];
      LOBYTE(v4) = v145.m64_i8[4];
      v43 = _m_pxor(v36, *(__m64 *)&_L001table[4 * v4 + 1]);
      v44 = _m_pxor(v37, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v145.m64_i8[7];
      LOBYTE(v4) = v145.m64_i8[6];
      v45 = _m_pxor(v38, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v46 = _m_pxor(v31, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v146.m64_i8[1];
      LOBYTE(v4) = v146.m64_i8[0];
      v47 = _m_pxor(v40, *(__m64 *)&_L001table[4 * v4]);
      v48 = _m_pxor(v41, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v146.m64_i8[3];
      LOBYTE(v4) = v146.m64_i8[2];
      v49 = _m_pxor(v42, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v50 = _m_pxor(v43, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v146.m64_i8[5];
      LOBYTE(v4) = v146.m64_i8[4];
      v51 = _m_pxor(v44, *(__m64 *)&_L001table[4 * v4 + 1]);
      v52 = _m_pxor(v45, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v146.m64_i8[7];
      LOBYTE(v4) = v146.m64_i8[6];
      v53 = _m_pxor(v46, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v54 = _m_pxor(v39, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v147.m64_i8[1];
      LOBYTE(v4) = v147.m64_i8[0];
      v55 = _m_pxor(v48, *(__m64 *)&_L001table[4 * v4]);
      v56 = _m_pxor(v49, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v147.m64_i8[3];
      LOBYTE(v4) = v147.m64_i8[2];
      v57 = _m_pxor(v50, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v58 = _m_pxor(v51, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v147.m64_i8[5];
      LOBYTE(v4) = v147.m64_i8[4];
      v59 = _m_pxor(v52, *(__m64 *)&_L001table[4 * v4 + 1]);
      v60 = _m_pxor(v53, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v147.m64_i8[7];
      LOBYTE(v4) = v147.m64_i8[6];
      v61 = _m_pxor(v54, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v62 = _m_pxor(v47, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v148.m64_i8[1];
      LOBYTE(v4) = v148.m64_i8[0];
      v63 = _m_pxor(v56, *(__m64 *)&_L001table[4 * v4]);
      v64 = _m_pxor(v57, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v148.m64_i8[3];
      LOBYTE(v4) = v148.m64_i8[2];
      v65 = _m_pxor(v58, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v66 = _m_pxor(v59, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v148.m64_i8[5];
      LOBYTE(v4) = v148.m64_i8[4];
      v67 = _m_pxor(v60, *(__m64 *)&_L001table[4 * v4 + 1]);
      v68 = _m_pxor(v61, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v148.m64_i8[7];
      LOBYTE(v4) = v148.m64_i8[6];
      v69 = _m_pxor(v62, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v70 = _m_pxor(v55, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v149.m64_i8[1];
      LOBYTE(v4) = v149.m64_i8[0];
      v71 = _m_pxor(v64, *(__m64 *)&_L001table[4 * v4]);
      v72 = _m_pxor(v65, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v149.m64_i8[3];
      LOBYTE(v4) = v149.m64_i8[2];
      v73 = _m_pxor(v66, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v74 = _m_pxor(v67, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v149.m64_i8[5];
      LOBYTE(v4) = v149.m64_i8[4];
      v75 = _m_pxor(v68, *(__m64 *)&_L001table[4 * v4 + 1]);
      v76 = _m_pxor(v69, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v149.m64_i8[7];
      LOBYTE(v4) = v149.m64_i8[6];
      v142 = v72;
      v143 = v73;
      v144 = v74;
      v145 = v75;
      v146 = v76;
      v147 = _m_pxor(v70, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v148 = _m_pxor(v63, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      v149 = v71;
      LOBYTE(v5) = v150.m64_i8[1];
      LOBYTE(v4) = v150.m64_i8[0];
      v77 = _m_pxor(v72, *(__m64 *)&_L001table[4 * v4]);
      v78 = _m_pxor(v73, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v150.m64_i8[3];
      LOBYTE(v4) = v150.m64_i8[2];
      v79 = _m_pxor(v74, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v80 = _m_pxor(v75, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v150.m64_i8[5];
      LOBYTE(v4) = v150.m64_i8[4];
      v81 = _m_pxor(v76, *(__m64 *)&_L001table[4 * v4 + 1]);
      v82 = _m_pxor(v147, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v150.m64_i8[7];
      LOBYTE(v4) = v150.m64_i8[6];
      v83 = _m_pxor(v148, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v84 = _m_pxor(v71, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v151.m64_i8[1];
      LOBYTE(v4) = v151.m64_i8[0];
      v85 = _m_pxor(v78, *(__m64 *)&_L001table[4 * v4]);
      v86 = _m_pxor(v79, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v151.m64_i8[3];
      LOBYTE(v4) = v151.m64_i8[2];
      v87 = _m_pxor(v80, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v88 = _m_pxor(v81, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v151.m64_i8[5];
      LOBYTE(v4) = v151.m64_i8[4];
      v89 = _m_pxor(v82, *(__m64 *)&_L001table[4 * v4 + 1]);
      v90 = _m_pxor(v83, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v151.m64_i8[7];
      LOBYTE(v4) = v151.m64_i8[6];
      v91 = _m_pxor(v84, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v92 = _m_pxor(v77, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v152.m64_i8[1];
      LOBYTE(v4) = v152.m64_i8[0];
      v93 = _m_pxor(v86, *(__m64 *)&_L001table[4 * v4]);
      v94 = _m_pxor(v87, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v152.m64_i8[3];
      LOBYTE(v4) = v152.m64_i8[2];
      v95 = _m_pxor(v88, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v96 = _m_pxor(v89, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v152.m64_i8[5];
      LOBYTE(v4) = v152.m64_i8[4];
      v97 = _m_pxor(v90, *(__m64 *)&_L001table[4 * v4 + 1]);
      v98 = _m_pxor(v91, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v152.m64_i8[7];
      LOBYTE(v4) = v152.m64_i8[6];
      v99 = _m_pxor(v92, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v100 = _m_pxor(v85, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v153.m64_i8[1];
      LOBYTE(v4) = v153.m64_i8[0];
      v101 = _m_pxor(v94, *(__m64 *)&_L001table[4 * v4]);
      v102 = _m_pxor(v95, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v153.m64_i8[3];
      LOBYTE(v4) = v153.m64_i8[2];
      v103 = _m_pxor(v96, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v104 = _m_pxor(v97, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v153.m64_i8[5];
      LOBYTE(v4) = v153.m64_i8[4];
      v105 = _m_pxor(v98, *(__m64 *)&_L001table[4 * v4 + 1]);
      v106 = _m_pxor(v99, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v153.m64_i8[7];
      LOBYTE(v4) = v153.m64_i8[6];
      v107 = _m_pxor(v100, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v108 = _m_pxor(v93, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v154.m64_i8[1];
      LOBYTE(v4) = v154.m64_i8[0];
      v109 = _m_pxor(v102, *(__m64 *)&_L001table[4 * v4]);
      v110 = _m_pxor(v103, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v154.m64_i8[3];
      LOBYTE(v4) = v154.m64_i8[2];
      v111 = _m_pxor(v104, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v112 = _m_pxor(v105, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v154.m64_i8[5];
      LOBYTE(v4) = v154.m64_i8[4];
      v113 = _m_pxor(v106, *(__m64 *)&_L001table[4 * v4 + 1]);
      v114 = _m_pxor(v107, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v154.m64_i8[7];
      LOBYTE(v4) = v154.m64_i8[6];
      v115 = _m_pxor(v108, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v116 = _m_pxor(v101, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v155.m64_i8[1];
      LOBYTE(v4) = v155.m64_i8[0];
      v117 = _m_pxor(v110, *(__m64 *)&_L001table[4 * v4]);
      v118 = _m_pxor(v111, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v155.m64_i8[3];
      LOBYTE(v4) = v155.m64_i8[2];
      v119 = _m_pxor(v112, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v120 = _m_pxor(v113, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v155.m64_i8[5];
      LOBYTE(v4) = v155.m64_i8[4];
      v121 = _m_pxor(v114, *(__m64 *)&_L001table[4 * v4 + 1]);
      v122 = _m_pxor(v115, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v155.m64_i8[7];
      LOBYTE(v4) = v155.m64_i8[6];
      v123 = _m_pxor(v116, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v124 = _m_pxor(v109, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v156.m64_i8[1];
      LOBYTE(v4) = v156.m64_i8[0];
      v125 = _m_pxor(v118, *(__m64 *)&_L001table[4 * v4]);
      v126 = _m_pxor(v119, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v156.m64_i8[3];
      LOBYTE(v4) = v156.m64_i8[2];
      v127 = _m_pxor(v120, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v128 = _m_pxor(v121, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v156.m64_i8[5];
      LOBYTE(v4) = v156.m64_i8[4];
      v129 = _m_pxor(v122, *(__m64 *)&_L001table[4 * v4 + 1]);
      v130 = _m_pxor(v123, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v156.m64_i8[7];
      LOBYTE(v4) = v156.m64_i8[6];
      v131 = _m_pxor(v124, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v132 = _m_pxor(v117, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      LOBYTE(v5) = v157.m64_i8[1];
      LOBYTE(v4) = v157.m64_i8[0];
      v133 = _m_pxor(v126, *(__m64 *)&_L001table[4 * v4]);
      v134 = _m_pxor(v127, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 3));
      LOBYTE(v5) = v157.m64_i8[3];
      LOBYTE(v4) = v157.m64_i8[2];
      v135 = _m_pxor(v128, *(__m64 *)((char *)&_L001table[4 * v4 + 1] + 2));
      v136 = _m_pxor(v129, *(__m64 *)((char *)&_L001table[4 * v5 + 1] + 1));
      LOBYTE(v5) = v157.m64_i8[5];
      LOBYTE(v4) = v157.m64_i8[4];
      v137 = _m_pxor(v130, *(__m64 *)&_L001table[4 * v4 + 1]);
      v138 = _m_pxor(v131, *(__m64 *)((char *)&_L001table[4 * v5] + 3));
      LOBYTE(v5) = v157.m64_i8[7];
      LOBYTE(v4) = v157.m64_i8[6];
      v139 = _m_pxor(v132, *(__m64 *)((char *)&_L001table[4 * v4] + 2));
      v140 = _m_pxor(v125, *(__m64 *)((char *)&_L001table[4 * v5] + 1));
      v14 = v160 + 1;
      if ( v160 == 9 )
        break;
      ++v160;
      v150 = v134;
      v151 = v135;
      v152 = v136;
      v153 = v137;
      v154 = v138;
      v155 = v139;
      v156 = v140;
      v157 = v133;
    }
    m64_u64 = _m_pxor(_m_pxor(v134, (__m64)v158->m64_u64), (__m64)a1->m64_u64);
    v7 = _m_pxor(_m_pxor(v135, v158[1]), a1[1]);
    v8 = _m_pxor(_m_pxor(v136, v158[2]), a1[2]);
    v9 = _m_pxor(_m_pxor(v137, v158[3]), a1[3]);
    v10 = _m_pxor(_m_pxor(v138, v158[4]), a1[4]);
    v11 = _m_pxor(_m_pxor(v139, v158[5]), a1[5]);
    v12 = _m_pxor(_m_pxor(v140, v158[6]), a1[6]);
    v13 = _m_pxor(_m_pxor(v133, v158[7]), a1[7]);
    a1->m64_u64 = (unsigned __int64)m64_u64;
    a1[1].m64_u64 = (unsigned __int64)v7;
    a1[2].m64_u64 = (unsigned __int64)v8;
    a1[3].m64_u64 = (unsigned __int64)v9;
    a1[4].m64_u64 = (unsigned __int64)v10;
    a1[5].m64_u64 = (unsigned __int64)v11;
    a1[6].m64_u64 = (unsigned __int64)v12;
    a1[7].m64_u64 = (unsigned __int64)v13;
    v3 = v158 + 8;
    result = a3 - 1;
    if ( a3 == 1 )
      break;
    v158 += 8;
    --a3;
  }
  _m_empty();
  return result;
}

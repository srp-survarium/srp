int __cdecl bn_mul_mont(int a1, unsigned int *a2, unsigned int *a3, unsigned int *a4, unsigned int *a5, int a6)
{
  int result; // eax
  int *v7; // esp
  void *v8; // esp
  void *v9; // esp
  unsigned int v10; // esi
  int v11; // ebx
  __m64 v12; // mm7
  unsigned int *v13; // esi
  unsigned int *v14; // edi
  unsigned int *v15; // ebp
  __m64 v16; // mm4
  __m64 v17; // mm2
  __m64 v18; // mm5
  __m64 v19; // mm3
  __m64 v20; // mm1
  __m64 v21; // mm0
  __m64 v22; // mm2
  __m64 v23; // mm3
  int v24; // ecx
  __m64 v25; // mm2
  __m64 v26; // mm3
  __m64 v27; // mm3
  __m64 v28; // mm2
  __m64 v29; // mm3
  int v30; // edx
  __m64 v31; // mm4
  __m64 v32; // mm2
  __m64 v33; // mm5
  __m64 v34; // mm1
  __m64 v35; // mm0
  __m64 v36; // mm3
  __m64 v37; // mm2
  int v38; // ecx
  int v39; // ebx
  __m64 v40; // mm2
  __m64 v41; // mm3
  __m64 v42; // mm6
  __m64 v43; // mm3
  __m64 v44; // mm2
  __m64 v45; // mm3
  unsigned int *v46; // esi
  int v47; // ecx
  unsigned int v48; // edi
  unsigned int v49; // eax
  unsigned int v50; // edx
  int v51; // kr28_4
  unsigned __int64 v52; // rax
  unsigned int *v53; // esi
  unsigned int v54; // edi
  unsigned __int64 v55; // rax
  unsigned int v56; // eax
  int v57; // edx
  int i; // ecx
  unsigned int v59; // ebp
  unsigned __int64 v60; // rax
  unsigned int v61; // kr00_4
  int v62; // ecx
  unsigned int v63; // kr04_4
  unsigned int v64; // eax
  unsigned int v65; // edx
  unsigned int v66; // edx
  unsigned int v67; // kr38_4
  unsigned int v68; // eax
  unsigned __int64 v69; // rax
  int v70; // ebp
  unsigned __int64 v71; // rax
  unsigned int v72; // kr08_4
  unsigned int v73; // kr0C_4
  int v74; // ebp
  unsigned __int64 v75; // rax
  unsigned __int64 v76; // kr50_8
  unsigned __int64 v77; // kr58_8
  unsigned int *v78; // ecx
  bool v79; // zf
  unsigned int v80; // edi
  unsigned int *v81; // esi
  unsigned __int64 v82; // rax
  int v83; // ebx
  int v84; // ecx
  unsigned int v85; // ebp
  unsigned __int64 v86; // rax
  int v87; // ebp
  bool v88; // cc
  unsigned __int64 v89; // rax
  unsigned int *v90; // esi
  unsigned int v91; // edi
  unsigned int v92; // ebp
  unsigned int v93; // edx
  unsigned int v94; // eax
  int j; // ecx
  unsigned int v96; // ebp
  unsigned __int64 v97; // rax
  unsigned int v98; // kr10_4
  unsigned int v99; // ebp
  unsigned __int64 v100; // rax
  unsigned int v101; // kr14_4
  unsigned int v102; // kr18_4
  unsigned int v103; // ebp
  unsigned __int64 v104; // rax
  unsigned __int64 v105; // kr80_8
  unsigned int *v106; // ecx
  unsigned int *v107; // esi
  unsigned __int64 v108; // kr88_8
  unsigned int v109; // edi
  unsigned int *v110; // ecx
  unsigned __int64 v111; // rax
  unsigned int v112; // ebp
  int v113; // ecx
  char v114; // bl
  int v115; // ebx
  int v116; // ebp
  unsigned int v117; // kr24_4
  unsigned __int64 v118; // kr90_8
  unsigned int v119; // ebp
  unsigned int *v120; // ebp
  int v121; // edi
  unsigned int v122; // eax
  signed int v123; // ecx
  bool v124; // cf
  int v125; // edx
  unsigned int v126; // ett
  int v127; // [esp+0h] [ebp-30h] BYREF
  int v128; // [esp+4h] [ebp-2Ch]
  unsigned int *v129; // [esp+8h] [ebp-28h]
  unsigned int *v130; // [esp+Ch] [ebp-24h]
  unsigned int *v131; // [esp+10h] [ebp-20h]
  __m64 v132; // [esp+14h] [ebp-1Ch]
  int v133; // [esp+1Ch] [ebp-14h]
  unsigned int v134; // [esp+20h] [ebp-10h] BYREF
  unsigned int v135[3]; // [esp+24h] [ebp-Ch]

  result = 0;
  if ( a6 >= 4 )
  {
    v7 = &v127 - a6 - 2;
    v8 = alloca(((_WORD)v7 - (unsigned __int16)&a2) & 0x7FF);
    v9 = alloca(((unsigned __int16)v8 ^ (unsigned __int16)&a2) & 0x800 ^ 0x800);
    v10 = *a5;
    v128 = a1;
    v129 = a2;
    v130 = a3;
    v131 = a4;
    v132.m64_u64 = __PAIR64__(&v134, v10);
    v11 = a6 - 1;
    if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 0x1Au) )
    {
      v12 = _mm_cvtsi32_si64(0xFFFFFFFF);
      v13 = v129;
      v14 = v130;
      v15 = v131;
      v16 = _mm_cvtsi32_si64(*v130);
      v17 = _mm_mul_su64(_mm_cvtsi32_si64(*v129), v16);
      v18 = _mm_mul_su64(v17, v132);
      v19 = _mm_add_si64(_mm_mul_su64(_mm_cvtsi32_si64(*v131), v18), _m_pand(v17, v12));
      v20 = _mm_cvtsi32_si64(v131[1]);
      v21 = _mm_cvtsi32_si64(v129[1]);
      v22 = _m_psrlqi(v17, 0x20u);
      v23 = _m_psrlqi(v19, 0x20u);
      v24 = 1;
      do
      {
        v25 = _mm_add_si64(v22, _mm_mul_su64(v21, v16));
        v26 = _mm_add_si64(v23, _mm_mul_su64(v20, v18));
        v20 = _mm_cvtsi32_si64(v15[v24 + 1]);
        v27 = _mm_add_si64(v26, _m_pand(v25, v12));
        v21 = _mm_cvtsi32_si64(v13[v24 + 1]);
        v22 = _m_psrlqi(v25, 0x20u);
        *(&v133 + v24) = _mm_cvtsi64_si32(v27);
        v23 = _m_psrlqi(v27, 0x20u);
        ++v24;
      }
      while ( v24 < v11 );
      v28 = _mm_add_si64(v22, _mm_mul_su64(v21, v16));
      v29 = _mm_add_si64(_mm_add_si64(v23, _mm_mul_su64(v20, v18)), _m_pand(v28, v12));
      *(&v133 + v24) = _mm_cvtsi64_si32(v29);
      *(__m64 *)&v135[v11 - 1] = _mm_add_si64(_m_psrlqi(v29, 0x20u), _m_psrlqi(v28, 0x20u));
      v30 = 1;
      do
      {
        v31 = _mm_cvtsi32_si64(v14[v30]);
        v32 = _mm_add_si64(_mm_mul_su64(_mm_cvtsi32_si64(*v13), v31), _mm_cvtsi32_si64(v134));
        v33 = _mm_mul_su64(v32, v132);
        v34 = _mm_cvtsi32_si64(v15[1]);
        v35 = _mm_cvtsi32_si64(v13[1]);
        v36 = _m_psrlqi(_mm_add_si64(_mm_mul_su64(_mm_cvtsi32_si64(*v15), v33), _m_pand(v32, v12)), 0x20u);
        v37 = _mm_add_si64(_m_psrlqi(v32, 0x20u), _mm_cvtsi32_si64(v135[0]));
        v38 = 1;
        v39 = v11 - 1;
        do
        {
          v40 = _mm_add_si64(v37, _mm_mul_su64(v35, v31));
          v41 = _mm_add_si64(v36, _mm_mul_su64(v34, v33));
          v42 = _mm_cvtsi32_si64(v135[v38]);
          v34 = _mm_cvtsi32_si64(v15[v38 + 1]);
          v43 = _mm_add_si64(v41, _m_pand(v40, v12));
          v35 = _mm_cvtsi32_si64(v13[v38 + 1]);
          *(&v133 + v38) = _mm_cvtsi64_si32(v43);
          v36 = _m_psrlqi(v43, 0x20u);
          v37 = _mm_add_si64(_m_psrlqi(v40, 0x20u), v42);
          --v39;
          ++v38;
        }
        while ( v39 );
        v11 = v38;
        v44 = _mm_add_si64(v37, _mm_mul_su64(v35, v31));
        v45 = _mm_add_si64(_mm_add_si64(v36, _mm_mul_su64(v34, v33)), _m_pand(v44, v12));
        *(&v133 + v38) = _mm_cvtsi64_si32(v45);
        *(__m64 *)&v135[v38 - 1] = _mm_add_si64(
                                     _mm_add_si64(_m_psrlqi(v45, 0x20u), _m_psrlqi(v44, 0x20u)),
                                     _mm_cvtsi32_si64(v135[v38]));
        ++v30;
      }
      while ( v30 <= v38 );
      _m_empty();
    }
    else
    {
      v46 = v129;
      v47 = 0;
      v48 = *v130;
      if ( ((char *)v129 - (char *)v130) | a6 & 1 )
      {
        v133 = (int)&v130[v11 + 1];
        v49 = *v129;
        v50 = 0;
        do
        {
          ++v47;
          v51 = v48 * v49 + v50;
          v50 = (v48 * (unsigned __int64)v49 + v50) >> 32;
          v49 = v46[v47];
          *(&v133 + v47) = v51;
        }
        while ( v47 < v11 );
        v53 = v131;
        v52 = v50 + v48 * (unsigned __int64)v49;
        v54 = v134 * v132.m64_i32[0];
        v135[v11 - 1] = v52;
        v135[v11] = HIDWORD(v52);
        v135[v11 + 1] = 0;
        v55 = v54 * (unsigned __int64)*v53;
        v124 = __CFADD__(v134, (_DWORD)v55);
        v56 = v53[1];
        v57 = v124 + HIDWORD(v55);
        for ( i = 1; ; i = 1 )
        {
          do
          {
            v70 = v57;
            v71 = v54 * (unsigned __int64)v56;
            v72 = v135[i++ - 1];
            v73 = v71;
            v56 = v53[i];
            v57 = (__PAIR64__(HIDWORD(v71), v72) + (unsigned int)v70 + v73) >> 32;
            v132.m64_i32[i + 1] = v72 + v70 + v73;
          }
          while ( i < v11 );
          v74 = v57;
          v75 = v54 * (unsigned __int64)v56;
          HIDWORD(v75) = (v135[v11 - 1] + __PAIR64__(HIDWORD(v75), v74)) >> 32;
          v76 = v75 + v135[v11 - 1] + v74;
          *(&v133 + v11) = v76;
          v77 = __PAIR64__(v135[v11 + 1], v135[v11]) + HIDWORD(v76);
          v78 = v130 + 1;
          v135[v11 - 1] = v77;
          v79 = v78 == (unsigned int *)v133;
          v135[v11] = HIDWORD(v77);
          if ( v79 )
            break;
          v80 = *v78;
          v81 = v129;
          v130 = v78;
          v62 = 0;
          v65 = 0;
          v64 = *v129;
          do
          {
            v59 = v65;
            v60 = v80 * (unsigned __int64)v64;
            v61 = v135[v62++ - 1];
            v63 = v60;
            v64 = v81[v62];
            v65 = (__PAIR64__(HIDWORD(v60), v61) + v59 + v63) >> 32;
            *(&v133 + v62) = v61 + v59 + v63;
          }
          while ( v62 < v11 );
          v53 = v131;
          v67 = v135[v11 - 1] + v80 * v64 + v65;
          v66 = (v135[v11 - 1] + v80 * (unsigned __int64)v64 + __PAIR64__(v135[v11], v65)) >> 32;
          v54 = v134 * v132.m64_i32[0];
          v124 = __CFADD__(v135[v11], v66);
          v135[v11 - 1] = v67;
          v68 = *v53;
          v135[v11] = v66;
          v135[v11 + 1] = v124;
          v69 = v54 * (unsigned __int64)v68;
          v124 = __CFADD__(v134, (_DWORD)v69);
          v56 = v53[1];
          v57 = v124 + HIDWORD(v69);
        }
      }
      else
      {
        v127 = a6 - 1;
        v130 = 0;
        v134 = v48 * v48;
        HIDWORD(v82) = (unsigned int)((v48 * (unsigned __int64)v48) >> 32) >> 1;
        v83 = ((v48 * (unsigned __int64)v48) >> 32) & 1;
        v84 = 1;
        do
        {
          v85 = HIDWORD(v82);
          v86 = v48 * (unsigned __int64)v46[v84++];
          v82 = v85 + v86;
          v87 = v83 + 2 * v82;
          v88 = v84 < v127;
          v83 = (unsigned int)v82 >> 31;
          *(&v133 + v84) = v87;
        }
        while ( v88 );
        v89 = HIDWORD(v82) + v48 * (unsigned __int64)v46[v84];
        v90 = v131;
        v91 = v134 * v132.m64_i32[0];
        v135[v84 - 1] = v83 + 2 * v89;
        v92 = ((unsigned int)v89 >> 31) + 2 * HIDWORD(v89);
        LODWORD(v89) = *v90;
        v135[v84] = v92;
        v135[v84 + 1] = HIDWORD(v89) >> 31;
        v11 = v84;
        v93 = __CFADD__(v134, v91 * v89) + ((v91 * (unsigned __int64)(unsigned int)v89) >> 32);
        v94 = v90[1];
        for ( j = 1; ; j = 1 )
        {
          do
          {
            v96 = v93;
            v97 = v91 * (unsigned __int64)v94;
            v98 = v97;
            LODWORD(v97) = v90[j + 1];
            HIDWORD(v97) = (v135[j - 1] + __PAIR64__(HIDWORD(v97), v96) + v98) >> 32;
            *(&v133 + j) = v135[j - 1] + v96 + v98;
            v99 = HIDWORD(v97);
            v100 = v91 * (unsigned __int64)(unsigned int)v97;
            v101 = v135[j];
            j += 2;
            v102 = v100;
            v94 = v90[j];
            v93 = (__PAIR64__(HIDWORD(v100), v101) + v99 + v102) >> 32;
            v132.m64_i32[j + 1] = v101 + v99 + v102;
          }
          while ( j < v11 );
          v103 = v93;
          v104 = v91 * (unsigned __int64)v94;
          HIDWORD(v104) = (v135[v11 - 1] + __PAIR64__(HIDWORD(v104), v103)) >> 32;
          v105 = v104 + v135[v11 - 1] + v103;
          *(&v133 + v11) = v105;
          v106 = v130;
          v107 = v129;
          v108 = __PAIR64__(v135[v11 + 1], v135[v11]) + HIDWORD(v105);
          v135[v11 - 1] = v108;
          v135[v11] = HIDWORD(v108);
          if ( v106 == (unsigned int *)v11 )
            break;
          v109 = v107[(_DWORD)v106 + 1];
          v110 = (unsigned int *)((char *)v106 + 1);
          v130 = v110;
          v111 = v135[(_DWORD)v110 - 1] + v109 * (unsigned __int64)v109;
          v135[(_DWORD)v110 - 1] = v111;
          v112 = 0;
          v79 = v110 == (unsigned int *)v11;
          v113 = (int)v110 + 1;
          if ( !v79 )
          {
            v114 = BYTE4(v111);
            HIDWORD(v111) >>= 1;
            v115 = v114 & 1;
            do
            {
              v116 = 2 * (HIDWORD(v111) + v109 * v107[v113]);
              v111 = v109 * (unsigned __int64)v107[v113] + HIDWORD(v111);
              v117 = v135[v113++ - 1];
              v118 = (unsigned int)v115 + __PAIR64__((unsigned int)v111 >> 31, v117) + (unsigned int)v116;
              v88 = v113 <= v127;
              *(&v133 + v113) = v118;
              v115 = HIDWORD(v118);
            }
            while ( v88 );
            v112 = (HIDWORD(v118) + __PAIR64__(HIDWORD(v111) >> 31, 2 * HIDWORD(v111))) >> 32;
            HIDWORD(v111) = HIDWORD(v118) + 2 * HIDWORD(v111);
          }
          v90 = v131;
          v91 = v134 * v132.m64_i32[0];
          LODWORD(v111) = *v131;
          v119 = (__PAIR64__(v112, v135[v113 - 1]) + HIDWORD(v111)) >> 32;
          v135[v113 - 1] += HIDWORD(v111);
          v135[v113] = v119;
          v11 = v113 - 1;
          v93 = __CFADD__(v134, v91 * v111) + ((v91 * (unsigned __int64)(unsigned int)v111) >> 32);
          v94 = v90[1];
        }
      }
    }
    v120 = v131;
    v121 = v128;
    v122 = v134;
    v123 = v11;
    v125 = 0;
    v124 = 0;
    do
    {
      v126 = v124 + v120[v125];
      v124 = v122 < v126;
      *(_DWORD *)(v121 + 4 * v125) = v122 - v126;
      v88 = v123-- < 1;
      v122 = v135[v125++];
    }
    while ( !v88 );
    do
    {
      *(_DWORD *)(v121 + 4 * v11) = *(_DWORD *)((~(v122 - v124) & v121 | (v122 - v124) & (unsigned int)&v134) + 4 * v11);
      v135[v11 - 1] = v123;
      v88 = v11-- < 1;
    }
    while ( !v88 );
    return 1;
  }
  return result;
}

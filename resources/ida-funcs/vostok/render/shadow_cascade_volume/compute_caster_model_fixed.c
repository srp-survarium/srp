void __userpurge vostok::render::shadow_cascade_volume::compute_caster_model_fixed(
        vostok::render::shadow_cascade_volume *this@<ecx>,
        float a2@<edi>,
        float *a3@<esi>,
        vostok::fixed_vector<vostok::math::plane,16> *dest,
        vostok::math::float3 *translation,
        float map_size,
        bool clip_by_view_near)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  signed int v10; // ecx
  unsigned int v11; // eax
  float *v12; // edx
  float v13; // ebx
  float y; // xmm4_4
  float z; // xmm5_4
  float v16; // xmm6_4
  int v17; // edi
  float v18; // xmm0_4
  unsigned int v19; // edx
  int v20; // ecx
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  int v25; // ecx
  unsigned int v26; // eax
  float v27; // ebx
  float v28; // ebx
  float v29; // ebx
  float v30; // ebx
  int v31; // eax
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  int v36; // ecx
  unsigned int v37; // eax
  float v38; // edx
  int v39; // eax
  float v40; // xmm4_4
  float v41; // xmm5_4
  signed int v42; // ebx
  bool v43; // cc
  float x; // xmm6_4
  float v45; // xmm4_4
  float v46; // xmm5_4
  int v47; // edi
  float v48; // xmm1_4
  float *v49; // eax
  float *v50; // ecx
  int v51; // edx
  float v52; // xmm2_4
  float v53; // xmm4_4
  float v54; // xmm0_4
  float v55; // xmm5_4
  float v56; // xmm7_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm3_4
  float v60; // xmm5_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // xmm6_4
  float v64; // xmm7_4
  float v65; // xmm3_4
  float v66; // xmm5_4
  float v67; // xmm4_4
  int v68; // eax
  float v69; // xmm0_4
  float v70; // xmm2_4
  float v71; // xmm3_4
  float *v72; // eax
  float v73; // xmm0_4
  float v74; // xmm0_4
  float v75; // xmm5_4
  float v76; // ecx
  float v77; // xmm3_4
  float v78; // xmm2_4
  float v79; // xmm4_4
  float v80; // xmm0_4
  float v81; // xmm3_4
  float v82; // xmm2_4
  float v83; // edi
  int v84; // ecx
  int v85; // ebx
  float v86; // xmm6_4
  float v87; // xmm4_4
  float v88; // xmm2_4
  unsigned int v89; // xmm0_4
  float v90; // xmm6_4
  float v91; // xmm1_4
  unsigned int v92; // xmm2_4
  float v93; // xmm3_4
  float v94; // xmm2_4
  float v95; // xmm1_4
  vostok::math::plane *m_end; // eax
  int v97; // ecx
  float v98; // xmm5_4
  float v99; // xmm4_4
  float v100; // xmm6_4
  float v101; // xmm1_4
  float v102; // xmm0_4
  float v103; // xmm2_4
  float v104; // xmm3_4
  unsigned int v105; // xmm4_4
  float v106; // xmm6_4
  unsigned int v107; // xmm2_4
  long double v108; // st7
  float v109; // xmm1_4
  float v110; // ebx
  float v111; // xmm6_4
  unsigned int v112; // edi
  int v113; // ecx
  float v114; // xmm3_4
  float v115; // xmm2_4
  float v116; // xmm4_4
  float v117; // xmm0_4
  float v118; // xmm0_4
  unsigned int v119; // eax
  unsigned int v120; // edx
  float *v121; // ecx
  float *v122; // edx
  unsigned int v123; // ecx
  unsigned int v124; // edx
  float v125; // ecx
  float v126; // xmm7_4
  float v127; // edi
  float v128; // xmm7_4
  vostok::math::plane *v129; // eax
  vostok::math::plane *v130; // ecx
  bool v131; // zf
  vostok::math::plane *v132; // ecx
  vostok::math::plane *v133; // ecx
  vostok::math::plane *v134; // ecx
  vostok::math::plane *v135; // eax
  float v136; // ecx
  unsigned int v137; // ebx
  float v138; // xmm5_4
  float v139; // xmm0_4
  int v140; // edi
  float v141; // xmm3_4
  float v142; // xmm4_4
  float v143; // xmm2_4
  float v144; // xmm1_4
  float v145; // xmm3_4
  float v146; // xmm4_4
  float v147; // xmm2_4
  float v148; // xmm1_4
  float v149; // xmm3_4
  float v150; // xmm4_4
  float v151; // xmm2_4
  float v152; // xmm1_4
  float v153; // xmm3_4
  float v154; // xmm4_4
  float v155; // xmm2_4
  float v156; // xmm1_4
  float v157; // xmm4_4
  float v158; // xmm3_4
  float v159; // xmm2_4
  float v160; // [esp+4h] [ebp-58h]
  float sign; // [esp+Ch] [ebp-50h] BYREF
  unsigned int i; // [esp+10h] [ebp-4Ch]
  float v163; // [esp+14h] [ebp-48h]
  float plane_dot_ray; // [esp+18h] [ebp-44h]
  float v165; // [esp+1Ch] [ebp-40h]
  float dist; // [esp+20h] [ebp-3Ch]
  vostok::math::plane tmp_plane; // [esp+24h] [ebp-38h] BYREF
  vostok::math::float3 origin; // [esp+34h] [ebp-28h]
  vostok::math::float3 perp_light_to_view; // [esp+40h] [ebp-1Ch] BYREF
  vostok::math::plane plane; // [esp+4Ch] [ebp-10h]

  *(_QWORD *)&translation->x = 0;
  translation->z = 0.0;
  *(float *)&i = fabs(
                   *(float *)&clear_value
                 - COERCE_FLOAT(
                     COERCE_UNSIGNED_INT((float)((float)(a3[58] * a3[52]) + (float)(a3[57] * a3[51])) + (float)(a3[56] * a3[50]))
                   & _mask__AbsFloat_));
  v160 = a2;
  if ( *(float *)&i < 0.0000001 )
    return;
  vostok::render::shadow_cascade_volume::compute_planes(this, (vostok::render::shadow_cascade_volume *)a3);
  v7 = a3[52];
  v8 = a3[51];
  v9 = a3[50];
  *(float *)&v10 = 0.0;
  v11 = 0;
  v12 = a3 + 91;
  do
  {
    if ( (float)((float)((float)(*(v12 - 1) * v9) + (float)(v12[1] * v7)) + (float)(v8 * *v12)) > 0.001 )
    {
      *((_DWORD *)&tmp_plane.normal.x + v10++) = v11;
      if ( v10 == 2 )
        break;
    }
    ++v11;
    v12 += 8;
  }
  while ( v11 < 4 );
  v13 = 0.0;
  y = 0.0;
  z = 0.0;
  i = v10;
  v16 = 0.0;
  *(_QWORD *)&perp_light_to_view.elements[1] = 0;
  sign = 0.0;
  if ( v10 > 0 )
  {
    v17 = (*((_DWORD *)a3 + 1) - *(_DWORD *)a3) / 24;
    do
    {
      v18 = 10000.0;
      v19 = 0;
      if ( v17 >= 4 )
      {
        v20 = 8 * *((_DWORD *)&tmp_plane.normal.x + LODWORD(v13));
        v21 = a3[v20 + 91];
        v22 = a3[v20 + 92];
        v23 = a3[v20 + 90];
        v24 = a3[v20 + 93];
        v25 = *(_DWORD *)a3 + 36;
        v26 = ((unsigned int)(v17 - 4) >> 2) + 1;
        v19 = 4 * v26;
        do
        {
          v27 = *(float *)(v25 - 16);
          *(_QWORD *)&origin.x = *(_QWORD *)(v25 - 24);
          origin.z = v27;
          if ( v18 > (float)((float)((float)((float)(origin.x * v23) + (float)(v27 * v22)) + (float)(origin.y * v21))
                           + v24) )
            v18 = (float)((float)((float)(origin.x * v23) + (float)(v27 * v22)) + (float)(origin.y * v21)) + v24;
          v28 = *(float *)(v25 + 8);
          *(_QWORD *)&origin.x = *(_QWORD *)v25;
          origin.z = v28;
          if ( v18 > (float)((float)((float)((float)(origin.x * v23) + (float)(v28 * v22)) + (float)(origin.y * v21))
                           + v24) )
            v18 = (float)((float)((float)(origin.x * v23) + (float)(v28 * v22)) + (float)(origin.y * v21)) + v24;
          v29 = *(float *)(v25 + 32);
          *(_QWORD *)&origin.x = *(_QWORD *)(v25 + 24);
          origin.z = v29;
          if ( v18 > (float)((float)((float)((float)(origin.x * v23) + (float)(v29 * v22)) + (float)(origin.y * v21))
                           + v24) )
            v18 = (float)((float)((float)(origin.x * v23) + (float)(v29 * v22)) + (float)(origin.y * v21)) + v24;
          v30 = *(float *)(v25 + 56);
          *(_QWORD *)&origin.x = *(_QWORD *)(v25 + 48);
          origin.z = v30;
          if ( v18 > (float)((float)((float)((float)(origin.x * v23) + (float)(v30 * v22)) + (float)(origin.y * v21))
                           + v24) )
            v18 = (float)((float)((float)(origin.x * v23) + (float)(v30 * v22)) + (float)(origin.y * v21)) + v24;
          v25 += 96;
          --v26;
        }
        while ( v26 );
        z = perp_light_to_view.z;
        y = perp_light_to_view.y;
        v13 = sign;
      }
      if ( v19 < v17 )
      {
        v31 = 8 * *((_DWORD *)&tmp_plane.normal.x + LODWORD(v13));
        v32 = a3[v31 + 91];
        v33 = a3[v31 + 92];
        v34 = a3[v31 + 90];
        v35 = a3[v31 + 93];
        v36 = *(_DWORD *)a3 + 24 * v19 + 12;
        v37 = v17 - v19;
        do
        {
          v38 = *(float *)(v36 + 8);
          *(_QWORD *)&origin.x = *(_QWORD *)v36;
          origin.z = v38;
          if ( v18 > (float)((float)((float)((float)(origin.x * v34) + (float)(v38 * v33)) + (float)(origin.y * v32))
                           + v35) )
            v18 = (float)((float)((float)(origin.x * v34) + (float)(v38 * v33)) + (float)(origin.y * v32)) + v35;
          v36 += 24;
          --v37;
        }
        while ( v37 );
        z = perp_light_to_view.z;
        y = perp_light_to_view.y;
      }
      v39 = 8 * *((_DWORD *)&tmp_plane.normal.x + LODWORD(v13)++);
      y = (float)(a3[v39 + 91] * v18) + y;
      z = (float)(a3[v39 + 92] * v18) + z;
      v16 = (float)(a3[v39 + 90] * v18) + v16;
      *(_QWORD *)&perp_light_to_view.elements[1] = __PAIR64__(LODWORD(z), LODWORD(y));
      sign = v13;
    }
    while ( SLODWORD(v13) < (int)i );
  }
  translation->x = translation->x + v16;
  translation->y = y + translation->y;
  translation->z = z + translation->z;
  v40 = y + a3[60];
  v41 = z + a3[61];
  v42 = 0;
  v43 = (int)i <= 0;
  a3[59] = v16 + a3[59];
  a3[60] = v40;
  a3[61] = v41;
  x = 0.0;
  v45 = 0.0;
  v46 = 0.0;
  memset(&perp_light_to_view, 0, sizeof(perp_light_to_view));
  if ( !v43 )
  {
    v47 = (*((_DWORD *)a3 + 1) - *(_DWORD *)a3) / 24;
    do
    {
      v48 = 0.0;
      sign = 0.0;
      if ( v47 )
      {
        v49 = *(float **)a3;
        v50 = &a3[8 * *((_DWORD *)&tmp_plane.normal.x + v42) + 90];
        v51 = v47;
        do
        {
          v52 = v49[2];
          v53 = *v49;
          v54 = v50[1] * v49[1];
          v163 = v49[1];
          plane_dot_ray = (float)(v54 + (float)(v50[2] * v52)) + (float)(v53 * *v50);
          if ( plane_dot_ray < 0.0 )
          {
            v55 = v50[1];
            v56 = v50[2];
            v57 = (float)(a3[52] * v55) - (float)(a3[51] * v56);
            v58 = (float)(a3[50] * v56) - (float)(*v50 * a3[52]);
            v59 = a3[50] * v55;
            v60 = a3[52];
            v61 = (float)(*v50 * a3[51]) - v59;
            v62 = a3[51];
            v63 = (float)(v58 * v60) - (float)(v61 * v62);
            v64 = a3[50];
            v65 = (float)(v62 * v57) - (float)(v58 * v64);
            v66 = v60 * v57;
            v48 = sign;
            v67 = (float)((float)(v53 * v63) + (float)(v163 * (float)((float)(v61 * v64) - v66)))
                + (float)(v65 * v49[2]);
            if ( (float)((float)(-1.0 / v67) * plane_dot_ray) > sign )
            {
              v48 = (float)(-1.0 / v67) * plane_dot_ray;
              sign = v48;
            }
          }
          v49 += 6;
          --v51;
        }
        while ( v51 );
        x = perp_light_to_view.x;
        v45 = perp_light_to_view.y;
        v46 = perp_light_to_view.z;
      }
      v165 = v48;
      LODWORD(dist) = LODWORD(v48) & 0x7FFFFFFF;
      if ( COERCE_FLOAT(LODWORD(v48) & 0x7FFFFFFF) >= 0.0000099999997 )
      {
        v68 = 8 * *((_DWORD *)&tmp_plane.normal.x + v42);
        v69 = a3[v68 + 92];
        v70 = a3[v68 + 91] * translation->y;
        v71 = v69;
        v72 = &a3[v68 + 90];
        v73 = (float)-(float)((float)((float)(v69 * translation->z) + v70) + (float)(translation->x * *v72)) * v48;
        x = (float)(*v72 * v73) + x;
        v45 = (float)(v72[1] * v73) + v45;
        v46 = (float)(v71 * v73) + v46;
        *(_QWORD *)&perp_light_to_view.x = __PAIR64__(LODWORD(v45), LODWORD(x));
        perp_light_to_view.z = v46;
      }
      ++v42;
    }
    while ( v42 < (int)i );
  }
  translation->x = translation->x + x;
  translation->y = v45 + translation->y;
  translation->z = v46 + translation->z;
  v74 = a3[59];
  v75 = v46 + a3[61];
  a3[60] = v45 + a3[60];
  a3[61] = v75;
  a3[59] = v74 + x;
  v76 = translation->z;
  v77 = a3[91];
  v78 = a3[92];
  v79 = a3[90];
  *(_QWORD *)&perp_light_to_view.x = *(_QWORD *)&translation->x;
  v80 = perp_light_to_view.y;
  perp_light_to_view.z = v76;
  v81 = (float)(v77 * perp_light_to_view.y) + (float)(v78 * v76);
  v82 = perp_light_to_view.x;
  a3[93] = a3[93] - (float)(v81 + (float)(v79 * perp_light_to_view.x));
  a3[101] = a3[101] - (float)((float)((float)(a3[99] * v80) + (float)(a3[100] * v76)) + (float)(a3[98] * v82));
  a3[109] = a3[109] - (float)((float)((float)(a3[107] * v80) + (float)(a3[108] * v76)) + (float)(a3[106] * v82));
  a3[117] = a3[117] - (float)((float)((float)(a3[115] * v80) + (float)(a3[116] * v76)) + (float)(a3[114] * v82));
  v83 = *a3;
  v84 = *((_DWORD *)a3 + 1) - *(_DWORD *)a3;
  *(float *)&i = 0.0;
  if ( v84 / 24 )
  {
    v85 = 0;
    do
    {
      v86 = *(float *)(LODWORD(v83) + v85 + 8);
      v87 = *(float *)(LODWORD(v83) + v85 + 4);
      v88 = a3[56] * v86;
      *(float *)&v89 = (float)(a3[58] * v87) - (float)(a3[57] * v86);
      v90 = *(float *)(LODWORD(v83) + v85);
      v91 = (float)(v90 * a3[57]) - (float)(a3[56] * v87);
      *(float *)&v92 = v88 - (float)(v90 * a3[58]);
      *(_QWORD *)&origin.x = __PAIR64__(v92, v89);
      origin.z = v91;
      *(_QWORD *)&perp_light_to_view.x = __PAIR64__(v92, v89);
      dist = (float)((float)(v91 * v91) + (float)(*(float *)&v92 * *(float *)&v92))
           + (float)(*(float *)&v89 * *(float *)&v89);
      v165 = fabs(dist);
      perp_light_to_view.z = v91;
      plane_dot_ray = dist;
      if ( v165 >= 0.0000099999997 )
      {
        v165 = 1.0 / sqrtf(plane_dot_ray);
        perp_light_to_view.x = v165 * origin.x;
        v93 = (float)(v165 * origin.x) * *(float *)(LODWORD(v83) + v85 + 12);
        perp_light_to_view.y = perp_light_to_view.y * v165;
        *(_QWORD *)&tmp_plane.normal.x = *(_QWORD *)&perp_light_to_view.x;
        v94 = *(float *)(LODWORD(v83) + v85 + 20) * (float)(perp_light_to_view.z * v165);
        perp_light_to_view.z = perp_light_to_view.z * v165;
        v95 = *(float *)(LODWORD(v83) + v85 + 16) * perp_light_to_view.y;
        tmp_plane.normal.z = perp_light_to_view.z;
        tmp_plane.d = -(float)((float)(v94 + v95) + v93);
        sign = 0.0;
        if ( vostok::render::shadow_cascade_volume::check_cull_plane_valid(
               (vostok::render::shadow_cascade_volume *)&sign,
               &tmp_plane,
               &sign,
               v160) )
        {
          m_end = dest->m_end;
          tmp_plane.normal.x = COERCE_FLOAT(LODWORD(sign) ^ 0x80000000) * perp_light_to_view.x;
          tmp_plane.normal.y = tmp_plane.normal.y * COERCE_FLOAT(LODWORD(sign) ^ 0x80000000);
          tmp_plane.normal.z = tmp_plane.normal.z * COERCE_FLOAT(LODWORD(sign) ^ 0x80000000);
          tmp_plane.d = -(float)(tmp_plane.d * sign);
          if ( m_end )
            *m_end = tmp_plane;
          ++dest->m_end;
        }
      }
      v83 = *a3;
      v97 = *((_DWORD *)a3 + 1);
      ++i;
      v85 += 24;
    }
    while ( i < (v97 - LODWORD(v83)) / 24 );
  }
  if ( COERCE_FLOAT(
         COERCE_UNSIGNED_INT((float)((float)(a3[52] * a3[58]) + (float)(a3[51] * a3[57])) + (float)(a3[50] * a3[56]))
       & _mask__AbsFloat_) < 0.8 )
  {
    v98 = a3[58];
    v99 = a3[51];
    v100 = a3[52];
    v101 = (float)(v98 * v99) - (float)(a3[57] * v100);
    v102 = (float)(a3[56] * v100) - (float)(a3[50] * v98);
    v103 = (float)(a3[50] * a3[57]) - (float)(a3[56] * v99);
    v104 = a3[57];
    *(float *)&v105 = (float)(v102 * v98) - (float)(v103 * v104);
    v106 = a3[56];
    *(float *)&v107 = (float)(v103 * v106) - (float)(v98 * v101);
    *(_QWORD *)&origin.x = __PAIR64__(v107, v105);
    *(_QWORD *)&perp_light_to_view.x = __PAIR64__(v107, v105);
    origin.z = (float)(v104 * v101) - (float)(v102 * v106);
    perp_light_to_view.z = origin.z;
    v108 = sqrtf(
             (float)((float)(*(float *)&v105 * *(float *)&v105) + (float)(origin.z * origin.z))
           + (float)(*(float *)&v107 * *(float *)&v107));
    v109 = a3[54];
    v110 = *a3;
    v111 = -1000.0;
    v112 = 0;
    v113 = *((_DWORD *)a3 + 1) - *(_DWORD *)a3;
    dist = 1.0 / v108;
    v114 = perp_light_to_view.y * dist;
    v115 = dist * origin.x;
    v116 = perp_light_to_view.z * dist;
    v117 = (float)(a3[55] * (float)(perp_light_to_view.z * dist)) + (float)(v109 * (float)(perp_light_to_view.y * dist));
    perp_light_to_view.z = perp_light_to_view.z * dist;
    v118 = -(float)(v117 + (float)((float)(dist * origin.x) * a3[53]));
    perp_light_to_view.x = dist * origin.x;
    perp_light_to_view.y = perp_light_to_view.y * dist;
    plane.normal.z = perp_light_to_view.z;
    v119 = v113 / 24;
    if ( v113 / 24 >= 4 )
    {
      v120 = ((v119 - 4) >> 2) + 1;
      v121 = (float *)(LODWORD(v110) + 20);
      v112 = 4 * v120;
      do
      {
        if ( (float)((float)((float)((float)(*(v121 - 2) * v115) + (float)(*(v121 - 1) * v114)) + (float)(v116 * *v121))
                   + v118) > v111 )
          v111 = (float)((float)((float)(*(v121 - 2) * v115) + (float)(*(v121 - 1) * v114)) + (float)(v116 * *v121))
               + v118;
        if ( (float)((float)((float)((float)(v121[4] * v115) + (float)(v121[6] * v116)) + (float)(v121[5] * v114)) + v118) > v111 )
          v111 = (float)((float)((float)(v121[4] * v115) + (float)(v121[6] * v116)) + (float)(v121[5] * v114)) + v118;
        if ( (float)((float)((float)((float)(v121[10] * v115) + (float)(v121[12] * v116)) + (float)(v121[11] * v114))
                   + v118) > v111 )
          v111 = (float)((float)((float)(v121[10] * v115) + (float)(v121[12] * v116)) + (float)(v121[11] * v114)) + v118;
        if ( (float)((float)((float)((float)(v121[16] * v115) + (float)(v121[18] * v116)) + (float)(v121[17] * v114))
                   + v118) > v111 )
          v111 = (float)((float)((float)(v121[16] * v115) + (float)(v121[18] * v116)) + (float)(v121[17] * v114)) + v118;
        v121 += 24;
        --v120;
      }
      while ( v120 );
    }
    if ( v112 < v119 )
    {
      v122 = (float *)(LODWORD(v110) + 24 * v112 + 20);
      v123 = v119 - v112;
      do
      {
        if ( (float)((float)((float)((float)(*(v122 - 2) * v115) + (float)(*(v122 - 1) * v114)) + (float)(v116 * *v122))
                   + v118) > v111 )
          v111 = (float)((float)((float)(*(v122 - 2) * v115) + (float)(*(v122 - 1) * v114)) + (float)(v116 * *v122))
               + v118;
        v122 += 6;
        --v123;
      }
      while ( v123 );
    }
    v124 = 0;
    if ( v119 )
    {
      v125 = v110;
      while ( 1 )
      {
        v126 = *(float *)(LODWORD(v125) + 4);
        v127 = *(float *)(LODWORD(v125) + 20);
        *(_QWORD *)&origin.x = *(_QWORD *)(LODWORD(v125) + 12);
        origin.x = (float)(*(float *)LODWORD(v125) * 5.0) + origin.x;
        tmp_plane.normal.y = v126 * 5.0;
        v128 = *(float *)(LODWORD(v125) + 8) * 5.0;
        origin.z = v127;
        if ( (float)((float)((float)((float)((float)(v127 + v128) * v116)
                                   + (float)((float)(origin.y + tmp_plane.normal.y) * v114))
                           + (float)(origin.x * v115))
                   + v118) > v111 )
          break;
        ++v124;
        LODWORD(v125) += 24;
        if ( v124 >= v119 )
          goto LABEL_68;
      }
      v111 = 0.0;
      goto LABEL_69;
    }
LABEL_68:
    if ( v111 > -1000.0 )
    {
LABEL_69:
      v129 = dest->m_end;
      plane.d = v118 + v111;
      if ( v129 )
      {
        *(_QWORD *)&v129->normal.x = *(_QWORD *)&perp_light_to_view.x;
        *(_QWORD *)&v129->vector.elements[2] = *(_QWORD *)&plane.vector.elements[2];
      }
      ++dest->m_end;
    }
  }
  v130 = dest->m_end;
  if ( v130 )
  {
    *(_QWORD *)&v130->normal.x = *((_QWORD *)a3 + 45);
    *(_QWORD *)&v130->vector.elements[2] = *((_QWORD *)a3 + 46);
  }
  v131 = dest->m_end++ == (vostok::math::plane *)-16;
  v132 = dest->m_end;
  v132[-1].normal.x = v132[-1].normal.x * -1.0;
  v132[-1].normal.y = v132[-1].normal.y * -1.0;
  v132[-1].normal.z = v132[-1].normal.z * -1.0;
  v132[-1].d = v132[-1].d * -1.0;
  if ( !v131 )
  {
    *(_QWORD *)&v132->normal.x = *((_QWORD *)a3 + 49);
    *(_QWORD *)&v132->vector.elements[2] = *((_QWORD *)a3 + 50);
  }
  v131 = dest->m_end++ == (vostok::math::plane *)-16;
  v133 = dest->m_end;
  v133[-1].normal.x = v133[-1].normal.x * -1.0;
  v133[-1].normal.y = v133[-1].normal.y * -1.0;
  v133[-1].normal.z = v133[-1].normal.z * -1.0;
  v133[-1].d = v133[-1].d * -1.0;
  if ( !v131 )
  {
    *(_QWORD *)&v133->normal.x = *((_QWORD *)a3 + 53);
    *(_QWORD *)&v133->vector.elements[2] = *((_QWORD *)a3 + 54);
  }
  v131 = dest->m_end++ == (vostok::math::plane *)-16;
  v134 = dest->m_end;
  v134[-1].normal.x = v134[-1].normal.x * -1.0;
  v134[-1].normal.y = v134[-1].normal.y * -1.0;
  v134[-1].normal.z = v134[-1].normal.z * -1.0;
  v134[-1].d = v134[-1].d * -1.0;
  if ( !v131 )
  {
    *(_QWORD *)&v134->normal.x = *((_QWORD *)a3 + 57);
    *(_QWORD *)&v134->vector.elements[2] = *((_QWORD *)a3 + 58);
  }
  v135 = ++dest->m_end;
  v135[-1].normal.x = v135[-1].normal.x * -1.0;
  v135[-1].normal.y = v135[-1].normal.y * -1.0;
  v135[-1].normal.z = v135[-1].normal.z * -1.0;
  v135[-1].d = v135[-1].d * -1.0;
  v136 = *a3;
  v137 = 0;
  if ( (*((_DWORD *)a3 + 1) - *(_DWORD *)a3) / 24 )
  {
    v138 = map_size * 2.0;
    dist = map_size * 2.0;
    v139 = map_size * 2.0;
    v140 = 0;
    while ( 1 )
    {
      if ( (float)((float)((float)(a3[92] * *(float *)(v140 + LODWORD(v136) + 8))
                         + (float)(a3[91] * *(float *)(v140 + LODWORD(v136) + 4)))
                 + (float)(a3[90] * *(float *)(v140 + LODWORD(v136)))) <= -0.1 )
      {
        v141 = a3[92];
        v142 = a3[91];
        v143 = a3[90];
        v144 = (float)((float)(*(float *)(v140 + LODWORD(v136) + 4) * v142)
                     + (float)(*(float *)(v140 + LODWORD(v136) + 8) * v141))
             + (float)(v143 * *(float *)(v140 + LODWORD(v136)));
        sign = v144;
        i = LODWORD(v144) & 0x7FFFFFFF;
        if ( COERCE_FLOAT(LODWORD(v144) & 0x7FFFFFFF) >= 0.0000001 )
          v139 = -(float)((float)((float)((float)((float)(*(float *)(v140 + LODWORD(v136) + 16) * v142)
                                                + (float)(*(float *)(v140 + LODWORD(v136) + 20) * v141))
                                        + (float)(v143 * *(float *)(v140 + LODWORD(v136) + 12)))
                                + a3[93])
                        / v144);
      }
      else
      {
        v139 = map_size;
      }
      if ( v139 > 0.001 && v138 > v139 )
        v138 = v139;
      if ( (float)((float)((float)(a3[100] * *(float *)(v140 + LODWORD(v136) + 8))
                         + (float)(a3[99] * *(float *)(v140 + LODWORD(v136) + 4)))
                 + (float)(a3[98] * *(float *)(v140 + LODWORD(v136)))) <= -0.1 )
      {
        v145 = a3[100];
        v146 = a3[99];
        v147 = a3[98];
        v148 = (float)((float)(*(float *)(v140 + LODWORD(v136) + 4) * v146)
                     + (float)(*(float *)(v140 + LODWORD(v136) + 8) * v145))
             + (float)(v147 * *(float *)(v140 + LODWORD(v136)));
        sign = v148;
        i = LODWORD(v148) & 0x7FFFFFFF;
        if ( COERCE_FLOAT(LODWORD(v148) & 0x7FFFFFFF) >= 0.0000001 )
          v139 = -(float)((float)((float)((float)((float)(*(float *)(v140 + LODWORD(v136) + 16) * v146)
                                                + (float)(*(float *)(v140 + LODWORD(v136) + 20) * v145))
                                        + (float)(v147 * *(float *)(v140 + LODWORD(v136) + 12)))
                                + a3[101])
                        / v148);
      }
      else
      {
        v139 = map_size;
      }
      if ( v139 > 0.001 && v138 > v139 )
        v138 = v139;
      if ( (float)((float)((float)(a3[108] * *(float *)(v140 + LODWORD(v136) + 8))
                         + (float)(a3[107] * *(float *)(v140 + LODWORD(v136) + 4)))
                 + (float)(a3[106] * *(float *)(v140 + LODWORD(v136)))) <= -0.1 )
      {
        v149 = a3[108];
        v150 = a3[107];
        v151 = a3[106];
        v152 = (float)((float)(*(float *)(v140 + LODWORD(v136) + 4) * v150)
                     + (float)(*(float *)(v140 + LODWORD(v136) + 8) * v149))
             + (float)(v151 * *(float *)(v140 + LODWORD(v136)));
        sign = v152;
        i = LODWORD(v152) & 0x7FFFFFFF;
        if ( COERCE_FLOAT(LODWORD(v152) & 0x7FFFFFFF) >= 0.0000001 )
          v139 = -(float)((float)((float)((float)((float)(*(float *)(v140 + LODWORD(v136) + 16) * v150)
                                                + (float)(*(float *)(v140 + LODWORD(v136) + 20) * v149))
                                        + (float)(v151 * *(float *)(v140 + LODWORD(v136) + 12)))
                                + a3[109])
                        / v152);
      }
      else
      {
        v139 = map_size;
      }
      if ( v139 > 0.001 && v138 > v139 )
        v138 = v139;
      if ( (float)((float)((float)(a3[116] * *(float *)(v140 + LODWORD(v136) + 8))
                         + (float)(a3[115] * *(float *)(v140 + LODWORD(v136) + 4)))
                 + (float)(a3[114] * *(float *)(v140 + LODWORD(v136)))) <= -0.1 )
      {
        v153 = a3[116];
        v154 = a3[115];
        v155 = a3[114];
        v156 = (float)((float)(*(float *)(v140 + LODWORD(v136) + 4) * v154)
                     + (float)(*(float *)(v140 + LODWORD(v136) + 8) * v153))
             + (float)(v155 * *(float *)(v140 + LODWORD(v136)));
        sign = v156;
        i = LODWORD(v156) & 0x7FFFFFFF;
        if ( COERCE_FLOAT(LODWORD(v156) & 0x7FFFFFFF) >= 0.0000001 )
          v139 = -(float)((float)((float)((float)((float)(*(float *)(v140 + LODWORD(v136) + 16) * v154)
                                                + (float)(*(float *)(v140 + LODWORD(v136) + 20) * v153))
                                        + (float)(v155 * *(float *)(v140 + LODWORD(v136) + 12)))
                                + a3[117])
                        / v156);
      }
      else
      {
        v139 = map_size;
      }
      if ( v139 > 0.001 && v138 > v139 )
        v138 = v139;
      v157 = *(float *)(v140 + LODWORD(v136) + 12);
      v158 = *(float *)(v140 + LODWORD(v136)) * v138;
      v159 = (float)(*(float *)(v140 + LODWORD(v136) + 8) * v138) + *(float *)(v140 + LODWORD(v136) + 20);
      *(float *)(v140 + LODWORD(v136) + 16) = (float)(*(float *)(v140 + LODWORD(v136) + 4) * v138)
                                            + *(float *)(v140 + LODWORD(v136) + 16);
      *(float *)(v140 + LODWORD(v136) + 20) = v159;
      *(float *)(v140 + LODWORD(v136) + 12) = v157 + v158;
      v136 = *a3;
      ++v137;
      v140 += 24;
      if ( v137 >= (*((_DWORD *)a3 + 1) - *(_DWORD *)a3) / 24 )
        break;
      v138 = dist;
    }
  }
}

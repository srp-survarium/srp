void __userpurge vostok::render::shadow_cascade_volume::compute_caster_model_fixed(
        vostok::render::shadow_cascade_volume *this@<ecx>,
        float *a2@<edi>,
        float a3@<esi>,
        vostok::fixed_vector<vostok::math::plane,16> *dest,
        vostok::math::plane *translation,
        vostok::math::plane map_size)
{
  float x; // esi
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  int v11; // edx
  unsigned int v12; // ecx
  float *v13; // eax
  int v14; // ecx
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm6_4
  float v18; // eax
  float v19; // xmm7_4
  float *v20; // edx
  float v21; // xmm1_4
  float v22; // xmm0_4
  vostok::math::plane *m_begin; // edx
  float *p_d; // edx
  int v25; // eax
  float v26; // xmm3_4
  int v27; // ecx
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // eax
  vostok::math::plane *v31; // edi
  float *v32; // edx
  float v33; // xmm4_4
  float v34; // xmm7_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm4_4
  int v39; // eax
  float *v40; // edx
  float v41; // xmm0_4
  float v42; // xmm0_4
  float *v43; // esi
  float *v44; // eax
  int v45; // ecx
  vostok::math::plane *v46; // ecx
  float *v47; // eax
  float v48; // xmm7_4
  float v49; // xmm4_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  float v52; // xmm7_4
  float v53; // xmm3_4
  float v54; // xmm0_4
  float v55; // xmm3_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm3_4
  float v60; // xmm0_4
  float v61; // xmm2_4
  vostok::buffer_vector<vostok::math::plane> *v62; // ecx
  unsigned int v63; // eax
  float v64; // xmm4_4
  float v65; // xmm6_4
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm6_4
  float v69; // xmm2_4
  float v70; // xmm1_4
  float v71; // xmm4_4
  float v72; // xmm5_4
  vostok::math::plane *m_end; // eax
  float v74; // xmm3_4
  float v75; // xmm6_4
  float v76; // xmm5_4
  float v77; // xmm4_4
  float v78; // xmm1_4
  float v79; // xmm2_4
  float v80; // xmm0_4
  float v81; // xmm4_4
  float v82; // xmm3_4
  float v83; // xmm0_4
  float v84; // xmm3_4
  float v85; // xmm0_4
  unsigned int v86; // eax
  float *p_y; // edx
  unsigned int v88; // esi
  unsigned int v89; // edx
  float v90; // xmm3_4
  float z; // xmm5_4
  float y; // xmm7_4
  vostok::math::plane *v93; // esi
  char *v94; // edi
  float *v95; // eax
  bool v96; // zf
  vostok::math::plane *v97; // edi
  float v98; // xmm3_4
  const vostok::math::float3 *v99; // edi
  vostok::math::plane *v100; // eax
  float v101; // xmm0_4
  float v102; // xmm1_4
  unsigned int v103; // eax
  float *v104; // [esp-Ch] [ebp-48h]
  float v105; // [esp-8h] [ebp-44h]
  float v106; // [esp+4h] [ebp-38h] BYREF
  float v107; // [esp+8h] [ebp-34h]
  float v108; // [esp+Ch] [ebp-30h]
  float v109; // [esp+10h] [ebp-2Ch]
  float d; // [esp+14h] [ebp-28h]
  float v111; // [esp+18h] [ebp-24h]
  float v112; // [esp+1Ch] [ebp-20h]
  float v113; // [esp+20h] [ebp-1Ch]
  float v114; // [esp+24h] [ebp-18h]
  float v115; // [esp+28h] [ebp-14h]
  float v116; // [esp+2Ch] [ebp-10h]
  int v117; // [esp+30h] [ebp-Ch]
  char *v118; // [esp+34h] [ebp-8h]
  float v119; // [esp+38h] [ebp-4h] BYREF
  int v120; // [esp+44h] [ebp+8h]
  int v121; // [esp+44h] [ebp+8h]
  unsigned int v122; // [esp+44h] [ebp+8h]
  int value; // [esp+48h] [ebp+Ch]
  vostok::math::plane *valuea; // [esp+48h] [ebp+Ch]

  v105 = a3;
  x = map_size.normal.x;
  *(_DWORD *)LODWORD(map_size.normal.x) = 0;
  *(_DWORD *)(LODWORD(x) + 4) = 0;
  *(_DWORD *)(LODWORD(x) + 8) = 0;
  v104 = a2;
  if ( fabs(
         s_bm_current_air_resistance
       - COERCE_FLOAT(
           COERCE_UNSIGNED_INT(
             (float)((float)(*(float *)dest->m_buffer[14].m_store * *(float *)&dest->m_buffer[12].m_store[8])
                   + (float)(*(float *)&dest->m_buffer[13].m_store[12] * *(float *)&dest->m_buffer[12].m_store[4]))
           + (float)(*(float *)&dest->m_buffer[13].m_store[8] * *(float *)dest->m_buffer[12].m_store))
         & _mask__AbsFloat_)) >= 0.0000001 )
  {
    vostok::render::shadow_cascade_volume::compute_planes(this, (int)dest);
    v8 = *(float *)&dest->m_buffer[12].m_store[8];
    v9 = *(float *)&dest->m_buffer[12].m_store[4];
    v10 = *(float *)dest->m_buffer[12].m_store;
    v11 = 0;
    v120 = 0;
    v12 = 0;
    v13 = (float *)&dest[1].m_buffer[5].m_store[8];
    do
    {
      if ( (float)((float)((float)(*(v13 - 1) * v10) + (float)(v13[1] * v8)) + (float)(v9 * *v13)) > 0.001 )
      {
        *((_DWORD *)&v114 + v11++) = v12;
        v120 = v11;
        if ( v11 == 2 )
          break;
      }
      ++v12;
      v13 += 8;
    }
    while ( v12 < 4 );
    v14 = 0;
    v15 = 0.0;
    v16 = 0.0;
    v17 = 0.0;
    if ( v11 > 0 )
    {
      LODWORD(v119) = ((char *)dest->m_end - (char *)dest->m_begin) / 24;
      do
      {
        v18 = v119;
        v19 = FLOAT_10000_0;
        if ( v119 != 0.0 )
        {
          v20 = (float *)&dest[1].m_buffer[2 * *((_DWORD *)&v114 + v14) + 5].m_store[4];
          v21 = *(float *)&dest[1].m_buffer[2 * *((_DWORD *)&v114 + v14) + 5].m_store[8];
          v118 = *(char **)&dest[1].m_buffer[2 * *((_DWORD *)&v114 + v14) + 5].m_store[12];
          v117 = *(int *)v20;
          v22 = v20[3];
          m_begin = dest->m_begin;
          v116 = v22;
          p_d = &m_begin->d;
          do
          {
            d = *p_d;
            v111 = p_d[1];
            v112 = p_d[2];
            if ( v19 > (float)((float)((float)((float)(*(float *)&v117 * d) + (float)(*(float *)&v118 * v112))
                                     + (float)(v21 * v111))
                             + v116) )
              v19 = (float)((float)((float)(*(float *)&v117 * d) + (float)(*(float *)&v118 * v112)) + (float)(v21 * v111))
                  + v116;
            p_d += 6;
            --LODWORD(v18);
          }
          while ( v18 != 0.0 );
          x = map_size.normal.x;
        }
        v25 = 2 * *((_DWORD *)&v114 + v14++);
        v15 = (float)(*(float *)&dest[1].m_buffer[v25 + 5].m_store[4] * v19) + v15;
        v16 = (float)(*(float *)&dest[1].m_buffer[v25 + 5].m_store[8] * v19) + v16;
        v17 = (float)(*(float *)&dest[1].m_buffer[v25 + 5].m_store[12] * v19) + v17;
      }
      while ( v14 < v120 );
    }
    *(float *)LODWORD(x) = *(float *)LODWORD(x) + v15;
    *(float *)(LODWORD(x) + 4) = v16 + *(float *)(LODWORD(x) + 4);
    *(float *)(LODWORD(x) + 8) = v17 + *(float *)(LODWORD(x) + 8);
    v26 = v15 + *(float *)&dest->m_buffer[14].m_store[4];
    *(float *)&dest->m_buffer[14].m_store[8] = v16 + *(float *)&dest->m_buffer[14].m_store[8];
    v27 = 0;
    *(float *)&dest->m_buffer[14].m_store[12] = v17 + *(float *)&dest->m_buffer[14].m_store[12];
    v28 = 0.0;
    v29 = 0.0;
    *(float *)&dest->m_buffer[14].m_store[4] = v26;
    d = 0.0;
    v111 = 0.0;
    v112 = 0.0;
    if ( v120 > 0 )
    {
      LODWORD(v119) = ((char *)dest->m_end - (char *)dest->m_begin) / 24;
      do
      {
        v30 = v119;
        map_size.normal.x = 0.0;
        if ( v119 != 0.0 )
        {
          v31 = dest->m_begin;
          v32 = (float *)&dest[1].m_buffer[2 * *((_DWORD *)&v114 + v27) + 5].m_store[4];
          do
          {
            v33 = (float)((float)(v32[1] * v31->normal.y) + (float)(v32[2] * v31->normal.z))
                + (float)(*v32 * v31->normal.x);
            if ( v33 < 0.0 )
            {
              v34 = v32[2];
              v35 = (float)(*(float *)&dest->m_buffer[12].m_store[8] * v32[1])
                  - (float)(*(float *)&dest->m_buffer[12].m_store[4] * v34);
              v36 = (float)(*(float *)dest->m_buffer[12].m_store * v34)
                  - (float)(*v32 * *(float *)&dest->m_buffer[12].m_store[8]);
              v37 = (float)(*v32 * *(float *)&dest->m_buffer[12].m_store[4])
                  - (float)(*(float *)dest->m_buffer[12].m_store * v32[1]);
              v28 = v111;
              v29 = v112;
              LODWORD(v38) = COERCE_UNSIGNED_INT(
                               v33
                             / (float)((float)((float)((float)((float)(v36 * *(float *)&dest->m_buffer[12].m_store[8])
                                                             - (float)(v37 * *(float *)&dest->m_buffer[12].m_store[4]))
                                                     * v31->normal.x)
                                             + (float)((float)((float)(v37 * *(float *)dest->m_buffer[12].m_store)
                                                             - (float)(v35 * *(float *)&dest->m_buffer[12].m_store[8]))
                                                     * v31->normal.y))
                                     + (float)((float)((float)(v35 * *(float *)&dest->m_buffer[12].m_store[4])
                                                     - (float)(v36 * *(float *)dest->m_buffer[12].m_store))
                                             * v31->normal.z)))
                           ^ _mask__NegFloat_;
              if ( v38 > map_size.normal.x )
                map_size.normal.x = v38;
            }
            v31 = (vostok::math::plane *)((char *)v31 + 24);
            --LODWORD(v30);
          }
          while ( v30 != 0.0 );
        }
        v116 = map_size.normal.x;
        v117 = LODWORD(map_size.normal.x) & 0x7FFFFFFF;
        if ( COERCE_FLOAT(LODWORD(map_size.normal.x) & 0x7FFFFFFF) >= 0.0000099999997 )
        {
          v39 = 2 * *((_DWORD *)&v114 + v27);
          v40 = (float *)&dest[1].m_buffer[v39 + 5].m_store[4];
          v41 = COERCE_FLOAT(
                  COERCE_UNSIGNED_INT(
                    (float)((float)(*(float *)&dest[1].m_buffer[v39 + 5].m_store[12] * *(float *)(LODWORD(x) + 8))
                          + (float)(*(float *)&dest[1].m_buffer[v39 + 5].m_store[8] * *(float *)(LODWORD(x) + 4)))
                  + (float)(*(float *)LODWORD(x) * *v40))
                ^ _mask__NegFloat_)
              * map_size.normal.x;
          v28 = (float)(*(float *)&dest[1].m_buffer[v39 + 5].m_store[8] * v41) + v28;
          v29 = (float)(*(float *)&dest[1].m_buffer[v39 + 5].m_store[12] * v41) + v29;
          d = (float)(*v40 * v41) + d;
          v111 = v28;
          v112 = v29;
        }
        ++v27;
      }
      while ( v27 < v120 );
    }
    *(float *)LODWORD(x) = *(float *)LODWORD(x) + d;
    *(float *)(LODWORD(x) + 4) = v28 + *(float *)(LODWORD(x) + 4);
    *(float *)(LODWORD(x) + 8) = v29 + *(float *)(LODWORD(x) + 8);
    v42 = *(float *)&dest->m_buffer[14].m_store[4] + d;
    *(float *)&dest->m_buffer[14].m_store[8] = v28 + *(float *)&dest->m_buffer[14].m_store[8];
    *(float *)&dest->m_buffer[14].m_store[12] = v29 + *(float *)&dest->m_buffer[14].m_store[12];
    *(float *)&dest->m_buffer[14].m_store[4] = v42;
    d = *(float *)LODWORD(x);
    v43 = (float *)(LODWORD(x) + 4);
    v111 = *v43;
    v112 = v43[1];
    v44 = (float *)&dest[1].m_buffer[5].m_store[12];
    v45 = 4;
    do
    {
      v44[1] = v44[1] - (float)((float)((float)(*(v44 - 2) * d) + (float)(*(v44 - 1) * v111)) + (float)(v112 * *v44));
      v44 += 8;
      --v45;
    }
    while ( v45 );
    v119 = 0.0;
    v46 = dest->m_begin;
    if ( ((char *)dest->m_end - (char *)dest->m_begin) / 24 )
    {
      v121 = 0;
      do
      {
        v47 = (float *)((char *)&v46->normal.x + v121);
        v48 = *(float *)((char *)&v46->normal.z + v121);
        v49 = *(float *)((char *)&v46->normal.y + v121);
        v50 = (float)(*(float *)dest->m_buffer[14].m_store * v49)
            - (float)(*(float *)&dest->m_buffer[13].m_store[12] * v48);
        v51 = *(float *)&dest->m_buffer[13].m_store[8] * v48;
        v52 = *(float *)((char *)&v46->normal.x + v121) * *(float *)dest->m_buffer[14].m_store;
        v115 = (float)(*(float *)((char *)&v46->normal.x + v121) * *(float *)&dest->m_buffer[13].m_store[12])
             - (float)(*(float *)&dest->m_buffer[13].m_store[8] * v49);
        v53 = v51 - v52;
        v113 = v50;
        v114 = v53;
        d = v50;
        v116 = (float)((float)(v115 * v115) + (float)(v53 * v53)) + (float)(v50 * v50);
        v111 = v53;
        *(float *)&v117 = fabs(v116);
        v112 = v115;
        if ( *(float *)&v117 >= 0.0000099999997 )
        {
          v54 = s_bm_current_air_resistance
              / fsqrt((float)((float)(v115 * v115) + (float)(v53 * v53)) + (float)(v50 * v50));
          v55 = v54 * v50;
          v56 = v112 * v54;
          v57 = v111 * v54;
          v58 = v47[5];
          v112 = v56;
          d = v55;
          v59 = v55 * v47[3];
          v111 = v57;
          v106 = d;
          v60 = v58 * v56;
          v61 = v47[4];
          v107 = v57;
          v108 = v112;
          LODWORD(v109) = COERCE_UNSIGNED_INT((float)(v60 + (float)(v61 * v57)) + v59) ^ _mask__NegFloat_;
          map_size.normal.x = 0.0;
          if ( vostok::render::shadow_cascade_volume::check_cull_plane_valid(
                 (vostok::render::shadow_cascade_volume *)&v106,
                 (int)dest,
                 &map_size,
                 v104,
                 v105) )
          {
            v106 = COERCE_FLOAT(LODWORD(map_size.normal.x) ^ _mask__NegFloat_) * d;
            v107 = v107 * COERCE_FLOAT(LODWORD(map_size.normal.x) ^ _mask__NegFloat_);
            v108 = v108 * COERCE_FLOAT(LODWORD(map_size.normal.x) ^ _mask__NegFloat_);
            LODWORD(v109) = COERCE_UNSIGNED_INT(v109 * map_size.normal.x) ^ _mask__NegFloat_;
            vostok::buffer_vector<vostok::math::plane>::push_back(v62, translation, &v106);
          }
        }
        v46 = dest->m_begin;
        v63 = ((char *)dest->m_end - (char *)dest->m_begin) / 24;
        ++LODWORD(v119);
        v121 += 24;
      }
      while ( LODWORD(v119) < v63 );
    }
    if ( COERCE_FLOAT(
           COERCE_UNSIGNED_INT(
             (float)((float)(*(float *)dest->m_buffer[14].m_store * *(float *)&dest->m_buffer[12].m_store[8])
                   + (float)(*(float *)&dest->m_buffer[13].m_store[12] * *(float *)&dest->m_buffer[12].m_store[4]))
           + (float)(*(float *)&dest->m_buffer[13].m_store[8] * *(float *)dest->m_buffer[12].m_store))
         & _mask__AbsFloat_) >= 0.8 )
      goto LABEL_48;
    v64 = *(float *)&dest->m_buffer[12].m_store[4];
    v65 = *(float *)&dest->m_buffer[12].m_store[8];
    v66 = (float)(*(float *)dest->m_buffer[14].m_store * v64) - (float)(*(float *)&dest->m_buffer[13].m_store[12] * v65);
    v67 = *(float *)&dest->m_buffer[13].m_store[8] * v65;
    v68 = *(float *)dest->m_buffer[12].m_store;
    v69 = (float)(v68 * *(float *)&dest->m_buffer[13].m_store[12])
        - (float)(*(float *)&dest->m_buffer[13].m_store[8] * v64);
    v70 = v67 - (float)(v68 * *(float *)dest->m_buffer[14].m_store);
    v71 = *(float *)dest->m_buffer[14].m_store;
    v72 = *(float *)&dest->m_buffer[13].m_store[12];
    v46 = dest->m_begin;
    m_end = dest->m_end;
    v74 = (float)(v70 * v71) - (float)(v69 * v72);
    v75 = *(float *)&dest->m_buffer[13].m_store[8];
    v115 = (float)(v66 * v72) - (float)(v70 * v75);
    v76 = FLOAT_N1000_0;
    v113 = v74;
    v114 = (float)(v69 * v75) - (float)(v66 * v71);
    d = v74;
    v111 = v114;
    v112 = v115;
    v77 = s_bm_current_air_resistance / fsqrt((float)((float)(v74 * v74) + (float)(v115 * v115)) + (float)(v114 * v114));
    v78 = v114 * v77;
    v79 = v115 * v77;
    v80 = *(float *)&dest->m_buffer[13].m_store[4];
    v81 = v77 * v74;
    v82 = *(float *)dest->m_buffer[13].m_store;
    d = v81;
    v111 = v78;
    v112 = v79;
    v106 = v81;
    v83 = (float)(v80 * v79) + (float)(v82 * v78);
    v84 = *(float *)&dest->m_buffer[12].m_store[12];
    v107 = v78;
    LODWORD(v85) = COERCE_UNSIGNED_INT(v83 + (float)(v84 * v81)) ^ _mask__NegFloat_;
    v108 = v79;
    map_size.normal.x = FLOAT_N1000_0;
    v86 = ((char *)m_end - (char *)v46) / 24;
    if ( v86 )
    {
      p_y = &v46[1].normal.y;
      v88 = v86;
      do
      {
        if ( (float)((float)((float)((float)(*(p_y - 2) * v81) + (float)(*(p_y - 1) * v78)) + (float)(v79 * *p_y)) + v85) > v76 )
          v76 = (float)((float)((float)(*(p_y - 2) * v81) + (float)(*(p_y - 1) * v78)) + (float)(v79 * *p_y)) + v85;
        p_y += 6;
        --v88;
      }
      while ( v88 );
      map_size.normal.x = v76;
    }
    v89 = 0;
    if ( v86 )
    {
      while ( 1 )
      {
        v90 = v46->normal.x;
        z = v46->normal.z;
        y = v46->normal.y;
        d = v46->d;
        v111 = v46[1].normal.x;
        v112 = v46[1].normal.y;
        v115 = z * 5.0;
        d = (float)(v90 * 5.0) + d;
        v112 = v112 + (float)(z * 5.0);
        v111 = v111 + (float)(y * 5.0);
        v76 = map_size.normal.x;
        if ( (float)((float)((float)((float)(v112 * v79) + (float)(v111 * v78)) + (float)(d * v81)) + v85) > map_size.normal.x )
          break;
        ++v89;
        v46 = (vostok::math::plane *)((char *)v46 + 24);
        if ( v89 >= v86 )
          goto LABEL_46;
      }
      v76 = 0.0;
    }
LABEL_46:
    if ( v76 <= -1000.0 )
    {
LABEL_48:
      v93 = translation;
    }
    else
    {
      v93 = translation;
      v109 = v85 + v76;
      vostok::buffer_vector<vostok::math::plane>::push_back(
        (vostok::buffer_vector<vostok::math::plane> *)v46,
        translation,
        &v106);
    }
    v94 = &dest[1].m_buffer[5].m_store[4];
    value = 4;
    do
    {
      vostok::buffer_vector<vostok::math::plane>::push_back((vostok::buffer_vector<vostok::math::plane> *)v46, v93, v94);
      v95 = (float *)(LODWORD(v93->normal.y) - 16);
      *v95 = *v95 * -1.0;
      v95[1] = v95[1] * -1.0;
      v95[2] = v95[2] * -1.0;
      v94 += 32;
      v96 = value-- == 1;
      *(float *)(LODWORD(v93->normal.y) - 4) = *(float *)(LODWORD(v93->normal.y) - 4) * -1.0;
    }
    while ( !v96 );
    v97 = dest->m_begin;
    v122 = 0;
    if ( ((char *)dest->m_end - (char *)dest->m_begin) / 24 )
    {
      v98 = map_size.normal.y * 2.0;
      map_size.normal.x = 0.0;
      v116 = map_size.normal.y * 2.0;
      do
      {
        v99 = (const vostok::math::float3 *)((char *)v97 + LODWORD(map_size.normal.x));
        v100 = (vostok::math::plane *)&dest[1].m_buffer[5].m_store[4];
        *(float *)&valuea = v98;
        v118 = &dest[1].m_buffer[5].m_store[4];
        v117 = 4;
        do
        {
          if ( (float)((float)((float)(v99->z * v100->normal.z) + (float)(v99->y * v100->normal.y))
                     + (float)(v100->normal.x * v99->x)) <= -0.1 )
          {
            vostok::math::plane::intersect_ray(v99 + 1, v99, &v119, v100);
            v98 = v116;
            v100 = (vostok::math::plane *)v118;
          }
          else
          {
            v119 = map_size.normal.y;
          }
          if ( v119 > 0.001 && *(float *)&valuea > v119 )
            *(float *)&valuea = v119;
          v100 += 2;
          v96 = v117-- == 1;
          v118 = (char *)v100;
        }
        while ( !v96 );
        v101 = (float)(v99->y * *(float *)&valuea) + v99[1].y;
        v102 = (float)(v99->z * *(float *)&valuea) + v99[1].z;
        v99[1].x = (float)(*(float *)&valuea * v99->x) + v99[1].x;
        v99[1].y = v101;
        v99[1].z = v102;
        v97 = dest->m_begin;
        v103 = ((char *)dest->m_end - (char *)dest->m_begin) / 24;
        ++v122;
        LODWORD(map_size.normal.x) += 24;
      }
      while ( v122 < v103 );
    }
  }
}

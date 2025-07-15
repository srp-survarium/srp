bool __cdecl vostok::render::culling::cull_points_by_frustum(
        const vostok::math::frustum *f,
        vostok::math::float3 io_points)
{
  float x; // ebx
  float v3; // xmm5_4
  float v4; // xmm6_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm7_4
  float v14; // xmm1_4
  void *v15; // esp
  void *v16; // esp
  float v17; // esi
  float *p_y; // edi
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  vostok::buffer_vector<vostok::math::float3> *v23; // ecx
  bool is_similar; // al
  unsigned int v25; // edi
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  int v30; // eax
  float v31; // xmm3_4
  float *v32; // ecx
  float *v33; // edx
  float v34; // xmm1_4
  vostok::math::float4x4 *v35; // ecx
  float *v36; // edx
  float v37; // xmm2_4
  float v38; // xmm4_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm5_4
  float v42; // xmm6_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm1_4
  void *v47; // esp
  Wm4::Vector2<float> *v48; // eax
  const char **v49; // esi
  float *v50; // edi
  float v51; // xmm3_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  float y; // xmm6_4
  float v60; // xmm4_4
  float v61; // xmm0_4
  float v62; // xmm5_4
  float v63; // xmm5_4
  float v64; // xmm7_4
  float v65; // xmm1_4
  Wm4::Vector2<float> *v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm1_4
  float v69; // xmm5_4
  float v70; // xmm2_4
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm4_4
  float v74; // xmm5_4
  float v75; // xmm6_4
  float v76; // xmm1_4
  float v77; // xmm3_4
  float v78; // xmm2_4
  float v79; // xmm0_4
  float v80; // xmm4_4
  float v81; // xmm5_4
  float v82; // xmm6_4
  float v83; // xmm1_4
  float v84; // xmm4_4
  float v85; // xmm6_4
  float v86; // xmm5_4
  float v87; // xmm3_4
  float v88; // xmm0_4
  float v89; // xmm2_4
  unsigned int v90; // xmm0_4
  float v91; // xmm1_4
  unsigned int v92; // xmm6_4
  float v93; // xmm5_4
  const char *v95; // [esp+4h] [ebp-2A0h] BYREF
  _BYTE v96[192]; // [esp+C4h] [ebp-1E0h] BYREF
  int v97; // [esp+184h] [ebp-120h] BYREF
  vostok::math::float4x4 v98; // [esp+194h] [ebp-110h] BYREF
  vostok::math::float4x4 v99; // [esp+1D4h] [ebp-D0h] BYREF
  Wm4::Box2<float> iQuantity; // [esp+214h] [ebp-90h] BYREF
  float v101; // [esp+23Ch] [ebp-68h]
  float v102; // [esp+240h] [ebp-64h]
  float v103; // [esp+244h] [ebp-60h]
  vostok::math::float3 v104; // [esp+248h] [ebp-5Ch] BYREF
  float v105; // [esp+254h] [ebp-50h]
  vostok::math::float3 value; // [esp+258h] [ebp-4Ch] BYREF
  float v107; // [esp+268h] [ebp-3Ch]
  Wm4::Vector2<float> *akPoint; // [esp+270h] [ebp-34h]
  __int64 v109; // [esp+274h] [ebp-30h]
  float v110; // [esp+27Ch] [ebp-28h]
  vostok::math::float3_pod v111; // [esp+280h] [ebp-24h] BYREF
  float v112; // [esp+28Ch] [ebp-18h]
  float v113; // [esp+290h] [ebp-14h]
  float v114; // [esp+294h] [ebp-10h]
  vostok::math::float3 v115; // [esp+298h] [ebp-Ch] BYREF

  x = io_points.x;
  v3 = *(float *)(LODWORD(io_points.x) + 4);
  v4 = *(float *)(LODWORD(io_points.x) + 8);
  v5 = *(float *)(LODWORD(io_points.x) + 24) - *(float *)LODWORD(io_points.x);
  v6 = *(float *)(LODWORD(io_points.x) + 32) - v4;
  v7 = *(float *)(LODWORD(io_points.x) + 28) - v3;
  v8 = *(float *)(LODWORD(io_points.x) + 12) - *(float *)LODWORD(io_points.x);
  v9 = *(float *)(LODWORD(io_points.x) + 16) - v3;
  v10 = *(float *)(LODWORD(io_points.x) + 20) - v4;
  v11 = (float)(v9 * v6) - (float)(v7 * v10);
  v12 = (float)(v7 * v8) - (float)(v5 * v9);
  v13 = (float)(v5 * v10) - (float)(v8 * v6);
  v14 = s_bm_current_air_resistance / fsqrt((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13));
  v104.y = v14 * v11;
  v104.z = v14 * v13;
  v105 = v14 * v12;
  v15 = alloca(192);
  LODWORD(v115.x) = v96;
  LODWORD(v115.y) = v96;
  LODWORD(v115.z) = &v97;
  v16 = alloca(192);
  v17 = COERCE_FLOAT(&v95);
  LODWORD(value.z) = v96;
  LODWORD(value.x) = &v95;
  stlp_std::copy<vostok::math::float3 *,stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3>>>(
    (vostok::math::float3 *)(LODWORD(io_points.x) + 48),
    (stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3> > *)&io_points,
    LODWORD(io_points.x),
    &v115);
  v112 = 0.0;
  p_y = &f->m_planes[0].plane.normal.y;
  LODWORD(v114) = &f->m_planes[0].plane.normal.y;
  do
  {
    v113 = 0.0;
    value.y = v17;
    LODWORD(v107) = (LODWORD(v115.y) - LODWORD(v115.x)) / 12;
    if ( v107 != 0.0 )
    {
      io_points.x = 0.0;
      do
      {
        v19 = p_y[1];
        v20 = *p_y;
        v21 = *(p_y - 1);
        v22 = p_y[2];
        v101 = (float)((float)((float)(*(float *)(LODWORD(io_points.x) + LODWORD(v115.x) + 4) * *p_y)
                             + (float)(*(float *)(LODWORD(io_points.x) + LODWORD(v115.x) + 8) * v19))
                     + (float)(*(float *)(LODWORD(io_points.x) + LODWORD(v115.x)) * v21))
             + v22;
        akPoint = (Wm4::Vector2<float> *)(LODWORD(v101) & 0x7FFFFFFF);
        if ( COERCE_FLOAT(LODWORD(v101) & 0x7FFFFFFF) < 0.0000099999997
          || (float)((float)((float)((float)(*(float *)(LODWORD(io_points.x) + LODWORD(v115.x) + 4) * v20)
                                   + (float)(*(float *)(LODWORD(io_points.x) + LODWORD(v115.x) + 8) * v19))
                           + (float)(v21 * *(float *)(LODWORD(io_points.x) + LODWORD(v115.x))))
                   + v22) > 0.0 )
        {
          vostok::buffer_vector<vostok::math::float3>::push_back(
            (vostok::buffer_vector<vostok::math::float3> *)(LODWORD(v101) & 0x7FFFFFFF),
            &value,
            (_DWORD *)(LODWORD(io_points.x) + LODWORD(v115.x)));
          v17 = value.x;
        }
        akPoint = (Wm4::Vector2<float> *)(LODWORD(v113) + 1);
        if ( vostok::math::plane::intersect_segment(
               (const vostok::math::float3 *)(LODWORD(v115.x) + LODWORD(io_points.x)),
               (const vostok::math::float3 *)(LODWORD(v115.x) + 12 * ((LODWORD(v113) + 1) % LODWORD(v107))),
               (vostok::math::plane *)(p_y - 1),
               (vostok::math::float3 *)&v111) )
        {
          if ( LODWORD(v17) == LODWORD(value.y)
            || (is_similar = vostok::math::float3_pod::is_similar(
                               &v111,
                               (const vostok::math::float3_pod *)(LODWORD(value.y) - 12),
                               0.0000099999997),
                *(float *)&p_y = v114,
                !is_similar) )
          {
            vostok::buffer_vector<vostok::math::float3>::push_back(v23, &value, &v111);
            v17 = value.x;
          }
        }
        LODWORD(io_points.x) += 12;
        v113 = *(float *)&akPoint;
      }
      while ( (unsigned int)akPoint < LODWORD(v107) );
    }
    if ( (unsigned int)((LODWORD(value.y) - LODWORD(v17)) / 12) < 3 )
      return 0;
    v115.y = v115.x;
    stlp_std::copy<vostok::math::float3 *,stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3>>>(
      (vostok::math::float3 *)LODWORD(value.y),
      (stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3> > *)&v104,
      LODWORD(v17),
      &v115);
    ++LODWORD(v112);
    p_y += 5;
    v114 = *(float *)&p_y;
  }
  while ( LODWORD(v112) != 6 );
  v25 = (LODWORD(value.y) - LODWORD(v17)) / 12;
  v101 = *(float *)&v25;
  if ( v25 < 3 )
    return 0;
  v26 = *(float *)(LODWORD(v17) + 16);
  v27 = *(float *)(LODWORD(v17) + 20) - *(float *)(LODWORD(v17) + 8);
  v28 = *(float *)(LODWORD(v17) + 12) - *(float *)LODWORD(v17);
  v107 = 0.0;
  v29 = v26 - *(float *)(LODWORD(v17) + 4);
  LODWORD(v113) = LODWORD(v17) + 4;
  v30 = 1;
  v31 = (float)((float)(v28 * v28) + (float)(v27 * v27)) + (float)(v29 * v29);
  LODWORD(io_points.x) = 1;
  v32 = (float *)(LODWORD(v17) + 20);
  do
  {
    akPoint = (Wm4::Vector2<float> *)(v30 + 1);
    v33 = (float *)(LODWORD(v17) + 12 * ((v30 + 1) % v25));
    v34 = v33[1] - *(v32 - 1);
    if ( (float)((float)((float)((float)(*v33 - *(v32 - 2)) * (float)(*v33 - *(v32 - 2)))
                       + (float)((float)(v33[2] - *v32) * (float)(v33[2] - *v32)))
               + (float)(v34 * v34)) > v31 )
    {
      v31 = (float)((float)((float)(*v33 - *(v32 - 2)) * (float)(*v33 - *(v32 - 2)))
                  + (float)((float)(v33[2] - *v32) * (float)(v33[2] - *v32)))
          + (float)(v34 * v34);
      v107 = io_points.x;
    }
    v30 = (int)akPoint;
    v32 += 3;
    LODWORD(io_points.x) = akPoint;
  }
  while ( (unsigned int)akPoint < v25 );
  LODWORD(io_points.x) = LODWORD(v31) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(v31) & 0x7FFFFFFF) < 0.0000099999997 )
    return 0;
  v35 = (vostok::math::float4x4 *)(LODWORD(v17) + 12 * LODWORD(v107));
  v36 = (float *)(LODWORD(v17) + 12 * ((LODWORD(v107) + 1) % v25));
  v37 = *v36 - v35->i.x;
  v38 = v36[2] - v35->i.z;
  v39 = v36[1] - v35->i.y;
  v40 = s_bm_current_air_resistance / fsqrt((float)((float)(v37 * v37) + (float)(v38 * v38)) + (float)(v39 * v39));
  v41 = v40 * v37;
  v42 = v40 * v39;
  v110 = v40 * v38;
  *(float *)&v109 = v40 * v37;
  v43 = (float)((float)(v40 * v38) * v104.z) - (float)((float)(v40 * v39) * v105);
  v44 = (float)(v41 * v105) - (float)(v104.y * v110);
  v45 = (float)(v104.y * v42) - (float)(v41 * v104.z);
  v46 = s_bm_current_air_resistance / fsqrt((float)((float)(v43 * v43) + (float)(v45 * v45)) + (float)(v44 * v44));
  *((float *)&v109 + 1) = v42;
  v111.x = v46 * v43;
  v111.y = v46 * v44;
  v111.z = v46 * v45;
  vostok::math::float4x4::identity(v35, &v99);
  *(_QWORD *)&v99.i.x = v109;
  v99.i.z = v110;
  *(_QWORD *)&v99.lines[1].x = *(_QWORD *)&v111.x;
  v99.j.z = v111.z;
  *(_QWORD *)&v99.lines[2].x = *(_QWORD *)&v104.elements[1];
  v99.k.z = v105;
  *(_QWORD *)&v99.lines[3].x = *(_QWORD *)LODWORD(value.x);
  v99.c.z = *(float *)(LODWORD(value.x) + 8);
  vostok::math::float4x4::try_invert(&v99, &v98);
  v47 = alloca(8 * LODWORD(v101));
  v48 = (Wm4::Vector2<float> *)&v95;
  *(float *)&akPoint = COERCE_FLOAT(&v95);
  v49 = &v95;
  LODWORD(v101) = v96 + 8 * LODWORD(v101) + 184;
  if ( LODWORD(value.x) != LODWORD(value.y) )
  {
    v50 = (float *)LODWORD(v113);
    do
    {
      v51 = *(v50 - 1);
      v52 = v50[1];
      v53 = (float)((float)((float)(v98.i.x * v51) + (float)(*v50 * v98.j.x)) + (float)(v98.k.x * v52)) + v98.c.x;
      v54 = (float)((float)((float)(*v50 * v98.j.y) + (float)(v98.i.y * v51)) + (float)(v98.k.y * v52)) + v98.c.y;
      v102 = v53;
      v103 = v54;
      if ( (unsigned int)v49 >= LODWORD(v101)
        && !`vostok::buffer_vector<Wm4::Vector2<float>>::push_back'::`11'::debug_macro_helper_ignore_always )
      {
        HIBYTE(io_points.elements[0]) = 0;
        vostok::debug::on_error(
          (bool *)io_points.elements + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class Wm4::Vector2<float> >::push_back",
          (const char *)0x12E,
          "buffer overflow",
          v95);
        if ( vostok::debug::is_debugger_present() || HIBYTE(io_points.elements[0]) )
          __debugbreak();
        v53 = v102;
      }
      if ( v49 )
      {
        v55 = v103;
        *(float *)v49 = v53;
        *((float *)v49 + 1) = v55;
      }
      v50 += 3;
      v49 += 2;
    }
    while ( v50 - 1 != (float *)LODWORD(value.y) );
    v48 = akPoint;
  }
  Wm4::ContMinBox<float>(v48, &iQuantity, ((char *)v49 - (char *)v48) >> 3);
  v104.x = (float)(iQuantity.Center.m_afTuple[1] - (float)(iQuantity.Axis[0].m_afTuple[1] * iQuantity.Extent[0]))
         - (float)(iQuantity.Axis[1].m_afTuple[1] * iQuantity.Extent[1]);
  io_points.x = iQuantity.Center.m_afTuple[0] + (float)(iQuantity.Axis[0].m_afTuple[0] * iQuantity.Extent[0]);
  v56 = io_points.x - (float)(iQuantity.Axis[1].m_afTuple[0] * iQuantity.Extent[1]);
  v101 = (float)(iQuantity.Center.m_afTuple[1] + (float)(iQuantity.Axis[0].m_afTuple[1] * iQuantity.Extent[0]))
       - (float)(iQuantity.Axis[1].m_afTuple[1] * iQuantity.Extent[1]);
  v57 = io_points.x + (float)(iQuantity.Axis[1].m_afTuple[0] * iQuantity.Extent[1]);
  v58 = (float)(iQuantity.Center.m_afTuple[0] - (float)(iQuantity.Axis[0].m_afTuple[0] * iQuantity.Extent[0]))
      + (float)(iQuantity.Axis[1].m_afTuple[0] * iQuantity.Extent[1]);
  io_points.x = v104.y * 0.0;
  v107 = (float)(iQuantity.Center.m_afTuple[1] - (float)(iQuantity.Axis[0].m_afTuple[1] * iQuantity.Extent[0]))
       + (float)(iQuantity.Axis[1].m_afTuple[1] * iQuantity.Extent[1]);
  y = v111.y;
  v115.x = (float)((float)((float)((float)((float)(iQuantity.Center.m_afTuple[0]
                                                 - (float)(iQuantity.Axis[0].m_afTuple[0] * iQuantity.Extent[0]))
                                         - (float)(iQuantity.Axis[1].m_afTuple[0] * iQuantity.Extent[1]))
                                 * *(float *)&v109)
                         + (float)(v111.x * v104.x))
                 + (float)(v104.y * 0.0))
         + v99.c.x;
  v114 = v104.z * 0.0;
  *(float *)&akPoint = (float)(iQuantity.Center.m_afTuple[1]
                             + (float)(iQuantity.Axis[0].m_afTuple[1] * iQuantity.Extent[0]))
                     + (float)(iQuantity.Axis[1].m_afTuple[1] * iQuantity.Extent[1]);
  v115.y = (float)((float)((float)((float)((float)(iQuantity.Center.m_afTuple[0]
                                                 - (float)(iQuantity.Axis[0].m_afTuple[0] * iQuantity.Extent[0]))
                                         - (float)(iQuantity.Axis[1].m_afTuple[0] * iQuantity.Extent[1]))
                                 * *((float *)&v109 + 1))
                         + (float)(v104.x * v111.y))
                 + (float)(v104.z * 0.0))
         + v99.c.y;
  v115.z = (float)((float)((float)((float)((float)(iQuantity.Center.m_afTuple[0]
                                                 - (float)(iQuantity.Axis[0].m_afTuple[0] * iQuantity.Extent[0]))
                                         - (float)(iQuantity.Axis[1].m_afTuple[0] * iQuantity.Extent[1]))
                                 * v110)
                         + (float)(v104.x * v111.z))
                 + (float)(v105 * 0.0))
         + v99.c.z;
  v112 = v105 * 0.0;
  *(_DWORD *)LODWORD(x) = LODWORD(v115.x);
  v60 = v111.x;
  v61 = v101;
  v62 = v56 * *(float *)&v109;
  *(_QWORD *)(LODWORD(x) + 4) = *(_QWORD *)&v115.elements[1];
  v115.x = (float)((float)(v62 + (float)(v60 * v61)) + io_points.x) + v99.c.x;
  v63 = v56;
  v64 = v61;
  v65 = (float)((float)((float)(v56 * v110) + (float)(v61 * v111.z)) + v112) + v99.c.z;
  v66 = akPoint;
  v115.z = v65;
  v115.y = (float)((float)((float)(v63 * *((float *)&v109 + 1)) + (float)(v64 * y)) + v114) + v99.c.y;
  *(_QWORD *)(LODWORD(x) + 12) = *(_QWORD *)&v115.x;
  v67 = v57 * *(float *)&v109;
  *(float *)(LODWORD(x) + 20) = v115.z;
  v115.x = (float)((float)(v67 + (float)(v60 * *(float *)&v66)) + io_points.x) + v99.c.x;
  v68 = v57 * *((float *)&v109 + 1);
  v69 = *(float *)&v66;
  v70 = (float)((float)((float)(v57 * v110) + (float)(*(float *)&v66 * v111.z)) + v112) + v99.c.z;
  v71 = v107;
  v115.y = (float)((float)(v68 + (float)(v69 * y)) + v114) + v99.c.y;
  v115.z = v70;
  *(_QWORD *)(LODWORD(x) + 24) = *(_QWORD *)&v115.x;
  v72 = (float)((float)((float)(v58 * *(float *)&v109) + (float)(v60 * v71)) + io_points.x) + v99.c.x;
  *(float *)(LODWORD(x) + 32) = v115.z;
  v115.x = v72;
  v115.y = (float)((float)((float)(v58 * *((float *)&v109 + 1)) + (float)(v71 * y)) + v114) + v99.c.y;
  v73 = *(float *)LODWORD(x);
  v74 = *(float *)(LODWORD(x) + 4);
  v75 = *(float *)(LODWORD(x) + 8);
  v115.z = (float)((float)((float)(v58 * v110) + (float)(v71 * v111.z)) + v112) + v99.c.z;
  *(float *)(LODWORD(x) + 36) = v72;
  *(_QWORD *)(LODWORD(x) + 40) = *(_QWORD *)&v115.elements[1];
  v76 = *(float *)(LODWORD(x) + 24) - v73;
  v77 = *(float *)(LODWORD(x) + 32) - v75;
  v78 = *(float *)(LODWORD(x) + 28) - v74;
  v79 = *(float *)(LODWORD(x) + 12) - v73;
  io_points.x = v73;
  v80 = *(float *)(LODWORD(x) + 16) - v74;
  v107 = v74;
  v81 = *(float *)(LODWORD(x) + 20) - v75;
  v113 = v75;
  v111.x = (float)(v80 * v77) - (float)(v81 * v78);
  v82 = v76;
  v83 = v76 * v80;
  v84 = *(float *)(LODWORD(x) + 28) - v107;
  v85 = v82 * v81;
  v86 = v79 * v77;
  v87 = *(float *)(LODWORD(x) + 44) - v113;
  v88 = v79 * v78;
  v89 = *(float *)(LODWORD(x) + 32) - v113;
  *(float *)&v90 = v88 - v83;
  v91 = *(float *)(LODWORD(x) + 40) - v107;
  *(float *)&v92 = v85 - v86;
  v93 = *(float *)(LODWORD(x) + 36) - io_points.x;
  *(_QWORD *)&v111.elements[1] = __PAIR64__(v90, v92);
  io_points.x = fabs(
                  (float)(fsqrt(
                            (float)((float)((float)((float)(v91 * (float)(*(float *)(LODWORD(x) + 24) - io_points.x))
                                                  - (float)(v84 * v93))
                                          * (float)((float)(v91 * (float)(*(float *)(LODWORD(x) + 24) - io_points.x))
                                                  - (float)(v84 * v93)))
                                  + (float)((float)((float)(v89 * v93)
                                                  - (float)(v87 * (float)(*(float *)(LODWORD(x) + 24) - io_points.x)))
                                          * (float)((float)(v89 * v93)
                                                  - (float)(v87 * (float)(*(float *)(LODWORD(x) + 24) - io_points.x)))))
                          + (float)((float)((float)(v84 * v87) - (float)(v89 * v91))
                                  * (float)((float)(v84 * v87) - (float)(v89 * v91))))
                        * 0.5)
                + (float)(fsqrt(
                            (float)((float)(v111.x * v111.x) + (float)(*(float *)&v90 * *(float *)&v90))
                          + (float)(*(float *)&v92 * *(float *)&v92))
                        * 0.5));
  return io_points.x >= 0.0000099999997;
}

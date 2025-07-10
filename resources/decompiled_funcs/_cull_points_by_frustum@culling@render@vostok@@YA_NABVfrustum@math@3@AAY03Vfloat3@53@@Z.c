bool __cdecl vostok::render::culling::cull_points_by_frustum(
        const vostok::math::frustum *f,
        vostok::math::float3 (*io_points)[4])
{
  float y; // xmm7_4
  float z; // xmm3_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm7_4
  void *v10; // esp
  void *v11; // esp
  float *p_y; // esi
  vostok::math::float3 *m_begin; // ecx
  vostok::math::float3 *v14; // edi
  int v15; // edi
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  vostok::math::float3 *v20; // eax
  vostok::math::float3 *m_end; // edx
  float x; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm3_4
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  vostok::math::float3 *v34; // eax
  float v35; // ecx
  vostok::math::float3 *v36; // edi
  unsigned int v37; // esi
  unsigned int v38; // ecx
  unsigned int v39; // eax
  float v40; // xmm0_4
  unsigned int v41; // edi
  float *v42; // ecx
  unsigned int v43; // edx
  float v44; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm2_4
  float v48; // xmm3_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  unsigned int v52; // edx
  float v53; // xmm3_4
  float v54; // xmm2_4
  unsigned int v55; // eax
  unsigned int v56; // edi
  float *p_z; // ecx
  float v58; // xmm3_4
  float v59; // xmm2_4
  unsigned int v60; // edx
  float v61; // xmm2_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  void *v65; // esp
  vostok::math::float3 *v66; // ecx
  float *v67; // edx
  float v68; // xmm4_4
  float v69; // xmm5_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  float v73; // xmm0_4
  float v74; // xmm4_4
  float v75; // xmm3_4
  float v76; // edx
  float v77; // xmm7_4
  float v78; // xmm5_4
  float v79; // ecx
  float v80; // xmm2_4
  float v81; // xmm6_4
  float v82; // xmm0_4
  float v83; // xmm4_4
  float v84; // xmm1_4
  float v85; // xmm0_4
  float v86; // edx
  float v87; // xmm3_4
  float v88; // xmm5_4
  float v89; // xmm4_4
  float v90; // xmm7_4
  float v91; // xmm2_4
  float v92; // xmm1_4
  float v93; // xmm0_4
  float v94; // xmm2_4
  float v95; // xmm1_4
  float v96; // xmm6_4
  float v97; // xmm7_4
  float v98; // xmm6_4
  float v99; // xmm0_4
  float v100; // xmm1_4
  float v101; // xmm6_4
  float v102; // xmm2_4
  float v103; // xmm0_4
  float v104; // xmm2_4
  float v105; // xmm7_4
  float v106; // xmm6_4
  float v107; // xmm3_4
  vostok::math::float3 *v109; // [esp+0h] [ebp-22Ch]
  vostok::math::float3 v110[31]; // [esp+4h] [ebp-228h] BYREF
  float v111; // [esp+10h] [ebp-21Ch]
  float v112; // [esp+14h] [ebp-218h]
  float v113; // [esp+18h] [ebp-214h]
  vostok::math::float3 v114[31]; // [esp+24h] [ebp-208h] BYREF
  _BYTE v115[188]; // [esp+C4h] [ebp-168h] BYREF
  vostok::math::float4x4 world_to_local; // [esp+190h] [ebp-9Ch] BYREF
  Wm4::Box2<float> min_box; // [esp+1D0h] [ebp-5Ch] BYREF
  vostok::math::float4x4 local_to_world; // [esp+1F0h] [ebp-3Ch] BYREF
  float v119; // [esp+230h] [ebp+4h]
  float v120; // [esp+234h] [ebp+8h]
  float v121; // [esp+238h] [ebp+Ch]
  float v122; // [esp+23Ch] [ebp+10h]
  float v123; // [esp+240h] [ebp+14h]
  __int64 v124; // [esp+244h] [ebp+18h]
  float v125; // [esp+24Ch] [ebp+20h]
  vostok::buffer_vector<vostok::math::float3> temp; // [esp+250h] [ebp+24h] BYREF
  __int64 v127; // [esp+258h] [ebp+2Ch]
  float v128; // [esp+260h] [ebp+34h]
  __int64 v129; // [esp+264h] [ebp+38h]
  float v130; // [esp+26Ch] [ebp+40h]
  vostok::buffer_vector<vostok::math::float3> pos; // [esp+270h] [ebp+44h]
  float v132; // [esp+278h] [ebp+4Ch]
  stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3> > v133; // [esp+27Ch] [ebp+50h] BYREF
  unsigned int plane_id; // [esp+280h] [ebp+54h]
  stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3> > v135; // [esp+284h] [ebp+58h] BYREF
  unsigned __int64 v136; // [esp+288h] [ebp+5Ch]
  float v137; // [esp+290h] [ebp+64h]
  unsigned int temp_count; // [esp+294h] [ebp+68h]
  unsigned int i; // [esp+298h] [ebp+6Ch]
  float io_pointsa; // [esp+2A8h] [ebp+7Ch]
  float io_pointsb; // [esp+2A8h] [ebp+7Ch]

  y = (*io_points)[0].y;
  z = (*io_points)[0].z;
  v4 = (*io_points)[2].x - (*io_points)[0].x;
  v5 = (*io_points)[2].y - y;
  v6 = (*io_points)[1].y - y;
  v7 = (*io_points)[2].z - z;
  v8 = (*io_points)[1].x - (*io_points)[0].x;
  v9 = (*io_points)[1].z - z;
  *(float *)&v136 = (float)(v6 * v7) - (float)(v5 * v9);
  v137 = (float)(v5 * v8) - (float)(v4 * v6);
  *((float *)&v136 + 1) = (float)(v4 * v9) - (float)(v8 * v7);
  *(float *)&plane_id = sqrtf(
                          (float)((float)(*(float *)&v136 * *(float *)&v136) + (float)(v137 * v137))
                        + (float)(*((float *)&v136 + 1) * *((float *)&v136 + 1)));
  *(float *)&v124 = (float)(*(float *)&clear_value / *(float *)&plane_id) * *(float *)&v136;
  *((float *)&v124 + 1) = (float)(*(float *)&clear_value / *(float *)&plane_id) * *((float *)&v136 + 1);
  v125 = (float)(*(float *)&clear_value / *(float *)&plane_id) * v137;
  v10 = alloca(192);
  temp.m_begin = (vostok::math::float3 *)v115;
  temp.m_end = (vostok::math::float3 *)v115;
  v11 = alloca(192);
  stlp_std::priv::__copy<vostok::math::float3 *,stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3>>,int>(
    (vostok::math::float3 *)io_points,
    &(*io_points)[4],
    &v133,
    (stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3> >)&temp);
  *(float *)&plane_id = 0.0;
  p_y = &f->m_planes[0].plane.normal.y;
  do
  {
    m_begin = temp.m_begin;
    v14 = v110;
    pos.m_end = v110;
    temp_count = temp.m_end - temp.m_begin;
    *(float *)&i = 0.0;
    if ( *(float *)&temp_count != 0.0 )
    {
      v15 = 0;
      do
      {
        v16 = p_y[1];
        v17 = *p_y;
        v18 = *(p_y - 1);
        v19 = p_y[2];
        v20 = &m_begin[v15];
        v120 = (float)((float)((float)(m_begin[v15].y * *p_y) + (float)(m_begin[v15].z * v16))
                     + (float)(v18 * m_begin[v15].x))
             + v19;
        v135.container = (vostok::buffer_vector<vostok::math::float3> *)(LODWORD(v120) & 0x7FFFFFFF);
        if ( COERCE_FLOAT(LODWORD(v120) & 0x7FFFFFFF) < 0.0000099999997
          || (float)((float)((float)((float)(v20->y * v17) + (float)(v20->z * v16)) + (float)(v20->x * v18)) + v19) > 0.0 )
        {
          m_end = pos.m_end;
          if ( pos.m_end )
          {
            *(_QWORD *)&pos.m_end->x = *(_QWORD *)&v20->x;
            m_end->z = v20->z;
            m_begin = temp.m_begin;
          }
          pos.m_end = m_end + 1;
        }
        ++i;
        x = m_begin[v15].x;
        v23 = *p_y;
        v24 = p_y[1];
        v25 = m_begin[i % temp_count].y - m_begin[v15].y;
        v26 = m_begin[i % temp_count].x - x;
        v27 = (float)(*(p_y - 1) * v26) + (float)(*p_y * v25);
        v128 = m_begin[i % temp_count].z - m_begin[v15].z;
        v28 = v27 + (float)(v24 * v128);
        v29 = (float)((float)((float)(x * *(p_y - 1)) + (float)(v24 * m_begin[v15].z)) + (float)(v23 * m_begin[v15].y))
            + p_y[2];
        if ( v28 == 0.0 )
        {
          v121 = (float)((float)((float)(x * *(p_y - 1)) + (float)(v24 * m_begin[v15].z)) + (float)(v23 * m_begin[v15].y))
               + p_y[2];
          v135.container = (vostok::buffer_vector<vostok::math::float3> *)(LODWORD(v29) & 0x7FFFFFFF);
          v30 = -COERCE_FLOAT(LODWORD(v29) & 0x7FFFFFFF);
        }
        else
        {
          v30 = (float)(-1.0 / v28) * v29;
        }
        v31 = x + (float)(v26 * v30);
        v32 = m_begin[v15].y + (float)(v30 * v25);
        v33 = m_begin[v15].z + (float)(v30 * v128);
        v136 = __PAIR64__(LODWORD(v32), LODWORD(v31));
        v137 = v33;
        if ( v30 >= 0.0 && *(float *)&clear_value >= v30 )
        {
          v34 = pos.m_end;
          if ( v110 == pos.m_end
            || (v119 = v31 - pos.m_end[-1].x,
                v135.container = (vostok::buffer_vector<vostok::math::float3> *)(LODWORD(v119) & 0x7FFFFFFF),
                COERCE_FLOAT(LODWORD(v119) & 0x7FFFFFFF) >= 0.0000099999997)
            || (v123 = v32 - pos.m_end[-1].y,
                v135.container = (vostok::buffer_vector<vostok::math::float3> *)(LODWORD(v123) & 0x7FFFFFFF),
                COERCE_FLOAT(LODWORD(v123) & 0x7FFFFFFF) >= 0.0000099999997)
            || (*(float *)&v133.container = v33 - pos.m_end[-1].z,
                v135.container = (vostok::buffer_vector<vostok::math::float3> *)((unsigned int)v133.container
                                                                               & 0x7FFFFFFF),
                COERCE_FLOAT((unsigned int)v133.container & 0x7FFFFFFF) >= 0.0000099999997) )
          {
            if ( pos.m_end )
            {
              v35 = v137;
              *(_QWORD *)&pos.m_end->x = v136;
              v34->z = v35;
              m_begin = temp.m_begin;
            }
            pos.m_end = v34 + 1;
          }
        }
        ++v15;
      }
      while ( i < temp_count );
      v14 = pos.m_end;
    }
    if ( (unsigned int)(v14 - v110) < 3 )
      return 0;
    temp.m_end = m_begin;
    stlp_std::priv::__copy<vostok::math::float3 *,stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3>>,int>(
      v110,
      v14,
      &v135,
      (stlp_std::back_insert_iterator<vostok::buffer_vector<vostok::math::float3> >)&temp);
    p_y += 5;
    ++plane_id;
  }
  while ( plane_id != 6 );
  v36 = pos.m_end;
  v37 = pos.m_end - v110;
  if ( v37 < 3 )
    return 0;
  v123 = COERCE_FLOAT((vostok::math::float3 *)&v110[0].elements[1]);
  v38 = 1;
  v39 = 0;
  *(float *)&i = 0.0;
  v40 = (float)((float)((float)(v111 - v110[0].x) * (float)(v111 - v110[0].x))
              + (float)((float)(v113 - v110[0].z) * (float)(v113 - v110[0].z)))
      + (float)((float)(v112 - v110[0].y) * (float)(v112 - v110[0].y));
  temp_count = 1;
  if ( v37 > 1 )
  {
    if ( (int)(v37 - 1) >= 4 )
    {
      v41 = 3;
      v42 = (float *)v114;
      do
      {
        v43 = (v41 - 1) % v37;
        v44 = v110[v43].z - *(v42 - 3);
        v45 = v110[v43].y - *(v42 - 4);
        if ( (float)((float)((float)((float)(v110[v43].x - *(v42 - 5)) * (float)(v110[v43].x - *(v42 - 5)))
                           + (float)(v44 * v44))
                   + (float)(v45 * v45)) > v40 )
        {
          v40 = (float)((float)((float)(v110[v43].x - *(v42 - 5)) * (float)(v110[v43].x - *(v42 - 5)))
                      + (float)(v44 * v44))
              + (float)(v45 * v45);
          i = temp_count;
        }
        v46 = v110[v41 % v37].z - *v42;
        v47 = v110[v41 % v37].y - *(v42 - 1);
        if ( (float)((float)((float)((float)(v110[v41 % v37].x - *(v42 - 2)) * (float)(v110[v41 % v37].x - *(v42 - 2)))
                           + (float)(v46 * v46))
                   + (float)(v47 * v47)) > v40 )
        {
          v40 = (float)((float)((float)(v110[v41 % v37].x - *(v42 - 2)) * (float)(v110[v41 % v37].x - *(v42 - 2)))
                      + (float)(v46 * v46))
              + (float)(v47 * v47);
          i = v41 - 1;
        }
        v48 = v110[(v41 + 1) % v37].z - v42[3];
        v49 = v110[(v41 + 1) % v37].x;
        v50 = v110[(v41 + 1) % v37].y - v42[2];
        v51 = (float)((float)((float)(v49 - v42[1]) * (float)(v49 - v42[1])) + (float)(v48 * v48)) + (float)(v50 * v50);
        if ( v51 > v40 )
        {
          v40 = v51;
          i = v41;
        }
        v52 = (v41 + 2) % v37;
        v53 = v110[v52].z - v42[6];
        v54 = v110[v52].y - v42[5];
        if ( (float)((float)((float)((float)(v110[v52].x - v42[4]) * (float)(v110[v52].x - v42[4])) + (float)(v53 * v53))
                   + (float)(v54 * v54)) > v40 )
        {
          v40 = (float)((float)((float)(v110[v52].x - v42[4]) * (float)(v110[v52].x - v42[4])) + (float)(v53 * v53))
              + (float)(v54 * v54);
          i = v41 + 1;
        }
        v55 = temp_count + 4;
        v42 += 12;
        v41 += 4;
        temp_count = v55;
      }
      while ( v55 < v37 - 3 );
      v36 = pos.m_end;
      v38 = v55;
      v39 = i;
    }
    if ( v38 < v37 )
    {
      v56 = v38 + 1;
      p_z = &v110[v38].z;
      do
      {
        v58 = v110[v56 % v37].z - *p_z;
        v59 = v110[v56 % v37].y - *(p_z - 1);
        if ( (float)((float)((float)((float)(v110[v56 % v37].x - *(p_z - 2)) * (float)(v110[v56 % v37].x - *(p_z - 2)))
                           + (float)(v58 * v58))
                   + (float)(v59 * v59)) > v40 )
        {
          v40 = (float)((float)((float)(v110[v56 % v37].x - *(p_z - 2)) * (float)(v110[v56 % v37].x - *(p_z - 2)))
                      + (float)(v58 * v58))
              + (float)(v59 * v59);
          i = temp_count;
        }
        p_z += 3;
        ++v56;
        ++temp_count;
      }
      while ( temp_count < v37 );
      v39 = i;
      v36 = pos.m_end;
    }
  }
  v133.container = (vostok::buffer_vector<vostok::math::float3> *)(LODWORD(v40) & 0x7FFFFFFF);
  if ( COERCE_FLOAT(LODWORD(v40) & 0x7FFFFFFF) < 0.0000099999997 )
    return 0;
  v60 = (v39 + 1) % v37;
  v109 = &v110[v39];
  v61 = v110[v60].z - v109->z;
  v62 = v110[v60].y - v109->y;
  *(float *)&v129 = v110[v60].x - v109->x;
  *((float *)&v129 + 1) = v62;
  v130 = v61;
  *(float *)&v133.container = 1.0
                            / sqrtf(
                                (float)((float)(*(float *)&v129 * *(float *)&v129) + (float)(v61 * v61))
                              + (float)(v62 * v62));
  v63 = (float)((float)(*(float *)&v133.container * v130) * *((float *)&v124 + 1))
      - (float)((float)(*(float *)&v133.container * *((float *)&v129 + 1)) * v125);
  v64 = (float)(*(float *)&v133.container * *(float *)&v129) * v125;
  *(float *)&v129 = *(float *)&v133.container * *(float *)&v129;
  v137 = (float)(*(float *)&v124 * (float)(*(float *)&v133.container * *((float *)&v129 + 1)))
       - (float)(*(float *)&v129 * *((float *)&v124 + 1));
  *((float *)&v136 + 1) = v64 - (float)(*(float *)&v124 * (float)(*(float *)&v133.container * v130));
  *((float *)&v129 + 1) = *(float *)&v133.container * *((float *)&v129 + 1);
  v130 = *(float *)&v133.container * v130;
  *(float *)&v136 = v63;
  *(float *)&v133.container = 1.0
                            / sqrtf(
                                (float)((float)(v137 * v137) + (float)(*((float *)&v136 + 1) * *((float *)&v136 + 1)))
                              + (float)(v63 * v63));
  *(float *)&v136 = *(float *)&v133.container * *(float *)&v136;
  *((float *)&v136 + 1) = *(float *)&v133.container * *((float *)&v136 + 1);
  v137 = *(float *)&v133.container * v137;
  vostok::math::float4x4::identity(&local_to_world);
  *(_QWORD *)&local_to_world.i.x = v129;
  *(_QWORD *)&local_to_world.lines[1].x = v136;
  local_to_world.j.z = v137;
  local_to_world.i.z = v130;
  *(_QWORD *)&local_to_world.lines[2].x = v124;
  local_to_world.k.z = v125;
  *(_QWORD *)&local_to_world.lines[3].x = *(_QWORD *)&v110[0].x;
  local_to_world.c.z = v110[0].z;
  vostok::math::float4x4::try_invert(&world_to_local, &local_to_world);
  v65 = alloca(8 * v37);
  v66 = v110;
  if ( v110 != v36 )
  {
    v67 = (float *)LODWORD(v123);
    v68 = world_to_local.c.y;
    v69 = world_to_local.c.x;
    do
    {
      v70 = (float)((float)((float)(*(v67 - 1) * world_to_local.i.y) + (float)(v67[1] * world_to_local.k.y))
                  + (float)(*v67 * world_to_local.j.y))
          + v68;
      if ( v66 )
      {
        v66->x = (float)((float)((float)(v67[1] * world_to_local.k.x) + (float)(*(v67 - 1) * world_to_local.i.x))
                       + (float)(*v67 * world_to_local.j.x))
               + v69;
        v66->y = v70;
      }
      v67 += 3;
      v66 = (vostok::math::float3 *)((char *)v66 + 8);
    }
    while ( v67 - 1 != (float *)v36 );
  }
  Wm4::ContMinBox<float>((Wm4::Vector2<float> *)v110, &min_box, ((char *)v66 - (char *)v110) >> 3);
  *(float *)&v133.container = min_box.Center.m_afTuple[0] + (float)(min_box.Axis[0].m_afTuple[0] * min_box.Extent[0]);
  *(float *)&pos.m_end = min_box.Center.m_afTuple[1] - (float)(min_box.Axis[0].m_afTuple[1] * min_box.Extent[0]);
  *(float *)&temp.m_begin = (float)(min_box.Center.m_afTuple[0]
                                  - (float)(min_box.Axis[0].m_afTuple[0] * min_box.Extent[0]))
                          - (float)(min_box.Axis[1].m_afTuple[0] * min_box.Extent[1]);
  v71 = *(float *)&pos.m_end - (float)(min_box.Axis[1].m_afTuple[1] * min_box.Extent[1]);
  *(float *)&pos.m_begin = *(float *)&v133.container - (float)(min_box.Axis[1].m_afTuple[0] * min_box.Extent[1]);
  v72 = (float)(min_box.Center.m_afTuple[1] + (float)(min_box.Axis[0].m_afTuple[1] * min_box.Extent[0]))
      - (float)(min_box.Axis[1].m_afTuple[1] * min_box.Extent[1]);
  *(float *)&i = *(float *)&v124 * 0.0;
  v73 = *(float *)&v136;
  v122 = (float)(min_box.Center.m_afTuple[0] - (float)(min_box.Axis[0].m_afTuple[0] * min_box.Extent[0]))
       + (float)(min_box.Axis[1].m_afTuple[0] * min_box.Extent[1]);
  v74 = *(float *)&pos.m_end + (float)(min_box.Axis[1].m_afTuple[1] * min_box.Extent[1]);
  *(float *)&v127 = (float)((float)((float)(*(float *)&v136 * v71) + (float)(*(float *)&temp.m_begin * *(float *)&v129))
                          + (float)(*(float *)&v124 * 0.0))
                  + local_to_world.c.x;
  *(float *)&plane_id = *((float *)&v124 + 1) * 0.0;
  *((float *)&v127 + 1) = (float)((float)((float)(v71 * *((float *)&v136 + 1))
                                        + (float)(*(float *)&temp.m_begin * *((float *)&v129 + 1)))
                                + (float)(*((float *)&v124 + 1) * 0.0))
                        + local_to_world.c.y;
  v132 = *(float *)&v133.container + (float)(min_box.Axis[1].m_afTuple[0] * min_box.Extent[1]);
  v75 = (float)(min_box.Center.m_afTuple[1] + (float)(min_box.Axis[0].m_afTuple[1] * min_box.Extent[0]))
      + (float)(min_box.Axis[1].m_afTuple[1] * min_box.Extent[1]);
  *(float *)&temp_count = v125 * 0.0;
  v76 = (float)((float)((float)(v71 * v137) + (float)(*(float *)&temp.m_begin * v130)) + (float)(v125 * 0.0))
      + local_to_world.c.z;
  v77 = *((float *)&v129 + 1);
  *(_QWORD *)&(*io_points)[0].x = v127;
  *(float *)&v127 = (float)((float)((float)(v73 * v72) + (float)(*(float *)&pos.m_begin * *(float *)&v129))
                          + *(float *)&i)
                  + local_to_world.c.x;
  v78 = *(float *)&plane_id;
  *((float *)&v127 + 1) = (float)((float)((float)(v72 * *((float *)&v136 + 1))
                                        + (float)(*(float *)&pos.m_begin * *((float *)&v129 + 1)))
                                + *(float *)&plane_id)
                        + local_to_world.c.y;
  v79 = (float)((float)((float)(v72 * v137) + (float)(*(float *)&pos.m_begin * v130)) + *(float *)&temp_count)
      + local_to_world.c.z;
  *(_QWORD *)&(*io_points)[1].x = v127;
  *(float *)&v127 = (float)((float)((float)(v73 * v75) + (float)(v132 * *(float *)&v129)) + *(float *)&i)
                  + local_to_world.c.x;
  v80 = local_to_world.c.y;
  *((float *)&v127 + 1) = (float)((float)((float)(v75 * *((float *)&v136 + 1)) + (float)(v132 * v77)) + v78)
                        + local_to_world.c.y;
  v81 = *(float *)&temp_count;
  v128 = (float)((float)((float)(v75 * v137) + (float)(v132 * v130)) + *(float *)&temp_count) + local_to_world.c.z;
  *(_QWORD *)&(*io_points)[2].x = v127;
  *(float *)&v127 = (float)((float)((float)(v73 * v74) + (float)(v122 * *(float *)&v129)) + *(float *)&i)
                  + local_to_world.c.x;
  v82 = v74 * *((float *)&v136 + 1);
  v83 = v74 * v137;
  v84 = v122 * v130;
  v85 = v82 + (float)(v122 * v77);
  (*io_points)[0].z = v76;
  v86 = v128;
  (*io_points)[1].z = v79;
  (*io_points)[2].z = v86;
  *((float *)&v127 + 1) = (float)(v85 + v78) + v80;
  v87 = (*io_points)[0].x;
  v88 = (*io_points)[0].z;
  *(_QWORD *)&(*io_points)[3].x = v127;
  v128 = (float)((float)(v83 + v84) + v81) + local_to_world.c.z;
  v89 = (*io_points)[0].y;
  (*io_points)[3].z = v128;
  v90 = (*io_points)[1].z;
  v91 = (*io_points)[2].z;
  v92 = (*io_points)[2].x;
  v93 = (*io_points)[2].y - v89;
  *(float *)&v124 = (*io_points)[1].x - v87;
  v94 = v91 - v88;
  *((float *)&v124 + 1) = (*io_points)[1].y - v89;
  v95 = v92 - v87;
  v125 = v90 - v88;
  v96 = (float)(*((float *)&v124 + 1) * v94) - (float)((float)(v90 - v88) * v93);
  v97 = (*io_points)[2].x;
  *(float *)&v136 = v96;
  v98 = v95 * v125;
  v99 = (float)(v93 * *(float *)&v124) - (float)(v95 * *((float *)&v124 + 1));
  v100 = (*io_points)[2].z;
  v101 = v98 - (float)(v94 * *(float *)&v124);
  v102 = (*io_points)[3].z;
  v137 = v99;
  v103 = (*io_points)[3].y - v89;
  v104 = v102 - v88;
  v105 = v97 - v87;
  *((float *)&v136 + 1) = v101;
  v106 = (*io_points)[3].x - v87;
  v107 = (*io_points)[2].y - v89;
  io_pointsa = sqrtf(
                 (float)((float)((float)((float)(v103 * v105) - (float)(v107 * v106))
                               * (float)((float)(v103 * v105) - (float)(v107 * v106)))
                       + (float)((float)((float)((float)(v100 - v88) * v106) - (float)(v104 * v105))
                               * (float)((float)((float)(v100 - v88) * v106) - (float)(v104 * v105))))
               + (float)((float)((float)(v107 * v104) - (float)((float)(v100 - v88) * v103))
                       * (float)((float)(v107 * v104) - (float)((float)(v100 - v88) * v103))))
             * 0.5;
  io_pointsb = sqrtf(
                 (float)((float)(v137 * v137) + (float)(*((float *)&v136 + 1) * *((float *)&v136 + 1)))
               + (float)(*(float *)&v136 * *(float *)&v136))
             * 0.5
             + io_pointsa;
  return COERCE_FLOAT(LODWORD(io_pointsb) & 0x7FFFFFFF) >= 0.0000099999997;
}

void __thiscall vostok::render::speedtree_tree_component_leafcard::speedtree_tree_component_leafcard(
        vostok::render::speedtree_tree_component_leafcard *this,
        vostok::render::speedtree_tree_component_leafcard *parent,
        vostok::render::speedtree_tree *parenta)
{
  vostok::render::resource_manager *v3; // edx
  vostok::render::speedtree_tree *v4; // ebp
  vostok::render::speedtree_tree *v5; // edi
  vostok::render::res_declaration *declaration; // eax
  SpeedTree::CCore *v7; // ecx
  signed int m_nNumLeafCardLods; // eax
  unsigned __int16 *v9; // esi
  int v10; // ebx
  bool v11; // cc
  vostok::render::leafcard_vertex *v12; // ebp
  unsigned int v13; // esi
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v15; // ebx
  int v16; // ebp
  vostok::render::untyped_buffer *v17; // eax
  vostok::render::untyped_buffer *v18; // esi
  vostok::render::res_declaration *v19; // ebp
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v21; // ecx
  vostok::render::res_geometry *m_flags; // eax
  bool v23; // zf
  vostok::render::leafcard_vertex *v24; // edx
  void *v25; // esi
  void *v26; // esi
  SpeedTree::SLeafCards *v27; // edi
  unsigned __int16 *M_finish; // ecx
  unsigned __int16 *M_start; // eax
  vostok::render::grass_render_model *m_object; // edx
  unsigned __int16 *M_data; // ebp
  signed int v32; // esi
  unsigned int v33; // eax
  const float **p_card_dimensons; // ecx
  unsigned int v35; // ecx
  const float **p_card_pivot_point; // eax
  unsigned int v37; // ecx
  bool v38; // al
  unsigned __int8 *v39; // ebp
  int v40; // eax
  unsigned __int8 *v41; // eax
  unsigned __int16 *v42; // ebx
  unsigned __int16 *v43; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::leafcard_vertex *v45; // esi
  const float *m_pDimensions; // eax
  float v47; // xmm4_4
  const float *v48; // eax
  int v49; // ecx
  float v50; // xmm1_4
  float x; // xmm2_4
  float y; // xmm3_4
  int v53; // ebp
  float v54; // xmm0_4
  float v55; // xmm1_4
  long double v56; // st7
  const vostok::render::leafcard_vertex *v57; // ebx
  int v58; // ebp
  float *v59; // eoff
  float v60; // xmm1_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // ecx
  float v64; // edx
  const unsigned __int8 *m_pWindData; // eax
  unsigned __int8 v66; // al
  const unsigned __int8 *m_pNormals; // eax
  const unsigned __int8 *m_pAmbientOcclusionValues; // eax
  char v69; // al
  const unsigned __int8 *m_pTangents; // eax
  const float *m_pLodScales; // ecx
  float v72; // xmm0_4
  float *v73; // ecx
  float v74; // xmm0_4
  char IsYAxisUp; // al
  const float *v76; // ecx
  float v77; // xmm0_4
  const float *v78; // eax
  float v79; // xmm1_4
  float *v80; // eax
  const float *m_pLeafCardOffsets; // eax
  float v82; // xmm0_4
  vostok::render::grass_render_model *v83; // edi
  const vostok::render::leafcard_vertex *v84; // edx
  vostok::render::leafcard_vertex *v85; // eax
  vostok::render::leafcard_vertex *v86; // edi
  unsigned int v87; // esi
  unsigned int v88; // eax
  const float **v89; // ecx
  const float *v90; // ebx
  const float **v91; // eax
  unsigned int v92; // ecx
  bool v93; // al
  unsigned __int8 *v94; // ebp
  int v95; // eax
  float *v96; // eax
  vostok::render::leafcard_vertex *v97; // eax
  void *v98; // esi
  vostok::render::leafcard_vertex *v99; // eax
  void *v100; // esi
  unsigned __int16 *v101; // eax
  void *v102; // esi
  vostok::render::resource_manager *v103; // [esp-10h] [ebp-118h]
  vostok::render::resource_manager *v104; // [esp-10h] [ebp-118h]
  unsigned __int16 *v105; // [esp-Ch] [ebp-114h]
  vostok::render::leafcard_vertex *v106; // [esp-Ch] [ebp-114h]
  unsigned int v107; // [esp+4h] [ebp-104h]
  const float *card_dimensons; // [esp+18h] [ebp-F0h] BYREF
  int card_index; // [esp+1Ch] [ebp-ECh]
  const float *card_pivot_point; // [esp+20h] [ebp-E8h] BYREF
  const vostok::render::leafcard_vertex *it; // [esp+24h] [ebp-E4h]
  vostok::render::vector<vostok::render::leafcard_vertex> total_vertices; // [esp+28h] [ebp-E0h] BYREF
  int v113; // [esp+34h] [ebp-D4h]
  vostok::render::vector<unsigned short> total_indices; // [esp+38h] [ebp-D0h] BYREF
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> decl; // [esp+44h] [ebp-C4h]
  int v116; // [esp+48h] [ebp-C0h]
  float fMaxDistanceFromPivotPoint; // [esp+4Ch] [ebp-BCh]
  int v118; // [esp+50h] [ebp-B8h]
  int num_lods; // [esp+54h] [ebp-B4h]
  vostok::render::vector<vostok::render::leafcard_vertex> vertices; // [esp+58h] [ebp-B0h] BYREF
  vostok::render::vector<unsigned short> indices; // [esp+64h] [ebp-A4h] BYREF
  int lod_index; // [esp+70h] [ebp-98h]
  float c_fStartLodScale; // [esp+74h] [ebp-94h]
  __int64 v124; // [esp+78h] [ebp-90h]
  float v125; // [esp+80h] [ebp-88h]
  __int64 v126; // [esp+84h] [ebp-84h]
  float z; // [esp+8Ch] [ebp-7Ch]
  float v128; // [esp+90h] [ebp-78h]
  float v129; // [esp+94h] [ebp-74h]
  const SpeedTree::SLeafCards *lods; // [esp+98h] [ebp-70h]
  float card_offsets[4][2]; // [esp+9Ch] [ebp-6Ch]
  SpeedTree::Vec3 pivot; // [esp+BCh] [ebp-4Ch]
  vostok::render::leafcard_vertex dst; // [esp+C8h] [ebp-40h] BYREF

  v3 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  v4 = parenta;
  v5 = (vostok::render::speedtree_tree *)parent;
  parent->m_render_geometry.geom.m_object = 0;
  parent->m_render_geometry.shadow_pass_geom.m_object = 0;
  parent->m_render_geometry.lpv_pass_geom.m_object = 0;
  parent->m_render_geometry.shading_group_name.m_begin = parent->m_render_geometry.shading_group_name.m_buffer;
  parent->m_render_geometry.shading_group_name.m_end = parent->m_render_geometry.shading_group_name.m_buffer;
  parent->m_render_geometry.shading_group_name.m_max_end = (char *)&parent->m_materail_effects_instance;
  parent->m_render_geometry.shading_group_name.m_buffer[0] = 0;
  parent->m_render_geometry.shading_group_name.m_buffer[0] = 0;
  parent->m_materail_effects_instance.m_object = 0;
  parent->m_parent = parenta;
  parent->__vftable = (vostok::render::speedtree_tree_component_leafcard_vtbl *)&vostok::render::speedtree_tree_component_leafcard::`vftable';
  declaration = vostok::render::resource_manager::create_declaration(6u, v3, (stlp_std::forward_iterator_tag *)layout_1);
  decl.m_object = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    decl.m_object = declaration;
  }
  if ( parenta )
    v7 = &parenta->SpeedTree::CCore;
  else
    v7 = 0;
  m_nNumLeafCardLods = v7->m_sGeometry.m_nNumLeafCardLods;
  lods = v7->m_sGeometry.m_pLeafCardLods;
  parenta->m_lod_render_info[2].num_lods = m_nNumLeafCardLods;
  num_lods = m_nNumLeafCardLods;
  v9 = 0;
  v10 = 0;
  v11 = m_nNumLeafCardLods <= 0;
  parenta->m_lod_render_info[2].lods = vostok::memory::new_array_helper<vostok::render::lod_entry>::call<vostok::memory::doug_lea_allocator>(
                                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                         m_nNumLeafCardLods);
  memset(&total_indices, 0, sizeof(total_indices));
  memset(&total_vertices, 0, sizeof(total_vertices));
  lod_index = 0;
  if ( !v11 )
  {
    while ( 1 )
    {
      v27 = (SpeedTree::SLeafCards *)&lods[v10];
      if ( SpeedTree::SLeafCards::HasGeometry(v27) )
      {
        memset(&indices, 0, sizeof(indices));
        vostok::render::speedtree_tree_component_leafcard::init_index_buffer(
          &indices,
          (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)(total_vertices._M_impl._M_finish - total_vertices._M_impl._M_start),
          (vostok::render::speedtree_tree_component_leafcard *)v27,
          (const SpeedTree::SLeafCards *)(total_vertices._M_impl._M_finish - total_vertices._M_impl._M_start),
          v107);
        M_finish = indices._M_impl._M_finish;
        v4->m_lod_render_info[2].lods[v10].start_index = v9 - total_indices._M_impl._M_start;
        M_start = indices._M_impl._M_start;
        v4->m_lod_render_info[2].lods[v10].num_indices = M_finish - indices._M_impl._M_start;
        card_index = (int)M_start;
        if ( M_start != M_finish )
        {
          m_object = vostok::render::g_allocator.m_object;
          M_data = total_indices._M_impl._M_end_of_storage._M_data;
          do
          {
            if ( v9 == M_data )
            {
              v32 = (char *)v9 - (char *)total_indices._M_impl._M_start;
              v33 = v32 >> 1;
              card_pivot_point = (const float *)1;
              card_dimensons = (const float *)(v32 >> 1);
              if ( 0x7FFFFFFF == v32 >> 1 )
LABEL_143:
                stlp_std::__stl_throw_length_error("vector");
              p_card_dimensons = &card_dimensons;
              if ( v33 <= 1 )
                p_card_dimensons = &card_pivot_point;
              v35 = (unsigned int)*p_card_dimensons + v33;
              it = (const vostok::render::leafcard_vertex *)v35;
              if ( v35 > 0x7FFFFFFF || v35 < v33 )
              {
                v35 = 0x7FFFFFFF;
                it = (const vostok::render::leafcard_vertex *)0x7FFFFFFF;
              }
              card_pivot_point = (const float *)v35;
              card_dimensons = (const float *)1;
              p_card_pivot_point = &card_dimensons;
              if ( v35 )
                p_card_pivot_point = &card_pivot_point;
              v37 = 2 * (_DWORD)*p_card_pivot_point;
              v38 = BYTE2(m_object->m_children_resources.m_lock) && v37;
              BYTE2(m_object->m_children_resources.m_lock) = v38;
              if ( v37 )
                v39 = (unsigned __int8 *)vostok_mspace_malloc(
                                           (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                           v37);
              else
                v39 = 0;
              if ( v32 )
              {
                memmove(v39, (unsigned __int8 *)total_indices._M_impl._M_start, v32);
                v41 = (unsigned __int8 *)(v32 + v40);
              }
              else
              {
                v41 = v39;
              }
              v23 = total_indices._M_impl._M_start == 0;
              *(_WORD *)v41 = *(_WORD *)card_index;
              m_object = vostok::render::g_allocator.m_object;
              v42 = (unsigned __int16 *)(v41 + 2);
              if ( !v23 )
              {
                v43 = total_indices._M_impl._M_start;
                m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v43);
                m_object = vostok::render::g_allocator.m_object;
              }
              total_indices._M_impl._M_start = (unsigned __int16 *)v39;
              M_data = (unsigned __int16 *)&v39[2 * (_DWORD)it];
              v9 = v42;
              total_indices._M_impl._M_end_of_storage._M_data = M_data;
            }
            else
            {
              *v9 = *(_WORD *)card_index;
              m_object = vostok::render::g_allocator.m_object;
              ++v9;
            }
            total_indices._M_impl._M_finish = v9;
            card_index += 2;
          }
          while ( (unsigned __int16 *)card_index != indices._M_impl._M_finish );
        }
        memset(&vertices, 0, sizeof(vertices));
        memset((int)&dst, 0, sizeof(dst));
        stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex>>::resize(
          4 * v27->m_nTotalNumCards,
          &vertices._M_impl,
          &dst);
        v11 = v27->m_nTotalNumCards <= 0;
        v45 = vertices._M_impl._M_start;
        card_index = 0;
        if ( !v11 )
        {
          v116 = 0;
          it = 0;
          do
          {
            m_pDimensions = v27->m_pDimensions;
            v47 = m_pDimensions[2 * card_index + 1];
            v48 = &m_pDimensions[2 * card_index];
            v49 = (int)&v27->m_pPivotPoints[2 * card_index];
            card_offsets[0][1] = FLOAT_0_5;
            card_offsets[1][0] = FLOAT_0_5;
            card_offsets[1][1] = FLOAT_0_5;
            *(_QWORD *)&card_offsets[2][0] = LODWORD(FLOAT_0_5) | 0xBF00000000000000uLL;
            v50 = *v48;
            x = *v48 * *(float *)v49;
            y = v47 * *(float *)(v49 + 4);
            card_offsets[0][0] = -0.5;
            *(_QWORD *)&card_offsets[3][0] = 0xBF000000BF000000uLL;
            card_dimensons = v48;
            card_pivot_point = (const float *)v49;
            v128 = v50;
            pivot.x = x;
            v129 = v47;
            pivot.y = y;
            fMaxDistanceFromPivotPoint = 0.0;
            v53 = 0;
            while ( 1 )
            {
              v54 = card_offsets[v53][0] * v50;
              v55 = (float)(card_offsets[v53][1] * v47) - y;
              v56 = sqrtf((float)(v55 * v55) + (float)((float)(v54 - x) * (float)(v54 - x)));
              *(float *)&v113 = v56;
              if ( fMaxDistanceFromPivotPoint <= v56 )
                fMaxDistanceFromPivotPoint = *(float *)&v113;
              if ( ++v53 >= 4 )
                break;
              v50 = v128;
              v47 = v129;
              y = pivot.y;
              x = pivot.x;
            }
            v57 = it;
            v118 = 16 * card_index;
            v58 = 0;
            v113 = 32 * card_index;
            do
            {
              v59 = (float *)((char *)it->m_afCardCenter + (unsigned int)v27->m_pPositions);
              *(_QWORD *)v45->m_afCardCenter = *(_QWORD *)v59;
              v45->m_afCardCenter[2] = v59[2];
              v60 = v45->m_afCardCenter[0];
              v61 = v45->m_afCardCenter[1];
              v62 = v45->m_afCardCenter[2];
              if ( v45->m_afCardCenter[0] <= parenta->m_bbox.min.x )
                *(float *)&v126 = v45->m_afCardCenter[0];
              else
                *(float *)&v126 = parenta->m_bbox.min.x;
              if ( v61 <= parenta->m_bbox.min.y )
                *((float *)&v126 + 1) = v61;
              else
                HIDWORD(v126) = LODWORD(parenta->m_bbox.min.y);
              if ( v62 <= parenta->m_bbox.min.z )
                z = v62;
              else
                z = parenta->m_bbox.min.z;
              v63 = z;
              *(_QWORD *)&parenta->m_bbox.min.x = v126;
              parenta->m_bbox.min.z = v63;
              if ( parenta->m_bbox.max.x <= v60 )
                *(float *)&v124 = v60;
              else
                *(float *)&v124 = parenta->m_bbox.max.x;
              if ( parenta->m_bbox.max.y <= v61 )
                *((float *)&v124 + 1) = v61;
              else
                HIDWORD(v124) = LODWORD(parenta->m_bbox.max.y);
              if ( parenta->m_bbox.max.z <= v62 )
                v125 = v62;
              else
                v125 = parenta->m_bbox.max.z;
              v64 = v125;
              *(_QWORD *)&parenta->m_bbox.max.x = v124;
              parenta->m_bbox.max.z = v64;
              m_pWindData = v27->m_pWindData;
              if ( m_pWindData )
              {
                v66 = m_pWindData[v116 + 4];
                if ( v66 == 127 )
                  v45->m_fWindScalar = 0.0 * 10.0;
                else
                  v45->m_fWindScalar = (float)((float)((float)v66 * 0.0078431377) - *(float *)&clear_value) * 10.0;
              }
              else
              {
                v45->m_fWindScalar = 0.0;
              }
              m_pNormals = v27->m_pNormals;
              *(_WORD *)v45->m_aucNormal = *(_WORD *)((char *)v57->m_afCardCenter + (_DWORD)m_pNormals);
              v45->m_aucNormal[2] = m_pNormals[(_DWORD)v57 + 2];
              m_pAmbientOcclusionValues = v27->m_pAmbientOcclusionValues;
              if ( m_pAmbientOcclusionValues )
                v69 = m_pAmbientOcclusionValues[card_index];
              else
                v69 = -1;
              v45->m_ucAmbOcc = v69;
              m_pTangents = v27->m_pTangents;
              *(_WORD *)v45->m_aucTangent = *(_WORD *)((char *)v57->m_afCardCenter + (_DWORD)m_pTangents);
              v45->m_aucTangent[2] = m_pTangents[(_DWORD)v57 + 2];
              v45->m_ucTangentPadding = 0;
              if ( v27->m_pWindData )
              {
                v45->m_fWindScalarMag = v27->m_fWindDataMagnitude;
                *(_DWORD *)v45->m_aucWindData = *(_DWORD *)&v27->m_pWindData[v116];
              }
              else
              {
                v45->m_fWindScalarMag = 0.0;
                v45->m_aucWindData[3] = 0;
                v45->m_aucWindData[2] = 0;
                v45->m_aucWindData[1] = 0;
                v45->m_aucWindData[0] = 0;
              }
              m_pLodScales = v27->m_pLodScales;
              v72 = m_pLodScales[2 * card_index + 1];
              v73 = (float *)&m_pLodScales[2 * card_index];
              if ( v72 == 0.0 )
              {
                v45->m_fLodScale = 0.0;
              }
              else
              {
                if ( *v73 == v72 )
                  v74 = *(float *)&clear_value;
                else
                  v74 = v72 / *v73;
                v45->m_fLodScale = v74;
              }
              c_fStartLodScale = *v73;
              IsYAxisUp = SpeedTree::CCoordSys::IsYAxisUp();
              v76 = card_pivot_point;
              v77 = c_fStartLodScale;
              v23 = IsYAxisUp == 0;
              v78 = card_dimensons;
              if ( v23 )
              {
                v45->m_afCardCorner[0] = (float)((float)(card_offsets[v58][0] - *card_pivot_point) * *card_dimensons)
                                       * c_fStartLodScale;
                v79 = (float)((float)(card_offsets[v58][1] - v76[1]) * v77) * v78[1];
              }
              else
              {
                v45->m_afCardCorner[0] = (float)((float)(card_offsets[v58][1] - card_pivot_point[1]) * c_fStartLodScale)
                                       * card_dimensons[1];
                v79 = (float)((float)(card_offsets[v58][0] - *v76) * *v78) * v77;
              }
              v45->m_afCardCorner[1] = v79;
              v80 = (float *)&v27->m_pTexCoordsDiffuse[v113 / 4u];
              v45->m_afDiffuseTexCoords[0] = *v80;
              v45->m_afDiffuseTexCoords[1] = v80[1];
              m_pLeafCardOffsets = v27->m_pLeafCardOffsets;
              if ( m_pLeafCardOffsets )
                v82 = m_pLeafCardOffsets[v118 / 4u];
              else
                v82 = 0.0;
              v118 += 4;
              v113 += 8;
              v45->m_fPlanarOffset = v82;
              v45->m_fShadowOffset = fMaxDistanceFromPivotPoint;
              ++v58;
              ++v45;
              v57 = (const vostok::render::leafcard_vertex *)((char *)v57 + 3);
            }
            while ( v58 < 4 );
            v116 += 5;
            v11 = ++card_index < v27->m_nTotalNumCards;
            it = v57;
          }
          while ( v11 );
          v45 = vertices._M_impl._M_start;
        }
        v83 = vostok::render::g_allocator.m_object;
        v84 = v45;
        it = v45;
        if ( v45 != vertices._M_impl._M_finish )
        {
          v85 = total_vertices._M_impl._M_finish;
          do
          {
            if ( v85 == total_vertices._M_impl._M_end_of_storage._M_data )
            {
              v87 = (char *)v85 - (char *)total_vertices._M_impl._M_start;
              v88 = v85 - total_vertices._M_impl._M_start;
              card_pivot_point = (const float *)1;
              card_dimensons = (const float *)v88;
              if ( &vostok::memory::s_CRT_arena[60379772] == (unsigned __int8 *)v88 )
                goto LABEL_143;
              v89 = &card_dimensons;
              if ( v88 <= 1 )
                v89 = &card_pivot_point;
              v90 = (const float *)((char *)*v89 + v88);
              if ( v90 > (const float *)&vostok::memory::s_CRT_arena[60379772] || (unsigned int)v90 < v88 )
                v90 = (const float *)&vostok::memory::s_CRT_arena[60379772];
              card_pivot_point = v90;
              card_dimensons = (const float *)1;
              v91 = &card_dimensons;
              if ( v90 )
                v91 = &card_pivot_point;
              v92 = 60 * (_DWORD)*v91;
              v93 = BYTE2(v83->m_children_resources.m_lock) && v92;
              BYTE2(v83->m_children_resources.m_lock) = v93;
              if ( v92 )
                v94 = (unsigned __int8 *)vostok_mspace_malloc(
                                           (void *)HIDWORD(v83->m_reconstruction_info_actuality_tick),
                                           v92);
              else
                v94 = 0;
              if ( v87 )
              {
                memmove(v94, (unsigned __int8 *)total_vertices._M_impl._M_start, v87);
                v96 = (float *)(v87 + v95);
              }
              else
              {
                v96 = (float *)v94;
              }
              v23 = total_vertices._M_impl._M_start == 0;
              qmemcpy(v96, it, 0x3Cu);
              v83 = vostok::render::g_allocator.m_object;
              card_dimensons = v96 + 15;
              if ( !v23 )
              {
                v97 = total_vertices._M_impl._M_start;
                v98 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                vostok_mspace_free(v98, v97);
                v83 = vostok::render::g_allocator.m_object;
              }
              v84 = it;
              total_vertices._M_impl._M_end_of_storage._M_data = (vostok::render::leafcard_vertex *)&v94[60 * (_DWORD)v90];
              total_vertices._M_impl._M_start = (vostok::render::leafcard_vertex *)v94;
              total_vertices._M_impl._M_finish = (vostok::render::leafcard_vertex *)card_dimensons;
              v85 = (vostok::render::leafcard_vertex *)card_dimensons;
            }
            else
            {
              v86 = v85++;
              qmemcpy(v86, v84, sizeof(vostok::render::leafcard_vertex));
              v83 = vostok::render::g_allocator.m_object;
              total_vertices._M_impl._M_finish = v85;
            }
            it = ++v84;
          }
          while ( v84 != vertices._M_impl._M_finish );
          v45 = vertices._M_impl._M_start;
        }
        if ( v45 )
        {
          v99 = v45;
          v100 = (void *)HIDWORD(v83->m_reconstruction_info_actuality_tick);
          BYTE2(v83->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v100, v99);
          v83 = vostok::render::g_allocator.m_object;
        }
        if ( indices._M_impl._M_start )
        {
          v101 = indices._M_impl._M_start;
          v102 = (void *)HIDWORD(v83->m_reconstruction_info_actuality_tick);
          BYTE2(v83->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v102, v101);
        }
      }
      v9 = total_indices._M_impl._M_finish;
      v10 = ++lod_index;
      if ( lod_index >= num_lods )
        break;
      v4 = parenta;
    }
    v5 = (vostok::render::speedtree_tree *)parent;
  }
  v12 = total_vertices._M_impl._M_finish;
  v13 = v9 - total_indices._M_impl._M_start;
  v105 = total_indices._M_impl._M_start;
  v103 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  v5->m_reconstruction_size = v13;
  *(&v5->m_reconstruction_size + 1) = v13 / 3;
  buffer = vostok::render::resource_manager::create_buffer(2 * v13, (bool)v5, v103, v105, enum_buffer_type_index, 0, 0);
  v15 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v15 = buffer;
  }
  v16 = (char *)v12 - (char *)total_vertices._M_impl._M_start;
  v106 = total_vertices._M_impl._M_start;
  v104 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  HIDWORD(v5->m_reconstruction_info_actuality_tick) = v16 / 60;
  v17 = vostok::render::resource_manager::create_buffer(
          60 * (v16 / 60),
          (bool)v5,
          v104,
          v106,
          enum_buffer_type_vertex,
          (vostok::render::untyped_buffer *)1,
          0);
  v18 = 0;
  if ( v17 )
  {
    ++v17->m_reference_count;
    v18 = v17;
  }
  v19 = decl.m_object;
  geometry = vostok::render::resource_manager::create_geometry(
               decl.m_object,
               v18,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               0x3Cu,
               v15);
  v21 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v21 = geometry;
  }
  m_flags = (vostok::render::res_geometry *)v5->vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v5->vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = (volatile int)v21;
  if ( m_flags )
  {
    v23 = m_flags->m_reference_count-- == 1;
    if ( v23 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_flags);
  }
  if ( v18 )
  {
    v23 = v18->m_reference_count-- == 1;
    if ( v23 )
    {
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v18,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
      v19 = decl.m_object;
    }
  }
  if ( v15 )
  {
    v23 = v15->m_reference_count-- == 1;
    if ( v23 )
    {
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v15,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
      v19 = decl.m_object;
    }
  }
  v24 = total_vertices._M_impl._M_start;
  if ( total_vertices._M_impl._M_start )
  {
    v25 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v25, v24);
  }
  if ( total_indices._M_impl._M_start )
  {
    v26 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v26, total_indices._M_impl._M_start);
  }
  if ( v19 )
  {
    v23 = v19->m_reference_count-- == 1;
    if ( v23 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v19);
  }
}

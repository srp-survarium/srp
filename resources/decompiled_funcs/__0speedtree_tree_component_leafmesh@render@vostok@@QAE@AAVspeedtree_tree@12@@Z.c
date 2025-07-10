void __thiscall vostok::render::speedtree_tree_component_leafmesh::speedtree_tree_component_leafmesh(
        vostok::render::speedtree_tree_component_leafmesh *this,
        vostok::render::speedtree_tree_component_leafmesh *parent,
        vostok::render::speedtree_tree *parenta)
{
  vostok::render::resource_manager *v3; // edx
  vostok::render::speedtree_tree *v4; // ebx
  vostok::render::speedtree_tree *v5; // edi
  vostok::render::res_declaration *declaration; // eax
  SpeedTree::CCore *v7; // eax
  int m_nNumLeafMeshLods; // ebp
  unsigned __int16 *v9; // ecx
  unsigned __int16 *v10; // esi
  vostok::render::leafmesh_vertex *v11; // ebx
  unsigned int v12; // esi
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v14; // ebp
  int v15; // ebx
  vostok::render::resource_manager *v16; // ecx
  vostok::render::untyped_buffer *v17; // eax
  vostok::render::untyped_buffer *v18; // ebx
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v20; // ecx
  vostok::render::res_geometry *m_flags; // eax
  bool v22; // zf
  survarium::options_tab *v23; // edi
  vostok::render::leafmesh_vertex *v24; // eax
  void *v25; // esi
  unsigned __int16 *v26; // eax
  void *v27; // esi
  vostok::render::res_declaration *v28; // eax
  SpeedTree::SIndexedTriangles *v29; // ebp
  int v30; // ecx
  unsigned __int16 *M_finish; // edx
  unsigned __int16 *M_start; // eax
  vostok::render::grass_render_model *m_object; // edx
  unsigned __int8 *v34; // edi
  unsigned __int16 v35; // cx
  unsigned int v36; // ebx
  unsigned int v37; // eax
  int *v38; // ecx
  unsigned int v39; // esi
  int *v40; // eax
  unsigned int v41; // ecx
  bool v42; // al
  int v43; // eax
  unsigned __int8 *v44; // eax
  unsigned __int16 *v45; // ebx
  unsigned __int16 *v46; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int16 *v48; // eax
  int v49; // ebx
  int v50; // esi
  const vostok::math::float4x4 *v51; // xmm6_4
  int v52; // edx
  float *p_m_fWindScalar; // ecx
  const float *v54; // eax
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // eax
  float v59; // edi
  const unsigned __int8 *m_pWindData; // edi
  unsigned __int8 v61; // al
  const float *m_pLodCoords; // eax
  char *v63; // eax
  const unsigned __int8 *m_pAmbientOcclusionValues; // edi
  char v65; // al
  char *v66; // eax
  char v67; // al
  double v68; // st7
  double v69; // st7
  vostok::render::leafmesh_vertex *v70; // ebx
  vostok::render::grass_render_model *v71; // edx
  vostok::render::leafmesh_vertex *v72; // eax
  vostok::render::leafmesh_vertex *v73; // edi
  unsigned int v74; // esi
  unsigned int v75; // eax
  int *v76; // ecx
  unsigned int v77; // ebp
  int *v78; // eax
  unsigned int v79; // ecx
  bool v80; // al
  unsigned __int8 *v81; // ebx
  int v82; // eax
  vostok::render::leafmesh_vertex *v83; // eax
  vostok::render::leafmesh_vertex *v84; // edi
  vostok::render::leafmesh_vertex *v85; // eax
  void *v86; // esi
  vostok::render::leafmesh_vertex *v87; // ebp
  void *v88; // esi
  unsigned __int16 *v89; // eax
  void *v90; // esi
  vostok::render::resource_manager *v91; // [esp-14h] [ebp-D8h]
  vostok::render::leafmesh_vertex *v92; // [esp-10h] [ebp-D4h]
  const SpeedTree::SIndexedTriangles *v93; // [esp+0h] [ebp-C4h]
  const vostok::render::leafmesh_vertex *it; // [esp+10h] [ebp-B4h]
  const vostok::render::leafmesh_vertex *ita; // [esp+10h] [ebp-B4h]
  vostok::render::leafmesh_vertex *itb; // [esp+10h] [ebp-B4h]
  int v97; // [esp+14h] [ebp-B0h] BYREF
  vostok::render::vector<vostok::render::leafmesh_vertex> total_vertices; // [esp+18h] [ebp-ACh] BYREF
  int v99; // [esp+24h] [ebp-A0h] BYREF
  vostok::render::vector<unsigned short> total_indices; // [esp+28h] [ebp-9Ch] BYREF
  int lod_index; // [esp+34h] [ebp-90h]
  int v102; // [esp+38h] [ebp-8Ch] BYREF
  int num_lods; // [esp+3Ch] [ebp-88h] BYREF
  int v104; // [esp+40h] [ebp-84h] BYREF
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> decl; // [esp+44h] [ebp-80h]
  vostok::render::vector<vostok::render::leafmesh_vertex> vertices; // [esp+48h] [ebp-7Ch] BYREF
  vostok::render::vector<unsigned short> indices; // [esp+54h] [ebp-70h] BYREF
  unsigned int v108; // [esp+60h] [ebp-64h] BYREF
  __int64 v109; // [esp+64h] [ebp-60h]
  float z; // [esp+6Ch] [ebp-58h]
  __int64 v111; // [esp+70h] [ebp-54h]
  float v112; // [esp+78h] [ebp-4Ch]
  const SpeedTree::SIndexedTriangles *lods; // [esp+7Ch] [ebp-48h]
  vostok::render::leafmesh_vertex dst; // [esp+80h] [ebp-44h] BYREF

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
  parent->__vftable = (vostok::render::speedtree_tree_component_leafmesh_vtbl *)&vostok::render::speedtree_tree_component_leafmesh::`vftable';
  declaration = vostok::render::resource_manager::create_declaration(7u, v3, (stlp_std::forward_iterator_tag *)layout_2);
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
  m_nNumLeafMeshLods = v7->m_sGeometry.m_nNumLeafMeshLods;
  lods = v7->m_sGeometry.m_pLeafMeshLods;
  parenta->m_lod_render_info[3].num_lods = m_nNumLeafMeshLods;
  num_lods = m_nNumLeafMeshLods;
  parenta->m_lod_render_info[3].lods = vostok::memory::new_array_helper<vostok::render::lod_entry>::call<vostok::memory::doug_lea_allocator>(
                                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                         m_nNumLeafMeshLods);
  v9 = 0;
  v10 = 0;
  memset(&total_indices, 0, sizeof(total_indices));
  memset(&total_vertices, 0, sizeof(total_vertices));
  lod_index = 0;
  if ( m_nNumLeafMeshLods > 0 )
  {
    while ( 1 )
    {
      v29 = (SpeedTree::SIndexedTriangles *)&lods[lod_index];
      if ( SpeedTree::SIndexedTriangles::HasGeometry(v29) )
      {
        memset(&indices, 0, sizeof(indices));
        vostok::render::speedtree_tree_component_leafmesh::init_index_buffer(
          &indices,
          (vostok::render::speedtree_tree_component_leafmesh *)v29,
          v93);
        v30 = lod_index;
        v4->m_lod_render_info[3].lods[lod_index].start_index = v10 - total_indices._M_impl._M_start;
        M_finish = indices._M_impl._M_finish;
        M_start = indices._M_impl._M_start;
        v4->m_lod_render_info[3].lods[v30].num_indices = indices._M_impl._M_finish - indices._M_impl._M_start;
        it = (const vostok::render::leafmesh_vertex *)M_start;
        if ( M_start != M_finish )
        {
          m_object = vostok::render::g_allocator.m_object;
          v34 = (unsigned __int8 *)(total_vertices._M_impl._M_finish - total_vertices._M_impl._M_start);
          v97 = (int)v34;
          do
          {
            v35 = (_WORD)v34 + *M_start;
            v99 = v35;
            if ( v10 == total_indices._M_impl._M_end_of_storage._M_data )
            {
              v36 = (char *)v10 - (char *)total_indices._M_impl._M_start;
              v37 = v10 - total_indices._M_impl._M_start;
              v104 = 1;
              v102 = v37;
              if ( v37 == 0x7FFFFFFF )
LABEL_130:
                stlp_std::__stl_throw_length_error("vector");
              v38 = &v102;
              if ( v37 <= 1 )
                v38 = &v104;
              v39 = v37 + *v38;
              v102 = v39;
              if ( v39 > 0x7FFFFFFF || v39 < v37 )
              {
                v39 = 0x7FFFFFFF;
                v102 = 0x7FFFFFFF;
              }
              v108 = v39;
              v104 = 1;
              v40 = &v104;
              if ( v39 )
                v40 = (int *)&v108;
              v41 = 2 * *v40;
              v42 = BYTE2(m_object->m_children_resources.m_lock) && v41;
              BYTE2(m_object->m_children_resources.m_lock) = v42;
              if ( v41 )
                v34 = (unsigned __int8 *)vostok_mspace_malloc(
                                           (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                           v41);
              else
                v34 = 0;
              if ( v36 )
              {
                memmove(v34, (unsigned __int8 *)total_indices._M_impl._M_start, v36);
                v44 = (unsigned __int8 *)(v36 + v43);
              }
              else
              {
                v44 = v34;
              }
              v22 = total_indices._M_impl._M_start == 0;
              *(_WORD *)v44 = v99;
              m_object = vostok::render::g_allocator.m_object;
              v45 = (unsigned __int16 *)(v44 + 2);
              if ( !v22 )
              {
                v46 = total_indices._M_impl._M_start;
                m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v46);
                m_object = vostok::render::g_allocator.m_object;
                v39 = v102;
              }
              v48 = (unsigned __int16 *)&v34[2 * v39];
              total_indices._M_impl._M_start = (unsigned __int16 *)v34;
              LOWORD(v34) = v97;
              total_indices._M_impl._M_end_of_storage._M_data = v48;
              M_start = (unsigned __int16 *)it;
              total_indices._M_impl._M_finish = v45;
              v10 = v45;
            }
            else
            {
              *v10 = v35;
              m_object = vostok::render::g_allocator.m_object;
              total_indices._M_impl._M_finish = ++v10;
            }
            it = (const vostok::render::leafmesh_vertex *)++M_start;
          }
          while ( M_start != indices._M_impl._M_finish );
        }
        v49 = 0;
        memset(&vertices, 0, sizeof(vertices));
        memset((int)&dst, 0, sizeof(dst));
        stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::resize(
          &vertices._M_impl,
          v29->m_nNumVertices,
          &dst);
        v50 = 0;
        if ( v29->m_nNumVertices > 0 )
        {
          v51 = clear_value;
          v52 = 0;
          ita = 0;
          p_m_fWindScalar = &vertices._M_impl._M_start->m_fWindScalar;
          do
          {
            v54 = &v29->m_pCoords[v52];
            *(_QWORD *)(p_m_fWindScalar - 3) = *(_QWORD *)v54;
            *(p_m_fWindScalar - 1) = v54[2];
            v55 = *(p_m_fWindScalar - 3);
            v56 = *(p_m_fWindScalar - 2);
            v57 = *(p_m_fWindScalar - 1);
            if ( v55 <= parenta->m_bbox.min.x )
              *(float *)&v109 = *(p_m_fWindScalar - 3);
            else
              *(float *)&v109 = parenta->m_bbox.min.x;
            if ( v56 <= parenta->m_bbox.min.y )
              *((float *)&v109 + 1) = v56;
            else
              HIDWORD(v109) = LODWORD(parenta->m_bbox.min.y);
            if ( v57 <= parenta->m_bbox.min.z )
              z = v57;
            else
              z = parenta->m_bbox.min.z;
            v58 = z;
            *(_QWORD *)&parenta->m_bbox.min.x = v109;
            parenta->m_bbox.min.z = v58;
            if ( parenta->m_bbox.max.x <= v55 )
              *(float *)&v111 = v55;
            else
              *(float *)&v111 = parenta->m_bbox.max.x;
            if ( parenta->m_bbox.max.y <= v56 )
              *((float *)&v111 + 1) = v56;
            else
              HIDWORD(v111) = LODWORD(parenta->m_bbox.max.y);
            if ( parenta->m_bbox.max.z <= v57 )
              v112 = v57;
            else
              v112 = parenta->m_bbox.max.z;
            v59 = v112;
            *(_QWORD *)&parenta->m_bbox.max.x = v111;
            parenta->m_bbox.max.z = v59;
            m_pWindData = v29->m_pWindData;
            if ( m_pWindData )
            {
              v61 = m_pWindData[v49 + 4];
              if ( v61 == 127 )
                *p_m_fWindScalar = 0.0 * 10.0;
              else
                *p_m_fWindScalar = (float)((float)((float)v61 * 0.0078431377) - *(float *)&v51) * 10.0;
            }
            else
            {
              *p_m_fWindScalar = 0.0;
            }
            m_pLodCoords = v29->m_pLodCoords;
            if ( !m_pLodCoords )
              m_pLodCoords = v29->m_pCoords;
            *(_QWORD *)(p_m_fWindScalar + 1) = *(_QWORD *)&m_pLodCoords[v52];
            p_m_fWindScalar[3] = m_pLodCoords[v52 + 2];
            v63 = (char *)ita + (unsigned int)v29->m_pNormals;
            *((_WORD *)p_m_fWindScalar + 10) = *(_WORD *)v63;
            *((_BYTE *)p_m_fWindScalar + 22) = v63[2];
            m_pAmbientOcclusionValues = v29->m_pAmbientOcclusionValues;
            if ( m_pAmbientOcclusionValues )
              v65 = m_pAmbientOcclusionValues[v50];
            else
              v65 = -1;
            *((_BYTE *)p_m_fWindScalar + 23) = v65;
            v66 = (char *)ita + (unsigned int)v29->m_pTangents;
            *((_WORD *)p_m_fWindScalar + 12) = *(_WORD *)v66;
            *((_BYTE *)p_m_fWindScalar + 26) = v66[2];
            if ( (float)v29->m_pWindData[v49 + 5] == 0.0 )
              v67 = 0;
            else
              v67 = -1;
            *((_BYTE *)p_m_fWindScalar + 27) = v67;
            if ( v29->m_pWindData )
            {
              p_m_fWindScalar[4] = v29->m_fWindDataMagnitude;
              p_m_fWindScalar[7] = *(float *)&v29->m_pWindData[v49];
            }
            else
            {
              p_m_fWindScalar[4] = 0.0;
              *((_BYTE *)p_m_fWindScalar + 31) = 0;
              *((_BYTE *)p_m_fWindScalar + 30) = 0;
              *((_BYTE *)p_m_fWindScalar + 29) = 0;
              *((_BYTE *)p_m_fWindScalar + 28) = 0;
            }
            ita = (const vostok::render::leafmesh_vertex *)((char *)ita + 3);
            p_m_fWindScalar[8] = v29->m_pTexCoordsDiffuse[2 * v50];
            v68 = v29->m_pTexCoordsDiffuse[2 * v50++ + 1];
            p_m_fWindScalar[9] = v68;
            p_m_fWindScalar += 16;
            *(p_m_fWindScalar - 6) = v29->m_pLeafMeshWind[v52];
            v49 += 6;
            *(p_m_fWindScalar - 5) = v29->m_pLeafMeshWind[v52 + 1];
            v69 = v29->m_pLeafMeshWind[v52 + 2];
            v52 += 3;
            *(p_m_fWindScalar - 4) = v69;
          }
          while ( v50 < v29->m_nNumVertices );
        }
        v70 = vertices._M_impl._M_start;
        v71 = vostok::render::g_allocator.m_object;
        itb = vertices._M_impl._M_start;
        if ( vertices._M_impl._M_start != vertices._M_impl._M_finish )
        {
          v72 = total_vertices._M_impl._M_finish;
          do
          {
            if ( v72 == total_vertices._M_impl._M_end_of_storage._M_data )
            {
              v74 = (char *)v72 - (char *)total_vertices._M_impl._M_start;
              v75 = v72 - total_vertices._M_impl._M_start;
              v99 = 1;
              v97 = v75;
              if ( &vostok::memory::s_CRT_arena[55905847] == (unsigned __int8 *)v75 )
                goto LABEL_130;
              v76 = &v97;
              if ( v75 <= 1 )
                v76 = &v99;
              v77 = v75 + *v76;
              if ( v77 > (unsigned int)&vostok::memory::s_CRT_arena[55905847] || v77 < v75 )
                v77 = (unsigned int)&vostok::memory::s_CRT_arena[55905847];
              v99 = v77;
              v97 = 1;
              v78 = &v97;
              if ( v77 )
                v78 = &v99;
              v79 = *v78 << 6;
              v80 = BYTE2(v71->m_children_resources.m_lock) && v79;
              BYTE2(v71->m_children_resources.m_lock) = v80;
              if ( v79 )
                v81 = (unsigned __int8 *)vostok_mspace_malloc(
                                           (void *)HIDWORD(v71->m_reconstruction_info_actuality_tick),
                                           v79);
              else
                v81 = 0;
              if ( v74 )
              {
                memmove(v81, (unsigned __int8 *)total_vertices._M_impl._M_start, v74);
                v83 = (vostok::render::leafmesh_vertex *)(v74 + v82);
              }
              else
              {
                v83 = (vostok::render::leafmesh_vertex *)v81;
              }
              v22 = total_vertices._M_impl._M_start == 0;
              qmemcpy(v83, itb, sizeof(vostok::render::leafmesh_vertex));
              v71 = vostok::render::g_allocator.m_object;
              v84 = v83 + 1;
              if ( !v22 )
              {
                v85 = total_vertices._M_impl._M_start;
                v86 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                vostok_mspace_free(v86, v85);
                v71 = vostok::render::g_allocator.m_object;
              }
              v87 = (vostok::render::leafmesh_vertex *)&v81[64 * v77];
              total_vertices._M_impl._M_start = (vostok::render::leafmesh_vertex *)v81;
              v70 = itb;
              total_vertices._M_impl._M_finish = v84;
              total_vertices._M_impl._M_end_of_storage._M_data = v87;
              v72 = v84;
            }
            else
            {
              v73 = v72++;
              qmemcpy(v73, v70, sizeof(vostok::render::leafmesh_vertex));
              v71 = vostok::render::g_allocator.m_object;
              total_vertices._M_impl._M_finish = v72;
            }
            itb = ++v70;
          }
          while ( v70 != vertices._M_impl._M_finish );
          v70 = vertices._M_impl._M_start;
        }
        if ( v70 )
        {
          v88 = (void *)HIDWORD(v71->m_reconstruction_info_actuality_tick);
          BYTE2(v71->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v88, v70);
          v71 = vostok::render::g_allocator.m_object;
        }
        if ( indices._M_impl._M_start )
        {
          v89 = indices._M_impl._M_start;
          v90 = (void *)HIDWORD(v71->m_reconstruction_info_actuality_tick);
          BYTE2(v71->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v90, v89);
        }
        v10 = total_indices._M_impl._M_finish;
      }
      if ( ++lod_index >= num_lods )
        break;
      v4 = parenta;
    }
    v5 = (vostok::render::speedtree_tree *)parent;
    v9 = total_indices._M_impl._M_start;
  }
  v11 = total_vertices._M_impl._M_finish;
  v12 = v10 - v9;
  *(&v5->m_reconstruction_size + 1) = v12 / 3;
  v91 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  v5->m_reconstruction_size = v12;
  buffer = vostok::render::resource_manager::create_buffer(2 * v12, (bool)v5, v91, v9, enum_buffer_type_index, 0, 0);
  v14 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v14 = buffer;
  }
  v15 = (char *)v11 - (char *)total_vertices._M_impl._M_start;
  v92 = total_vertices._M_impl._M_start;
  v16 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  HIDWORD(v5->m_reconstruction_info_actuality_tick) = v15 >> 6;
  v17 = vostok::render::resource_manager::create_buffer(
          v15 >> 6 << 6,
          (bool)v5,
          v16,
          v92,
          enum_buffer_type_vertex,
          (vostok::render::untyped_buffer *)1,
          0);
  v18 = 0;
  if ( v17 )
  {
    ++v17->m_reference_count;
    v18 = v17;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               decl.m_object,
               v18,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               0x40u,
               v14);
  v20 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v20 = geometry;
  }
  m_flags = (vostok::render::res_geometry *)v5->vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v5->vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = (volatile int)v20;
  if ( m_flags )
  {
    v22 = m_flags->m_reference_count-- == 1;
    if ( v22 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_flags);
  }
  if ( v18 )
  {
    v22 = v18->m_reference_count-- == 1;
    if ( v22 )
    {
      v23 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      num_lods = (int)v18;
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             (const vostok::render::res_state *)v18) )
      {
        v23[2].m_options = (survarium::options_item_base **)((char *)v23[2].m_options - v18->m_size);
        vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::res_signature const,vostok::render::resource_manager_call_destructor_predicate>(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          (const vostok::render::untyped_buffer **)&num_lods);
      }
    }
  }
  if ( v14 )
  {
    v22 = v14->m_reference_count-- == 1;
    if ( v22 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v14,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v24 = total_vertices._M_impl._M_start;
  if ( total_vertices._M_impl._M_start )
  {
    v25 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v25, v24);
  }
  v26 = total_indices._M_impl._M_start;
  if ( total_indices._M_impl._M_start )
  {
    v27 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v27, v26);
  }
  v28 = decl.m_object;
  if ( decl.m_object )
  {
    v22 = decl.m_object->m_reference_count-- == 1;
    if ( v22 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v28);
  }
}

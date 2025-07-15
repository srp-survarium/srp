void __thiscall vostok::render::speedtree_tree_component_frond::speedtree_tree_component_frond(
        vostok::render::speedtree_tree_component_frond *this,
        vostok::render::speedtree_tree_component_frond *parent,
        vostok::render::speedtree_tree *parenta)
{
  vostok::render::resource_manager *v3; // edx
  vostok::render::speedtree_tree *v4; // ebx
  vostok::render::speedtree_tree *v5; // ebp
  vostok::render::res_declaration *declaration; // eax
  SpeedTree::CCore *v7; // eax
  vostok::render::grass_render_model *m_nNumFrondLods; // edi
  int v9; // eax
  unsigned __int16 *v10; // ecx
  unsigned __int16 *v11; // esi
  SpeedTree::SIndexedTriangles *v12; // ebp
  int v13; // ecx
  unsigned __int16 *M_finish; // edx
  unsigned __int16 *M_start; // eax
  unsigned __int8 *v16; // edi
  vostok::render::grass_render_model *m_object; // edx
  unsigned __int16 v18; // cx
  unsigned int v19; // ebx
  unsigned int v20; // eax
  int *v21; // ecx
  unsigned int v22; // esi
  int *v23; // eax
  unsigned int v24; // ecx
  bool v25; // al
  int v26; // eax
  unsigned __int8 *v27; // eax
  bool v28; // zf
  unsigned __int16 *v29; // ebx
  unsigned __int16 *v30; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int16 *v32; // eax
  int v33; // edi
  int v34; // ecx
  int v35; // ebx
  float *v36; // eax
  const float *v37; // edx
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // esi
  float v42; // esi
  const float *m_pLodCoords; // edx
  const unsigned __int8 *m_pNormals; // esi
  const unsigned __int8 *m_pAmbientOcclusionValues; // esi
  char v46; // dl
  const unsigned __int8 *m_pTangents; // esi
  vostok::render::frond_vertex *v48; // edx
  vostok::render::frond_vertex *v49; // eax
  vostok::render::frond_vertex *v50; // edi
  unsigned int v51; // esi
  unsigned int v52; // eax
  int *v53; // ecx
  unsigned int v54; // ebx
  int *v55; // eax
  unsigned int v56; // ecx
  bool v57; // al
  unsigned __int8 *v58; // ebp
  int v59; // eax
  unsigned __int8 *v60; // eax
  vostok::render::frond_vertex *v61; // eax
  void *v62; // esi
  void *v63; // esi
  unsigned __int16 *v64; // eax
  void *v65; // esi
  vostok::render::frond_vertex *v66; // ebx
  unsigned int v67; // esi
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v69; // edi
  int v70; // ebx
  vostok::render::untyped_buffer *v71; // eax
  vostok::render::untyped_buffer *v72; // ebx
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v74; // ecx
  vostok::render::res_geometry *m_flags; // eax
  survarium::options_tab *v76; // ebp
  ID3D11Buffer *m_hardware_buffer; // eax
  vostok::render::grass_render_model *v78; // esi
  vostok::render::frond_vertex *v79; // eax
  void *v80; // esi
  unsigned __int16 *v81; // eax
  void *v82; // esi
  vostok::render::res_declaration *v83; // eax
  vostok::render::resource_manager *v84; // [esp-14h] [ebp-D0h]
  vostok::render::resource_manager *v85; // [esp-14h] [ebp-D0h]
  vostok::render::frond_vertex *v86; // [esp-10h] [ebp-CCh]
  const SpeedTree::SIndexedTriangles *v87; // [esp+0h] [ebp-BCh]
  const vostok::render::frond_vertex *it; // [esp+10h] [ebp-ACh]
  const vostok::render::frond_vertex *ita; // [esp+10h] [ebp-ACh]
  vostok::render::frond_vertex *itb; // [esp+10h] [ebp-ACh]
  int v91; // [esp+14h] [ebp-A8h] BYREF
  vostok::render::vector<vostok::render::frond_vertex> total_vertices; // [esp+18h] [ebp-A4h] BYREF
  vostok::render::vector<unsigned short> total_indices; // [esp+24h] [ebp-98h] BYREF
  int v94; // [esp+30h] [ebp-8Ch] BYREF
  int lod_index; // [esp+34h] [ebp-88h]
  int v96; // [esp+38h] [ebp-84h] BYREF
  int v97; // [esp+3Ch] [ebp-80h] BYREF
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> decl; // [esp+40h] [ebp-7Ch]
  unsigned int v99; // [esp+44h] [ebp-78h] BYREF
  vostok::render::vector<vostok::render::frond_vertex> vertices; // [esp+48h] [ebp-74h] BYREF
  vostok::render::vector<unsigned short> indices; // [esp+54h] [ebp-68h] BYREF
  __int64 v102; // [esp+60h] [ebp-5Ch]
  float v103; // [esp+68h] [ebp-54h]
  __int64 v104; // [esp+6Ch] [ebp-50h]
  float z; // [esp+74h] [ebp-48h]
  int num_lods; // [esp+78h] [ebp-44h]
  const SpeedTree::SIndexedTriangles *lods; // [esp+7Ch] [ebp-40h]
  vostok::render::frond_vertex dst; // [esp+80h] [ebp-3Ch] BYREF

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
  parent->__vftable = (vostok::render::speedtree_tree_component_frond_vtbl *)&vostok::render::speedtree_tree_component_frond::`vftable';
  declaration = vostok::render::resource_manager::create_declaration(6u, v3, (stlp_std::forward_iterator_tag *)layout_3);
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
  m_nNumFrondLods = (vostok::render::grass_render_model *)v7->m_sGeometry.m_nNumFrondLods;
  lods = v7->m_sGeometry.m_pFrondLods;
  parenta->m_lod_render_info[1].num_lods = (unsigned int)m_nNumFrondLods;
  num_lods = (int)m_nNumFrondLods;
  parenta->m_lod_render_info[1].lods = vostok::memory::new_array_helper<vostok::render::lod_entry>::call<vostok::memory::doug_lea_allocator>(
                                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                         (unsigned int)m_nNumFrondLods);
  v9 = 0;
  v10 = 0;
  v11 = 0;
  memset(&total_indices, 0, sizeof(total_indices));
  memset(&total_vertices, 0, sizeof(total_vertices));
  lod_index = 0;
  if ( (int)m_nNumFrondLods > 0 )
  {
    while ( 1 )
    {
      v12 = (SpeedTree::SIndexedTriangles *)&lods[v9];
      if ( SpeedTree::SIndexedTriangles::HasGeometry(v12) )
      {
        memset(&indices, 0, sizeof(indices));
        vostok::render::speedtree_tree_component_frond::init_index_buffer(
          &indices,
          (vostok::render::speedtree_tree_component_frond *)v12,
          v87);
        v13 = lod_index;
        v4->m_lod_render_info[1].lods[lod_index].start_index = v11 - total_indices._M_impl._M_start;
        M_finish = indices._M_impl._M_finish;
        M_start = indices._M_impl._M_start;
        v4->m_lod_render_info[1].lods[v13].num_indices = indices._M_impl._M_finish - indices._M_impl._M_start;
        it = (const vostok::render::frond_vertex *)M_start;
        if ( M_start != M_finish )
        {
          v16 = (unsigned __int8 *)(total_vertices._M_impl._M_finish - total_vertices._M_impl._M_start);
          m_object = vostok::render::g_allocator.m_object;
          v91 = (int)v16;
          do
          {
            v18 = (_WORD)v16 + *M_start;
            v94 = v18;
            if ( v11 == total_indices._M_impl._M_end_of_storage._M_data )
            {
              v19 = (char *)v11 - (char *)total_indices._M_impl._M_start;
              v20 = v11 - total_indices._M_impl._M_start;
              v97 = 1;
              v96 = v20;
              if ( v20 == 0x7FFFFFFF )
LABEL_125:
                stlp_std::__stl_throw_length_error("vector");
              v21 = &v96;
              if ( v20 <= 1 )
                v21 = &v97;
              v22 = v20 + *v21;
              v96 = v22;
              if ( v22 > 0x7FFFFFFF || v22 < v20 )
              {
                v22 = 0x7FFFFFFF;
                v96 = 0x7FFFFFFF;
              }
              v99 = v22;
              v97 = 1;
              v23 = &v97;
              if ( v22 )
                v23 = (int *)&v99;
              v24 = 2 * *v23;
              v25 = BYTE2(m_object->m_children_resources.m_lock) && v24;
              BYTE2(m_object->m_children_resources.m_lock) = v25;
              if ( v24 )
                v16 = (unsigned __int8 *)vostok_mspace_malloc(
                                           (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                           v24);
              else
                v16 = 0;
              if ( v19 )
              {
                memmove(v16, (unsigned __int8 *)total_indices._M_impl._M_start, v19);
                v27 = (unsigned __int8 *)(v19 + v26);
              }
              else
              {
                v27 = v16;
              }
              v28 = total_indices._M_impl._M_start == 0;
              *(_WORD *)v27 = v94;
              m_object = vostok::render::g_allocator.m_object;
              v29 = (unsigned __int16 *)(v27 + 2);
              if ( !v28 )
              {
                v30 = total_indices._M_impl._M_start;
                m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v30);
                m_object = vostok::render::g_allocator.m_object;
                v22 = v96;
              }
              v32 = (unsigned __int16 *)&v16[2 * v22];
              total_indices._M_impl._M_start = (unsigned __int16 *)v16;
              LOWORD(v16) = v91;
              total_indices._M_impl._M_end_of_storage._M_data = v32;
              M_start = (unsigned __int16 *)it;
              total_indices._M_impl._M_finish = v29;
              v11 = v29;
            }
            else
            {
              *v11 = v18;
              m_object = vostok::render::g_allocator.m_object;
              total_indices._M_impl._M_finish = ++v11;
            }
            it = (const vostok::render::frond_vertex *)++M_start;
          }
          while ( M_start != indices._M_impl._M_finish );
        }
        v33 = 0;
        memset(&vertices, 0, sizeof(vertices));
        memset((int)&dst, 0, sizeof(dst));
        stlp_std::priv::_Impl_vector<vostok::render::branch_vertex,vostok::render::std_allocator<vostok::render::branch_vertex>>::resize(
          v12->m_nNumVertices,
          &vertices._M_impl,
          &dst);
        v34 = 0;
        if ( v12->m_nNumVertices > 0 )
        {
          v35 = 0;
          ita = 0;
          v36 = &vertices._M_impl._M_start->m_afCoord[2];
          do
          {
            v37 = &v12->m_pCoords[v35];
            *((_QWORD *)v36 - 1) = *(_QWORD *)v37;
            *v36 = v37[2];
            v38 = *(v36 - 2);
            v39 = *(v36 - 1);
            v40 = *v36;
            if ( v38 <= parenta->m_bbox.min.x )
              *(float *)&v104 = *(v36 - 2);
            else
              *(float *)&v104 = parenta->m_bbox.min.x;
            if ( v39 <= parenta->m_bbox.min.y )
              *((float *)&v104 + 1) = v39;
            else
              HIDWORD(v104) = LODWORD(parenta->m_bbox.min.y);
            if ( v40 <= parenta->m_bbox.min.z )
              z = v40;
            else
              z = parenta->m_bbox.min.z;
            v41 = z;
            *(_QWORD *)&parenta->m_bbox.min.x = v104;
            parenta->m_bbox.min.z = v41;
            if ( parenta->m_bbox.max.x <= v38 )
              *(float *)&v102 = v38;
            else
              *(float *)&v102 = parenta->m_bbox.max.x;
            if ( parenta->m_bbox.max.y <= v39 )
              *((float *)&v102 + 1) = v39;
            else
              HIDWORD(v102) = LODWORD(parenta->m_bbox.max.y);
            if ( parenta->m_bbox.max.z <= v40 )
              v103 = v40;
            else
              v103 = parenta->m_bbox.max.z;
            v42 = v103;
            *(_QWORD *)&parenta->m_bbox.max.x = v102;
            parenta->m_bbox.max.z = v42;
            m_pLodCoords = v12->m_pLodCoords;
            if ( !m_pLodCoords )
              m_pLodCoords = v12->m_pCoords;
            *(_QWORD *)(v36 + 1) = *(_QWORD *)&m_pLodCoords[v35];
            v36[3] = m_pLodCoords[v35 + 2];
            m_pNormals = v12->m_pNormals;
            *((_WORD *)v36 + 18) = *(_WORD *)&m_pNormals[v33];
            *((_BYTE *)v36 + 38) = m_pNormals[v33 + 2];
            m_pAmbientOcclusionValues = v12->m_pAmbientOcclusionValues;
            if ( m_pAmbientOcclusionValues )
              v46 = m_pAmbientOcclusionValues[v34];
            else
              v46 = -1;
            *((_BYTE *)v36 + 39) = v46;
            v36[5] = v12->m_pTexCoordsDiffuse[2 * v34];
            v36[6] = v12->m_pTexCoordsDiffuse[2 * v34 + 1];
            v36[7] = v12->m_pFrondRipple[2 * v34];
            v36[8] = v12->m_pFrondRipple[2 * v34 + 1];
            m_pTangents = v12->m_pTangents;
            *((_WORD *)v36 + 20) = *(_WORD *)&m_pTangents[v33];
            *((_BYTE *)v36 + 42) = m_pTangents[v33 + 2];
            *((_BYTE *)v36 + 43) = 0;
            if ( v12->m_pWindData )
            {
              v36[4] = v12->m_fWindDataMagnitude;
              v36[11] = *(float *)((char *)ita->m_afCoord + (unsigned int)v12->m_pWindData);
            }
            else
            {
              v36[4] = 0.0;
              *((_BYTE *)v36 + 47) = 0;
              *((_BYTE *)v36 + 46) = 0;
              *((_BYTE *)v36 + 45) = 0;
              *((_BYTE *)v36 + 44) = 0;
            }
            ita = (const vostok::render::frond_vertex *)((char *)ita + 6);
            ++v34;
            v36 += 14;
            v35 += 3;
            v33 += 3;
          }
          while ( v34 < v12->m_nNumVertices );
          v11 = total_indices._M_impl._M_finish;
        }
        v48 = vertices._M_impl._M_start;
        m_nNumFrondLods = vostok::render::g_allocator.m_object;
        itb = vertices._M_impl._M_start;
        if ( vertices._M_impl._M_start != vertices._M_impl._M_finish )
        {
          v49 = total_vertices._M_impl._M_finish;
          do
          {
            if ( v49 == total_vertices._M_impl._M_end_of_storage._M_data )
            {
              v51 = (char *)v49 - (char *)total_vertices._M_impl._M_start;
              v52 = v49 - total_vertices._M_impl._M_start;
              v94 = 1;
              v91 = v52;
              if ( &vostok::memory::s_CRT_arena[65492828] == (unsigned __int8 *)v52 )
                goto LABEL_125;
              v53 = &v91;
              if ( v52 <= 1 )
                v53 = &v94;
              v54 = v52 + *v53;
              if ( v54 > (unsigned int)&vostok::memory::s_CRT_arena[65492828] || v54 < v52 )
                v54 = (unsigned int)&vostok::memory::s_CRT_arena[65492828];
              v94 = v54;
              v91 = 1;
              v55 = &v91;
              if ( v54 )
                v55 = &v94;
              v56 = 56 * *v55;
              v57 = BYTE2(m_nNumFrondLods->m_children_resources.m_lock) && v56;
              BYTE2(m_nNumFrondLods->m_children_resources.m_lock) = v57;
              if ( v56 )
                v58 = (unsigned __int8 *)vostok_mspace_malloc(
                                           (void *)HIDWORD(m_nNumFrondLods->m_reconstruction_info_actuality_tick),
                                           v56);
              else
                v58 = 0;
              if ( v51 )
              {
                memmove(v58, (unsigned __int8 *)total_vertices._M_impl._M_start, v51);
                v60 = (unsigned __int8 *)(v51 + v59);
              }
              else
              {
                v60 = v58;
              }
              v28 = total_vertices._M_impl._M_start == 0;
              qmemcpy(v60, itb, 0x38u);
              m_nNumFrondLods = vostok::render::g_allocator.m_object;
              v91 = (int)(v60 + 56);
              if ( !v28 )
              {
                v61 = total_vertices._M_impl._M_start;
                v62 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                vostok_mspace_free(v62, v61);
                m_nNumFrondLods = vostok::render::g_allocator.m_object;
              }
              v48 = itb;
              total_vertices._M_impl._M_end_of_storage._M_data = (vostok::render::frond_vertex *)&v58[56 * v54];
              total_vertices._M_impl._M_start = (vostok::render::frond_vertex *)v58;
              total_vertices._M_impl._M_finish = (vostok::render::frond_vertex *)v91;
              v49 = (vostok::render::frond_vertex *)v91;
            }
            else
            {
              v50 = v49++;
              qmemcpy(v50, v48, sizeof(vostok::render::frond_vertex));
              m_nNumFrondLods = vostok::render::g_allocator.m_object;
              total_vertices._M_impl._M_finish = v49;
            }
            itb = ++v48;
          }
          while ( v48 != vertices._M_impl._M_finish );
          v48 = vertices._M_impl._M_start;
          v11 = total_indices._M_impl._M_finish;
        }
        if ( v48 )
        {
          v63 = (void *)HIDWORD(m_nNumFrondLods->m_reconstruction_info_actuality_tick);
          BYTE2(m_nNumFrondLods->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v63, v48);
          m_nNumFrondLods = vostok::render::g_allocator.m_object;
          v11 = total_indices._M_impl._M_finish;
        }
        if ( indices._M_impl._M_start )
        {
          v64 = indices._M_impl._M_start;
          v65 = (void *)HIDWORD(m_nNumFrondLods->m_reconstruction_info_actuality_tick);
          BYTE2(m_nNumFrondLods->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v65, v64);
          v11 = total_indices._M_impl._M_finish;
        }
      }
      v9 = ++lod_index;
      if ( lod_index >= num_lods )
        break;
      v4 = parenta;
    }
    v5 = (vostok::render::speedtree_tree *)parent;
    v10 = total_indices._M_impl._M_start;
  }
  v66 = total_vertices._M_impl._M_finish;
  v67 = v11 - v10;
  v84 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  v5->m_reconstruction_size = v67;
  *(&v5->m_reconstruction_size + 1) = v67 / 3;
  buffer = vostok::render::resource_manager::create_buffer(
             2 * v67,
             (bool)m_nNumFrondLods,
             v84,
             v10,
             enum_buffer_type_index,
             0,
             0);
  v69 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v69 = buffer;
  }
  v70 = (char *)v66 - (char *)total_vertices._M_impl._M_start;
  v86 = total_vertices._M_impl._M_start;
  v85 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  HIDWORD(v5->m_reconstruction_info_actuality_tick) = v70 / 56;
  v71 = vostok::render::resource_manager::create_buffer(
          56 * (v70 / 56),
          (bool)v69,
          v85,
          v86,
          enum_buffer_type_vertex,
          (vostok::render::untyped_buffer *)1,
          0);
  v72 = 0;
  if ( v71 )
  {
    ++v71->m_reference_count;
    v72 = v71;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               decl.m_object,
               v72,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               0x38u,
               v69);
  v74 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v74 = geometry;
  }
  m_flags = (vostok::render::res_geometry *)v5->vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v5->vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = (volatile int)v74;
  if ( m_flags )
  {
    v28 = m_flags->m_reference_count-- == 1;
    if ( v28 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_flags);
  }
  if ( v72 )
  {
    v28 = v72->m_reference_count-- == 1;
    if ( v28 )
    {
      v76 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             (const vostok::render::res_state *)v72) )
      {
        v76[2].m_options = (survarium::options_item_base **)((char *)v76[2].m_options - v72->m_size);
        m_hardware_buffer = v72->m_hardware_buffer;
        v78 = vostok::render::g_allocator.m_object;
        if ( m_hardware_buffer )
        {
          m_hardware_buffer->Release(v72->m_hardware_buffer);
          v72->m_hardware_buffer = 0;
        }
        BYTE2(v78->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v78->m_reconstruction_info_actuality_tick), v72);
      }
    }
  }
  if ( v69 )
  {
    v28 = v69->m_reference_count-- == 1;
    if ( v28 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v69,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v79 = total_vertices._M_impl._M_start;
  if ( total_vertices._M_impl._M_start )
  {
    v80 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v80, v79);
  }
  v81 = total_indices._M_impl._M_start;
  if ( total_indices._M_impl._M_start )
  {
    v82 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v82, v81);
  }
  v83 = decl.m_object;
  if ( decl.m_object )
  {
    v28 = decl.m_object->m_reference_count-- == 1;
    if ( v28 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v83);
  }
}

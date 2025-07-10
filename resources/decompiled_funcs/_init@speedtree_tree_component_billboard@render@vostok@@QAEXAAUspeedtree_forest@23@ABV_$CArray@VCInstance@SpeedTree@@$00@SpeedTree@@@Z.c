void __thiscall vostok::render::speedtree_tree_component_billboard::init(
        vostok::render::speedtree_tree_component_billboard *this,
        vostok::render::speedtree_tree_component_billboard *forest,
        vostok::render::speedtree_forest *instances_of_tree,
        const SpeedTree::CArray<SpeedTree::CInstance,1> *instances_of_treea)
{
  vostok::render::speedtree_forest *v4; // ebp
  vostok::render::res_declaration *declaration; // eax
  unsigned __int8 *p_total_vertices; // edi
  stlp_std::priv::_Impl_vector<vostok::render::billboard_vertex,vostok::render::std_allocator<vostok::render::billboard_vertex> > *v7; // ecx
  unsigned __int16 *M_finish; // esi
  vostok::render::billboard_vertex *v9; // ebx
  int v10; // ebp
  stlp_std::priv::_Impl_vector<vostok::render::geometry_batch,vostok::render::std_allocator<vostok::render::geometry_batch> > *v11; // ecx
  int v12; // edx
  unsigned int v13; // xmm4_4
  unsigned int v14; // xmm5_4
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm0_4
  float v18; // eax
  vostok::render::billboard_vertex *v19; // ebx
  float v20; // ecx
  unsigned int v21; // xmm4_4
  unsigned int v22; // xmm5_4
  float v23; // edx
  vostok::render::billboard_vertex *v24; // ebx
  int v25; // eax
  unsigned int v26; // xmm4_4
  unsigned int v27; // xmm5_4
  vostok::render::billboard_vertex *v28; // ebx
  int v29; // edx
  unsigned int v30; // xmm5_4
  float v31; // eax
  unsigned __int16 v32; // bp
  vostok::render::grass_render_model *v33; // edx
  unsigned __int16 *v34; // esi
  signed int v35; // esi
  unsigned int v36; // eax
  int *v37; // ecx
  unsigned int v38; // ebx
  int *v39; // eax
  unsigned int v40; // ecx
  vostok::render::grass_render_model *m_object; // edi
  bool v42; // dl
  int v43; // eax
  unsigned __int8 *v44; // eax
  bool v45; // zf
  unsigned __int16 *v46; // ebp
  unsigned __int16 *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int16 *v49; // eax
  vostok::render::grass_render_model *v50; // edx
  unsigned __int16 *v51; // esi
  signed int v52; // esi
  unsigned int v53; // eax
  int *v54; // ecx
  unsigned int v55; // ebx
  int *v56; // eax
  unsigned int v57; // ecx
  bool v58; // al
  int v59; // eax
  unsigned __int8 *v60; // eax
  unsigned __int16 *v61; // ebp
  unsigned __int16 *v62; // eax
  void *v63; // esi
  unsigned __int16 *v64; // eax
  unsigned __int16 *v65; // esi
  signed int v66; // esi
  unsigned int v67; // eax
  unsigned __int16 *v68; // ecx
  unsigned int v69; // ebx
  unsigned __int16 *v70; // eax
  unsigned int v71; // ecx
  bool v72; // al
  int v73; // eax
  unsigned __int8 *v74; // eax
  unsigned __int16 *v75; // ebp
  void *v76; // esi
  unsigned __int16 *v77; // eax
  stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *v78; // ecx
  unsigned __int16 *v79; // esi
  unsigned __int16 *v80; // esi
  unsigned int v81; // esi
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::billboard_vertex *v83; // esi
  int v84; // ebx
  vostok::render::resource_manager *v85; // edx
  vostok::render::untyped_buffer *v86; // eax
  vostok::render::untyped_buffer *v87; // edi
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v89; // ecx
  vostok::render::res_geometry *m_wind_distances_parameter; // eax
  vostok::render::grass_render_model *v91; // ecx
  void *v92; // esi
  vostok::render::resource_manager *v93; // [esp-10h] [ebp-A4h]
  unsigned __int16 *v94; // [esp-Ch] [ebp-A0h]
  unsigned int _X; // [esp+0h] [ebp-94h]
  const SpeedTree::CInstance *v96; // [esp+4h] [ebp-90h]
  unsigned int v97; // [esp+8h] [ebp-8Ch]
  bool v98; // [esp+Ch] [ebp-88h]
  float i_index; // [esp+18h] [ebp-7Ch]
  unsigned int instance_index; // [esp+1Ch] [ebp-78h]
  vostok::render::untyped_buffer *instance_indexa; // [esp+1Ch] [ebp-78h]
  vostok::render::res_declaration *decl; // [esp+20h] [ebp-74h]
  int v103; // [esp+24h] [ebp-70h] BYREF
  int v104; // [esp+28h] [ebp-6Ch] BYREF
  unsigned __int16 __x[2]; // [esp+2Ch] [ebp-68h] BYREF
  vostok::render::vector<unsigned short> total_indices; // [esp+30h] [ebp-64h] BYREF
  vostok::render::vector<vostok::render::billboard_vertex> total_vertices; // [esp+3Ch] [ebp-58h] BYREF
  vostok::math::float3 up_direction; // [esp+48h] [ebp-4Ch]
  vostok::math::float4x4 transform; // [esp+54h] [ebp-40h] BYREF

  v4 = (vostok::render::speedtree_forest *)forest;
  declaration = vostok::render::resource_manager::create_declaration(
                  3u,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)layout_0);
  decl = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    decl = declaration;
  }
  _X = 6 * instances_of_treea->m_uiSize;
  memset(&total_indices, 0, sizeof(total_indices));
  memset(&total_vertices, 0, sizeof(total_vertices));
  stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::reserve(
    (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)_X,
    (unsigned int)&total_indices,
    _X);
  p_total_vertices = (unsigned __int8 *)&total_vertices;
  stlp_std::priv::_Impl_vector<vostok::render::billboard_vertex,vostok::render::std_allocator<vostok::render::billboard_vertex>>::reserve(
    v7,
    (int)&total_vertices,
    4 * instances_of_treea->m_uiSize);
  M_finish = total_indices._M_impl._M_finish;
  instance_index = 0;
  v9 = total_vertices._M_impl._M_finish;
  if ( instances_of_treea->m_uiSize )
  {
    do
    {
      v10 = (int)&instances_of_treea->m_pData[instance_index];
      vostok::render::speedtree_forest::get_instance_transform((vostok::render::speedtree_forest *)v10, &transform, v96);
      i_index = sqrtf(
                  (float)((float)(transform.j.y * transform.j.y) + (float)(transform.j.x * transform.j.x))
                + (float)(transform.j.z * transform.j.z));
      v12 = *(unsigned __int8 *)(v10 + 34);
      v13 = *(_DWORD *)(v10 + 4);
      v14 = *(_DWORD *)(v10 + 8);
      x = transform.j.x * (float)(*(float *)&clear_value / i_index);
      y = transform.j.y * (float)(*(float *)&clear_value / i_index);
      z = transform.j.z * (float)(*(float *)&clear_value / i_index);
      transform.i.x = *(float *)v10;
      transform.i.w = *(float *)(v10 + 12);
      up_direction.x = x;
      up_direction.y = y;
      up_direction.z = z;
      *(_QWORD *)&transform.lines[0].elements[1] = __PAIR64__(v14, v13);
      transform.j.x = x;
      transform.j.y = y;
      transform.j.z = z;
      transform.j.w = (float)((float)v12 * 0.0039215689) * 6.2831855;
      LOBYTE(transform.lines[2].x) = 0;
      if ( v9 == total_vertices._M_impl._M_end_of_storage._M_data )
      {
        p_total_vertices = (unsigned __int8 *)&total_vertices;
        stlp_std::priv::_Impl_vector<vostok::render::billboard_vertex,vostok::render::std_allocator<vostok::render::billboard_vertex>>::_M_insert_overflow(
          &total_vertices._M_impl,
          (const vostok::render::billboard_vertex *)&transform,
          v11,
          v9,
          (const stlp_std::__true_type *)v96,
          v97,
          v98);
        v19 = total_vertices._M_impl._M_finish;
        z = up_direction.z;
        y = up_direction.y;
        x = up_direction.x;
      }
      else
      {
        if ( v9 )
        {
          v18 = transform.k.x;
          *(_QWORD *)&v9->position_and_scale.x = *(_QWORD *)&transform.i.x;
          *(_QWORD *)&v9->position_and_scale.elements[2] = *(_QWORD *)&transform.lines[0].elements[2];
          v9->direction_and_rotation = (vostok::math::float4)transform.j;
          *(float *)&v9->corner_index = v18;
        }
        v19 = v9 + 1;
        total_vertices._M_impl._M_finish = v19;
      }
      LODWORD(v20) = *(unsigned __int8 *)(v10 + 34);
      v21 = *(_DWORD *)(v10 + 4);
      v22 = *(_DWORD *)(v10 + 8);
      transform.i.x = *(float *)v10;
      transform.i.w = *(float *)(v10 + 12);
      *(_QWORD *)&transform.lines[0].elements[1] = __PAIR64__(v22, v21);
      *(_QWORD *)&transform.lines[1].x = __PAIR64__(LODWORD(y), LODWORD(x));
      transform.j.z = z;
      transform.j.w = (float)((float)SLODWORD(v20) * 0.0039215689) * 6.2831855;
      LOBYTE(transform.lines[2].x) = 1;
      if ( v19 == total_vertices._M_impl._M_end_of_storage._M_data )
      {
        p_total_vertices = (unsigned __int8 *)&total_vertices;
        stlp_std::priv::_Impl_vector<vostok::render::billboard_vertex,vostok::render::std_allocator<vostok::render::billboard_vertex>>::_M_insert_overflow(
          &total_vertices._M_impl,
          (const vostok::render::billboard_vertex *)&transform,
          (stlp_std::priv::_Impl_vector<vostok::render::geometry_batch,vostok::render::std_allocator<vostok::render::geometry_batch> > *)LODWORD(v20),
          v19,
          (const stlp_std::__true_type *)v96,
          v97,
          v98);
        v24 = total_vertices._M_impl._M_finish;
        z = up_direction.z;
        y = up_direction.y;
        x = up_direction.x;
      }
      else
      {
        if ( v19 )
        {
          v23 = transform.k.x;
          *(_QWORD *)&v19->position_and_scale.x = *(_QWORD *)&transform.i.x;
          *(_QWORD *)&v19->position_and_scale.elements[2] = *(_QWORD *)&transform.lines[0].elements[2];
          v19->direction_and_rotation = (vostok::math::float4)transform.j;
          *(float *)&v19->corner_index = v23;
        }
        v24 = v19 + 1;
        total_vertices._M_impl._M_finish = v24;
      }
      v25 = *(unsigned __int8 *)(v10 + 34);
      v26 = *(_DWORD *)(v10 + 4);
      v27 = *(_DWORD *)(v10 + 8);
      transform.i.x = *(float *)v10;
      transform.i.w = *(float *)(v10 + 12);
      *(_QWORD *)&transform.lines[0].elements[1] = __PAIR64__(v27, v26);
      *(_QWORD *)&transform.lines[1].x = __PAIR64__(LODWORD(y), LODWORD(x));
      transform.j.z = z;
      transform.j.w = (float)((float)v25 * 0.0039215689) * 6.2831855;
      LOBYTE(transform.lines[2].x) = 2;
      if ( v24 == total_vertices._M_impl._M_end_of_storage._M_data )
      {
        p_total_vertices = (unsigned __int8 *)&total_vertices;
        stlp_std::priv::_Impl_vector<vostok::render::billboard_vertex,vostok::render::std_allocator<vostok::render::billboard_vertex>>::_M_insert_overflow(
          &total_vertices._M_impl,
          (const vostok::render::billboard_vertex *)&transform,
          (stlp_std::priv::_Impl_vector<vostok::render::geometry_batch,vostok::render::std_allocator<vostok::render::geometry_batch> > *)LODWORD(v20),
          v24,
          (const stlp_std::__true_type *)v96,
          v97,
          v98);
        v28 = total_vertices._M_impl._M_finish;
        z = up_direction.z;
        y = up_direction.y;
        x = up_direction.x;
      }
      else
      {
        if ( v24 )
        {
          v20 = transform.k.x;
          *(_QWORD *)&v24->position_and_scale.x = *(_QWORD *)&transform.i.x;
          *(_QWORD *)&v24->position_and_scale.elements[2] = *(_QWORD *)&transform.lines[0].elements[2];
          v24->direction_and_rotation = (vostok::math::float4)transform.j;
          *(float *)&v24->corner_index = v20;
        }
        v28 = v24 + 1;
        total_vertices._M_impl._M_finish = v28;
      }
      v29 = *(unsigned __int8 *)(v10 + 34);
      v30 = *(_DWORD *)(v10 + 8);
      *(_QWORD *)&transform.i.x = *(_QWORD *)v10;
      *(_QWORD *)&transform.lines[0].elements[2] = __PAIR64__(*(_DWORD *)(v10 + 12), v30);
      transform.j.x = x;
      *(_QWORD *)&transform.lines[1].elements[1] = __PAIR64__(LODWORD(z), LODWORD(y));
      transform.j.w = (float)((float)v29 * 0.0039215689) * 6.2831855;
      LOBYTE(transform.lines[2].x) = 3;
      if ( v28 == total_vertices._M_impl._M_end_of_storage._M_data )
      {
        p_total_vertices = (unsigned __int8 *)&total_vertices;
        stlp_std::priv::_Impl_vector<vostok::render::billboard_vertex,vostok::render::std_allocator<vostok::render::billboard_vertex>>::_M_insert_overflow(
          &total_vertices._M_impl,
          (const vostok::render::billboard_vertex *)&transform,
          (stlp_std::priv::_Impl_vector<vostok::render::geometry_batch,vostok::render::std_allocator<vostok::render::geometry_batch> > *)LODWORD(v20),
          v28,
          (const stlp_std::__true_type *)v96,
          v97,
          v98);
        v9 = total_vertices._M_impl._M_finish;
      }
      else
      {
        if ( v28 )
        {
          v31 = transform.k.x;
          *(_QWORD *)&v28->position_and_scale.x = *(_QWORD *)&transform.i.x;
          *(_QWORD *)&v28->position_and_scale.elements[2] = *(_QWORD *)&transform.lines[0].elements[2];
          v28->direction_and_rotation = (vostok::math::float4)transform.j;
          *(float *)&v28->corner_index = v31;
        }
        v9 = v28 + 1;
        total_vertices._M_impl._M_finish = v9;
      }
      v32 = 4 * instance_index;
      if ( M_finish == total_indices._M_impl._M_end_of_storage._M_data )
      {
        v35 = (char *)M_finish - (char *)total_indices._M_impl._M_start;
        v36 = v35 >> 1;
        v104 = 1;
        v103 = v35 >> 1;
        if ( v35 >> 1 == 0x7FFFFFFF )
          goto LABEL_127;
        v37 = &v103;
        if ( v36 <= 1 )
          v37 = &v104;
        v38 = v36 + *v37;
        if ( v38 > 0x7FFFFFFF || v38 < v36 )
          v38 = 0x7FFFFFFF;
        v103 = v38;
        v104 = 1;
        v39 = &v104;
        if ( v38 )
          v39 = &v103;
        v40 = 2 * *v39;
        m_object = vostok::render::g_allocator.m_object;
        v42 = BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) && v40;
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v42;
        if ( v40 )
          p_total_vertices = (unsigned __int8 *)vostok_mspace_malloc(
                                                  (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                                  v40);
        else
          p_total_vertices = 0;
        if ( v35 )
        {
          memmove(p_total_vertices, (unsigned __int8 *)total_indices._M_impl._M_start, v35);
          v44 = (unsigned __int8 *)(v35 + v43);
        }
        else
        {
          v44 = p_total_vertices;
        }
        v45 = total_indices._M_impl._M_start == 0;
        *(_WORD *)v44 = 4 * instance_index;
        v33 = vostok::render::g_allocator.m_object;
        v46 = (unsigned __int16 *)(v44 + 2);
        if ( !v45 )
        {
          M_start = total_indices._M_impl._M_start;
          m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
          v33 = vostok::render::g_allocator.m_object;
        }
        v49 = (unsigned __int16 *)&p_total_vertices[2 * v38];
        v9 = total_vertices._M_impl._M_finish;
        v34 = v46;
        v32 = 4 * instance_index;
        total_indices._M_impl._M_start = (unsigned __int16 *)p_total_vertices;
        total_indices._M_impl._M_end_of_storage._M_data = v49;
      }
      else
      {
        *M_finish = v32;
        v33 = vostok::render::g_allocator.m_object;
        v34 = M_finish + 1;
      }
      *(_DWORD *)__x = (unsigned __int16)(v32 + 1);
      if ( v34 == total_indices._M_impl._M_end_of_storage._M_data )
      {
        v52 = (char *)v34 - (char *)total_indices._M_impl._M_start;
        v53 = v52 >> 1;
        v103 = 1;
        v104 = v52 >> 1;
        if ( v52 >> 1 == 0x7FFFFFFF )
          goto LABEL_127;
        v54 = &v104;
        if ( v53 <= 1 )
          v54 = &v103;
        v55 = v53 + *v54;
        if ( v55 > 0x7FFFFFFF || v55 < v53 )
          v55 = 0x7FFFFFFF;
        v103 = v55;
        v104 = 1;
        v56 = &v104;
        if ( v55 )
          v56 = &v103;
        v57 = 2 * *v56;
        v58 = BYTE2(v33->m_children_resources.m_lock) && v57;
        BYTE2(v33->m_children_resources.m_lock) = v58;
        if ( v57 )
          p_total_vertices = (unsigned __int8 *)vostok_mspace_malloc(
                                                  (void *)HIDWORD(v33->m_reconstruction_info_actuality_tick),
                                                  v57);
        else
          p_total_vertices = 0;
        if ( v52 )
        {
          memmove(p_total_vertices, (unsigned __int8 *)total_indices._M_impl._M_start, v52);
          v60 = (unsigned __int8 *)(v52 + v59);
        }
        else
        {
          v60 = p_total_vertices;
        }
        v45 = total_indices._M_impl._M_start == 0;
        *(_WORD *)v60 = __x[0];
        v50 = vostok::render::g_allocator.m_object;
        v61 = (unsigned __int16 *)(v60 + 2);
        if ( !v45 )
        {
          v62 = total_indices._M_impl._M_start;
          v63 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v63, v62);
          v50 = vostok::render::g_allocator.m_object;
        }
        v64 = (unsigned __int16 *)&p_total_vertices[2 * v55];
        v9 = total_vertices._M_impl._M_finish;
        v51 = v61;
        v32 = 4 * instance_index;
        total_indices._M_impl._M_start = (unsigned __int16 *)p_total_vertices;
        total_indices._M_impl._M_end_of_storage._M_data = v64;
      }
      else
      {
        *v34 = v32 + 1;
        v50 = vostok::render::g_allocator.m_object;
        v51 = v34 + 1;
      }
      v103 = (unsigned __int16)(v32 + 2);
      if ( v51 == total_indices._M_impl._M_end_of_storage._M_data )
      {
        v66 = (char *)v51 - (char *)total_indices._M_impl._M_start;
        v67 = v66 >> 1;
        v104 = 1;
        *(_DWORD *)__x = v66 >> 1;
        if ( v66 >> 1 == 0x7FFFFFFF )
LABEL_127:
          stlp_std::__stl_throw_length_error("vector");
        v68 = __x;
        if ( v67 <= 1 )
          v68 = (unsigned __int16 *)&v104;
        v69 = v67 + *(_DWORD *)v68;
        if ( v69 > 0x7FFFFFFF || v69 < v67 )
          v69 = 0x7FFFFFFF;
        v104 = v69;
        *(_DWORD *)__x = 1;
        v70 = __x;
        if ( v69 )
          v70 = (unsigned __int16 *)&v104;
        v71 = 2 * *(_DWORD *)v70;
        v72 = BYTE2(v50->m_children_resources.m_lock) && v71;
        BYTE2(v50->m_children_resources.m_lock) = v72;
        if ( v71 )
          p_total_vertices = (unsigned __int8 *)vostok_mspace_malloc(
                                                  (void *)HIDWORD(v50->m_reconstruction_info_actuality_tick),
                                                  v71);
        else
          p_total_vertices = 0;
        if ( v66 )
        {
          memmove(p_total_vertices, (unsigned __int8 *)total_indices._M_impl._M_start, v66);
          v74 = (unsigned __int8 *)(v66 + v73);
        }
        else
        {
          v74 = p_total_vertices;
        }
        v45 = total_indices._M_impl._M_start == 0;
        *(_WORD *)v74 = v103;
        v75 = (unsigned __int16 *)(v74 + 2);
        if ( !v45 )
        {
          v76 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v76, total_indices._M_impl._M_start);
        }
        v77 = (unsigned __int16 *)&p_total_vertices[2 * v69];
        v9 = total_vertices._M_impl._M_finish;
        v65 = v75;
        v32 = 4 * instance_index;
        total_indices._M_impl._M_start = (unsigned __int16 *)p_total_vertices;
        total_indices._M_impl._M_end_of_storage._M_data = v77;
      }
      else
      {
        *v51 = v32 + 2;
        v65 = v51 + 1;
      }
      v78 = (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)v32;
      total_indices._M_impl._M_finish = v65;
      *(_DWORD *)__x = v32;
      if ( v65 == total_indices._M_impl._M_end_of_storage._M_data )
      {
        p_total_vertices = (unsigned __int8 *)&total_indices;
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)v32,
          (int)&total_indices,
          v65,
          __x,
          (const stlp_std::__true_type *)1,
          1,
          (bool)v96);
        v79 = total_indices._M_impl._M_finish;
      }
      else
      {
        *v65 = v32;
        v79 = v65 + 1;
        total_indices._M_impl._M_finish = v79;
      }
      *(_DWORD *)__x = (unsigned __int16)(v32 + 2);
      if ( v79 == total_indices._M_impl._M_end_of_storage._M_data )
      {
        p_total_vertices = (unsigned __int8 *)&total_indices;
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::_M_insert_overflow(
          v78,
          (int)&total_indices,
          v79,
          __x,
          (const stlp_std::__true_type *)1,
          1,
          (bool)v96);
        v80 = total_indices._M_impl._M_finish;
      }
      else
      {
        *v79 = v32 + 2;
        v80 = v79 + 1;
        total_indices._M_impl._M_finish = v80;
      }
      *(_DWORD *)__x = (unsigned __int16)(v32 + 3);
      if ( v80 == total_indices._M_impl._M_end_of_storage._M_data )
      {
        p_total_vertices = (unsigned __int8 *)&total_indices;
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)__x,
          (int)&total_indices,
          v80,
          __x,
          (const stlp_std::__true_type *)1,
          1,
          (bool)v96);
        M_finish = total_indices._M_impl._M_finish;
      }
      else
      {
        *v80 = v32 + 3;
        M_finish = v80 + 1;
      }
      ++instance_index;
    }
    while ( instance_index < instances_of_treea->m_uiSize );
    v4 = (vostok::render::speedtree_forest *)forest;
  }
  v81 = M_finish - total_indices._M_impl._M_start;
  v94 = total_indices._M_impl._M_start;
  v93 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  v4->m_speedtree_wind_parameters.m_wind_frond_ripple_parameter = (vostok::render::shader_constant_host *)v81;
  v4->m_speedtree_wind_parameters.m_wind_rolling_branches_parameter = (vostok::render::shader_constant_host *)(v81 / 3);
  buffer = vostok::render::resource_manager::create_buffer(
             2 * v81,
             (bool)p_total_vertices,
             v93,
             v94,
             enum_buffer_type_index,
             0,
             0);
  instance_indexa = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    instance_indexa = buffer;
  }
  v83 = total_vertices._M_impl._M_start;
  v84 = (char *)v9 - (char *)total_vertices._M_impl._M_start;
  v85 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  v4->m_speedtree_wind_parameters.m_wind_gust_hints_parameter = (vostok::render::shader_constant_host *)(v84 / 36);
  v86 = vostok::render::resource_manager::create_buffer(
          36 * (v84 / 36),
          (bool)p_total_vertices,
          v85,
          v83,
          enum_buffer_type_vertex,
          (vostok::render::untyped_buffer *)1,
          0);
  v87 = 0;
  if ( v86 )
  {
    ++v86->m_reference_count;
    v87 = v86;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               decl,
               v87,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               0x24u,
               instance_indexa);
  v89 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v89 = geometry;
  }
  m_wind_distances_parameter = (vostok::render::res_geometry *)v4->m_speedtree_wind_parameters.m_wind_distances_parameter;
  v4->m_speedtree_wind_parameters.m_wind_distances_parameter = (vostok::render::shader_constant_host *)v89;
  if ( m_wind_distances_parameter )
  {
    v45 = m_wind_distances_parameter->m_reference_count-- == 1;
    if ( v45 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_wind_distances_parameter);
  }
  LOBYTE(v4->m_visible_trees.m_aVisibleCells.m_uiDataSize) = 1;
  if ( v87 )
  {
    v45 = v87->m_reference_count-- == 1;
    if ( v45 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v87,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  if ( instance_indexa )
  {
    v45 = instance_indexa->m_reference_count-- == 1;
    if ( v45 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)instance_indexa,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  if ( v83 )
  {
    v91 = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v91->m_reconstruction_info_actuality_tick), v83);
  }
  if ( total_indices._M_impl._M_start )
  {
    v92 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v92, total_indices._M_impl._M_start);
  }
  if ( decl )
  {
    v45 = decl->m_reference_count-- == 1;
    if ( v45 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        decl);
  }
}

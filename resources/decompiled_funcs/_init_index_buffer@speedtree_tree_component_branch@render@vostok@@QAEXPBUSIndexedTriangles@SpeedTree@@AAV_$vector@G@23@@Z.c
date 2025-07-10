void __userpurge vostok::render::speedtree_tree_component_branch::init_index_buffer(
        vostok::render::vector<unsigned short> *out_indices@<edi>,
        vostok::render::speedtree_tree_component_branch *this,
        const SpeedTree::SIndexedTriangles *lod)
{
  vostok::render::speedtree_tree_component_branch *v3; // edx
  int v4; // esi
  bool v5; // cc
  int v6; // eax
  int v7; // ecx
  unsigned __int16 *M_finish; // esi
  unsigned __int16 *v9; // ebx
  unsigned int v10; // eax
  char v11; // dl
  int *v12; // ecx
  unsigned int v13; // ecx
  int *v14; // eax
  int v15; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v17; // ecx
  unsigned __int8 *v18; // ebp
  unsigned int v19; // esi
  int v20; // eax
  unsigned __int8 *v21; // eax
  unsigned __int16 *v22; // ebx
  unsigned __int16 *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int16 *v25; // eax
  unsigned __int16 *v26; // esi
  unsigned __int16 *v27; // ebx
  unsigned int v28; // eax
  char v29; // dl
  int *v30; // ecx
  unsigned int v31; // ecx
  int *v32; // eax
  int v33; // ecx
  vostok::render::grass_render_model *v34; // eax
  unsigned int v35; // ecx
  unsigned __int8 *v36; // ebp
  unsigned int v37; // esi
  int v38; // eax
  unsigned __int8 *v39; // eax
  unsigned __int16 *v40; // ebx
  unsigned __int16 *v41; // eax
  void *v42; // esi
  unsigned __int16 *v43; // eax
  unsigned __int16 *v44; // esi
  unsigned __int16 *v45; // ebx
  unsigned int v46; // eax
  char v47; // dl
  int *v48; // ecx
  unsigned int v49; // ecx
  int *v50; // eax
  int v51; // ecx
  vostok::render::grass_render_model *v52; // eax
  unsigned int v53; // ecx
  unsigned __int8 *v54; // ebp
  unsigned int v55; // esi
  int v56; // eax
  unsigned __int8 *v57; // eax
  unsigned __int16 *v58; // ebx
  unsigned __int16 *v59; // eax
  void *v60; // esi
  unsigned __int16 *v61; // eax
  int i; // [esp+Ch] [ebp-18h]
  int v63; // [esp+10h] [ebp-14h] BYREF
  int mg_index; // [esp+14h] [ebp-10h]
  int v65; // [esp+18h] [ebp-Ch] BYREF
  int v66; // [esp+1Ch] [ebp-8h] BYREF
  int num_triangles; // [esp+20h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v5 = (int)this->__vftable <= 0;
  mg_index = 0;
  if ( !v5 )
  {
    do
    {
      v6 = (int)v3->m_parent + 20 * v4;
      v7 = *(_DWORD *)(v6 + 4);
      num_triangles = v7 + *(_DWORD *)(v6 + 8);
      i = v7;
      if ( v7 < num_triangles )
      {
        do
        {
          M_finish = out_indices->_M_impl._M_finish;
          v9 = (unsigned __int16 *)&v3->m_render_geometry.geom.m_object->m_vb + v7;
          if ( M_finish == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            v10 = M_finish - out_indices->_M_impl._M_start;
            v11 = 1;
            v65 = 1;
            v63 = v10;
            if ( v10 == 0x7FFFFFFF )
              goto LABEL_73;
            v12 = &v63;
            if ( v10 <= 1 )
              v12 = &v65;
            v13 = v10 + *v12;
            v63 = v13;
            if ( v13 > 0x7FFFFFFF || v13 < v10 )
            {
              v63 = 0x7FFFFFFF;
              v13 = 0x7FFFFFFF;
            }
            v66 = v13;
            v65 = 1;
            v14 = &v65;
            if ( v13 )
              v14 = &v66;
            v15 = *v14;
            m_object = vostok::render::g_allocator.m_object;
            v17 = 2 * v15;
            if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v17 )
              v11 = 0;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v11;
            if ( v17 )
              v18 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                         v17);
            else
              v18 = 0;
            v19 = (char *)M_finish - (char *)out_indices->_M_impl._M_start;
            if ( v19 )
            {
              memmove(v18, (unsigned __int8 *)out_indices->_M_impl._M_start, v19);
              v21 = (unsigned __int8 *)(v19 + v20);
            }
            else
            {
              v21 = v18;
            }
            *(_WORD *)v21 = *v9;
            v22 = (unsigned __int16 *)(v21 + 2);
            M_start = out_indices->_M_impl._M_start;
            if ( out_indices->_M_impl._M_start )
            {
              m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
            }
            v7 = i;
            v25 = (unsigned __int16 *)&v18[2 * v63];
            v3 = this;
            out_indices->_M_impl._M_start = (unsigned __int16 *)v18;
            out_indices->_M_impl._M_finish = v22;
            out_indices->_M_impl._M_end_of_storage._M_data = v25;
          }
          else
          {
            *M_finish = *v9;
            ++out_indices->_M_impl._M_finish;
          }
          v26 = out_indices->_M_impl._M_finish;
          v27 = (unsigned __int16 *)&v3->m_render_geometry.geom.m_object->m_reference_count + v7 + 1;
          if ( v26 == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            v28 = v26 - out_indices->_M_impl._M_start;
            v29 = 1;
            v65 = 1;
            v66 = v28;
            if ( v28 == 0x7FFFFFFF )
              goto LABEL_73;
            v30 = &v66;
            if ( v28 <= 1 )
              v30 = &v65;
            v31 = v28 + *v30;
            v63 = v31;
            if ( v31 > 0x7FFFFFFF || v31 < v28 )
            {
              v63 = 0x7FFFFFFF;
              v31 = 0x7FFFFFFF;
            }
            v65 = v31;
            v66 = 1;
            v32 = &v66;
            if ( v31 )
              v32 = &v65;
            v33 = *v32;
            v34 = vostok::render::g_allocator.m_object;
            v35 = 2 * v33;
            if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v35 )
              v29 = 0;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v29;
            if ( v35 )
              v36 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(v34->m_reconstruction_info_actuality_tick),
                                         v35);
            else
              v36 = 0;
            v37 = (char *)v26 - (char *)out_indices->_M_impl._M_start;
            if ( v37 )
            {
              memmove(v36, (unsigned __int8 *)out_indices->_M_impl._M_start, v37);
              v39 = (unsigned __int8 *)(v37 + v38);
            }
            else
            {
              v39 = v36;
            }
            *(_WORD *)v39 = *v27;
            v40 = (unsigned __int16 *)(v39 + 2);
            v41 = out_indices->_M_impl._M_start;
            if ( out_indices->_M_impl._M_start )
            {
              v42 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v42, v41);
            }
            v7 = i;
            v43 = (unsigned __int16 *)&v36[2 * v63];
            v3 = this;
            out_indices->_M_impl._M_start = (unsigned __int16 *)v36;
            out_indices->_M_impl._M_finish = v40;
            out_indices->_M_impl._M_end_of_storage._M_data = v43;
          }
          else
          {
            *v26 = *v27;
            ++out_indices->_M_impl._M_finish;
          }
          v44 = out_indices->_M_impl._M_finish;
          v45 = (unsigned __int16 *)((char *)v3->m_render_geometry.geom.m_object + 2 * v7);
          if ( v44 == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            v46 = v44 - out_indices->_M_impl._M_start;
            v47 = 1;
            v65 = 1;
            v66 = v46;
            if ( v46 == 0x7FFFFFFF )
LABEL_73:
              stlp_std::__stl_throw_length_error("vector");
            v48 = &v66;
            if ( v46 <= 1 )
              v48 = &v65;
            v49 = v46 + *v48;
            v63 = v49;
            if ( v49 > 0x7FFFFFFF || v49 < v46 )
            {
              v63 = 0x7FFFFFFF;
              v49 = 0x7FFFFFFF;
            }
            v65 = v49;
            v66 = 1;
            v50 = &v66;
            if ( v49 )
              v50 = &v65;
            v51 = *v50;
            v52 = vostok::render::g_allocator.m_object;
            v53 = 2 * v51;
            if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v53 )
              v47 = 0;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v47;
            if ( v53 )
              v54 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(v52->m_reconstruction_info_actuality_tick),
                                         v53);
            else
              v54 = 0;
            v55 = (char *)v44 - (char *)out_indices->_M_impl._M_start;
            if ( v55 )
            {
              memmove(v54, (unsigned __int8 *)out_indices->_M_impl._M_start, v55);
              v57 = (unsigned __int8 *)(v55 + v56);
            }
            else
            {
              v57 = v54;
            }
            *(_WORD *)v57 = *v45;
            v58 = (unsigned __int16 *)(v57 + 2);
            v59 = out_indices->_M_impl._M_start;
            if ( out_indices->_M_impl._M_start )
            {
              v60 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v60, v59);
            }
            v7 = i;
            v61 = (unsigned __int16 *)&v54[2 * v63];
            v3 = this;
            out_indices->_M_impl._M_start = (unsigned __int16 *)v54;
            out_indices->_M_impl._M_finish = v58;
            out_indices->_M_impl._M_end_of_storage._M_data = v61;
          }
          else
          {
            *v44 = *v45;
            ++out_indices->_M_impl._M_finish;
          }
          v7 += 3;
          i = v7;
        }
        while ( v7 < num_triangles );
        v4 = mg_index;
      }
      v5 = ++v4 < (int)v3->__vftable;
      mg_index = v4;
    }
    while ( v5 );
  }
}

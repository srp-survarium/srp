void __userpurge vostok::render::speedtree_tree_component_frond::init_index_buffer(
        vostok::render::vector<unsigned short> *out_indices@<edi>,
        vostok::render::speedtree_tree_component_frond *this,
        const SpeedTree::SIndexedTriangles *lod)
{
  vostok::render::speedtree_tree_component_frond *v3; // edx
  bool v4; // cc
  const SpeedTree::SDrawCallInfo *v5; // ecx
  int m_nOffset; // eax
  int v7; // esi
  bool v8; // sf
  unsigned __int16 *v9; // ebx
  unsigned __int16 *M_finish; // esi
  unsigned int v11; // eax
  char v12; // dl
  int *v13; // ecx
  unsigned int v14; // ecx
  int *v15; // eax
  int v16; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v18; // ecx
  unsigned __int8 *v19; // ebp
  unsigned int v20; // esi
  int v21; // eax
  unsigned __int8 *v22; // eax
  unsigned __int16 *v23; // ebx
  unsigned __int16 *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  int v26; // esi
  int v27; // [esp+Ch] [ebp-1Ch] BYREF
  int v28; // [esp+10h] [ebp-18h]
  int i; // [esp+14h] [ebp-14h]
  int mg_index; // [esp+18h] [ebp-10h]
  int v31; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int v32; // [esp+20h] [ebp-8h] BYREF
  const SpeedTree::SDrawCallInfo *info; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = (int)this->__vftable <= 0;
  mg_index = 0;
  if ( !v4 )
  {
    v28 = 0;
    do
    {
      v5 = (const SpeedTree::SDrawCallInfo *)((char *)v3->m_parent + v28);
      m_nOffset = v5->m_nOffset;
      v7 = m_nOffset + v5->m_nLength;
      v8 = -v5->m_nLength < 0;
      info = v5;
      i = m_nOffset;
      if ( v8 != __OFSUB__(m_nOffset, v7) )
      {
        do
        {
          v9 = (unsigned __int16 *)((char *)v3->m_render_geometry.geom.m_object + 2 * m_nOffset);
          M_finish = out_indices->_M_impl._M_finish;
          if ( M_finish == out_indices->_M_impl._M_end_of_storage._M_data )
          {
            v11 = M_finish - out_indices->_M_impl._M_start;
            v12 = 1;
            v31 = 1;
            v27 = v11;
            if ( v11 == 0x7FFFFFFF )
              stlp_std::__stl_throw_length_error("vector");
            v13 = &v27;
            if ( v11 <= 1 )
              v13 = &v31;
            v14 = v11 + *v13;
            v27 = v14;
            if ( v14 > 0x7FFFFFFF || v14 < v11 )
            {
              v27 = 0x7FFFFFFF;
              v14 = 0x7FFFFFFF;
            }
            v32 = v14;
            v31 = 1;
            v15 = &v31;
            if ( v14 )
              v15 = (int *)&v32;
            v16 = *v15;
            m_object = vostok::render::g_allocator.m_object;
            v18 = 2 * v16;
            if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v18 )
              v12 = 0;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v12;
            if ( v18 )
              v19 = (unsigned __int8 *)vostok_mspace_malloc(
                                         (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                         v18);
            else
              v19 = 0;
            v20 = (char *)M_finish - (char *)out_indices->_M_impl._M_start;
            if ( v20 )
            {
              memmove(v19, (unsigned __int8 *)out_indices->_M_impl._M_start, v20);
              v22 = (unsigned __int8 *)(v20 + v21);
            }
            else
            {
              v22 = v19;
            }
            *(_WORD *)v22 = *v9;
            v23 = (unsigned __int16 *)(v22 + 2);
            M_start = out_indices->_M_impl._M_start;
            if ( out_indices->_M_impl._M_start )
            {
              m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
            }
            v5 = info;
            v3 = this;
            out_indices->_M_impl._M_end_of_storage._M_data = (unsigned __int16 *)&v19[2 * v27];
            m_nOffset = i;
            out_indices->_M_impl._M_start = (unsigned __int16 *)v19;
            out_indices->_M_impl._M_finish = v23;
          }
          else
          {
            *M_finish = *v9;
            ++out_indices->_M_impl._M_finish;
          }
          v26 = v5->m_nOffset + v5->m_nLength;
          i = ++m_nOffset;
        }
        while ( m_nOffset < v26 );
      }
      v28 += 20;
      v4 = ++mg_index < (int)v3->__vftable;
    }
    while ( v4 );
  }
}

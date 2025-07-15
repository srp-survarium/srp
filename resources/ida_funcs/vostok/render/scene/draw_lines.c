void __userpurge vostok::render::scene::draw_lines(
        const vostok::vectora<vostok::render::vertex_colored> *vertices@<eax>,
        vostok::render::scene *this,
        int indices)
{
  const vostok::vectora<unsigned short> *v3; // ebx
  vostok::render::vertex_colored *M_finish; // ecx
  vostok::render::vertex_colored *M_start; // edx
  vostok::render::vertex_colored *v8; // esi
  unsigned int v9; // eax
  const unsigned __int16 *v10; // eax
  const unsigned __int16 *v11; // ecx
  unsigned __int16 *v12; // esi
  unsigned __int16 v13; // bx
  unsigned int v14; // eax
  char v15; // dl
  int *p_indices; // ecx
  unsigned int v17; // ecx
  int *v18; // eax
  int v19; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v21; // ecx
  unsigned __int8 *v22; // edi
  unsigned __int8 *v23; // eax
  unsigned int v24; // esi
  int v25; // eax
  unsigned __int8 *v26; // eax
  unsigned __int16 *v27; // ebx
  unsigned __int16 *v28; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  const stlp_std::__false_type *v30; // [esp+0h] [ebp-20h]
  __int16 n; // [esp+10h] [ebp-10h]
  int v32; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v33; // [esp+18h] [ebp-8h] BYREF
  const unsigned __int16 *e; // [esp+1Ch] [ebp-4h]
  const unsigned __int16 *i; // [esp+24h] [ebp+4h]

  v3 = (const vostok::vectora<unsigned short> *)indices;
  if ( ((*(_DWORD *)(indices + 4) - *(_DWORD *)indices) >> 1)
     + this->m_line_indices._M_impl._M_finish
     - this->m_line_indices._M_impl._M_start >= (unsigned int)&_sbh_sizeHeaderList )
    vostok::render::scene::render_lines(this, 0);
  M_finish = vertices->_M_impl._M_finish;
  M_start = vertices->_M_impl._M_start;
  v8 = this->m_line_vertices._M_impl._M_finish;
  n = v8 - this->m_line_vertices._M_impl._M_start;
  if ( M_start != M_finish )
  {
    v9 = M_finish - M_start;
    if ( this->m_line_vertices._M_impl._M_end_of_storage._M_data - this->m_line_vertices._M_impl._M_finish < v9 )
      stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::_M_range_insert_realloc<vostok::render::vertex_colored const *>(
        v9,
        (stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *)M_finish,
        &this->m_line_vertices._M_impl,
        v8,
        M_start,
        M_finish);
    else
      stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::_M_range_insert_aux<vostok::render::vertex_colored const *>(
        (stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *)M_finish,
        (int)&this->m_line_vertices,
        v8,
        M_start,
        M_finish,
        (const vostok::render::vertex_colored *)(M_finish - M_start),
        v30);
    v3 = (const vostok::vectora<unsigned short> *)indices;
  }
  v10 = v3->_M_impl._M_start;
  v11 = v3->_M_impl._M_finish;
  i = v10;
  for ( e = v11; v10 != v11; i = v10 )
  {
    v12 = this->m_line_indices._M_impl._M_finish;
    v13 = n + *v10;
    if ( v12 == this->m_line_indices._M_impl._M_end_of_storage._M_data )
    {
      v14 = v12 - this->m_line_indices._M_impl._M_start;
      v15 = 1;
      v32 = 1;
      indices = v14;
      if ( v14 == 0x7FFFFFFF )
        stlp_std::__stl_throw_length_error("vector");
      p_indices = &indices;
      if ( v14 <= 1 )
        p_indices = &v32;
      v17 = v14 + *p_indices;
      indices = v17;
      if ( v17 > 0x7FFFFFFF || v17 < v14 )
      {
        indices = 0x7FFFFFFF;
        v17 = 0x7FFFFFFF;
      }
      v33 = v17;
      v32 = 1;
      v18 = &v32;
      if ( v17 )
        v18 = (int *)&v33;
      v19 = *v18;
      m_object = vostok::render::g_allocator.m_object;
      v21 = 2 * v19;
      if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v21 )
        v15 = 0;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v15;
      if ( v21 )
        v22 = (unsigned __int8 *)vostok_mspace_malloc(
                                   (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                   v21);
      else
        v22 = 0;
      v23 = (unsigned __int8 *)this->m_line_indices._M_impl._M_start;
      v24 = (char *)v12 - (char *)v23;
      if ( v24 )
      {
        memmove(v22, v23, v24);
        v26 = (unsigned __int8 *)(v24 + v25);
      }
      else
      {
        v26 = v22;
      }
      *(_WORD *)v26 = v13;
      v27 = (unsigned __int16 *)(v26 + 2);
      v28 = this->m_line_indices._M_impl._M_start;
      if ( v28 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v28);
      }
      v10 = i;
      this->m_line_indices._M_impl._M_end_of_storage._M_data = (unsigned __int16 *)&v22[2 * indices];
      v11 = e;
      this->m_line_indices._M_impl._M_start = (unsigned __int16 *)v22;
      this->m_line_indices._M_impl._M_finish = v27;
    }
    else
    {
      *v12 = v13;
      ++this->m_line_indices._M_impl._M_finish;
    }
    ++v10;
  }
}

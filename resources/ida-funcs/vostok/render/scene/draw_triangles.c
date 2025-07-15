void __userpurge vostok::render::scene::draw_triangles(
        const vostok::vectora<vostok::render::vertex_colored> *vertices@<eax>,
        vostok::render::scene *this,
        int indices)
{
  const vostok::vectora<unsigned short> *v3; // ebx
  vostok::render::vector<vostok::render::vertex_colored> *p_m_triangle_vertices; // edi
  vostok::render::vertex_colored *M_finish; // ecx
  vostok::render::vertex_colored *M_start; // edx
  vostok::render::vertex_colored *v9; // esi
  unsigned int v10; // eax
  const unsigned __int16 *v11; // eax
  const unsigned __int16 *v12; // ecx
  unsigned __int16 *v13; // esi
  unsigned __int16 v14; // bx
  unsigned int v15; // eax
  char v16; // dl
  int *p_indices; // ecx
  unsigned int v18; // ecx
  int *v19; // eax
  int v20; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v22; // ecx
  unsigned __int8 *v23; // edi
  unsigned __int8 *v24; // eax
  unsigned int v25; // esi
  int v26; // eax
  unsigned __int8 *v27; // eax
  unsigned __int16 *v28; // ebx
  unsigned __int16 *v29; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  const stlp_std::__false_type *v31; // [esp+0h] [ebp-20h]
  __int16 n; // [esp+10h] [ebp-10h]
  int v33; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v34; // [esp+18h] [ebp-8h] BYREF
  const unsigned __int16 *e; // [esp+1Ch] [ebp-4h]
  const unsigned __int16 *i; // [esp+24h] [ebp+4h]

  v3 = (const vostok::vectora<unsigned short> *)indices;
  p_m_triangle_vertices = &this->m_triangle_vertices;
  if ( ((*(_DWORD *)(indices + 4) - *(_DWORD *)indices) >> 1)
     + this->m_triangle_vertices._M_impl._M_finish
     - this->m_triangle_vertices._M_impl._M_start >= (unsigned int)&_sbh_sizeHeaderList )
    vostok::render::scene::render_triangles(this);
  M_finish = vertices->_M_impl._M_finish;
  M_start = vertices->_M_impl._M_start;
  v9 = this->m_triangle_vertices._M_impl._M_finish;
  n = v9 - this->m_triangle_vertices._M_impl._M_start;
  if ( M_start != M_finish )
  {
    v10 = M_finish - M_start;
    if ( this->m_triangle_vertices._M_impl._M_end_of_storage._M_data - this->m_triangle_vertices._M_impl._M_finish < v10 )
      stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::_M_range_insert_realloc<vostok::render::vertex_colored const *>(
        v10,
        (stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *)M_finish,
        &p_m_triangle_vertices->_M_impl,
        v9,
        M_start,
        M_finish);
    else
      stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::_M_range_insert_aux<vostok::render::vertex_colored const *>(
        (stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *)M_finish,
        (int)p_m_triangle_vertices,
        v9,
        M_start,
        M_finish,
        (const vostok::render::vertex_colored *)(M_finish - M_start),
        v31);
    v3 = (const vostok::vectora<unsigned short> *)indices;
  }
  v11 = v3->_M_impl._M_start;
  v12 = v3->_M_impl._M_finish;
  i = v11;
  for ( e = v12; v11 != v12; i = v11 )
  {
    v13 = this->m_triangle_indices._M_impl._M_finish;
    v14 = n + *v11;
    if ( v13 == this->m_triangle_indices._M_impl._M_end_of_storage._M_data )
    {
      v15 = v13 - this->m_triangle_indices._M_impl._M_start;
      v16 = 1;
      v33 = 1;
      indices = v15;
      if ( v15 == 0x7FFFFFFF )
        stlp_std::__stl_throw_length_error("vector");
      p_indices = &indices;
      if ( v15 <= 1 )
        p_indices = &v33;
      v18 = v15 + *p_indices;
      indices = v18;
      if ( v18 > 0x7FFFFFFF || v18 < v15 )
      {
        indices = 0x7FFFFFFF;
        v18 = 0x7FFFFFFF;
      }
      v34 = v18;
      v33 = 1;
      v19 = &v33;
      if ( v18 )
        v19 = (int *)&v34;
      v20 = *v19;
      m_object = vostok::render::g_allocator.m_object;
      v22 = 2 * v20;
      if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v22 )
        v16 = 0;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v16;
      if ( v22 )
        v23 = (unsigned __int8 *)vostok_mspace_malloc(
                                   (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                   v22);
      else
        v23 = 0;
      v24 = (unsigned __int8 *)this->m_triangle_indices._M_impl._M_start;
      v25 = (char *)v13 - (char *)v24;
      if ( v25 )
      {
        memmove(v23, v24, v25);
        v27 = (unsigned __int8 *)(v25 + v26);
      }
      else
      {
        v27 = v23;
      }
      *(_WORD *)v27 = v14;
      v28 = (unsigned __int16 *)(v27 + 2);
      v29 = this->m_triangle_indices._M_impl._M_start;
      if ( v29 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v29);
      }
      v11 = i;
      this->m_triangle_indices._M_impl._M_end_of_storage._M_data = (unsigned __int16 *)&v23[2 * indices];
      v12 = e;
      this->m_triangle_indices._M_impl._M_start = (unsigned __int16 *)v23;
      this->m_triangle_indices._M_impl._M_finish = v28;
    }
    else
    {
      *v13 = v14;
      ++this->m_triangle_indices._M_impl._M_finish;
    }
    ++v11;
  }
}

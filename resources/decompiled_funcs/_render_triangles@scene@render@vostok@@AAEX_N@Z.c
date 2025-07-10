void __usercall vostok::render::scene::render_triangles(vostok::render::scene *this@<eax>)
{
  vostok::render::system_renderer **p_m_triangle_vertices; // esi
  vostok::render::vector<unsigned short> *p_m_triangle_indices; // edi
  unsigned __int16 v4[2]; // [esp+Ch] [ebp-14h] BYREF
  vostok::render::vertex_colored __x; // [esp+10h] [ebp-10h]

  p_m_triangle_vertices = (vostok::render::system_renderer **)&this->m_triangle_vertices;
  if ( this->m_triangle_vertices._M_impl._M_start != this->m_triangle_vertices._M_impl._M_finish )
  {
    p_m_triangle_indices = &this->m_triangle_indices;
    vostok::render::system_renderer::draw_triangles(
      *p_m_triangle_vertices,
      (const vostok::render::vertex_colored *const)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
      (const vostok::render::vertex_colored *const)*p_m_triangle_vertices,
      (const unsigned __int16 *const)this->m_triangle_vertices._M_impl._M_finish,
      this->m_triangle_indices._M_impl._M_start,
      (bool)this->m_triangle_indices._M_impl._M_finish);
    __x.color.m_value = -1;
    stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::resize((stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *)p_m_triangle_vertices);
    *(_DWORD *)v4 = 0;
    stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::resize(
      &p_m_triangle_indices->_M_impl,
      0,
      v4);
  }
}

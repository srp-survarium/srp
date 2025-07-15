void __usercall vostok::render::scene::render_lines(vostok::render::scene *this@<eax>, bool covering_effect@<dl>)
{
  vostok::render::vector<vostok::render::vertex_colored> *p_m_line_vertices; // esi
  vostok::render::vector<unsigned short> *p_m_line_indices; // edi
  unsigned __int16 v4[2]; // [esp+Ch] [ebp-14h] BYREF
  vostok::render::vertex_colored __x; // [esp+10h] [ebp-10h]

  p_m_line_vertices = &this->m_line_vertices;
  if ( this->m_line_vertices._M_impl._M_start != this->m_line_vertices._M_impl._M_finish )
  {
    p_m_line_indices = &this->m_line_indices;
    vostok::render::system_renderer::draw_lines(
      (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
      p_m_line_vertices->_M_impl._M_start,
      this->m_line_vertices._M_impl._M_finish,
      this->m_line_indices._M_impl._M_start,
      this->m_line_indices._M_impl._M_finish,
      covering_effect);
    __x.color.m_value = -1;
    stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::resize(&p_m_line_vertices->_M_impl);
    *(_DWORD *)v4 = 0;
    stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::resize(
      &p_m_line_indices->_M_impl,
      0,
      v4);
  }
}

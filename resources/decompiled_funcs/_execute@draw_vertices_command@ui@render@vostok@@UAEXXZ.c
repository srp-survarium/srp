void __thiscall vostok::render::ui::draw_vertices_command::execute(vostok::render::ui::draw_vertices_command *this)
{
  unsigned int m_points_type; // [esp-4h] [ebp-Ch]
  int prim_type; // [esp+4h] [ebp-4h] BYREF

  m_points_type = this->m_points_type;
  prim_type = this->m_vertices._M_impl._M_finish - this->m_vertices._M_impl._M_start;
  vostok::render::system_renderer::draw_ui_vertices(
    (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
    (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
    (unsigned __int8 *)this->m_vertices._M_impl._M_start,
    (unsigned int)&prim_type,
    this->m_primitives_type,
    m_points_type);
}

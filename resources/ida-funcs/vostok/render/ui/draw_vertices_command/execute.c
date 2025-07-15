void __thiscall vostok::render::ui::draw_vertices_command::execute(vostok::render::ui::draw_vertices_command *this)
{
  unsigned int m_primitives_type; // [esp-8h] [ebp-10h]
  unsigned int m_points_type; // [esp-4h] [ebp-Ch]
  int prim_type; // [esp+4h] [ebp-4h] BYREF

  m_points_type = this->m_points_type;
  m_primitives_type = this->m_primitives_type;
  prim_type = this->m_vertices.m_end - this->m_vertices.m_begin;
  vostok::render::system_renderer::draw_ui_vertices(
    (vostok::render::system_renderer *)this,
    (vostok::render::vertex_formats::TL *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
    (unsigned __int8 *)this->m_vertices.m_begin,
    (unsigned int *)&prim_type,
    m_primitives_type,
    m_points_type);
}

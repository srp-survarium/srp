void __usercall vostok::render::backend::set_vs(
        vostok::render::backend *this@<eax>,
        vostok::render::res_xs_hw<vostok::render::vs_data> *vs@<esi>)
{
  bool v2; // zf
  bool v3; // dl
  bool vertex_shader; // cl
  vostok::render::res_input_layout *m_input_layout; // edx

  v2 = this->m_vs == vs;
  this->m_vs = vs;
  v3 = !v2;
  v2 = v2 && !this->m_dirty_objects.vertex_shader;
  this->m_dirty_objects.vertex_shader |= v3;
  vertex_shader = this->m_dirty_objects.vertex_shader;
  if ( !v2 )
    ++this->num_vs_changes;
  if ( vertex_shader )
    m_input_layout = 0;
  else
    m_input_layout = this->m_input_layout;
  this->m_input_layout = m_input_layout;
  this->m_dirty_objects.input_layout = vertex_shader;
}

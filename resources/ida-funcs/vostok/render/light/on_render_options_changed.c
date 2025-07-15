void __thiscall vostok::render::light::on_render_options_changed(vostok::render::light *this)
{
  unsigned int m_shadow_map_size_index; // eax
  vostok::render::options *v2; // edx

  m_shadow_map_size_index = this->m_shadow_map_size_index;
  v2 = vostok::quasi_singleton<vostok::render::options>::pinst;
  this->m_quality_shadow_map_size_index = m_shadow_map_size_index;
  if ( m_shadow_map_size_index < 3 )
  {
    if ( !v2->current.m_shadow_quality )
      this->m_quality_shadow_map_size_index = m_shadow_map_size_index + 2;
    if ( v2->current.m_shadow_quality == 1 )
      this->m_quality_shadow_map_size_index = m_shadow_map_size_index + 1;
  }
}

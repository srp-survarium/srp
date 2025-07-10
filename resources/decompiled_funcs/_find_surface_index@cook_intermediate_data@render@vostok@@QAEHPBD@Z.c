int __thiscall vostok::render::cook_intermediate_data::find_surface_index(
        vostok::render::cook_intermediate_data *this,
        const char *surface_name)
{
  unsigned int m_num_render_models; // edi
  int result; // eax
  vostok::fs_new::virtual_path_string *i; // esi

  m_num_render_models = this->m_num_render_models;
  result = 0;
  if ( !this->m_num_render_models )
    return -1;
  for ( i = &this->assets->m_surface_name;
        strcmp(i->m_string.m_begin, surface_name);
        i = (vostok::fs_new::virtual_path_string *)((char *)i + 288) )
  {
    if ( ++result >= m_num_render_models )
      return -1;
  }
  return result;
}

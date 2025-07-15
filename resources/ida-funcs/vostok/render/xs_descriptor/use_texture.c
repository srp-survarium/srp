char __thiscall vostok::render::xs_descriptor<vostok::render::gs_data>::use_texture(
        vostok::render::xs_descriptor<vostok::render::vs_data> *this,
        const char *name)
{
  int v2; // ebx
  unsigned int v3; // edi
  vostok::render::texture_slot *i; // esi

  v2 = 0;
  v3 = this->m_shader_data.textures.m_end - this->m_shader_data.textures.m_begin;
  if ( !v3 )
    return 0;
  for ( i = this->m_shader_data.textures.m_begin; vostok::detail::strcmp_s(i->name.m_begin, name); ++i )
  {
    if ( ++v2 >= v3 )
      return 0;
  }
  return 1;
}

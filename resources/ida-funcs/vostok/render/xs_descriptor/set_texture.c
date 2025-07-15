char __thiscall vostok::render::xs_descriptor<vostok::render::gs_data>::set_texture(
        vostok::render::xs_descriptor<vostok::render::vs_data> *this,
        const char *name,
        vostok::render::res_texture *texture)
{
  int v3; // esi
  vostok::render::texture_slot *m_begin; // edi
  const char **i; // ebx
  unsigned int v7; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v7 = this->m_shader_data.textures.m_end - this->m_shader_data.textures.m_begin;
  if ( !v7 )
    return 0;
  m_begin = this->m_shader_data.textures.m_begin;
  for ( i = (const char **)&m_begin->name.m_begin; vostok::detail::strcmp_s(*i, name); i += 21 )
  {
    if ( ++v3 >= v7 )
      return 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    texture,
    (vostok::render::res_texture *)&m_begin[v3].texture);
  return 1;
}

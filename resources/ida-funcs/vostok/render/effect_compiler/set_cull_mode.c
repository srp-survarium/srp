vostok::render::effect_compiler *__usercall vostok::render::effect_compiler::set_cull_mode@<eax>(
        vostok::render::effect_compiler *this@<esi>,
        vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *mode@<edi>,
        vostok::command_line::key *a3@<ecx>)
{
  bool v3; // zf

  if ( !byte_61F4C[(_DWORD)this] && !vostok::command_line::key::is_set(a3, (int)&s_no_effect_result) )
  {
    v3 = *(vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > **)((char *)&this->m_shader_sources + (_DWORD)&loc_5033D + 3) == mode;
    *(vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > **)((char *)&this->m_shader_sources + (_DWORD)&loc_5033D + 3) = mode;
    *((_BYTE *)&this->m_shader_sources + (_DWORD)&loc_504A3 + 1) |= !v3;
  }
  return this;
}

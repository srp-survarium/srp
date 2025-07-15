vostok::render::effect_compiler *__usercall vostok::render::effect_compiler::set_fill_mode@<eax>(
        vostok::render::effect_compiler *this@<esi>,
        vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *fill_mode@<edi>,
        vostok::command_line::key *a3@<ecx>)
{
  char *v3; // eax
  bool v4; // zf

  if ( !byte_61F4C[(_DWORD)this] && !vostok::command_line::key::is_set(a3, (int)&s_no_effect_result) )
  {
    v3 = (char *)this + (_DWORD)&loc_5033B + 1;
    v4 = *(vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > **)((char *)&this->m_shader_sources + (_DWORD)&loc_5033B + 1) == fill_mode;
    *(_DWORD *)v3 = fill_mode;
    v3[360] |= !v4;
  }
  return this;
}

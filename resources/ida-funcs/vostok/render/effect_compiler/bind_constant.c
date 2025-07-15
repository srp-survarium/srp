vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::bind_constant@<eax>(
        const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *binding@<eax>,
        vostok::command_line::key *a2@<ecx>,
        vostok::render::effect_compiler *this)
{
  vostok::render::shader_constant_binding *v4; // ebx
  vostok::buffer_vector<vostok::render::shader_constant_binding> *v6; // [esp-4h] [ebp-14h]

  if ( byte_61F4C[(_DWORD)this] || vostok::command_line::key::is_set(a2, (int)&s_no_effect_result) )
    return this;
  v4 = *(vostok::render::shader_constant_binding **)((char *)&dword_61C20 + (_DWORD)this);
  if ( stlp_std::priv::__find<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>(
         *(vostok::render::shader_constant_binding **)((char *)&dword_61C1C + (_DWORD)this),
         (const vostok::render::shader_constant_binding *)binding,
         v4) == v4 )
    vostok::buffer_vector<vostok::render::shader_constant_binding>::push_back(
      v6,
      (const vostok::render::shader_constant_binding *)((char *)&dword_61C1C + (_DWORD)this),
      binding);
  return this;
}

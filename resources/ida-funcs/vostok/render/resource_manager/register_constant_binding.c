const vostok::render::shader_constant_host *__usercall vostok::render::resource_manager::register_constant_binding@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        const vostok::render::shader_constant_binding *binding@<eax>)
{
  vostok::render::shader_constant_binding *v2; // ebx
  const vostok::render::shader_constant_binding *v3; // esi
  vostok::render::shader_constant_binding *v5; // eax
  vostok::render::backend *v6; // ecx
  const vostok::render::shader_constant_host *result; // eax
  vostok::buffer_vector<vostok::render::shader_constant_binding> *v8; // [esp-4h] [ebp-10h]

  v2 = *(vostok::render::shader_constant_binding **)((char *)&this->sh_created + (_DWORD)&loc_94653 + 1);
  v3 = (const vostok::render::shader_constant_binding *)((char *)this + (_DWORD)&loc_9464F + 1);
  v5 = stlp_std::priv::__find<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>(
         *(vostok::render::shader_constant_binding **)((char *)&this->sh_created + (_DWORD)&loc_9464F + 1),
         binding,
         v2);
  v6 = (vostok::render::backend *)v8;
  if ( v5 == v2 )
    vostok::buffer_vector<vostok::render::shader_constant_binding>::push_back(
      v8,
      v3,
      (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)binding);
  result = vostok::render::backend::register_constant_host(
             v6,
             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
             &binding->m_name,
             (vostok::strings::shared::profile *)binding->m_type);
  if ( result )
  {
    result->m_source.m_pointer = binding->m_source.m_pointer;
    result->m_source.m_size = binding->m_source.m_size;
  }
  return result;
}

void __thiscall vostok::render::engine::world::register_material_parameter(
        vostok::render::engine::world *this,
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *host)
{
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v2; // edi
  vostok::render::backend *v3; // ecx
  vostok::render::shader_constant_host *v4; // eax
  bool v5; // zf

  v2 = host;
  vostok::shared_string::shared_string(
    (vostok::shared_string *)this,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&host,
    (char *)host->m_buffer[0]);
  v4 = vostok::render::backend::register_constant_host(
         v3,
         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
         (const vostok::shared_string *)&host,
         0);
  v5 = host == 0;
  *(_DWORD *)&v2->m_threading_policy.vostok::core::noncopyable = v4;
  if ( !v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)host, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(0, host);
}

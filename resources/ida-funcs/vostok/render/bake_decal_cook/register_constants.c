void __usercall vostok::render::bake_decal_cook::register_constants(
        vostok::render::bake_decal_cook *this@<ecx>,
        int a2@<edi>)
{
  vostok::render::backend *v2; // ecx
  vostok::shared_string *v3; // ecx
  vostok::render::backend *v4; // ecx
  vostok::shared_string *v5; // ecx
  vostok::render::backend *v6; // ecx
  vostok::shared_string *v7; // ecx
  vostok::render::backend *v8; // ecx
  vostok::shared_string *v9; // ecx
  vostok::render::backend *v10; // ecx
  vostok::shared_string *v11; // ecx
  vostok::render::backend *v12; // ecx
  vostok::shared_string *v13; // ecx
  vostok::render::backend *v14; // ecx
  vostok::shared_string *v15; // ecx
  vostok::render::backend *v16; // ecx
  vostok::shared_string name; // [esp+Ch] [ebp-4h] BYREF

  if ( !*(_BYTE *)(a2 + 88) )
  {
    vostok::shared_string::shared_string((vostok::shared_string *)this, &name.m_pointer, "m_W");
    *(_DWORD *)(a2 + 56) = vostok::render::backend::register_constant_host(
                             v2,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             &name,
                             0);
    if ( name.m_pointer.m_object )
    {
      v3 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
      if ( !v3 )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
    }
    vostok::shared_string::shared_string(v3, &name.m_pointer, "use_ao_texture");
    *(_DWORD *)(a2 + 80) = vostok::render::backend::register_constant_host(
                             v4,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             &name,
                             (vostok::strings::shared::profile *)1);
    if ( name.m_pointer.m_object )
    {
      v5 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
      if ( !v5 )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
    }
    vostok::shared_string::shared_string(v5, &name.m_pointer, "use_compression");
    *(_DWORD *)(a2 + 84) = vostok::render::backend::register_constant_host(
                             v6,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             &name,
                             (vostok::strings::shared::profile *)1);
    if ( name.m_pointer.m_object )
    {
      v7 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
      if ( !v7 )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
    }
    vostok::shared_string::shared_string(v7, &name.m_pointer, "decal_transform");
    *(_DWORD *)(a2 + 72) = vostok::render::backend::register_constant_host(
                             v8,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             &name,
                             0);
    if ( name.m_pointer.m_object )
    {
      v9 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
      if ( !v9 )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
    }
    vostok::shared_string::shared_string(v9, &name.m_pointer, "local_to_occlusion");
    *(_DWORD *)(a2 + 76) = vostok::render::backend::register_constant_host(
                             v10,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             &name,
                             0);
    if ( name.m_pointer.m_object )
    {
      v11 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
      if ( !v11 )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
    }
    vostok::shared_string::shared_string(v11, &name.m_pointer, "camouflage_scale");
    *(_DWORD *)(a2 + 60) = vostok::render::backend::register_constant_host(
                             v12,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             &name,
                             0);
    if ( name.m_pointer.m_object )
    {
      v13 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
      if ( !v13 )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
    }
    vostok::shared_string::shared_string(v13, &name.m_pointer, "decal_texture_use_flags");
    *(_DWORD *)(a2 + 64) = vostok::render::backend::register_constant_host(
                             v14,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             &name,
                             0);
    if ( name.m_pointer.m_object )
    {
      v15 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
      if ( !v15 )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
    }
    vostok::shared_string::shared_string(v15, &name.m_pointer, "camouflage_texture_use_flags");
    *(_DWORD *)(a2 + 68) = vostok::render::backend::register_constant_host(
                             v16,
                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                             &name,
                             0);
    if ( name.m_pointer.m_object )
    {
      if ( !_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
    }
    *(_BYTE *)(a2 + 88) = 1;
  }
}

void __usercall survarium::weapon::play_weapon_shell_pfx(survarium::weapon *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // edx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp-8h] [ebp-8h] BYREF
  const vostok::math::float4x4 *v5; // [esp-4h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 4012);
  if ( v2 )
  {
    v3 = *(unsigned __int8 *)(a2 + 4018);
    v5 = (const vostok::math::float4x4 *)(a2 + 1240);
    v4.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v4,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(v2 + 4 * v3));
    vostok::render::scene_renderer::play_particle_system(
      (vostok::render::scene_renderer *)(*(_DWORD *)(a2 + 4032) + 4),
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 4032) + 4),
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v4.m_object,
      v5);
    if ( ++*(_BYTE *)(a2 + 4018) == *(_BYTE *)(a2 + 4017) )
      *(_BYTE *)(a2 + 4018) = 0;
  }
}

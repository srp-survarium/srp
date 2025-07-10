void __usercall survarium::booby_trap::play_fired_effects(survarium::booby_trap *this@<ecx>, int a2@<eax>)
{
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v3; // [esp-8h] [ebp-Ch] BYREF
  const vostok::math::float4x4 *v4; // [esp-4h] [ebp-8h]

  v4 = (const vostok::math::float4x4 *)(a2 + 372);
  v3.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v3,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 456));
  vostok::render::scene_renderer::play_particle_system(
    (vostok::render::scene_renderer *)(*(_DWORD *)(a2 + 464) + 4),
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 464) + 4),
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v3.m_object,
    v4);
  (**(void (__thiscall ***)(int, int, int))(*(_DWORD *)(a2 + 464) + 196))(
    *(_DWORD *)(a2 + 464) + 196,
    a2 + 460,
    a2 + 420);
}

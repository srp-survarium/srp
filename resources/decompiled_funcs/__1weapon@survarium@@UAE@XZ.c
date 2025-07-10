void __usercall survarium::weapon::~weapon(survarium::weapon *this@<ecx>, int a2@<esi>)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  unsigned __int8 v3; // bl
  unsigned __int8 i; // bl
  int v5; // eax
  int v6; // eax
  void *v7; // eax
  int v8; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *in_instance; // [esp+8h] [ebp-8h]
  vostok::render::scene_renderer *scene; // [esp+Ch] [ebp-4h]

  v2 = *(vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)(a2 + 4032);
  *(_DWORD *)a2 = &survarium::weapon::`vftable';
  if ( v2 )
  {
    in_instance = v2 + 1;
    if ( v2[1].m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v3 = 0;
        for ( scene = *(vostok::render::scene_renderer **)(v2[42].m_object->grm_satisfaction_tree_hook.color_ + 16);
              v3 < *(_BYTE *)(a2 + 4016);
              ++v3 )
        {
          if ( vostok::particle::is_playing((const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(4 * v3 + *(_DWORD *)(a2 + 4008))) )
            vostok::render::scene_renderer::remove_particle_system_instance(
              scene,
              (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene,
              in_instance);
        }
        for ( i = 0; i < *(_BYTE *)(a2 + 4017); ++i )
        {
          if ( vostok::particle::is_playing((const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(4 * i + *(_DWORD *)(a2 + 4012))) )
            vostok::render::scene_renderer::remove_particle_system_instance(
              scene,
              (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene,
              in_instance);
        }
      }
    }
  }
  v5 = *(_DWORD *)(a2 + 4028);
  if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 4028) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 4028));
  v6 = *(_DWORD *)(a2 + 4020);
  if ( v6 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 4020) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 4020));
  if ( *(_DWORD *)(a2 + 3992) )
  {
    v7 = *(void **)(a2 + 3984);
    if ( v7 )
      pt3free(v7);
    *(_DWORD *)(a2 + 3984) = 0;
    *(_DWORD *)(a2 + 3992) = 0;
  }
  v8 = *(_DWORD *)(a2 + 3760);
  if ( v8 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 3760) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 3760));
  survarium::weapon_core::~weapon_core((survarium::weapon_core *)a2);
}

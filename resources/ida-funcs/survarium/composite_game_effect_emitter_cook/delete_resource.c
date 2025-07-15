void __thiscall survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter>::delete_resource(
        survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter> *this,
        vostok::resources::resource_base *resource)
{
  unsigned int i; // ebx
  vostok::memory::doug_lea_allocator *v3; // ecx
  const char *v4; // [esp+0h] [ebp-Ch]
  const char *v5; // [esp+4h] [ebp-8h]
  unsigned int v6; // [esp+8h] [ebp-4h]

  for ( i = 0; i < resource[1].m_parent_resources.m_size; ++i )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource[1].m_children_resources.m_last->resource
    + i);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  vostok::memory::doug_lea_allocator::free_impl(v3, (int)survarium::g_allocator, (char *)resource, v4, v5, v6);
}

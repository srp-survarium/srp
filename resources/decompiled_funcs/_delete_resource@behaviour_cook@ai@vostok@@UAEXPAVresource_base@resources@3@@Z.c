void __thiscall vostok::ai::behaviour_cook::delete_resource(
        vostok::ai::behaviour_cook *this,
        vostok::ai::behaviour *resource)
{
  const vostok::ai::movement_target *j; // [esp+4Ch] [ebp-28h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *i; // [esp+50h] [ebp-24h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *it; // [esp+54h] [ebp-20h]
  const vostok::ai::sound_item *it_end2; // [esp+58h] [ebp-1Ch]
  const vostok::ai::movement_target *it_begin3; // [esp+64h] [ebp-10h]
  const vostok::ai::animation_item *it_end1; // [esp+6Ch] [ebp-8h]
  vostok::ai::behaviour *behavior_res; // [esp+70h] [ebp-4h]

  behavior_res = resource;
  it_end1 = (const vostok::ai::animation_item *)((char *)&resource[1] + 280 * resource->m_animations_count);
  for ( it = (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&resource[1];
        it != (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)it_end1;
        it += 70 )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(it);
  }
  it_end2 = (const vostok::ai::sound_item *)((char *)&behavior_res[1]
                                           + 280 * behavior_res->m_animations_count
                                           + 280 * behavior_res->m_sounds_count);
  for ( i = (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)((char *)&behavior_res[1] + 280 * behavior_res->m_animations_count);
        i != (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)it_end2;
        i += 70 )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  it_begin3 = vostok::ai::behaviour::get_movement_targets(behavior_res);
  for ( j = it_begin3; j != &it_begin3[behavior_res->m_movement_targets_count]; ++j )
    ;
  ((void (__thiscall *)(vostok::ai::behaviour *, _DWORD))behavior_res->~vostok::resources::resource_base)(
    behavior_res,
    0);
  ___free_helper_Vdoug_lea_allocator_memory_vostok____CBX_memory_vostok__YAXAAVdoug_lea_allocator_01_AAPBX_Z(
    vostok::ai::g_allocator,
    (void **)&resource);
}

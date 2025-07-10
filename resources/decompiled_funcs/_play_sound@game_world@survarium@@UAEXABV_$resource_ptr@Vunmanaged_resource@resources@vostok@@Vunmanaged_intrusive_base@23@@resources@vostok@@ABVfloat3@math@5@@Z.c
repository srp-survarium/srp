void __thiscall survarium::game_world::play_sound(
        survarium::game_world *this,
        vostok::sound::sound_emitter *resource,
        const vostok::math::float3 *position)
{
  vostok::sound::world_user *v4; // eax
  vostok::resources::unmanaged_resource *v5; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_active_npc_stats; // [esp-18h] [ebp-1Ch]
  const vostok::math::float3 *v7; // [esp-10h] [ebp-14h]
  vostok::configs::binary_config *v8; // [esp-4h] [ebp-8h]

  if ( resource->__vftable )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v8 = (vostok::configs::binary_config *)resource->__vftable;
      resource = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource,
        v8);
      v7 = position;
      v4 = (vostok::sound::world_user *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this[-1].m_input_mode + 132) + 8))(*(_DWORD *)(this[-1].m_input_mode + 132));
      p_m_active_npc_stats = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&this[-1].m_active_npc_stats;
      v5 = resource;
      vostok::sound::sound_emitter::emit_and_play_once(resource, p_m_active_npc_stats, v4, v7, 0, 0, 0);
      if ( v5 )
      {
        if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
      }
    }
  }
}

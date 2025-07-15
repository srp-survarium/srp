void __userpurge survarium::game_world::play_sound(
        survarium::game_world *this@<ecx>,
        const vostok::sound::sound_receiver *a2@<esi>,
        vostok::sound::sound_emitter *resource,
        const vostok::math::float3 *position)
{
  vostok::sound::sound_instance_proxy *v5; // eax
  const vostok::math::float3 *v6; // [esp-Ch] [ebp-14h]
  bool v7; // [esp+0h] [ebp-8h]

  if ( resource->__vftable )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource,
        (vostok::particle::particle_system_instance_impl *)resource->__vftable);
      v6 = position;
      v5 = (vostok::sound::sound_instance_proxy *)this->m_game->m_sound_world->get_logic_world_user(this->m_game->m_sound_world);
      vostok::sound::sound_emitter::emit_and_play_once(resource, &this->m_sound_scene, v5, v6, 0, a2, v7);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource);
    }
  }
}


void __userpurge survarium::game_world::play_sound(
        int a1@<ecx>,
        const vostok::sound::sound_receiver *a2@<esi>,
        vostok::sound::sound_emitter *a3,
        const vostok::math::float3 *a4)
{
  survarium::game_world::play_sound((survarium::game_world *)(a1 - 240), a2, a3, a4);
}

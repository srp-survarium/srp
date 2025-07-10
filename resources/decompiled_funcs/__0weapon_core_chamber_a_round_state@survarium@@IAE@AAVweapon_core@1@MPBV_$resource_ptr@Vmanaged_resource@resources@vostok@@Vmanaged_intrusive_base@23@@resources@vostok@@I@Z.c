void __thiscall survarium::weapon_core_chamber_a_round_state::weapon_core_chamber_a_round_state(
        survarium::weapon_core_chamber_a_round_state *this,
        survarium::weapon_core *weapon,
        float animation_time_scale,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        unsigned int animations_count)
{
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  _BYTE *v7; // eax
  int j; // [esp+2Ch] [ebp-14h]
  int i; // [esp+30h] [ebp-10h]
  unsigned int user_state; // [esp+34h] [ebp-Ch]
  unsigned int view; // [esp+38h] [ebp-8h]
  unsigned int animation_index; // [esp+3Ch] [ebp-4h]

  survarium::weapon_core_chamber_a_round_state_base::weapon_core_chamber_a_round_state_base(
    this,
    weapon,
    animation_time_scale);
  this->survarium::weapon_core_chamber_a_round_state_base::survarium::weapon_core_animation_end_aware_state::survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_chamber_a_round_state_vtbl *)&survarium::weapon_core_chamber_a_round_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_chamber_a_round_state_base::survarium::weapon_core_animation_end_aware_state::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_chamber_a_round_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  `vector constructor iterator'(
    (char *)this->m_weapon_animations,
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_user_animations,
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  survarium::weapon_user_dead_state::finalize(v5);
  if ( *v7 )
    survarium::weapon_user_dead_state::finalize(v6);
  animation_index = 0;
  for ( view = 0; view != 2; ++view )
  {
    for ( user_state = 0; user_state != 2; ++user_state )
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
        &this->m_weapon_animations[view][user_state],
        &animations[animation_index++]);
    v6 = (survarium::game_camera *)(view + 1);
  }
  for ( i = 0; i != 2; ++i )
  {
    for ( j = 0; j != 2; ++j )
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
        &this->m_user_animations[i][j],
        &animations[animation_index++]);
      v6 = (survarium::game_camera *)(j + 1);
    }
  }
  survarium::weapon_user_dead_state::finalize(v6);
}

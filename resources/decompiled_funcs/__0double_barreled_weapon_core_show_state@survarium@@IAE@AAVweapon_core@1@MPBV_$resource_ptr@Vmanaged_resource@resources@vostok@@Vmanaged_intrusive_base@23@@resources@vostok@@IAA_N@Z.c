void __thiscall survarium::double_barreled_weapon_core_show_state::double_barreled_weapon_core_show_state(
        survarium::double_barreled_weapon_core_show_state *this,
        survarium::weapon_core *weapon,
        float animation_timescale,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        survarium::game_camera *animations_count,
        bool *is_shown)
{
  survarium::game_camera *v6; // ecx
  _BYTE *v7; // eax
  survarium::weapon_core *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  _BYTE *v11; // eax
  int j; // [esp+28h] [ebp-18h]
  int i; // [esp+2Ch] [ebp-14h]
  unsigned int weapon_state_index; // [esp+30h] [ebp-10h]
  unsigned int user_state_index; // [esp+34h] [ebp-Ch]
  unsigned int view_index; // [esp+38h] [ebp-8h]
  unsigned int animation_index; // [esp+3Ch] [ebp-4h]

  survarium::weapon_core_show_state_base::weapon_core_show_state_base(this, weapon, is_shown);
  this->survarium::weapon_core_show_state_base::survarium::weapon_core_animation_end_aware_state::survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::double_barreled_weapon_core_show_state_vtbl *)&survarium::double_barreled_weapon_core_show_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_show_state_base::survarium::weapon_core_animation_end_aware_state::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::double_barreled_weapon_core_show_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  `vector constructor iterator'(
    (char *)this->m_weapon_animations,
    4u,
    12,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_user_animations,
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->m_time_scale = animation_timescale;
  survarium::weapon_user_dead_state::finalize(v6);
  v8 = (survarium::weapon_core *)(unsigned __int8)*v7;
  if ( *v7 )
  {
    survarium::weapon_core::get_magazine_capacity(v8, (int)weapon);
    survarium::weapon_user_dead_state::finalize(v9);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v8);
  if ( *v11 )
    survarium::weapon_user_dead_state::finalize(animations_count);
  animation_index = 0;
  for ( view_index = 0; view_index != 2; ++view_index )
  {
    for ( user_state_index = 0; user_state_index != 2; ++user_state_index )
    {
      for ( weapon_state_index = 0; weapon_state_index != 3; ++weapon_state_index )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
          &this->m_weapon_animations[view_index][user_state_index][weapon_state_index],
          &animations[animation_index++]);
        v10 = (survarium::game_camera *)(weapon_state_index + 1);
      }
    }
  }
  for ( i = 0; i != 2; ++i )
  {
    for ( j = 0; j != 2; ++j )
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
        &this->m_user_animations[i][j],
        &animations[animation_index++]);
      v10 = (survarium::game_camera *)(j + 1);
    }
  }
  survarium::weapon_user_dead_state::finalize(v10);
}

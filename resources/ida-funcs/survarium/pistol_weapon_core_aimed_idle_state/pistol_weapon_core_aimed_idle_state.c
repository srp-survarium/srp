void __thiscall survarium::pistol_weapon_core_aimed_idle_state::pistol_weapon_core_aimed_idle_state(
        survarium::pistol_weapon_core_aimed_idle_state *this,
        survarium::weapon_core *weapon,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        unsigned int animations_count)
{
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  survarium::game_camera *v6; // ecx
  unsigned int weapon_state_index; // [esp+1Ch] [ebp-10h]
  unsigned int user_state_index; // [esp+20h] [ebp-Ch]
  unsigned int view_index; // [esp+24h] [ebp-8h]
  unsigned int animation_index; // [esp+28h] [ebp-4h]

  survarium::weapon_core_aimed_state_base::weapon_core_aimed_state_base(this, weapon);
  this->survarium::weapon_core_aimed_state_base::survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::pistol_weapon_core_aimed_idle_state_vtbl *)&survarium::pistol_weapon_core_aimed_idle_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_aimed_state_base::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::pistol_weapon_core_aimed_idle_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  `vector constructor iterator'(
    (char *)this->m_weapon_animations,
    4u,
    8,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  survarium::weapon_user_dead_state::finalize(v4);
  v6 = (survarium::game_camera *)(unsigned __int8)*v5;
  if ( *v5 )
    survarium::weapon_user_dead_state::finalize(v6);
  animation_index = 0;
  for ( view_index = 0; view_index != 2; ++view_index )
  {
    for ( user_state_index = 0; user_state_index != 2; ++user_state_index )
    {
      for ( weapon_state_index = 0; weapon_state_index != 2; ++weapon_state_index )
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
          &this->m_weapon_animations[view_index][user_state_index][weapon_state_index],
          &animations[animation_index++]);
      v6 = (survarium::game_camera *)(user_state_index + 1);
    }
  }
  survarium::weapon_user_dead_state::finalize(v6);
}

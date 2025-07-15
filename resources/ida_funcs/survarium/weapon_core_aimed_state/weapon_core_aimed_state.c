void __thiscall survarium::weapon_core_aimed_state::weapon_core_aimed_state(
        survarium::weapon_core_aimed_state *this,
        survarium::weapon_core *weapon,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        unsigned int animations_count)
{
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  unsigned int user_state; // [esp+1Ch] [ebp-Ch]
  unsigned int view; // [esp+20h] [ebp-8h]
  unsigned int animation_index; // [esp+24h] [ebp-4h]

  survarium::weapon_core_aimed_state_base::weapon_core_aimed_state_base(this, weapon);
  this->survarium::weapon_core_aimed_state_base::survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_aimed_state_vtbl *)&survarium::weapon_core_aimed_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_aimed_state_base::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_aimed_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  `vector constructor iterator'(
    (char *)this->m_weapon_animations,
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  survarium::weapon_user_dead_state::finalize(v4);
  if ( *v5 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(unsigned __int8)*v5);
  animation_index = 0;
  for ( view = 0; view != 2; ++view )
  {
    for ( user_state = 0; user_state != 2; ++user_state )
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
        &this->m_weapon_animations[view][user_state],
        &animations[animation_index++]);
  }
}

void __thiscall survarium::weapon_core_shotgun_reload_state::~weapon_core_shotgun_reload_state(
        survarium::weapon_core_shotgun_reload_state *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::ai::fsm_state *state; // [esp+28h] [ebp-4h] BYREF

  this->survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_shotgun_reload_state_vtbl *)&survarium::weapon_core_shotgun_reload_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_shotgun_reload_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  if ( this->m_delete_substates_on_destruction )
  {
    while ( 1 )
    {
      state = vostok::ai::fsm::pop_state(this->m_logic);
      if ( !state )
        break;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
        v1,
        (vostok::sound::sound_scene **)&state);
    }
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::fsm,vostok::memory::detail::call_destructor_predicate>(
    v2,
    &this->m_logic);
  survarium::weapon_core_base_state::~weapon_core_base_state(this);
}

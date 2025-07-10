void __thiscall survarium::weapon_core_animation_end_aware_state::set_animation_to_wait(
        survarium::weapon_core_animation_end_aware_state *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation)
{
  survarium::base_player *user; // eax

  user = survarium::weapon_core::get_user((survarium::weapon_core *)this, (int)this->m_weapon);
  if ( !((unsigned __int8 (__thiscall *)(survarium::base_player *, survarium::base_player *))user->is_replaying_history)(
          user,
          user) )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
      &this->m_animation_to_wait_for,
      animation);
}

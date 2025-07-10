char __thiscall survarium::weapon_user_animations_selector::stand_predicate(
        survarium::weapon_user_animations_selector *this)
{
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  vostok::physics::bt_character_controller *v4; // ecx
  char v5; // [esp+0h] [ebp-20h]
  survarium::weapon_user_state_enum m_weapon_user_state_id; // [esp+4h] [ebp-1Ch]
  const vostok::variant<32> **v8; // [esp+10h] [ebp-10h]

  m_weapon_user_state_id = survarium::weapon_user_animations_selector::current_state(this)->m_weapon_user_state_id;
  if ( m_weapon_user_state_id != type_crouch )
    return m_weapon_user_state_id != type_sprint
        || survarium::weapon_user_animations_selector::sprint_predicate(this) == 0;
  v2 = this->m_user->damage_model(this->m_user);
  v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v2);
  v5 = 0;
  if ( (unsigned __int8)(*((_BYTE *)v8 + 825) + *((_BYTE *)v8 + 824)) != 2
    && (this->m_user->input(this->m_user)->actions_mask & 0x100) == 0 )
  {
    this->m_user->physics_controller(this->m_user);
    if ( vostok::physics::bt_character_controller::can_stand(v4) )
      return 1;
  }
  return v5;
}

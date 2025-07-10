char __thiscall survarium::weapon_user_animations_selector::jump_predicate(
        survarium::weapon_user_animations_selector *this)
{
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v1; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // edx
  int *v4; // eax
  vostok::physics::bt_character_controller *v5; // ecx
  survarium::player_stamina *v6; // edx
  char v8; // [esp+3h] [ebp-1Dh]
  float m_value; // [esp+Ch] [ebp-14h]

  v8 = 0;
  if ( !survarium::weapon_user_animations_selector::is_weapon_firing(this)
    && !survarium::weapon_user_animations_selector::is_weapon_toggling(this) )
  {
    v1 = this->m_user->damage_model(this->m_user);
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)v1);
    if ( !(*((_BYTE *)v3 + 825) + *((_BYTE *)v3 + 824)) && (this->m_user->input(this->m_user)->actions_mask & 0x10) != 0 )
    {
      v4 = (int *)this->m_user->physics_controller(this->m_user);
      if ( vostok::physics::bt_character_controller::can_jump(v5, v4) )
      {
        m_value = this->m_user->stamina(this->m_user)->m_value;
        v6 = this->m_user->stamina(this->m_user);
        if ( m_value >= (float)((float)(v6->m_max_value * v6->m_max_value_factor) / 5.0) )
          return 1;
      }
    }
  }
  return v8;
}

char __thiscall survarium::weapon_user_animations_selector::sprint_predicate(
        survarium::weapon_user_animations_selector *this)
{
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v1; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // edx
  survarium::player_input *v4; // eax
  survarium::player_stamina *v5; // eax
  char v7; // [esp+0h] [ebp-10h]

  v7 = 0;
  if ( !survarium::weapon_user_animations_selector::is_weapon_firing(this)
    && !survarium::weapon_user_animations_selector::is_weapon_toggling(this) )
  {
    v1 = this->m_user->damage_model(this->m_user);
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)v1);
    if ( !(*((_BYTE *)v3 + 825) + *((_BYTE *)v3 + 824)) && !this->m_forced_not_to_sprint )
    {
      v4 = (survarium::player_input *)this->m_user->input(this->m_user);
      if ( survarium::player_input::is_sprinting(v4) )
      {
        v5 = this->m_user->stamina(this->m_user);
        if ( survarium::player_stamina::can_be_spent(v5) )
          return 1;
      }
    }
  }
  return v7;
}

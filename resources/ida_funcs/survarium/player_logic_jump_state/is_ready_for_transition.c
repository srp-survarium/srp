bool __thiscall survarium::player_logic_jump_state::is_ready_for_transition(survarium::player_logic_jump_state *this)
{
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v1; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  survarium::base_player *v3; // ecx
  bool v5; // [esp+0h] [ebp-10h]
  const vostok::variant<32> **v7; // [esp+8h] [ebp-8h]

  v5 = 1;
  if ( !survarium::jump_logic::is_jump_finished(&this->m_logic) )
  {
    v1 = this->m_user->damage_model(this->m_user);
    v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)v1);
    v3 = (survarium::base_player *)(*((unsigned __int8 *)v7 + 825) + *((unsigned __int8 *)v7 + 824));
    if ( (unsigned __int8)v3 != 2 && survarium::base_player::is_alive(v3, (int)this->m_user) )
      return 0;
  }
  return v5;
}

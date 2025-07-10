survarium::player_logic_base_state *__thiscall survarium::weapon_user_animations_selector::current_state(
        survarium::weapon_user_animations_selector *this)
{
  survarium::game_camera *v1; // ecx
  vostok::ai::fsm_state *m_current_state; // [esp+Ch] [ebp-8h] BYREF
  survarium::player_logic_base_state *result; // [esp+10h] [ebp-4h]

  m_current_state = this->m_logic.m_current_state;
  result = (survarium::player_logic_base_state *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                   (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)m_current_state,
                                                   (int)&m_current_state);
  survarium::weapon_user_dead_state::finalize(v1);
  return result;
}

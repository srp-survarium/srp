const vostok::variant<32> **__thiscall vostok::ai::selectors::position_target_selector::get_target_caption(
        vostok::ai::selectors::position_target_selector *this,
        unsigned int target_index)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::ai::movement_target *target; // [esp+8h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  target = this->m_selected_positions.m_begin[target_index];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)target);
  return stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           v2,
           (int)&target->caption);
}

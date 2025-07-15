unsigned int __thiscall vostok::ai::planning::operator_impl::weight(
        vostok::ai::planning::operator_impl *this,
        const vostok::ai::planning::world_state *state0,
        survarium::game_camera *state1)
{
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize(state1);
  survarium::weapon_user_dead_state::finalize(v3);
  return this->m_cost;
}

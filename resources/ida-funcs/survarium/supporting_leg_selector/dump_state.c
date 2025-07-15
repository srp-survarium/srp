char __thiscall survarium::supporting_leg_selector::dump_state(
        survarium::supporting_leg_selector *this,
        const vostok::animation::animation_states_dumper::animation_state_info *info)
{
  if ( info->animation_user_data != 1 )
    return 1;
  this->m_right_leg_is_supporting = info->interval_id == 0;
  return 0;
}

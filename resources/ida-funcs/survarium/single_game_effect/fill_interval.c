unsigned int __thiscall survarium::single_game_effect::fill_interval(
        survarium::single_game_effect *this,
        const survarium::game_effect_interval_description *interval,
        survarium::single_game_effect **effects)
{
  if ( this->m_length <= interval->start_time )
    return 0;
  *effects = this;
  return 1;
}

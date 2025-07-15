BOOL __thiscall survarium::single_game_effect::effects_count(
        survarium::single_game_effect *this,
        const survarium::game_effect_interval_description *interval)
{
  return this->m_length > interval->start_time;
}

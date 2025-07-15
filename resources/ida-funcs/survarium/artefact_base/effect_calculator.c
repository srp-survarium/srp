survarium::game_effect_time *__thiscall survarium::artefact_base::effect_calculator(
        survarium::artefact_base *this,
        survarium::game_effect_time *result,
        const survarium::game_effect_node *effect_node,
        unsigned int current_time_in_ms,
        unsigned int target_time_in_ms)
{
  survarium::game_effect_time *v5; // eax
  bool v6; // cl

  v5 = result;
  result->interval_id = 0;
  v6 = this->m_state != artefact_state_picked_active;
  result->interval_time = 0.0;
  result->effect_ended = v6;
  return v5;
}

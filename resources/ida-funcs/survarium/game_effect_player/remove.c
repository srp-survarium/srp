void __fastcall survarium::game_effect_player::remove(
        survarium::game_effect_player *this,
        const vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *effect,
        unsigned int time_in_ms)
{
  survarium::game_effect_node *m_first; // eax
  survarium::game_effect *m_object; // edx

  m_first = this->m_effects.m_first;
  if ( m_first )
  {
    m_object = effect->m_object;
    while ( m_first->effect.m_object != m_object )
    {
      m_first = m_first->next;
      if ( !m_first )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    m_first = 0;
  }
  m_first->state.initial_weight = m_first->state.current_weight;
  m_first->state.target_weight = 0.0;
  m_first->state.weight_transition_start_time_in_ms = time_in_ms;
  m_first->state.current_weight = 0.0;
  vostok::intrusive_list<survarium::game_effect_node,survarium::game_effect_node *,88,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::remove_if<survarium::game_effect_transited_to_zero_predicate>(
    (vostok::intrusive_list<survarium::game_effect_node,survarium::game_effect_node *,88,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
    (int)&this->m_effects);
}

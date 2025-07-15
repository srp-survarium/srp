void __thiscall survarium::victory_item_core::set_spotted(
        survarium::victory_item_core *this,
        const survarium::base_player *player)
{
  vostok::ai::fsm_state *m_current_state; // ecx
  void (__thiscall *finalize)(vostok::ai::fsm_state *); // ecx

  m_current_state = this->m_logic.m_current_state;
  this->m_deallocation_thread_id |= (player->m_profile->team != team_1) + 1;
  finalize = m_current_state[14].__vftable[1827].finalize;
  if ( finalize )
    (*(void (__thiscall **)(void (__thiscall *)(vostok::ai::fsm_state *), _DWORD, int, boost::function<void __cdecl(vostok::ai::fsm_state const *,vostok::ai::fsm_state const *)> *))(*(_DWORD *)finalize + 12))(
      finalize,
      player->id,
      4,
      &this[-1].m_logic.m_on_transition);
}

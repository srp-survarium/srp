vostok::memory::detail::call_destructor_predicate *__thiscall survarium::network_client::get_player(
        survarium::network_client *this,
        vostok::memory::detail::call_destructor_predicate *result,
        unsigned __int8 id)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  survarium::player *p_m_prev_in_global_list; // edi

  m_object = this->m_net_players.elems[id].player.m_object;
  if ( m_object )
    p_m_prev_in_global_list = (survarium::player *)&m_object[-2].m_prev_in_global_list;
  else
    p_m_prev_in_global_list = 0;
  *(_DWORD *)result = 0;
  if ( p_m_prev_in_global_list )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>(result);
    *(_DWORD *)result = p_m_prev_in_global_list;
    _InterlockedExchangeAdd(&p_m_prev_in_global_list->m_reference_count, 1u);
  }
  return result;
}

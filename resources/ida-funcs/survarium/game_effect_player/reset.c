void __userpurge survarium::game_effect_player::reset(
        survarium::game_effect_player *this@<ecx>,
        _DWORD *a2@<edi>,
        unsigned int current_time_in_ms)
{
  _DWORD *i; // eax

  for ( i = (_DWORD *)a2[11]; i; i = (_DWORD *)i[22] )
  {
    i[10] = 0;
    i[11] = 0;
  }
  vostok::intrusive_list<survarium::game_effect_node,survarium::game_effect_node *,88,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::remove_if<survarium::game_effect_transited_to_zero_predicate>(
    (vostok::intrusive_list<survarium::game_effect_node,survarium::game_effect_node *,88,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
    (int)(a2 + 2));
  *a2 = current_time_in_ms;
}

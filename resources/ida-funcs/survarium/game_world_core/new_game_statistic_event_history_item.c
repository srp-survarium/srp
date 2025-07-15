vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *__userpurge survarium::game_world_core::new_game_statistic_event_history_item@<eax>(
        survarium::game_world_core *this@<ecx>,
        int a2@<eax>,
        unsigned int time_in_ms)
{
  int v4; // eax
  survarium::history<survarium::game_statistic_event_history_item,vostok::memory::single_size_fixed_allocator<44,540,vostok::threading::single_threading_policy> > *v5; // ecx
  _DWORD *v6; // esi
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *result; // eax

  v4 = *(_DWORD *)(a2 + 25504);
  v5 = *(survarium::history<survarium::game_statistic_event_history_item,vostok::memory::single_size_fixed_allocator<44,540,vostok::threading::single_threading_policy> > **)(v4 + 36);
  v6 = (_DWORD *)(a2 + 25488);
  if ( (unsigned int)v5 >= *(_DWORD *)(v4 + 40) )
    survarium::history<survarium::game_statistic_event_history_item,vostok::memory::single_size_fixed_allocator<44,540,vostok::threading::single_threading_policy>>::pop_front(
      v5,
      v6);
  result = vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::allocate<44>(
             (vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy> *)v5,
             v6[4]);
  if ( result )
  {
    result->next = 0;
    *(_DWORD *)&result->data[4] = 0;
    *(_DWORD *)&result->data[8] = 0;
    *(_DWORD *)&result->data[28] = 0;
    *(_DWORD *)&result->data[32] = 0;
    result->data[40] = 0;
  }
  else
  {
    result = 0;
  }
  *(_DWORD *)&result->data[36] = time_in_ms;
  return result;
}

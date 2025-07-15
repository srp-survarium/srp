void __userpurge survarium::game_world_core::snap_inputs(
        survarium::game_world_core *this@<ecx>,
        int a2@<esi>,
        unsigned int current_time_in_ms)
{
  survarium::game_event_history_item *v3; // eax
  survarium::game_event_history_item *i; // ecx
  unsigned int v5; // edi
  unsigned int time_in_ms; // ebx
  survarium::game_world_core *v7; // ecx
  _DWORD *j; // eax
  bool v9; // [esp+0h] [ebp-8h]

  if ( *(_BYTE *)(a2 + 51212) != 20 && *(_DWORD *)(a2 + 4) && *(_DWORD *)(a2 + 51200) != -1 )
  {
    v3 = survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::greater_equal>(
           &this->m_game_events_history,
           a2,
           *(_DWORD *)(a2 + 51200));
    *(_DWORD *)(a2 + 51200) = -1;
    for ( i = v3; i; i = i->next )
    {
      v5 = *(_DWORD *)(a2 + 51184)
         + 50 * ((*(_DWORD *)(a2 + 51184) < i->time_in_ms ? i->time_in_ms - *(_DWORD *)(a2 + 51184) - 1 : 0) / 0x32 + 1);
      if ( current_time_in_ms < v5 )
      {
        *(_DWORD *)(a2 + 51200) = i->time_in_ms;
        return;
      }
      if ( i->time_in_ms != v5 )
      {
        time_in_ms = i->time_in_ms;
        survarium::game_world_core::erase_impl(
          (survarium::game_world_core *)i,
          (_DWORD *)a2,
          *(_BYTE *)(a2 + 51212),
          time_in_ms,
          0,
          v9);
        i = survarium::game_world_core::insert_impl(
              v7,
              (survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *)a2,
              (survarium::game_event_history_item::events_enum)*(unsigned __int8 *)(a2 + 51212),
              0,
              v5,
              1,
              0);
        for ( j = *(_DWORD **)(720 * *(unsigned __int8 *)(a2 + 51212) + *(_DWORD *)(a2 + 9860) + 4);
              j && j[5] < time_in_ms;
              j = (_DWORD *)*j )
        {
          ;
        }
        j[5] = v5;
        if ( !i )
          return;
      }
    }
  }
}

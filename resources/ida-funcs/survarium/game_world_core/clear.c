void __usercall survarium::game_world_core::clear(survarium::game_world_core *this@<ecx>, int a2@<eax>)
{
  _DWORD *i; // ebx
  int v4; // ecx
  int j; // ebx
  int v6; // edi
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *v7; // eax

  for ( i = (_DWORD *)(a2 + 9840);
        i[1];
        survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::pop_front(
          (survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *)this,
          i) )
  {
    ;
  }
  *(_DWORD *)(a2 + 51196) = -1;
  v4 = *(_DWORD *)(a2 + 51160);
  *(_DWORD *)(a2 + 51184) = 50;
  *(_DWORD *)(a2 + 51188) = 50;
  *(_DWORD *)(a2 + 51192) = 50;
  *(_DWORD *)(a2 + 51204) = 0;
  *(_DWORD *)(v4 + 172) = 50;
  for ( j = *(_DWORD *)(a2 + 51208); j; j &= j - 1 )
  {
    v6 = 4 * (unsigned __int8)vostok::bit_index(j & ~(j - 1));
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(v6 + *(_DWORD *)(a2 + 49320)) + 36))(
      *(_DWORD *)(v6 + *(_DWORD *)(a2 + 49320)),
      1);
    survarium::game_world_core::make_client_inactive(
      (survarium::game_world_core *)a2,
      *(survarium::base_player **)(*(_DWORD *)(a2 + 49320) + v6));
  }
  if ( !*(_DWORD *)(a2 + 24276) )
  {
    v7 = survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::new_item(
           (survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *)v4,
           a2 + 24272);
    *(_DWORD *)&v7->data[8] = 0;
    *(_DWORD *)&v7->data[12] = *(_DWORD *)(a2 + 51188);
    survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::insert(
      (survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *)(a2 + 24272),
      0,
      (survarium::player_input_history_item *)v7);
  }
}

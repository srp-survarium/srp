void __usercall survarium::game_world_core::new_game_state_history_item(
        survarium::game_world_core *this@<ecx>,
        int a2@<eax>)
{
  const survarium::fixed_history<survarium::players_mask_history_item,40> *v3; // eax
  int v4; // ebx
  survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *v5; // ecx
  int v6; // eax
  survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *v7; // ecx
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *v8; // eax
  int v9; // ecx
  unsigned int v10; // [esp+14h] [ebp-4h]

  if ( *(_BYTE *)(a2 + 51213)
    && (v3 = *(const survarium::fixed_history<survarium::players_mask_history_item,40> **)(a2 + 9844)) != 0 )
  {
    v4 = *(unsigned int *)((char *)&v3->m_items.m_size + (_DWORD)&loc_B9937 + 1);
    v10 = survarium::game_state_history_item::hash(
            (survarium::game_state_history_item *)(a2 + 24272),
            v3,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)(a2 + 24272));
    survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::new_item(
      v5,
      a2 + 9840);
    v6 = *(_DWORD *)(a2 + 25000);
    v7 = *(survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > **)(v6 + 36);
    if ( (unsigned int)v7 >= *(_DWORD *)(v6 + 40) )
      survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy>>::pop_front(
        v7,
        (_DWORD *)(a2 + 24984));
    v8 = vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::allocate<16>(
           (vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)v7,
           *(vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> **)(a2 + 25000));
    if ( v8 )
    {
      v8->next = 0;
      *(_DWORD *)&v8->data[4] = 0;
    }
    else
    {
      v8 = 0;
    }
    *(_DWORD *)&v8->data[8] = v4;
    *(_DWORD *)&v8->data[12] = v10;
    ++*(_DWORD *)(a2 + 24984);
    v9 = *(_DWORD *)(a2 + 24992);
    v8->next = 0;
    *(_DWORD *)&v8->data[4] = v9;
    if ( *(_DWORD *)(a2 + 24988) )
      **(_DWORD **)(a2 + 24992) = v8;
    else
      *(_DWORD *)(a2 + 24988) = v8;
    *(_DWORD *)(a2 + 24992) = v8;
  }
  else
  {
    survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::new_item(
      (survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *)this,
      a2 + 9840);
  }
}

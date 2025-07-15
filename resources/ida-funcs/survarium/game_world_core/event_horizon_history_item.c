survarium::game_state_history_item *__usercall survarium::game_world_core::event_horizon_history_item@<eax>(
        survarium::game_world_core *this@<ecx>,
        int a2@<eax>)
{
  survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *v3; // ecx

  if ( *(_BYTE *)(a2 + 51213) )
    return *(survarium::game_state_history_item **)(a2 + 9848);
  v3 = (survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *)(*(_DWORD *)(a2 + 51192) - *(_DWORD *)(a2 + 51180));
  return survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::less_equal>(
           v3,
           a2 + 9840,
           (unsigned int)v3);
}

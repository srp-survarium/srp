void __usercall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>>::owner_finalize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8> > *this@<ecx>,
        int a2@<edi>,
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8> > *a3@<esi>)
{
  int v3; // eax
  int v4; // ecx
  vostok::sound::sound_order **v5; // ebx
  vostok::sound::sound_order *v6; // esi
  vostok::sound::sound_order *m_next_for_orders; // eax
  vostok::sound::sound_order *v8; // esi
  vostok::sound::sound_order *v9; // esi
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8> > *i; // [esp-8h] [ebp-Ch]
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8> > *v11; // [esp-8h] [ebp-Ch]

  _InterlockedExchange((volatile __int32 *)(a2 + 8), GetCurrentThreadId());
  for ( i = a3;
        ;
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>>::delete_value(
          (vostok::sound::sound_order *)this,
          i) )
  {
    v3 = *(_DWORD *)(a2 + 64);
    if ( !*(_DWORD *)(v3 + 8) )
      break;
    v4 = *(_DWORD *)(v3 + 8);
    if ( v4 )
    {
      this = *(vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8> > **)(a2 + 64);
      *(_DWORD *)(a2 + 64) = v4;
    }
  }
  v5 = (vostok::sound::sound_order **)(a2 + 132);
  while ( 1 )
  {
    v6 = *v5;
    m_next_for_orders = (*v5)->m_next_for_orders;
    if ( !m_next_for_orders )
      break;
    *v5 = m_next_for_orders;
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>>::delete_value(
      v6,
      i);
  }
  v8 = *(vostok::sound::sound_order **)(a2 + 68);
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>>::delete_value(
    v8,
    i);
  v9 = *(vostok::sound::sound_order **)a2;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)a2 = 0;
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>>::delete_value(
    v9,
    v11);
}


void __usercall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::owner_finalize(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *this@<ecx>,
        int a2@<edi>,
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *a3@<esi>)
{
  int v3; // eax
  int v4; // ecx
  vostok::network::response **v5; // ebx
  vostok::network::response *v6; // esi
  vostok::network::response *next_for_responses; // eax
  vostok::network::response *v8; // esi
  vostok::network::response *v9; // esi
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *i; // [esp-8h] [ebp-Ch]
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *v11; // [esp-8h] [ebp-Ch]

  _InterlockedExchange((volatile __int32 *)(a2 + 8), GetCurrentThreadId());
  for ( i = a3;
        ;
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::delete_value(
          (vostok::network::response *)this,
          i) )
  {
    v3 = *(_DWORD *)(a2 + 64);
    if ( !*(_DWORD *)(v3 + 8) )
      break;
    v4 = *(_DWORD *)(v3 + 8);
    if ( v4 )
    {
      this = *(vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > **)(a2 + 64);
      *(_DWORD *)(a2 + 64) = v4;
    }
  }
  v5 = (vostok::network::response **)(a2 + 132);
  while ( 1 )
  {
    v6 = *v5;
    next_for_responses = (*v5)->next_for_responses;
    if ( !next_for_responses )
      break;
    *v5 = next_for_responses;
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::delete_value(
      v6,
      i);
  }
  v8 = *(vostok::network::response **)(a2 + 68);
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::delete_value(
    v8,
    i);
  v9 = *(vostok::network::response **)a2;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)a2 = 0;
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::delete_value(
    v9,
    v11);
}

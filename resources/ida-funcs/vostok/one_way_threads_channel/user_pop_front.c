vostok::network::response *__fastcall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::user_pop_front(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *this,
        int a2)
{
  __int32 v2; // ecx
  vostok::network::response *result; // eax

  v2 = *(_DWORD *)(a2 + 64);
  result = *(vostok::network::response **)(v2 + 8);
  if ( result )
  {
    *(_DWORD *)(a2 + 64) = result;
    *(_DWORD *)(v2 + 8) = 0;
    _InterlockedExchange((volatile __int32 *)(*(_DWORD *)(a2 + 68) + 8), v2);
    *(_DWORD *)(a2 + 68) = v2;
  }
  return result;
}

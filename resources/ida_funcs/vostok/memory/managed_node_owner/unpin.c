void __thiscall vostok::memory::managed_node_owner::unpin(
        vostok::memory::managed_node_owner *this,
        const unsigned __int8 *const_pinned_data)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)const_pinned_data - 2, 0xFFFFFFFF);
  if ( *((_DWORD *)const_pinned_data - 9) )
  {
    if ( !*((_DWORD *)const_pinned_data - 2) )
    {
      _InterlockedExchangeAdd((volatile signed __int32 *)(*((_DWORD *)const_pinned_data - 9) + 40), 1u);
      *((_DWORD *)const_pinned_data - 9) = 0;
    }
  }
}

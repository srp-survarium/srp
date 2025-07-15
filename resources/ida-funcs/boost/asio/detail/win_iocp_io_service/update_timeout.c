void __usercall boost::asio::detail::win_iocp_io_service::update_timeout(
        boost::asio::detail::win_iocp_io_service *this@<ecx>,
        int a2@<edi>)
{
  _DWORD *v2; // esi
  int v3; // eax
  LARGE_INTEGER DueTime; // [esp+8h] [ebp-8h] BYREF

  if ( *(_DWORD *)(a2 + 36) )
  {
    v2 = *(_DWORD **)(a2 + 72);
    v3 = 300000000;
    if ( v2 )
    {
      do
      {
        v3 = (*(int (__thiscall **)(_DWORD *, int))(*v2 + 12))(v2, v3);
        v2 = (_DWORD *)v2[1];
      }
      while ( v2 );
      if ( v3 < 300000000 )
      {
        DueTime.QuadPart = 10LL * -v3;
        SetWaitableTimer(*(HANDLE *)(a2 + 40), &DueTime, (LONG)&loc_493E0, 0, 0, 0);
      }
    }
  }
}

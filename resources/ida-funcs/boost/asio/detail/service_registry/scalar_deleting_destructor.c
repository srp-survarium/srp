_RTL_CRITICAL_SECTION *__usercall boost::asio::detail::service_registry::`scalar deleting destructor'@<eax>(
        boost::asio::detail::service_registry *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<esi>)
{
  _DWORD *i; // edi
  int LockCount; // ecx
  int v4; // edi

  for ( i = (_DWORD *)a2[1].LockCount; i; i = (_DWORD *)i[4] )
    (*(void (__thiscall **)(_DWORD *))(*i + 4))(i);
  if ( a2[1].LockCount )
  {
    do
    {
      LockCount = a2[1].LockCount;
      v4 = *(_DWORD *)(LockCount + 16);
      if ( LockCount )
        (**(void (__thiscall ***)(int, int))LockCount)(LockCount, 1);
      a2[1].LockCount = v4;
    }
    while ( v4 );
  }
  DeleteCriticalSection(a2);
  operator delete(a2);
  return a2;
}

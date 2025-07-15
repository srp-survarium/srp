void __userpurge vostok::input::receiver::keyboard::process(
        vostok::input::receiver::keyboard *this@<ecx>,
        int a2@<edi>,
        vostok::input::vector<vostok::input::handler *> *handlers)
{
  char *v3; // eax
  int v4; // ebx
  void **M_start; // esi
  void **M_finish; // ebp
  unsigned int v7; // ebx
  void **v8; // esi
  void **v9; // ebp
  unsigned int i; // [esp+18h] [ebp-8h]
  _DWORD *ia; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]

  i = 0;
  if ( *(_DWORD *)(a2 + 1028) )
  {
    v3 = (char *)(a2 + 1036);
    v12 = a2 + 1036;
    do
    {
      v4 = *((_DWORD *)v3 - 1);
      M_start = handlers->_M_impl._M_start;
      M_finish = handlers->_M_impl._M_finish;
      if ( *v3 >= 0 )
      {
        for ( ; M_start != M_finish; ++M_start )
        {
          if ( (**(unsigned __int8 (__thiscall ***)(void *, _DWORD, int, int))*M_start)(
                 *M_start,
                 *(_DWORD *)(a2 + 2320),
                 v4,
                 2) )
          {
            break;
          }
        }
      }
      else
      {
        for ( ; M_start != M_finish; ++M_start )
        {
          if ( (**(unsigned __int8 (__thiscall ***)(void *, _DWORD, int, int))*M_start)(
                 *M_start,
                 *(_DWORD *)(a2 + 2320),
                 v4,
                 1) )
          {
            break;
          }
        }
      }
      v3 = (char *)(v12 + 20);
      ++i;
      v12 += 20;
    }
    while ( i < *(_DWORD *)(a2 + 1028) );
  }
  v7 = 0;
  ia = (_DWORD *)(a2 + 4);
  do
  {
    if ( *ia )
    {
      v8 = handlers->_M_impl._M_start;
      v9 = handlers->_M_impl._M_finish;
      if ( handlers->_M_impl._M_start != v9 )
      {
        do
        {
          if ( (**(unsigned __int8 (__thiscall ***)(void *, _DWORD, unsigned int, int))*v8)(
                 *v8,
                 *(_DWORD *)(a2 + 2320),
                 v7,
                 3) )
          {
            break;
          }
          ++v8;
        }
        while ( v8 != v9 );
      }
    }
    ++ia;
    ++v7;
  }
  while ( v7 < 0x100 );
  *(_DWORD *)(a2 + 1028) = 0;
}

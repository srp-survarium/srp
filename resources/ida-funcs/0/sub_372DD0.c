char __cdecl sub_372DD0(_DWORD *a1)
{
  if ( !a1[99] && !sub_3728C0(a1) )
    return 0;
  if ( a1[99] == *(_DWORD *)(a1[105] + 16) + 208 )
  {
    *(_DWORD *)(*a1 + 20) = 100;
    *(_DWORD *)(*a1 + 24) = *(_DWORD *)(a1[105] + 16);
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 3);
    a1[99] = 0;
    *(_DWORD *)(a1[105] + 16) = ((unsigned __int8)*(_DWORD *)(a1[105] + 16) + 1) & 7;
    return 1;
  }
  else
  {
    if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *, _DWORD))(a1[6] + 20))(a1, *(_DWORD *)(a1[105] + 16)) )
      return 0;
    *(_DWORD *)(a1[105] + 16) = ((unsigned __int8)*(_DWORD *)(a1[105] + 16) + 1) & 7;
    return 1;
  }
}

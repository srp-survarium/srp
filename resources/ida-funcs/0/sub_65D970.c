int __cdecl sub_65D970(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  switch ( a2 )
  {
    case 15:
      return 33;
    case 20:
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, *(_DWORD *)(a5 + 68) + a3, a4, "IMPLIED") )
      {
        *a1 = sub_65D600;
        return 35;
      }
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, *(_DWORD *)(a5 + 68) + a3, a4, "REQUIRED") )
      {
        *a1 = sub_65D600;
        return 36;
      }
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, *(_DWORD *)(a5 + 68) + a3, a4, "FIXED") )
      {
        *a1 = sub_65DA70;
        return 33;
      }
      break;
    case 27:
      *a1 = sub_65D600;
      return 37;
  }
  return sub_65E280(a1, a2);
}

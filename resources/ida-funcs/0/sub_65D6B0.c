int __cdecl sub_65D6B0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int i; // [esp+4h] [ebp-4h]

  switch ( a2 )
  {
    case 15:
      return 33;
    case 18:
      for ( i = 0; i < 8; ++i )
      {
        if ( (*(int (__cdecl **)(int, int, int, char *))(a5 + 28))(a5, a3, a4, off_72FA28[i]) )
        {
          *a1 = sub_65D970;
          return i + 23;
        }
      }
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "NOTATION") )
      {
        *a1 = sub_65D870;
        return 33;
      }
      break;
    case 23:
      *a1 = sub_65D790;
      return 33;
  }
  return sub_65E280(a1, a2);
}

int __cdecl sub_542320(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int i; // [esp+4h] [ebp-4h]

  switch ( a2 )
  {
    case 15:
      return 33;
    case 18:
      for ( i = 0; i < 8; ++i )
      {
        if ( (*(int (__cdecl **)(int, int, int, char *))(a5 + 28))(a5, a3, a4, off_88BFB0[i]) )
        {
          *a1 = sub_5425E0;
          return i + 23;
        }
      }
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "NOTATION") )
      {
        *a1 = sub_5424E0;
        return 33;
      }
      break;
    case 23:
      *a1 = sub_542400;
      return 33;
  }
  return sub_542EE0(a1, a2);
}

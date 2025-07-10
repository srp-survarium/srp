int __cdecl sub_541B20(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  switch ( a2 )
  {
    case 15:
      return 11;
    case 18:
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "SYSTEM") )
      {
        *a1 = sub_541C30;
        return 11;
      }
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "PUBLIC") )
      {
        *a1 = sub_541BE0;
        return 11;
      }
      break;
    case 27:
      *a1 = sub_542E80;
      a1[2] = 11;
      return 12;
  }
  return sub_542EE0(a1, a2);
}

int __cdecl sub_65CEB0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  switch ( a2 )
  {
    case 15:
      return 11;
    case 18:
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "SYSTEM") )
      {
        *a1 = sub_65CFC0;
        return 11;
      }
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "PUBLIC") )
      {
        *a1 = sub_65CF70;
        return 11;
      }
      break;
    case 27:
      *a1 = sub_65E210;
      a1[2] = 11;
      return 12;
  }
  return sub_65E280(a1, a2);
}

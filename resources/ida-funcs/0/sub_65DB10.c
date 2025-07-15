int __cdecl sub_65DB10(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  switch ( a2 )
  {
    case 15:
      return 39;
    case 18:
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "EMPTY") )
      {
        *a1 = sub_65E210;
        a1[2] = 39;
        return 42;
      }
      if ( (*(int (__cdecl **)(int, int, int, void *))(a5 + 28))(a5, a3, a4, &unk_72F968) )
      {
        *a1 = sub_65E210;
        a1[2] = 39;
        return 41;
      }
      break;
    case 23:
      *a1 = sub_65DBF0;
      a1[1] = 1;
      return 44;
  }
  return sub_65E280(a1, a2);
}

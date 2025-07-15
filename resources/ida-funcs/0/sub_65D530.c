int __cdecl sub_65D530(_DWORD *a1, int a2)
{
  int (__cdecl *v3)(_DWORD *, int, int, int, int); // [esp+0h] [ebp-8h]

  switch ( a2 )
  {
    case 15:
      return 17;
    case 17:
      if ( a1[4] )
        v3 = sub_65CC00;
      else
        v3 = sub_65D0B0;
      *a1 = v3;
      return 20;
    case 27:
      *a1 = sub_65E210;
      a1[2] = 17;
      return 19;
    default:
      return sub_65E280(a1, a2);
  }
}

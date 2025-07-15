int __cdecl sub_5421A0(_DWORD *a1, int a2)
{
  int (__cdecl *v3)(_DWORD *, int, int, int, int); // [esp+0h] [ebp-8h]

  switch ( a2 )
  {
    case 15:
      return 17;
    case 17:
      if ( a1[4] )
        v3 = sub_541870;
      else
        v3 = sub_541D20;
      *a1 = v3;
      return 20;
    case 27:
      *a1 = sub_542E80;
      a1[2] = 17;
      return 19;
    default:
      return sub_542EE0(a1, a2);
  }
}

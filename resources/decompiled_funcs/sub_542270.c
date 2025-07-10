int __cdecl sub_542270(_DWORD *a1, int a2)
{
  int result; // eax
  int (__cdecl *v3)(_DWORD *, int, int, int, int); // [esp+0h] [ebp-8h]

  switch ( a2 )
  {
    case 15:
      result = 33;
      break;
    case 17:
      if ( a1[4] )
        v3 = sub_541870;
      else
        v3 = sub_541D20;
      *a1 = v3;
      result = 33;
      break;
    case 18:
    case 41:
      *a1 = sub_542320;
      result = 22;
      break;
    default:
      result = sub_542EE0(a1, a2);
      break;
  }
  return result;
}

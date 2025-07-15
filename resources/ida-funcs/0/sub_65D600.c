int __cdecl sub_65D600(_DWORD *a1, int a2)
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
        v3 = sub_65CC00;
      else
        v3 = sub_65D0B0;
      *a1 = v3;
      result = 33;
      break;
    case 18:
    case 41:
      *a1 = sub_65D6B0;
      result = 22;
      break;
    default:
      result = sub_65E280(a1, a2);
      break;
  }
  return result;
}

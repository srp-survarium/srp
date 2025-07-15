int __cdecl sub_542400(_DWORD *a1, int a2)
{
  int result; // eax

  switch ( a2 )
  {
    case 15:
      result = 33;
      break;
    case 18:
    case 19:
    case 41:
      *a1 = sub_542480;
      result = 31;
      break;
    default:
      result = sub_542EE0(a1, a2);
      break;
  }
  return result;
}

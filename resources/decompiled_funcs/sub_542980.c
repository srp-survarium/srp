int __cdecl sub_542980(_DWORD *a1, int a2)
{
  int result; // eax

  switch ( a2 )
  {
    case 15:
      result = 39;
      break;
    case 21:
      *a1 = sub_542A40;
      result = 39;
      break;
    case 24:
      *a1 = sub_542E80;
      a1[2] = 39;
      result = 45;
      break;
    case 36:
      *a1 = sub_542E80;
      a1[2] = 39;
      result = 46;
      break;
    default:
      result = sub_542EE0(a1, a2);
      break;
  }
  return result;
}

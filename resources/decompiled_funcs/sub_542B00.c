int __cdecl sub_542B00(_DWORD *a1, int a2)
{
  int result; // eax

  switch ( a2 )
  {
    case 15:
      result = 39;
      break;
    case 18:
    case 41:
      *a1 = sub_542BE0;
      result = 51;
      break;
    case 23:
      ++a1[1];
      result = 44;
      break;
    case 30:
      *a1 = sub_542BE0;
      result = 53;
      break;
    case 31:
      *a1 = sub_542BE0;
      result = 52;
      break;
    case 32:
      *a1 = sub_542BE0;
      result = 54;
      break;
    default:
      result = sub_542EE0(a1, a2);
      break;
  }
  return result;
}

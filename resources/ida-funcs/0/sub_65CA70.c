int __cdecl sub_65CA70(_DWORD *a1, int a2)
{
  int result; // eax

  switch ( a2 )
  {
    case 11:
      result = 55;
      break;
    case 13:
      result = 56;
      break;
    case 15:
      result = 0;
      break;
    case 29:
      *a1 = _ThemeHelper::IsAppThemedFail;
      result = 2;
      break;
    default:
      result = sub_65E280(a1, a2);
      break;
  }
  return result;
}

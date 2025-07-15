int __cdecl sub_5413C0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int result; // eax

  switch ( a2 )
  {
    case 11:
      *a1 = sub_5414D0;
      result = 55;
      break;
    case 12:
      *a1 = sub_5414D0;
      result = 1;
      break;
    case 13:
      *a1 = sub_5414D0;
      result = 56;
      break;
    case 14:
      result = 0;
      break;
    case 15:
      *a1 = sub_5414D0;
      result = 0;
      break;
    case 16:
      if ( !(*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(
              a5,
              a3 + 2 * *(_DWORD *)(a5 + 68),
              a4,
              "DOCTYPE") )
        goto LABEL_10;
      *a1 = sub_5415A0;
      result = 3;
      break;
    case 29:
      *a1 = _ThemeHelper::IsAppThemedFail;
      result = 2;
      break;
    default:
LABEL_10:
      result = sub_542EE0(a1, a2);
      break;
  }
  return result;
}

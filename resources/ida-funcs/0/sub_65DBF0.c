int __cdecl sub_65DBF0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int result; // eax

  switch ( a2 )
  {
    case 15:
      result = 39;
      break;
    case 18:
    case 41:
      *a1 = sub_65DF70;
      result = 51;
      break;
    case 20:
      if ( !(*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, *(_DWORD *)(a5 + 68) + a3, a4, "PCDATA") )
        goto LABEL_11;
      *a1 = sub_65DD10;
      result = 43;
      break;
    case 23:
      a1[1] = 2;
      *a1 = sub_65DE90;
      result = 44;
      break;
    case 30:
      *a1 = sub_65DF70;
      result = 53;
      break;
    case 31:
      *a1 = sub_65DF70;
      result = 52;
      break;
    case 32:
      *a1 = sub_65DF70;
      result = 54;
      break;
    default:
LABEL_11:
      result = sub_65E280(a1, a2);
      break;
  }
  return result;
}

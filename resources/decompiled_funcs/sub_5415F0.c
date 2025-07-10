int __cdecl sub_5415F0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int result; // eax

  switch ( a2 )
  {
    case 15:
      result = 3;
      break;
    case 17:
      *a1 = sub_5416E0;
      result = 8;
      break;
    case 18:
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "SYSTEM") )
      {
        *a1 = sub_5417C0;
        result = 3;
      }
      else
      {
        if ( !(*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3, a4, "PUBLIC") )
          goto LABEL_9;
        *a1 = sub_541770;
        result = 3;
      }
      break;
    case 25:
      *a1 = sub_541870;
      result = 7;
      break;
    default:
LABEL_9:
      result = sub_542EE0(a1, a2);
      break;
  }
  return result;
}

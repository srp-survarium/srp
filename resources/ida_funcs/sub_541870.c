int __cdecl sub_541870(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int result; // eax

  switch ( a2 )
  {
    case -4:
      result = 0;
      break;
    case 11:
      result = 55;
      break;
    case 13:
      result = 56;
      break;
    case 15:
      result = 0;
      break;
    case 16:
      if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(a5, a3 + 2 * *(_DWORD *)(a5 + 68), a4, "ENTITY") )
      {
        *a1 = sub_541A70;
        result = 11;
      }
      else if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(
                  a5,
                  a3 + 2 * *(_DWORD *)(a5 + 68),
                  a4,
                  "ATTLIST") )
      {
        *a1 = sub_542220;
        result = 33;
      }
      else if ( (*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(
                  a5,
                  a3 + 2 * *(_DWORD *)(a5 + 68),
                  a4,
                  "ELEMENT") )
      {
        *a1 = sub_542730;
        result = 39;
      }
      else
      {
        if ( !(*(int (__cdecl **)(int, int, int, const char *))(a5 + 28))(
                a5,
                a3 + 2 * *(_DWORD *)(a5 + 68),
                a4,
                "NOTATION") )
          goto LABEL_17;
        *a1 = sub_542010;
        result = 17;
      }
      break;
    case 26:
      *a1 = sub_541A20;
      result = 3;
      break;
    case 28:
      result = 60;
      break;
    default:
LABEL_17:
      result = sub_542EE0(a1, a2);
      break;
  }
  return result;
}

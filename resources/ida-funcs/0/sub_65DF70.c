int __cdecl sub_65DF70(_DWORD *a1, int a2)
{
  int result; // eax

  switch ( a2 )
  {
    case 15:
      result = 39;
      break;
    case 21:
      *a1 = sub_65DE90;
      result = 49;
      break;
    case 24:
      if ( !--a1[1] )
      {
        *a1 = sub_65E210;
        a1[2] = 39;
      }
      result = 45;
      break;
    case 35:
      if ( !--a1[1] )
      {
        *a1 = sub_65E210;
        a1[2] = 39;
      }
      result = 47;
      break;
    case 36:
      if ( !--a1[1] )
      {
        *a1 = sub_65E210;
        a1[2] = 39;
      }
      result = 46;
      break;
    case 37:
      if ( !--a1[1] )
      {
        *a1 = sub_65E210;
        a1[2] = 39;
      }
      result = 48;
      break;
    case 38:
      *a1 = sub_65DE90;
      result = 50;
      break;
    default:
      result = sub_65E280(a1, a2);
      break;
  }
  return result;
}

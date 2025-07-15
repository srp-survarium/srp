int __cdecl sub_534A50(char a1, unsigned __int8 a2)
{
  int result; // eax

  switch ( a1 )
  {
    case -40:
    case -39:
    case -38:
    case -37:
      result = 7;
      break;
    case -36:
    case -35:
    case -34:
    case -33:
      result = 8;
      break;
    case -1:
      if ( a2 < 0xFEu )
        goto LABEL_6;
      result = 0;
      break;
    default:
LABEL_6:
      result = 29;
      break;
  }
  return result;
}

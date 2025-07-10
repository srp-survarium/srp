int __cdecl null_ctrl(bio_st *b, int cmd)
{
  int result; // eax

  switch ( cmd )
  {
    case 1:
    case 2:
    case 4:
    case 9:
    case 11:
    case 12:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

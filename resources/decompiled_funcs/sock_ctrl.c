int __cdecl sock_ctrl(bio_st *b, int cmd, int num, int *ptr)
{
  int v4; // edx
  int result; // eax

  switch ( cmd )
  {
    case 8:
      result = b->shutdown;
      break;
    case 9:
      b->shutdown = num;
      goto $LN2_106;
    case 11:
    case 12:
$LN2_106:
      result = 1;
      break;
    case 104:
      sock_free(b);
      v4 = *ptr;
      b->shutdown = num;
      b->init = 1;
      b->num = v4;
      result = 1;
      break;
    case 105:
      if ( b->init )
      {
        if ( ptr )
          *ptr = b->num;
        result = b->num;
      }
      else
      {
        result = -1;
      }
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

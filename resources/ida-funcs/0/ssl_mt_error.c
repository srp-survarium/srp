int __cdecl ssl_mt_error(int n)
{
  int result; // eax

  switch ( n )
  {
    case 1:
      result = 203;
      break;
    case 2:
      result = 202;
      break;
    case 4:
      result = 201;
      break;
    case 6:
      result = 204;
      break;
    default:
      result = 253;
      break;
  }
  return result;
}

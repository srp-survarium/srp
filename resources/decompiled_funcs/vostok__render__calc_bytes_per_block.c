unsigned int __usercall vostok::render::calc_bytes_per_block@<eax>(DXGI_FORMAT format@<eax>)
{
  unsigned int result; // eax

  switch ( *((_BYTE *)&_LN2_112 + format) )
  {
    case 0:
      result = 4;
      break;
    case 1:
      result = 1;
      break;
    case 2:
      result = 8;
      break;
    case 3:
      result = 16;
      break;
  }
  return result;
}

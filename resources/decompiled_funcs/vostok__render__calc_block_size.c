unsigned int __usercall vostok::render::calc_block_size@<eax>(DXGI_FORMAT format@<eax>)
{
  unsigned int result; // eax

  switch ( *((_BYTE *)&loc_5605F7 + format + 5) )
  {
    case 0:
      result = 1;
      break;
    case 1:
      result = 4;
      break;
  }
  return result;
}

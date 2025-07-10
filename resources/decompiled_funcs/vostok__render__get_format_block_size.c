unsigned int __usercall vostok::render::get_format_block_size@<eax>(DXGI_FORMAT format@<eax>)
{
  unsigned int result; // eax

  switch ( byte_634422[format] )
  {
    case 0:
      result = 16;
      break;
    case 1:
      result = 8;
      break;
    case 2:
      result = 4;
      break;
    case 3:
      result = 2;
      break;
    case 4:
      result = 1;
      break;
  }
  return result;
}

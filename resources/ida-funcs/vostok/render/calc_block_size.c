unsigned int __usercall vostok::render::calc_block_size@<eax>(DXGI_FORMAT format@<eax>)
{
  if ( format != DXGI_FORMAT_R8G8B8A8_UNORM
    && format != DXGI_FORMAT_R8_UNORM
    && (format == DXGI_FORMAT_BC1_UNORM || format == DXGI_FORMAT_BC2_UNORM || format == DXGI_FORMAT_BC3_UNORM) )
  {
    return 4;
  }
  else
  {
    return 1;
  }
}

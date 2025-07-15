DXGI_FORMAT __usercall vostok::render::find_typeless_format@<eax>(DXGI_FORMAT format@<eax>)
{
  switch ( format )
  {
    case DXGI_FORMAT_R8G8B8A8_UNORM:
      return 27;
    case DXGI_FORMAT_BC1_UNORM:
      return 70;
    case DXGI_FORMAT_BC2_UNORM:
      return 73;
    case DXGI_FORMAT_BC3_UNORM:
      return 76;
    case DXGI_FORMAT_B8G8R8A8_UNORM:
      return 90;
  }
  return format;
}

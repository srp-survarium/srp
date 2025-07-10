DXGI_FORMAT __usercall vostok::render::get_typeless_format@<eax>(DXGI_FORMAT format@<eax>)
{
  switch ( format )
  {
    case DXGI_FORMAT_R8G8B8A8_UNORM:
      format = DXGI_FORMAT_R8G8B8A8_TYPELESS;
      break;
    case DXGI_FORMAT_BC1_UNORM:
      format = DXGI_FORMAT_BC1_TYPELESS;
      break;
    case DXGI_FORMAT_BC2_UNORM:
      format = DXGI_FORMAT_BC2_TYPELESS;
      break;
    case DXGI_FORMAT_BC3_UNORM:
      format = DXGI_FORMAT_BC3_TYPELESS;
      break;
    case DXGI_FORMAT_BC7_UNORM:
      format = DXGI_FORMAT_BC7_TYPELESS;
      break;
    default:
      return format;
  }
  return format;
}

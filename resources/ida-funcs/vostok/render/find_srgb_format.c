DXGI_FORMAT __usercall vostok::render::find_srgb_format@<eax>(DXGI_FORMAT format@<eax>)
{
  switch ( format )
  {
    case DXGI_FORMAT_R8G8B8A8_UNORM:
      format = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
      break;
    case DXGI_FORMAT_BC1_UNORM:
      format = DXGI_FORMAT_BC1_UNORM_SRGB;
      break;
    case DXGI_FORMAT_BC2_UNORM:
      format = DXGI_FORMAT_BC2_UNORM_SRGB;
      break;
    case DXGI_FORMAT_BC3_UNORM:
      format = DXGI_FORMAT_BC3_UNORM_SRGB;
      break;
    case DXGI_FORMAT_B8G8R8A8_UNORM:
      format = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
      break;
    default:
      return format;
  }
  return format;
}

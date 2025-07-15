bool __usercall vostok::render::is_equal_formats@<al>(DXGI_FORMAT left@<eax>, DXGI_FORMAT right@<ecx>)
{
  bool v2; // zf
  bool v3; // zf

  if ( left == right )
    return 1;
  switch ( left )
  {
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
      v2 = right == DXGI_FORMAT_R8G8B8A8_UNORM;
      break;
    case DXGI_FORMAT_BC1_UNORM_SRGB:
      v2 = right == DXGI_FORMAT_BC1_UNORM;
      break;
    case DXGI_FORMAT_BC2_UNORM_SRGB:
      v2 = right == DXGI_FORMAT_BC2_UNORM;
      break;
    case DXGI_FORMAT_BC3_UNORM_SRGB:
      v2 = right == DXGI_FORMAT_BC3_UNORM;
      break;
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
      v2 = right == DXGI_FORMAT_B8G8R8A8_UNORM;
      break;
    case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
      v2 = right == DXGI_FORMAT_B8G8R8X8_UNORM;
      break;
    case DXGI_FORMAT_BC7_UNORM_SRGB:
      v2 = right == DXGI_FORMAT_BC7_UNORM;
      break;
    default:
      goto LABEL_17;
  }
  if ( v2 )
    return 1;
LABEL_17:
  switch ( right )
  {
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
      v3 = left == DXGI_FORMAT_R8G8B8A8_UNORM;
      break;
    case DXGI_FORMAT_BC1_UNORM_SRGB:
      v3 = left == DXGI_FORMAT_BC1_UNORM;
      break;
    case DXGI_FORMAT_BC2_UNORM_SRGB:
      v3 = left == DXGI_FORMAT_BC2_UNORM;
      break;
    case DXGI_FORMAT_BC3_UNORM_SRGB:
      v3 = left == DXGI_FORMAT_BC3_UNORM;
      break;
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
      v3 = left == DXGI_FORMAT_B8G8R8A8_UNORM;
      break;
    case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
      v3 = left == DXGI_FORMAT_B8G8R8X8_UNORM;
      break;
    default:
      return right == DXGI_FORMAT_BC7_UNORM_SRGB && left == DXGI_FORMAT_BC7_UNORM;
  }
  return v3;
}

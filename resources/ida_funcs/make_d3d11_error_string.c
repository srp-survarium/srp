const char *__usercall make_d3d11_error_string@<eax>(HRESULT error_code@<eax>)
{
  const char *result; // eax

  if ( error_code <= -2005270527 )
  {
    if ( error_code == -2005270527 )
      return "DXGI_ERROR_INVALID_CALL";
    if ( error_code > -2147024809 )
    {
      if ( error_code == -2005532132 )
        return "D3DERR_WASSTILLDRAWING";
      if ( error_code == -2005530516 )
        return "D3DERR_INVALIDCALL";
    }
    else
    {
      switch ( error_code )
      {
        case -2147024809:
          return "E_INVALIDARG";
        case -2147467262:
          return "E_NOINTERFACE";
        case -2147467259:
          return "E_FAIL";
        case -2147024882:
          return "E_OUTOFMEMORY";
      }
    }
    return "UNKNOWN D3D11 ERROR";
  }
  if ( error_code > -2005139455 )
  {
    if ( error_code <= 142213121 )
    {
      if ( error_code == 142213121 )
        return "DXGI_STATUS_OCCLUDED";
      if ( error_code == -2005139454 )
        return "D3D11_ERROR_FILE_NOT_FOUND";
      return "UNKNOWN D3D11 ERROR";
    }
    switch ( error_code )
    {
      case 142213122:
        result = "DXGI_STATUS_CLIPPED";
        break;
      case 142213124:
        result = "DXGI_STATUS_NO_REDIRECTION";
        break;
      case 142213125:
        result = "DXGI_STATUS_NO_DESKTOP_ACCESS";
        break;
      case 142213126:
        result = "DXGI_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE";
        break;
      case 142213127:
        result = "DXGI_STATUS_MODE_CHANGED";
        break;
      case 142213128:
        result = "DXGI_STATUS_MODE_CHANGE_IN_PROGRESS";
        break;
      default:
        return "UNKNOWN D3D11 ERROR";
    }
  }
  else if ( error_code == -2005139455 )
  {
    return "D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS";
  }
  else
  {
    switch ( error_code )
    {
      case -2005270526:
        result = "DXGI_ERROR_NOT_FOUND";
        break;
      case -2005270525:
        result = "DXGI_ERROR_MORE_DATA";
        break;
      case -2005270524:
        result = "DXGI_ERROR_UNSUPPORTED";
        break;
      case -2005270523:
        result = "DXGI_ERROR_DEVICE_REMOVED";
        break;
      case -2005270522:
        result = "DXGI_ERROR_DEVICE_HUNG";
        break;
      case -2005270521:
        result = "DXGI_ERROR_DEVICE_RESET";
        break;
      case -2005270518:
        result = "DXGI_ERROR_WAS_STILL_DRAWING";
        break;
      case -2005270517:
        result = "DXGI_ERROR_FRAME_STATISTICS_DISJOINT";
        break;
      case -2005270516:
        result = "DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE";
        break;
      case -2005270496:
        result = "DXGI_ERROR_DRIVER_INTERNAL_ERROR";
        break;
      case -2005270495:
        result = "DXGI_ERROR_NONEXCLUSIVE";
        break;
      case -2005270494:
        result = "DXGI_ERROR_NOT_CURRENTLY_AVAILABLE";
        break;
      case -2005270493:
        result = "DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED";
        break;
      case -2005270492:
        result = "DXGI_ERROR_REMOTE_OUTOFMEMORY";
        break;
      default:
        return "UNKNOWN D3D11 ERROR";
    }
  }
  return result;
}

const char *__usercall make_d3d11_error_string@<eax>(
        HRESULT error_code@<edi>,
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *a2@<ecx>)
{
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // [esp-4h] [ebp-34h]
  char v5; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v6; // [esp+10h] [ebp-20h] BYREF

  v5 = 0;
  if ( error_code > -2005530498 )
  {
    if ( error_code > -2005270492 )
    {
      if ( error_code > 142213121 )
      {
        switch ( error_code )
        {
          case 142213122:
            return "DXGI_STATUS_CLIPPED";
          case 142213124:
            return "DXGI_STATUS_NO_REDIRECTION";
          case 142213125:
            return "DXGI_STATUS_NO_DESKTOP_ACCESS";
          case 142213126:
            return "DXGI_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE";
          case 142213127:
            return "DXGI_STATUS_MODE_CHANGED";
          case 142213128:
            return "DXGI_STATUS_MODE_CHANGE_IN_PROGRESS";
        }
      }
      else
      {
        switch ( error_code )
        {
          case 142213121:
            return "DXGI_STATUS_OCCLUDED";
          case -2005139455:
            return "D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS";
          case -2005139454:
            return "D3D11_ERROR_FILE_NOT_FOUND";
          case 141953135:
            return "D3DOK_NOAUTOGEN";
          case 141953141:
            return "S_NOT_RESIDENT";
          case 141953142:
            return "S_RESIDENT_IN_SHARED_MEMORY";
          case 141953143:
            return "S_PRESENT_MODE_CHANGED";
          case 141953144:
            return "S_PRESENT_OCCLUDED";
        }
      }
    }
    else
    {
      if ( error_code == -2005270492 )
        return "DXGI_ERROR_REMOTE_OUTOFMEMORY";
      if ( error_code > -2005270521 )
      {
        switch ( error_code )
        {
          case -2005270518:
            return "DXGI_ERROR_WAS_STILL_DRAWING";
          case -2005270517:
            return "DXGI_ERROR_FRAME_STATISTICS_DISJOINT";
          case -2005270516:
            return "DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE";
          case -2005270496:
            return "DXGI_ERROR_DRIVER_INTERNAL_ERROR";
          case -2005270495:
            return "DXGI_ERROR_NONEXCLUSIVE";
          case -2005270494:
            return "DXGI_ERROR_NOT_CURRENTLY_AVAILABLE";
          case -2005270493:
            return "DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED";
        }
      }
      else
      {
        switch ( error_code )
        {
          case -2005270521:
            return "DXGI_ERROR_DEVICE_RESET";
          case -2005530492:
            return "D3DERR_PRESENT_STATISTICS_DISJOINT";
          case -2005270527:
            return "DXGI_ERROR_INVALID_CALL";
          case -2005270526:
            return "DXGI_ERROR_NOT_FOUND";
          case -2005270525:
            return "DXGI_ERROR_MORE_DATA";
          case -2005270524:
            return "DXGI_ERROR_UNSUPPORTED";
          case -2005270523:
            return "DXGI_ERROR_DEVICE_REMOVED";
          case -2005270522:
            return "DXGI_ERROR_DEVICE_HUNG";
        }
      }
    }
  }
  else
  {
    if ( error_code == -2005530498 )
      return "D3DERR_UNSUPPORTEDCRYPTO";
    if ( error_code > -2005530590 )
    {
      if ( error_code > -2005530517 )
      {
        switch ( error_code )
        {
          case -2005530516:
            return "D3DERR_INVALIDCALL";
          case -2005530515:
            return "D3DERR_DRIVERINVALIDCALL";
          case -2005530512:
            return "D3DERR_DEVICEREMOVED";
          case -2005530508:
            return "D3DERR_DEVICEHUNG";
          case -2005530501:
            return "D3DERR_UNSUPPORTEDOVERLAY";
          case -2005530500:
            return "D3DERR_UNSUPPORTEDOVERLAYFORMAT";
          case -2005530499:
            return "D3DERR_CANNOTPROTECTCONTENT";
        }
      }
      else
      {
        switch ( error_code )
        {
          case -2005530517:
            return "D3DERR_INVALIDDEVICE";
          case -2005530586:
            return "D3DERR_CONFLICTINGTEXTUREPALETTE";
          case -2005530585:
            return "D3DERR_DRIVERINTERNALERROR";
          case -2005530522:
            return "D3DERR_NOTFOUND";
          case -2005530521:
            return "D3DERR_MOREDATA";
          case -2005530520:
            return "D3DERR_DEVICELOST";
          case -2005530519:
            return "D3DERR_DEVICENOTRESET";
          case -2005530518:
            return "D3DERR_NOTAVAILABLE";
        }
      }
    }
    else
    {
      if ( error_code == -2005530590 )
        return "D3DERR_UNSUPPORTEDTEXTUREFILTER";
      if ( error_code > -2005530599 )
      {
        switch ( error_code )
        {
          case -2005530598:
            return "D3DERR_UNSUPPORTEDCOLORARG";
          case -2005530597:
            return "D3DERR_UNSUPPORTEDALPHAOPERATION";
          case -2005530596:
            return "D3DERR_UNSUPPORTEDALPHAARG";
          case -2005530595:
            return "D3DERR_TOOMANYOPERATIONS";
          case -2005530594:
            return "D3DERR_CONFLICTINGTEXTUREFILTER";
          case -2005530593:
            return "D3DERR_UNSUPPORTEDFACTORVALUE";
          case -2005530591:
            return "D3DERR_CONFLICTINGRENDERSTATE";
        }
      }
      else
      {
        switch ( error_code )
        {
          case -2005530599:
            return "D3DERR_UNSUPPORTEDCOLOROPERATION";
          case -2147467262:
            return "E_NOINTERFACE";
          case -2147467259:
            return "E_FAIL";
          case -2147024882:
            return "E_OUTOFMEMORY";
          case -2147024809:
            return "E_INVALIDARG";
          case -2005532292:
            return "D3DERR_OUTOFVIDEOMEMORY";
          case -2005532132:
            return "D3DERR_WASSTILLDRAWING";
          case -2005530600:
            return "D3DERR_WRONGTEXTUREFORMAT";
        }
      }
    }
  }
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                               (const char *)2),
        a2 = v4,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      a2,
      &v6);
    v5 = 1;
    vostok::logging::append(
      &v6,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\macros_extensions.cpp",
      0x5Fu,
      "const char *__cdecl make_d3d11_error_string(long)",
      (char *)&initiator_raw.initiator_tree,
      error,
      "UNKNOWN D3D11 ERROR (%d)",
      error_code);
  }
  if ( (v5 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)a2,
      (int *)&v6);
  return "UNKNOWN D3D11 ERROR";
}

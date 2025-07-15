DXGI_FORMAT __usercall vostok::render::get_srgb_format@<eax>(DXGI_FORMAT format@<eax>, bool srgb@<cl>)
{
  if ( format > DXGI_FORMAT_BC3_UNORM )
  {
    if ( format == DXGI_FORMAT_B8G8R8A8_UNORM || format == DXGI_FORMAT_B8G8R8A8_TYPELESS )
    {
      return 4 * srgb + 87;
    }
    else if ( format > DXGI_FORMAT_BC6H_SF16 && format <= DXGI_FORMAT_BC7_UNORM )
    {
      return srgb + 98;
    }
  }
  else if ( format >= DXGI_FORMAT_BC3_TYPELESS )
  {
    return srgb + 77;
  }
  else if ( format >= DXGI_FORMAT_R8G8B8A8_TYPELESS )
  {
    if ( format <= DXGI_FORMAT_R8G8B8A8_UNORM )
    {
      return srgb + 28;
    }
    else if ( format > DXGI_FORMAT_G8R8_G8B8_UNORM )
    {
      if ( format <= DXGI_FORMAT_BC1_UNORM )
      {
        return srgb + 71;
      }
      else if ( format > DXGI_FORMAT_BC1_UNORM_SRGB && format <= DXGI_FORMAT_BC2_UNORM )
      {
        return srgb + 74;
      }
    }
  }
  return format;
}

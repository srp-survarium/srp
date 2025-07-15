unsigned int __usercall vostok::render::utils::calc_surface_size@<eax>(
        unsigned int width@<ecx>,
        unsigned int height@<edx>,
        DXGI_FORMAT format@<edi>,
        unsigned int *row_min_pitch)
{
  unsigned int v4; // ecx

  if ( (unsigned int)(format - 70) > 0xE )
    return (height * width * vostok::render::utils::s_format_4x4_pixel[format]) >> 4;
  v4 = vostok::render::utils::s_format_4x4_pixel[format] * ((width >> 2) - (width >> 2 == 0 ? (width >> 2) - 1 : 0));
  *row_min_pitch = v4;
  return v4 * ((height >> 2) - (height >> 2 == 0 ? (height >> 2) - 1 : 0));
}

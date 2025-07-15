unsigned int __usercall vostok::render::utils::calc_surface_size@<eax>(
        unsigned int width@<ecx>,
        unsigned int height@<eax>,
        DXGI_FORMAT format,
        unsigned int *row_min_pitch)
{
  unsigned int v5; // edi
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v9; // [esp-1Ch] [ebp-28h]

  if ( (unsigned int)(format - 70) > 0xE )
    return (height * width * vostok::render::utils::s_format_4x4_pixel[format]) >> 4;
  v5 = vostok::math::max(width >> 2, 1u);
  v6 = vostok::math::max(height >> 2, 1u);
  v9 = v5 * vostok::render::utils::s_format_4x4_pixel[format];
  *row_min_pitch = v9;
  v7 = vostok::math::max(v9, 0);
  *row_min_pitch = v7;
  return v6 * v7;
}

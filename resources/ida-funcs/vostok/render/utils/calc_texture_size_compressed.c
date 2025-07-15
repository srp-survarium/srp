int __cdecl vostok::render::utils::calc_texture_size_compressed(
        unsigned int width,
        unsigned int height,
        DXGI_FORMAT format,
        unsigned int mips,
        unsigned int row_min_pitch,
        unsigned int surf_min_pitch)
{
  unsigned int v6; // eax
  int v7; // edi

  v6 = ((height >> 2) - (height >> 2 == 0 ? (height >> 2) - 1 : 0))
     * (vostok::render::utils::s_format_4x4_pixel[format] * ((width >> 2) - (width >> 2 == 0 ? (width >> 2) - 1 : 0))
      - ((vostok::render::utils::s_format_4x4_pixel[format] * ((width >> 2) - (width >> 2 == 0 ? (width >> 2) - 1 : 0))
        - row_min_pitch)
       & ((vostok::render::utils::s_format_4x4_pixel[format] * ((width >> 2) - (width >> 2 == 0 ? (width >> 2) - 1 : 0))
         - (unsigned __int64)row_min_pitch) >> 32)));
  v7 = v6 - ((v6 - surf_min_pitch) & ((v6 - (unsigned __int64)surf_min_pitch) >> 32));
  if ( mips > 1 )
    v7 += vostok::render::utils::calc_texture_size_compressed(
            width >> 1,
            height >> 1,
            format,
            mips - 1,
            row_min_pitch,
            surf_min_pitch);
  return v7;
}

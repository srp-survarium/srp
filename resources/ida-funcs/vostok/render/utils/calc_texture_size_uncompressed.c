unsigned __int64 __usercall vostok::render::utils::calc_texture_size_uncompressed@<edx:eax>(
        unsigned int mips@<eax>,
        unsigned int width,
        unsigned int height,
        DXGI_FORMAT format,
        unsigned int array_count)
{
  return (unsigned __int64)((1.0 / pow(4.0, (double)mips) - 1.0)
                          * -1.3333334
                          * (double)vostok::render::utils::s_format_4x4_pixel[format]
                          * (double)width
                          * (double)height
                          * (double)array_count
                          * 0.0625);
}

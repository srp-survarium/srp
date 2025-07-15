unsigned int __cdecl vostok::render::calc_bytes_per_block(DXGI_FORMAT format)
{
  if ( format == DXGI_FORMAT_BC1_UNORM )
    return 8;
  else
    return 16;
}

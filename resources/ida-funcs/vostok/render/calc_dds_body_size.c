int __usercall vostok::render::calc_dds_body_size@<eax>(
        unsigned int num_mips@<eax>,
        unsigned int height,
        DXGI_FORMAT format)
{
  unsigned int v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // esi
  int v10; // [esp+8h] [ebp-4h]

  v10 = 0;
  v4 = num_mips;
  if ( num_mips )
  {
    v5 = vostok::render::calc_bytes_per_block(format);
    do
    {
      v7 = v6 - ((v6 - 4) & (((unsigned __int64)v6 - 4) >> 32));
      v8 = height - ((height - 4) & (((unsigned __int64)height - 4) >> 32));
      v10 += v5 * ((v8 * v7) >> 4);
      v6 = v7 >> 1;
      height = v8 >> 1;
      --v4;
    }
    while ( v4 );
  }
  return v10;
}

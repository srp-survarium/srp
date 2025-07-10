unsigned __int8 __cdecl Scaleform::Render::JPEG::JPEGRwSource::FillInputBuffer(jpeg_decompress_struct *cinfo)
{
  jpeg_source_mgr *src; // esi
  unsigned __int8 *v2; // edi
  unsigned int v3; // eax

  src = cinfo->src;
  v2 = (unsigned __int8 *)&src[1].bytes_in_buffer + 1;
  v3 = (*(int (__thiscall **)(const unsigned __int8 *, int, int))(*(_DWORD *)src[1].next_input_byte + 40))(
         src[1].next_input_byte,
         (int)&src[1].bytes_in_buffer + 1,
         2048);
  if ( !v3 )
  {
    if ( LOBYTE(src[1].bytes_in_buffer) )
      return 0;
    *v2 = -1;
    BYTE2(src[1].bytes_in_buffer) = -39;
    v3 = 2;
  }
  if ( LOBYTE(src[1].bytes_in_buffer)
    && v3 >= 4
    && *v2 == 0xFF
    && BYTE2(src[1].bytes_in_buffer) == 0xD9
    && HIBYTE(src[1].bytes_in_buffer) == 0xFF
    && LOBYTE(src[1].init_source) == 0xD8 )
  {
    BYTE2(src[1].bytes_in_buffer) = -40;
    LOBYTE(src[1].init_source) = -39;
  }
  src->next_input_byte = v2;
  src->bytes_in_buffer = v3;
  LOBYTE(src[1].bytes_in_buffer) = 0;
  return 1;
}

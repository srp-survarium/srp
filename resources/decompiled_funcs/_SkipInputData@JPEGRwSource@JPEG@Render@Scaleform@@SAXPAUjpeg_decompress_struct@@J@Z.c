void __cdecl Scaleform::Render::JPEG::JPEGRwSource::SkipInputData(jpeg_decompress_struct *cinfo, int numBytes)
{
  int v2; // esi
  jpeg_source_mgr *src; // edi

  v2 = numBytes;
  src = cinfo->src;
  if ( numBytes > 0 )
  {
    if ( numBytes > (signed int)src->bytes_in_buffer )
    {
      do
      {
        v2 -= src->bytes_in_buffer;
        Scaleform::Render::JPEG::JPEGRwSource::FillInputBuffer(cinfo);
      }
      while ( v2 > (signed int)src->bytes_in_buffer );
    }
    src->next_input_byte += v2;
    src->bytes_in_buffer -= v2;
  }
}

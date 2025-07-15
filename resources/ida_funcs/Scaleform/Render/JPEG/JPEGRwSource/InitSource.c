void __cdecl Scaleform::Render::JPEG::JPEGRwSource::InitSource(jpeg_decompress_struct *cinfo)
{
  LOBYTE(cinfo->src[1].bytes_in_buffer) = 1;
}

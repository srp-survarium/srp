int __cdecl Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JpegReadHeader(
        jpeg_decompress_struct *pcinfo,
        Scaleform::Render::JPEG::JpegErrorHandler *pjerr,
        char require_image)
{
  if ( _setjmp3((int *)pjerr->psetjmp_buffer, 0) )
  {
    jpeg_destroy_decompress(pcinfo);
    return 0;
  }
  else
  {
    jpeg_read_header(pcinfo, require_image);
    return 1;
  }
}

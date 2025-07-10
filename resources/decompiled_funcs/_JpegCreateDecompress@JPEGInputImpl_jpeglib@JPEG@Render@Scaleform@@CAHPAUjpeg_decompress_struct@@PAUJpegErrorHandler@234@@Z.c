int __cdecl Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JpegCreateDecompress(
        jpeg_decompress_struct *pcinfo,
        Scaleform::Render::JPEG::JpegErrorHandler *pjerr)
{
  if ( _setjmp3((int *)pjerr->psetjmp_buffer, 0) )
  {
    jpeg_destroy_decompress(pcinfo);
    return 0;
  }
  else
  {
    jpeg_CreateDecompress((unsigned __int8 *)pcinfo, 80, 448);
    return 1;
  }
}

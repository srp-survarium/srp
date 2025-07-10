jpeg_error_mgr *__cdecl Scaleform::Render::JPEG::SetupJpegErr(Scaleform::Render::JPEG::JpegErrorHandler *jerr)
{
  jpeg_error_mgr *result; // eax

  result = (jpeg_error_mgr *)jpeg_std_error(jerr);
  jerr->pub.error_exit = (void (__cdecl *)(jpeg_common_struct *))Scaleform::Render::JPEG::JpegErrorExit;
  return result;
}

void __cdecl __noreturn Scaleform::Render::JPEG::JpegErrorExit(jpeg_common_struct *cinfo)
{
  jpeg_error_mgr *err; // esi
  char buffer[200]; // [esp+4h] [ebp-C8h] BYREF

  err = cinfo->err;
  cinfo->err->format_message(cinfo, buffer);
  strcpy_s((char *)&err[1], 0xC8u, buffer);
  longjmp(*(int **)&err[2].msg_parm.s[44], 1);
}

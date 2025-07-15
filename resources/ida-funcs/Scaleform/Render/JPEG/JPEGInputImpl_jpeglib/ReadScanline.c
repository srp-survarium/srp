char __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::ReadScanline(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this,
        unsigned __int8 *prgbData)
{
  if ( (*((_BYTE *)this + 792) & 2) != 0 )
    return 0;
  if ( _setjmp3((int *)this->JErr.psetjmp_buffer, 0) )
  {
    jpeg_destroy_decompress(&this->CInfo);
    *((_BYTE *)this + 792) = *((_BYTE *)this + 792) & 0xFC | 2;
    return 0;
  }
  jpeg_read_scanlines(&this->CInfo, &prgbData, 1);
  return 1;
}

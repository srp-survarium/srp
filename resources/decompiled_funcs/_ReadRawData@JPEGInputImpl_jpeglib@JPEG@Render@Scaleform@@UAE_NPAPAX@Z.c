char __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::ReadRawData(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this,
        void **pprawData)
{
  if ( (*((_BYTE *)this + 792) & 2) != 0 )
    return 0;
  if ( _setjmp3((int *)this->JErr.psetjmp_buffer, 0) )
  {
    jpeg_destroy_decompress(&this->CInfo);
    *((_BYTE *)this + 792) = *((_BYTE *)this + 792) & 0xFC | 2;
    return 0;
  }
  *pprawData = (void *)jpeg_read_coefficients(&this->CInfo);
  return 1;
}

char __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::FinishImage(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this)
{
  char v1; // al

  v1 = *((_BYTE *)this + 792);
  if ( (v1 & 2) != 0 )
    return 0;
  if ( (v1 & 1) != 0 )
  {
    if ( _setjmp3((int *)this->JErr.psetjmp_buffer, 0) )
    {
      jpeg_destroy_decompress(&this->CInfo);
      *((_BYTE *)this + 792) = *((_BYTE *)this + 792) & 0xFC | 2;
      return 0;
    }
    jpeg_finish_decompress(&this->CInfo);
    *((_BYTE *)this + 792) &= ~1u;
  }
  return 1;
}

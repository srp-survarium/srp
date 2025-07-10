char __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::StartImage(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this)
{
  if ( (*((_BYTE *)this + 792) & 2) != 0 )
    return 0;
  if ( _setjmp3((int *)this->JErr.psetjmp_buffer, 0) )
  {
    jpeg_destroy_decompress(&this->CInfo);
    *((_BYTE *)this + 792) = *((_BYTE *)this + 792) & 0xFC | 2;
    return 0;
  }
  if ( this->CInfo.global_state != 202 )
    jpeg_read_header(&this->CInfo, 1);
  jpeg_start_decompress(&this->CInfo);
  *((_BYTE *)this + 792) |= 1u;
  return 1;
}

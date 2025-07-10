void __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JPEGInputImpl_jpeglib(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this,
        Scaleform::GFx::Resource *pin)
{
  Scaleform::Render::JPEG::JpegErrorHandler *p_JErr; // edi
  Scaleform::Render::JPEG::JPEGRwSource *v4; // eax
  jpeg_source_mgr *v5; // eax

  p_JErr = &this->JErr;
  this->__vftable = (Scaleform::Render::JPEG::JPEGInputImpl_jpeglib_vtbl *)&Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::`vftable';
  Scaleform::Render::JPEG::JpegErrorHandler::JpegErrorHandler(&this->JErr);
  *((_BYTE *)this + 792) &= 0xF8u;
  this->CInfo.err = Scaleform::Render::JPEG::SetupJpegErr(p_JErr);
  if ( Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JpegCreateDecompress(&this->CInfo, p_JErr) )
  {
    v4 = (Scaleform::Render::JPEG::JPEGRwSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    2084,
                                                    0);
    if ( v4 )
      Scaleform::Render::JPEG::JPEGRwSource::JPEGRwSource(v4, pin);
    else
      v5 = 0;
    this->CInfo.src = v5;
    if ( Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::StartImage(this) )
      *((_BYTE *)this + 792) |= 4u;
  }
}

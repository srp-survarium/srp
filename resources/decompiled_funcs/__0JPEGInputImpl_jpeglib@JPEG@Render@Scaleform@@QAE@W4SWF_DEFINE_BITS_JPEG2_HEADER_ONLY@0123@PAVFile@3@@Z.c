void __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JPEGInputImpl_jpeglib(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this,
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::SWF_DEFINE_BITS_JPEG2_HEADER_ONLY e,
        Scaleform::GFx::Resource *pin)
{
  Scaleform::Render::JPEG::JpegErrorHandler *p_JErr; // edi
  Scaleform::Render::JPEG::JPEGRwSource *v5; // eax
  jpeg_source_mgr *v6; // eax

  p_JErr = &this->JErr;
  this->__vftable = (Scaleform::Render::JPEG::JPEGInputImpl_jpeglib_vtbl *)&Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::`vftable';
  Scaleform::Render::JPEG::JpegErrorHandler::JpegErrorHandler(&this->JErr);
  *((_BYTE *)this + 792) &= 0xF8u;
  this->CInfo.err = Scaleform::Render::JPEG::SetupJpegErr(p_JErr);
  if ( Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JpegCreateDecompress(&this->CInfo, p_JErr) )
  {
    v5 = (Scaleform::Render::JPEG::JPEGRwSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    2084,
                                                    0);
    if ( v5 )
      Scaleform::Render::JPEG::JPEGRwSource::JPEGRwSource(v5, pin);
    else
      v6 = 0;
    this->CInfo.src = v6;
    if ( Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JpegReadHeader(&this->CInfo, p_JErr, 0) )
      *((_BYTE *)this + 792) |= 4u;
  }
}

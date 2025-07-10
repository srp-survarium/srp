void __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::~JPEGInputImpl_jpeglib(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this)
{
  jpeg_source_mgr *src; // edi
  Scaleform::RefCountVImpl *next_input_byte; // ecx

  this->__vftable = (Scaleform::Render::JPEG::JPEGInputImpl_jpeglib_vtbl *)&Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::`vftable';
  Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::FinishImage(this);
  src = this->CInfo.src;
  if ( src )
  {
    next_input_byte = (Scaleform::RefCountVImpl *)src[1].next_input_byte;
    if ( next_input_byte )
      Scaleform::RefCountImpl::Release(next_input_byte);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, src);
  }
  this->CInfo.src = 0;
  jpeg_destroy_decompress(&this->CInfo);
  Scaleform::Render::JPEG::JpegErrorHandler::~JpegErrorHandler(&this->JErr);
  this->__vftable = (Scaleform::Render::JPEG::JPEGInputImpl_jpeglib_vtbl *)&Scaleform::Render::JPEG::Input::`vftable';
}

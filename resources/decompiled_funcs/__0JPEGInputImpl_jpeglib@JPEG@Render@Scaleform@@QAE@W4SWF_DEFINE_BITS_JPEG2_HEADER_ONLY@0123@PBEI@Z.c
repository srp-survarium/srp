void __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JPEGInputImpl_jpeglib(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this,
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::SWF_DEFINE_BITS_JPEG2_HEADER_ONLY e,
        const unsigned __int8 *pbuf,
        unsigned int bufSize)
{
  Scaleform::Render::JPEG::JpegErrorHandler *p_JErr; // esi
  jpeg_source_mgr *v6; // eax
  jpeg_source_mgr *v7; // ebp
  jpeg_source_mgr smgr; // [esp+Ch] [ebp-1Ch] BYREF

  p_JErr = &this->JErr;
  this->__vftable = (Scaleform::Render::JPEG::JPEGInputImpl_jpeglib_vtbl *)&Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::`vftable';
  Scaleform::Render::JPEG::JpegErrorHandler::JpegErrorHandler(&this->JErr);
  *((_BYTE *)this + 792) &= 0xF8u;
  memset(&smgr.fill_input_buffer, 0, 12);
  smgr.bytes_in_buffer = bufSize;
  smgr.next_input_byte = pbuf;
  smgr.init_source = (void (__cdecl *)(jpeg_decompress_struct *))Scaleform::Render::JPEG::JPEGRwSource::TermSource;
  smgr.term_source = (void (__cdecl *)(jpeg_decompress_struct *))Scaleform::Render::JPEG::JPEGRwSource::TermSource;
  this->CInfo.err = Scaleform::Render::JPEG::SetupJpegErr(p_JErr);
  if ( Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JpegCreateDecompress(&this->CInfo, p_JErr) )
  {
    v6 = (jpeg_source_mgr *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 2084, 0);
    v7 = v6;
    if ( v6 )
    {
      v6[1].next_input_byte = 0;
      v6[1].next_input_byte = 0;
      LOBYTE(v6[1].bytes_in_buffer) = 1;
      qmemcpy(v6, &smgr, sizeof(jpeg_source_mgr));
    }
    else
    {
      v7 = 0;
    }
    this->CInfo.src = v7;
    if ( Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::JpegReadHeader(&this->CInfo, &this->JErr, 0) )
      *((_BYTE *)this + 792) |= 4u;
  }
}

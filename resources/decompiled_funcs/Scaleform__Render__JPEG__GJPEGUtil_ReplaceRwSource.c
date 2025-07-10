void __usercall Scaleform::Render::JPEG::GJPEGUtil_ReplaceRwSource(
        jpeg_decompress_struct *cinfo@<edi>,
        Scaleform::GFx::Resource *pinstream)
{
  jpeg_source_mgr *src; // esi
  Scaleform::RefCountVImpl *next_input_byte; // ecx
  Scaleform::Render::JPEG::JPEGRwSource *v4; // eax
  jpeg_source_mgr *v5; // eax

  src = cinfo->src;
  if ( src )
  {
    next_input_byte = (Scaleform::RefCountVImpl *)src[1].next_input_byte;
    if ( next_input_byte )
      Scaleform::RefCountImpl::Release(next_input_byte);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, src);
  }
  v4 = (Scaleform::Render::JPEG::JPEGRwSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  2084,
                                                  0);
  if ( v4 )
  {
    Scaleform::Render::JPEG::JPEGRwSource::JPEGRwSource(v4, pinstream);
    cinfo->src = v5;
  }
  else
  {
    cinfo->src = 0;
  }
}

Scaleform::Render::JPEG::WrapperImageSource *__thiscall Scaleform::Render::JPEG::FileReader::CreateWrapperImageSource(
        Scaleform::Render::JPEG::FileReader *this,
        Scaleform::Render::Image *memImage)
{
  Scaleform::Render::JPEG::WrapperImageSource *v2; // eax
  Scaleform::Render::JPEG::WrapperImageSource *v3; // esi

  v2 = (Scaleform::Render::JPEG::WrapperImageSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        16,
                                                        0);
  v3 = v2;
  if ( !v2 )
    return 0;
  v2->__vftable = (Scaleform::Render::JPEG::WrapperImageSource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  v2->RefCount = 1;
  v2->__vftable = (Scaleform::Render::JPEG::WrapperImageSource_vtbl *)&Scaleform::Render::WrapperImageSource::`vftable';
  if ( memImage )
    memImage->AddRef(memImage);
  v3->pDelegate.pObject = memImage;
  v3->__vftable = (Scaleform::Render::JPEG::WrapperImageSource_vtbl *)&Scaleform::Render::JPEG::WrapperImageSource::`vftable';
  v3->pOriginalInput = 0;
  if ( !Scaleform::Render::JPEG::WrapperImageSource::ReadHeader(v3) )
  {
    v3->Release(v3);
    return 0;
  }
  return v3;
}

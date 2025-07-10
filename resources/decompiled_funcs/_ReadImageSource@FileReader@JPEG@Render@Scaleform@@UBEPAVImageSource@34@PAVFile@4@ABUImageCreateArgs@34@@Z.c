Scaleform::Render::JPEG::ImageSource *__thiscall Scaleform::Render::JPEG::FileReader::ReadImageSource(
        Scaleform::Render::JPEG::FileReader *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::JPEG::ImageSource *v3; // esi

  if ( file && file->IsValid(file) )
  {
    v3 = (Scaleform::Render::JPEG::ImageSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   64,
                                                   0);
    if ( v3 )
    {
      Scaleform::Render::FileImageSource::FileImageSource(v3, file, args->Format, 0);
      v3->__vftable = (Scaleform::Render::JPEG::ImageSource_vtbl *)&Scaleform::Render::JPEG::ImageSource::`vftable';
      v3->pOriginalInput = 0;
      v3->pExtraData.pObject = 0;
      v3->WithHeaders = 0;
      if ( Scaleform::Render::JPEG::ImageSource::ReadHeader(v3) )
        return v3;
      v3->Release(v3);
    }
    return 0;
  }
  return 0;
}

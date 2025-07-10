Scaleform::Render::SIF::SIFFileImageSource *__thiscall Scaleform::Render::SIF::FileReader::ReadImageSource(
        Scaleform::Render::SIF::FileReader *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::SIF::SIFFileImageSource *v3; // eax
  Scaleform::Render::SIF::SIFFileImageSource *v4; // eax
  Scaleform::Render::SIF::SIFFileImageSource *v5; // esi

  if ( !file || !file->IsValid(file) )
    return 0;
  v3 = (Scaleform::Render::SIF::SIFFileImageSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       112,
                                                       0);
  if ( !v3 )
    return 0;
  Scaleform::Render::SIF::SIFFileImageSource::SIFFileImageSource(v3, file, args->Format);
  v5 = v4;
  if ( v4 && !Scaleform::Render::SIF::SIFFileImageSource::ReadHeader(v4) )
  {
    v5->Release(v5);
    return 0;
  }
  return v5;
}

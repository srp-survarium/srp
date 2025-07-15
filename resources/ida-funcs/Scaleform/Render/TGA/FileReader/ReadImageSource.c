Scaleform::Render::TGA::TGAFileImageSource *__thiscall Scaleform::Render::TGA::FileReader::ReadImageSource(
        Scaleform::Render::TGA::FileReader *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::TGA::TGAFileImageSource *v3; // eax
  Scaleform::Render::TGA::TGAFileImageSource *v4; // eax
  Scaleform::Render::TGA::TGAFileImageSource *v5; // esi
  Scaleform::MemoryHeap *pHeap; // eax

  if ( !file || !file->IsValid(file) )
    return 0;
  v3 = (Scaleform::Render::TGA::TGAFileImageSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       64,
                                                       0);
  if ( !v3 )
    return 0;
  Scaleform::Render::TGA::TGAFileImageSource::TGAFileImageSource(v3, file, args->Format);
  v5 = v4;
  if ( v4 )
  {
    pHeap = args->pHeap;
    if ( !pHeap )
      pHeap = Scaleform::Memory::pGlobalHeap;
    if ( !Scaleform::Render::TGA::TGAFileImageSource::ReadHeader(v5, pHeap) )
    {
      v5->Release(v5);
      return 0;
    }
  }
  return v5;
}

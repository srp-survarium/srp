Scaleform::Render::PNG::PNGFileImageSource *__thiscall Scaleform::Render::PNG::FileReader::ReadImageSource(
        Scaleform::Render::PNG::FileReader *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::PNG::PNGFileImageSource *v3; // eax
  Scaleform::Render::PNG::PNGFileImageSource *v4; // eax
  Scaleform::Render::PNG::PNGFileImageSource *v5; // esi

  if ( file && file->IsValid(file) )
  {
    v3 = (Scaleform::Render::PNG::PNGFileImageSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         56,
                                                         0);
    if ( v3 )
    {
      Scaleform::Render::PNG::PNGFileImageSource::PNGFileImageSource(v3, file, args->Format);
      v5 = v4;
      if ( !v4 || Scaleform::Render::PNG::PNGFileImageSource::ReadHeader(v4) )
        return v5;
      v5->Release(v5);
    }
    return 0;
  }
  return 0;
}

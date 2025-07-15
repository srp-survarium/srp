Scaleform::Render::JPEG::ImageSource *__thiscall Scaleform::Render::JPEG::FileReader::CreateImageSource(
        Scaleform::Render::JPEG::FileReader *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageCreateArgs *args,
        Scaleform::GFx::Resource *exd,
        unsigned __int64 len,
        bool withHeaders)
{
  Scaleform::Render::JPEG::ImageSource *v6; // eax
  Scaleform::Render::JPEG::ImageSource *v7; // eax
  Scaleform::Render::JPEG::ImageSource *v8; // esi

  if ( file && file->IsValid(file) )
  {
    v6 = (Scaleform::Render::JPEG::ImageSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   64,
                                                   0);
    if ( v6 )
    {
      Scaleform::Render::JPEG::ImageSource::ImageSource(v6, file, args->Format, exd, len, withHeaders);
      v8 = v7;
      if ( !v7 || Scaleform::Render::JPEG::ImageSource::ReadHeader(v7) )
        return v8;
      v8->Release(v8);
    }
    return 0;
  }
  return 0;
}

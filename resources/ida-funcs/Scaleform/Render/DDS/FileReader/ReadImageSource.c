Scaleform::Render::DDS::DDSFileImageSource *__thiscall Scaleform::Render::DDS::FileReader::ReadImageSource(
        Scaleform::Render::DDS::FileReader *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::DDS::DDSFileImageSource *v3; // eax
  Scaleform::Render::DDS::DDSFileImageSource *v4; // eax
  Scaleform::Render::DDS::DDSFileImageSource *v5; // esi

  if ( !file || !file->IsValid(file) )
    return 0;
  v3 = (Scaleform::Render::DDS::DDSFileImageSource *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       112,
                                                       0);
  if ( !v3 )
    return 0;
  Scaleform::Render::DDS::DDSFileImageSource::DDSFileImageSource(v3, (Scaleform::GFx::Resource *)file, args->Format);
  v5 = v4;
  if ( v4 && !Scaleform::Render::DDS::DDSFileImageSource::ReadHeader(v4) )
  {
    v5->Release(v5);
    return 0;
  }
  return v5;
}

Scaleform::Render::ImageFileReader *__thiscall Scaleform::Render::ImageFileHandlerRegistry::GetReader(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        Scaleform::Render::ImageFileFormat format)
{
  int v3; // esi
  Scaleform::Render::ImageFileHandler *v4; // ecx
  Scaleform::Render::ImageFileHandler *v5; // ecx

  v3 = 0;
  if ( !this->Handlers.Data.Size )
    return 0;
  while ( 1 )
  {
    v4 = this->Handlers.Data.Data[v3];
    if ( v4->IsReader(v4) )
    {
      v5 = this->Handlers.Data.Data[v3];
      if ( v5->GetFormat(v5) == format )
        break;
    }
    if ( ++v3 >= this->Handlers.Data.Size )
      return 0;
  }
  return (Scaleform::Render::ImageFileReader *)this->Handlers.Data.Data[v3];
}

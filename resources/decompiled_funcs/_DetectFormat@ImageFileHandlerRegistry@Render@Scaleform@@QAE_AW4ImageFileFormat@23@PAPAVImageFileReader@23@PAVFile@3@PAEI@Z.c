int __thiscall Scaleform::Render::ImageFileHandlerRegistry::DetectFormat(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        Scaleform::Render::ImageFileReader **preader,
        Scaleform::File *file,
        unsigned __int8 *header,
        unsigned int headerSize)
{
  int v6; // edi
  unsigned int v7; // ebp
  Scaleform::Render::ImageFileHandler *v8; // ecx
  Scaleform::Render::ImageFileReader *v9; // esi

  if ( !preader )
    preader = (Scaleform::Render::ImageFileReader **)&preader;
  v6 = 0;
  if ( this->Handlers.Data.Size )
  {
    v7 = headerSize;
    while ( 1 )
    {
      v8 = this->Handlers.Data.Data[v6];
      if ( v8->IsReader(v8) )
      {
        v9 = (Scaleform::Render::ImageFileReader *)this->Handlers.Data.Data[v6];
        if ( v9->MatchFormat(v9, file, header, v7) )
          break;
      }
      if ( ++v6 >= this->Handlers.Data.Size )
        goto LABEL_8;
    }
    *preader = v9;
    return v9->GetFormat(v9);
  }
  else
  {
LABEL_8:
    *preader = 0;
    return 1;
  }
}

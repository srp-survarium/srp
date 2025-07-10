Scaleform::Render::Image *__thiscall Scaleform::Render::ImageFileHandlerRegistry::ReadImage(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageCreateArgs *args)
{
  int v4; // edi
  Scaleform::Render::ImageFileHandler *v5; // ecx
  Scaleform::Render::ImageFileHandler *v6; // esi

  v4 = 0;
  if ( !this->Handlers.Data.Size )
    return 0;
  while ( 1 )
  {
    v5 = this->Handlers.Data.Data[v4];
    if ( v5->IsReader(v5) )
    {
      v6 = this->Handlers.Data.Data[v4];
      if ( ((unsigned __int8 (__thiscall *)(Scaleform::Render::ImageFileHandler *, Scaleform::File *, _DWORD, _DWORD))v6->__vftable[1].~Scaleform::Render::ImageFileHandler)(
             v6,
             file,
             0,
             0) )
      {
        break;
      }
    }
    if ( ++v4 >= this->Handlers.Data.Size )
      return 0;
  }
  return (Scaleform::Render::Image *)((int (__thiscall *)(Scaleform::Render::ImageFileHandler *, Scaleform::File *, const Scaleform::Render::ImageCreateArgs *))v6->__vftable[1].IsReader)(
                                       v6,
                                       file,
                                       args);
}

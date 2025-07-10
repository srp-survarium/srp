Scaleform::Render::Image *__thiscall Scaleform::Render::ImageFileReader::Read(
        Scaleform::Render::ImageFileReader *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageSource *(__thiscall *ReadImageSource)(Scaleform::Render::ImageFileReader *, Scaleform::File *, const Scaleform::Render::ImageCreateArgs *); // eax
  int v4; // esi
  int v5; // edi
  _DWORD v7[5]; // [esp+8h] [ebp-14h] BYREF

  ReadImageSource = this->ReadImageSource;
  memset(v7, 0, sizeof(v7));
  v4 = (int)ReadImageSource(this, file, (const Scaleform::Render::ImageCreateArgs *)v7);
  if ( !v4 )
    return 0;
  v5 = (*(int (__thiscall **)(int, const Scaleform::Render::ImageCreateArgs *))(*(_DWORD *)v4 + 48))(v4, args);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4);
  return (Scaleform::Render::Image *)v5;
}

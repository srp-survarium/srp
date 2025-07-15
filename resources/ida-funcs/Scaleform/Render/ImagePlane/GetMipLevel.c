void __thiscall Scaleform::Render::ImagePlane::GetMipLevel(
        Scaleform::Render::ImagePlane *this,
        Scaleform::Render::ImageFormat format,
        unsigned int level,
        Scaleform::Render::ImagePlane *p,
        unsigned int plane)
{
  unsigned __int8 *pData; // eax
  unsigned int Height; // esi
  unsigned int Width; // edi
  unsigned int FormatPitch; // eax
  int v10; // ecx
  int v11; // [esp+4h] [ebp-10h]
  Scaleform::Render::ImagePlane *v12; // [esp+8h] [ebp-Ch]
  Scaleform::Render::Size<unsigned long> v13; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 *v14; // [esp+20h] [ebp+Ch]

  p->Width = this->Width;
  p->Height = this->Height;
  p->Pitch = this->Pitch;
  p->DataSize = this->DataSize;
  pData = this->pData;
  v12 = this;
  p->pData = pData;
  v11 = 0;
  if ( level )
  {
    Height = p->Height;
    Width = p->Width;
    v14 = pData;
    do
    {
      v13.Width = Width;
      v13.Height = Height;
      v14 += Scaleform::Render::ImageData::GetMipLevelSize(format, &v13, plane);
      Width >>= 1;
      if ( !Width )
        Width = 1;
      Height >>= 1;
      if ( !Height )
        Height = 1;
      FormatPitch = Scaleform::Render::ImageData::GetFormatPitch(format, Width, plane);
      v11 += v10;
      --level;
    }
    while ( level );
    this = v12;
    p->Width = Width;
    p->Height = Height;
    p->Pitch = FormatPitch;
    p->pData = v14;
  }
  p->DataSize = this->DataSize - v11;
}

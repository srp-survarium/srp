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
  unsigned int totalLevelSize; // [esp+4h] [ebp-10h]
  Scaleform::Render::ImagePlane *v12; // [esp+8h] [ebp-Ch]
  Scaleform::Render::Size<unsigned long> sz; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 *pa; // [esp+20h] [ebp+Ch]

  p->Width = this->Width;
  p->Height = this->Height;
  p->Pitch = this->Pitch;
  p->DataSize = this->DataSize;
  pData = this->pData;
  v12 = this;
  p->pData = pData;
  totalLevelSize = 0;
  if ( level )
  {
    Height = p->Height;
    Width = p->Width;
    pa = pData;
    do
    {
      sz.Width = Width;
      sz.Height = Height;
      pa += Scaleform::Render::ImageData::GetMipLevelSize(format, &sz, plane);
      Width >>= 1;
      if ( !Width )
        Width = 1;
      Height >>= 1;
      if ( !Height )
        Height = 1;
      FormatPitch = Scaleform::Render::ImageData::GetFormatPitch(format, Width, plane);
      totalLevelSize += v10;
      --level;
    }
    while ( level );
    this = v12;
    p->Width = Width;
    p->Height = Height;
    p->Pitch = FormatPitch;
    p->pData = pa;
  }
  p->DataSize = this->DataSize - totalLevelSize;
}

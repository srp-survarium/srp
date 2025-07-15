void __thiscall Scaleform::Render::DICommand_Noise::ExecuteSW(
        Scaleform::Render::DICommand_Noise *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  int v6; // eax
  Scaleform::Render::ImageData *v7; // ebx
  unsigned int v8; // edi
  Scaleform::Render::ImagePlane *pPlanes; // eax
  int v10; // ebp
  bool v11; // zf
  double UnitFloat; // st7
  float r; // [esp+28h] [ebp-44h]
  _DWORD v14[6]; // [esp+2Ch] [ebp-40h] BYREF
  Scaleform::Alg::Random::Generator v15; // [esp+44h] [ebp-28h] BYREF
  float v16; // [esp+70h] [ebp+4h]

  Scaleform::Alg::Random::Generator::Generator(&v15);
  Scaleform::Alg::Random::Generator::SeedRandom(&v15, this->RandomSeed);
  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = (int)v5->GetImageSwizzler(v5);
  v7 = dest;
  v8 = 0;
  v14[0] = v6;
  v14[1] = 0;
  v14[2] = dest;
  memset(&v14[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v6 + 4))(v6, v14);
  pPlanes = v7->pPlanes;
  v10 = 0;
  if ( pPlanes->Width )
  {
    while ( 1 )
    {
      if ( pPlanes->Height )
      {
        do
        {
          (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v14[0] + 8))(v14[0], v14, v8);
          v11 = !this->GrayScale;
          dest = 0;
          if ( v11 )
          {
            if ( (this->ChannelMask & 1) != 0 )
              BYTE2(dest) = (int)(Scaleform::Alg::Random::Generator::GetUnitFloat(&v15) * 255.0);
            if ( (this->ChannelMask & 2) != 0 )
              BYTE1(dest) = (int)(Scaleform::Alg::Random::Generator::GetUnitFloat(&v15) * 255.0);
            if ( (this->ChannelMask & 4) != 0 )
              LOBYTE(dest) = (int)(Scaleform::Alg::Random::Generator::GetUnitFloat(&v15) * 255.0);
            if ( (this->ChannelMask & 8) != 0 )
              HIBYTE(dest) = (int)(Scaleform::Alg::Random::Generator::GetUnitFloat(&v15) * 255.0);
            else
              HIBYTE(dest) = -1;
          }
          else
          {
            r = Scaleform::Alg::Random::Generator::GetUnitFloat(&v15);
            if ( (this->ChannelMask & 8) != 0 )
              UnitFloat = Scaleform::Alg::Random::Generator::GetUnitFloat(&v15);
            else
              UnitFloat = 1.0;
            v16 = UnitFloat;
            Scaleform::Render::Color::SetRGBFloat((Scaleform::Render::Color *)&dest, r, r, r);
            HIBYTE(dest) = (int)(v16 * 255.0);
          }
          if ( !this->pImage.pObject->Transparent )
            HIBYTE(dest) = -1;
          (*(void (__thiscall **)(_DWORD, _DWORD *, int, Scaleform::Render::ImageData *))(*(_DWORD *)v14[0] + 12))(
            v14[0],
            v14,
            v10,
            dest);
          ++v8;
        }
        while ( v8 < v7->pPlanes->Height );
      }
      pPlanes = v7->pPlanes;
      if ( ++v10 >= pPlanes->Width )
        break;
      v8 = 0;
    }
  }
}

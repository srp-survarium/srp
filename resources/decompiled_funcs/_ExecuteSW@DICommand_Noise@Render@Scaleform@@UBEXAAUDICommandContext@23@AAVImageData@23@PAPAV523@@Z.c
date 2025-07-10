void __thiscall Scaleform::Render::DICommand_Noise::ExecuteSW(
        Scaleform::Render::DICommand_Noise *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImageSwizzler *v6; // eax
  Scaleform::Render::ImageData *v7; // ebx
  unsigned int v8; // edi
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int v10; // ebp
  bool v11; // zf
  double UnitFloat; // st7
  float val; // [esp+28h] [ebp-44h]
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+2Ch] [ebp-40h] BYREF
  Scaleform::Alg::Random::Generator rng; // [esp+44h] [ebp-28h] BYREF
  float contexta; // [esp+70h] [ebp+4h]

  Scaleform::Alg::Random::Generator::Generator(&rng);
  Scaleform::Alg::Random::Generator::SeedRandom(&rng, this->RandomSeed);
  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = v5->GetImageSwizzler(v5);
  v7 = dest;
  v8 = 0;
  dstSwiz.Swizzler = v6;
  dstSwiz.pCurrentScanline = 0;
  dstSwiz.pImage = dest;
  memset(&dstSwiz.CachedBlockY, 0, 12);
  v6->Initialize(v6, &dstSwiz);
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
          dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, v8);
          v11 = !this->GrayScale;
          dest = 0;
          if ( v11 )
          {
            if ( (this->ChannelMask & 1) != 0 )
              BYTE2(dest) = (int)(Scaleform::Alg::Random::Generator::GetUnitFloat(&rng) * 255.0);
            if ( (this->ChannelMask & 2) != 0 )
              BYTE1(dest) = (int)(Scaleform::Alg::Random::Generator::GetUnitFloat(&rng) * 255.0);
            if ( (this->ChannelMask & 4) != 0 )
              LOBYTE(dest) = (int)(Scaleform::Alg::Random::Generator::GetUnitFloat(&rng) * 255.0);
            if ( (this->ChannelMask & 8) != 0 )
              HIBYTE(dest) = (int)(Scaleform::Alg::Random::Generator::GetUnitFloat(&rng) * 255.0);
            else
              HIBYTE(dest) = -1;
          }
          else
          {
            val = Scaleform::Alg::Random::Generator::GetUnitFloat(&rng);
            if ( (this->ChannelMask & 8) != 0 )
              UnitFloat = Scaleform::Alg::Random::Generator::GetUnitFloat(&rng);
            else
              UnitFloat = 1.0;
            contexta = UnitFloat;
            Scaleform::Render::Color::SetRGBFloat((Scaleform::Render::Color *)&dest, val, val, val);
            HIBYTE(dest) = (int)(contexta * 255.0);
          }
          if ( !this->pImage.pObject->Transparent )
            HIBYTE(dest) = -1;
          dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, v10, (unsigned int)dest);
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

void __thiscall Scaleform::Render::DICommand_PerlinNoise::ExecuteSW(
        Scaleform::Render::DICommand_PerlinNoise *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  bool v5; // zf
  unsigned int v6; // eax
  Scaleform::Render::TextureManager *v7; // eax
  Scaleform::Render::ImageData *v8; // edi
  unsigned int v9; // ebx
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int v11; // ebp
  bool Transparent; // al
  unsigned int v13; // ecx
  double v14; // st7
  double v15; // st6
  double v16; // st5
  unsigned int NumOctaves; // ebp
  unsigned int *v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // edi
  float *v22; // ebx
  double v23; // st7
  double v24; // st5
  Scaleform::Render::ImagePlane *v25; // eax
  Scaleform::Render::ImagePlane *v26; // ecx
  float noise; // [esp+28h] [ebp-64h]
  float noisea; // [esp+28h] [ebp-64h]
  Scaleform::Render::Color color; // [esp+2Ch] [ebp-60h] BYREF
  float yPos; // [esp+30h] [ebp-5Ch]
  float xPos; // [esp+34h] [ebp-58h]
  float freqX; // [esp+38h] [ebp-54h]
  float freqY; // [esp+3Ch] [ebp-50h]
  float fmax; // [esp+40h] [ebp-4Ch]
  unsigned int channel; // [esp+44h] [ebp-48h]
  unsigned int y; // [esp+48h] [ebp-44h]
  unsigned int channelMask; // [esp+4Ch] [ebp-40h]
  float amplitude; // [esp+50h] [ebp-3Ch]
  unsigned int x; // [esp+54h] [ebp-38h]
  float v40; // [esp+58h] [ebp-34h]
  float v41; // [esp+5Ch] [ebp-30h]
  unsigned int channelCount; // [esp+60h] [ebp-2Ch]
  Scaleform::Render::PerlinGenerator generator; // [esp+64h] [ebp-28h] BYREF
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+74h] [ebp-18h] BYREF
  bool contexta; // [esp+90h] [ebp+4h]

  v5 = !this->GrayScale;
  v6 = this->ChannelMask;
  channelMask = v6;
  if ( !v5 )
    channelMask = v6 & 0xFFFFFFF8 | 1;
  v7 = context->pHAL->GetTextureManager(context->pHAL);
  v8 = dest;
  v9 = 0;
  dstSwiz.Swizzler = v7->GetImageSwizzler(v7);
  dstSwiz.pCurrentScanline = 0;
  dstSwiz.pImage = dest;
  memset(&dstSwiz.CachedBlockY, 0, 12);
  dstSwiz.Swizzler->Initialize(dstSwiz.Swizzler, &dstSwiz);
  pPlanes = dest->pPlanes;
  v11 = 0;
  y = 0;
  if ( pPlanes->Height )
  {
    while ( 1 )
    {
      dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, v11);
      v5 = v8->pPlanes->Width == 0;
      x = 0;
      if ( !v5 )
      {
        do
        {
          Transparent = this->pImage.pObject->Transparent;
          v13 = 0;
          color = (Scaleform::Render::Color)-16777216;
          contexta = Transparent;
          channel = 0;
          channelCount = Transparent + 3;
          v14 = 2.0;
          v15 = 255.0;
          do
          {
            if ( ((1 << v13) & channelMask) != 0 )
            {
              v16 = v14 / this->FrequencyX;
              NumOctaves = this->NumOctaves;
              v18 = (unsigned int *)&Scaleform::Render::PerlinGenerator::NoisePrimeFactors[16
                                                                                         * ((-3
                                                                                           * ((_BYTE)v13
                                                                                            + LOBYTE(this->RandomSeed)))
                                                                                          & 7)];
              generator.PrimeSet.primes[0] = *v18;
              generator.PrimeSet.primes[1] = v18[1];
              v19 = v18[2];
              v20 = v18[3];
              v21 = 0;
              generator.PrimeSet.primes[2] = v19;
              generator.PrimeSet.primes[3] = v20;
              freqX = v16;
              freqY = v14 / this->FrequencyY;
              amplitude = 1.0;
              noise = 0.0;
              fmax = 0.0;
              if ( NumOctaves )
              {
                v40 = (float)v9;
                v41 = (float)y;
                v22 = &this->Offsets[1];
                do
                {
                  xPos = v40 * freqX;
                  yPos = v41 * freqY;
                  if ( v21 < this->OffsetCount )
                  {
                    xPos = *(v22 - 1) + xPos;
                    yPos = *v22 + yPos;
                  }
                  v23 = Scaleform::Render::PerlinGenerator::InterpolatedNoise(&generator, xPos, yPos);
                  ++v21;
                  v22 += 2;
                  noise = (v23 + 1.0) * 0.5 * amplitude + noise;
                  freqX = freqX * 2.0;
                  freqY = freqY * 2.0;
                  fmax = fmax + amplitude;
                  v14 = 2.0;
                  amplitude = 0.5 * amplitude;
                }
                while ( v21 < NumOctaves );
                v15 = 255.0;
                v13 = channel;
                v9 = x;
              }
              noisea = noise / fmax;
              if ( !this->GrayScale || v13 == 3 )
              {
                v24 = noisea * v15;
                if ( v13 == 1 )
                {
                  LODWORD(v41) = (int)v24;
                  color.Channels.Green = (int)v24;
                }
                else if ( v13 == 2 )
                {
                  LODWORD(v41) = (int)v24;
                  color.Channels.Blue = (int)v24;
                }
                else
                {
                  LODWORD(v41) = (int)v24;
                  if ( v13 == 3 )
                    color.Channels.Alpha = (int)v24;
                  else
                    color.Channels.Red = (int)v24;
                }
              }
              else
              {
                Scaleform::Render::Color::SetRGBFloat(&color, noisea, noisea, noisea);
                v14 = 2.0;
                v13 = channel;
                v15 = 255.0;
              }
            }
            channel = ++v13;
          }
          while ( v13 < channelCount );
          v8 = dest;
          if ( !contexta )
            color.Channels.Alpha = -1;
          dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, v9, (unsigned int)color);
          v25 = dest->pPlanes;
          x = ++v9;
        }
        while ( v9 < v25->Width );
        v11 = y;
      }
      v26 = v8->pPlanes;
      y = ++v11;
      if ( v11 >= v26->Height )
        break;
      v9 = 0;
    }
  }
}

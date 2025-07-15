void __thiscall Scaleform::Render::DICommand_PerlinNoise::ExecuteSW(
        Scaleform::Render::DICommand_PerlinNoise *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  bool v5; // zf
  unsigned int ChannelMask; // eax
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
  float v27; // [esp+28h] [ebp-64h]
  float r; // [esp+28h] [ebp-64h]
  Scaleform::Render::Color v29; // [esp+2Ch] [ebp-60h] BYREF
  float v30; // [esp+30h] [ebp-5Ch]
  float v31; // [esp+34h] [ebp-58h]
  float v32; // [esp+38h] [ebp-54h]
  float v33; // [esp+3Ch] [ebp-50h]
  float v34; // [esp+40h] [ebp-4Ch]
  unsigned int v35; // [esp+44h] [ebp-48h]
  unsigned int v36; // [esp+48h] [ebp-44h]
  unsigned int v37; // [esp+4Ch] [ebp-40h]
  float v38; // [esp+50h] [ebp-3Ch]
  unsigned int v39; // [esp+54h] [ebp-38h]
  float v40; // [esp+58h] [ebp-34h]
  float v41; // [esp+5Ch] [ebp-30h]
  unsigned int v42; // [esp+60h] [ebp-2Ch]
  Scaleform::Render::PerlinGenerator v43; // [esp+64h] [ebp-28h] BYREF
  _DWORD v44[6]; // [esp+74h] [ebp-18h] BYREF
  bool v45; // [esp+90h] [ebp+4h]

  v5 = !this->GrayScale;
  ChannelMask = this->ChannelMask;
  v37 = ChannelMask;
  if ( !v5 )
    v37 = ChannelMask & 0xFFFFFFF8 | 1;
  v7 = context->pHAL->GetTextureManager(context->pHAL);
  v8 = dest;
  v9 = 0;
  v44[0] = v7->GetImageSwizzler(v7);
  v44[1] = 0;
  v44[2] = dest;
  memset(&v44[3], 0, 12);
  (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v44[0] + 4))(v44[0], v44);
  pPlanes = dest->pPlanes;
  v11 = 0;
  v36 = 0;
  if ( pPlanes->Height )
  {
    while ( 1 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v44[0] + 8))(v44[0], v44, v11);
      v5 = v8->pPlanes->Width == 0;
      v39 = 0;
      if ( !v5 )
      {
        do
        {
          Transparent = this->pImage.pObject->Transparent;
          v13 = 0;
          v29 = (Scaleform::Render::Color)-16777216;
          v45 = Transparent;
          v35 = 0;
          v42 = Transparent + 3;
          v14 = 2.0;
          v15 = 255.0;
          do
          {
            if ( ((1 << v13) & v37) != 0 )
            {
              v16 = v14 / this->FrequencyX;
              NumOctaves = this->NumOctaves;
              v18 = (unsigned int *)&Scaleform::Render::PerlinGenerator::NoisePrimeFactors[16
                                                                                         * ((-3
                                                                                           * ((_BYTE)v13
                                                                                            + LOBYTE(this->RandomSeed)))
                                                                                          & 7)];
              v43.PrimeSet.primes[0] = *v18;
              v43.PrimeSet.primes[1] = v18[1];
              v19 = v18[2];
              v20 = v18[3];
              v21 = 0;
              v43.PrimeSet.primes[2] = v19;
              v43.PrimeSet.primes[3] = v20;
              v32 = v16;
              v33 = v14 / this->FrequencyY;
              v38 = 1.0;
              v27 = 0.0;
              v34 = 0.0;
              if ( NumOctaves )
              {
                v40 = (float)v9;
                v41 = (float)v36;
                v22 = &this->Offsets[1];
                do
                {
                  v31 = v40 * v32;
                  v30 = v41 * v33;
                  if ( v21 < this->OffsetCount )
                  {
                    v31 = *(v22 - 1) + v31;
                    v30 = *v22 + v30;
                  }
                  v23 = Scaleform::Render::PerlinGenerator::InterpolatedNoise(&v43, v31, v30);
                  ++v21;
                  v22 += 2;
                  v27 = (v23 + 1.0) * 0.5 * v38 + v27;
                  v32 = v32 * 2.0;
                  v33 = v33 * 2.0;
                  v34 = v34 + v38;
                  v14 = 2.0;
                  v38 = 0.5 * v38;
                }
                while ( v21 < NumOctaves );
                v15 = 255.0;
                v13 = v35;
                v9 = v39;
              }
              r = v27 / v34;
              if ( !this->GrayScale || v13 == 3 )
              {
                v24 = r * v15;
                if ( v13 == 1 )
                {
                  LODWORD(v41) = (int)v24;
                  v29.Channels.Green = (int)v24;
                }
                else if ( v13 == 2 )
                {
                  LODWORD(v41) = (int)v24;
                  v29.Channels.Blue = (int)v24;
                }
                else
                {
                  LODWORD(v41) = (int)v24;
                  if ( v13 == 3 )
                    v29.Channels.Alpha = (int)v24;
                  else
                    v29.Channels.Red = (int)v24;
                }
              }
              else
              {
                Scaleform::Render::Color::SetRGBFloat(&v29, r, r, r);
                v14 = 2.0;
                v13 = v35;
                v15 = 255.0;
              }
            }
            v35 = ++v13;
          }
          while ( v13 < v42 );
          v8 = dest;
          if ( !v45 )
            v29.Channels.Alpha = -1;
          (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int, Scaleform::Render::Color))(*(_DWORD *)v44[0] + 12))(
            v44[0],
            v44,
            v9,
            v29);
          v25 = dest->pPlanes;
          v39 = ++v9;
        }
        while ( v9 < v25->Width );
        v11 = v36;
      }
      v26 = v8->pPlanes;
      v36 = ++v11;
      if ( v11 >= v26->Height )
        break;
      v9 = 0;
    }
  }
}

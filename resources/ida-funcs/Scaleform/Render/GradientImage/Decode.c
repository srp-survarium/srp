char __thiscall Scaleform::Render::GradientImage::Decode(
        Scaleform::Render::GradientImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned __int8 *pData; // edi
  Scaleform::Render::GradientData *pObject; // esi
  const Scaleform::Render::GradientData *pMorphTo; // eax
  double v9; // st7
  unsigned int Height; // eax
  unsigned int v11; // esi
  unsigned int Width; // edx
  unsigned int v13; // edx
  double v14; // st7
  double v15; // st6
  unsigned int v16; // edi
  bool v17; // zf
  unsigned int v18; // esi
  int v19; // eax
  int v20; // eax
  unsigned __int8 last[4]; // [esp+4Ch] [ebp-868h]
  float lastb; // [esp+4Ch] [ebp-868h]
  float lastc; // [esp+4Ch] [ebp-868h]
  float lastd; // [esp+4Ch] [ebp-868h]
  float laste; // [esp+4Ch] [ebp-868h]
  float lastf; // [esp+4Ch] [ebp-868h]
  float lastg; // [esp+4Ch] [ebp-868h]
  float lasth; // [esp+4Ch] [ebp-868h]
  float lasta; // [esp+4Ch] [ebp-868h]
  unsigned int v30; // [esp+50h] [ebp-864h]
  float v31; // [esp+50h] [ebp-864h]
  float v32; // [esp+50h] [ebp-864h]
  float v33; // [esp+50h] [ebp-864h]
  const Scaleform::Render::GradientData *toLast; // [esp+54h] [ebp-860h]
  float toLastc; // [esp+54h] [ebp-860h]
  unsigned int toLasta; // [esp+54h] [ebp-860h]
  unsigned int toLastb; // [esp+54h] [ebp-860h]
  float center; // [esp+58h] [ebp-85Ch]
  unsigned __int8 *dst; // [esp+5Ch] [ebp-858h]
  unsigned __int8 *dsta; // [esp+5Ch] [ebp-858h]
  float radius; // [esp+60h] [ebp-854h]
  Scaleform::Render::GradientData *data; // [esp+64h] [ebp-850h]
  Scaleform::Render::GradientData tmpData; // [esp+68h] [ebp-84Ch] BYREF
  Scaleform::Render::ImagePlane dplane; // [esp+80h] [ebp-834h] BYREF
  double v45; // [esp+94h] [ebp-820h]
  Scaleform::Render::FocalRadialGradient gr; // [esp+A0h] [ebp-814h] BYREF
  unsigned __int8 src[1024]; // [esp+B4h] [ebp-800h] BYREF
  Scaleform::Render::GradientRamp ramp; // [esp+4B4h] [ebp-400h] BYREF

  memset(&dplane, 0, sizeof(dplane));
  Scaleform::Render::ImageData::GetPlane(pdest, 0, &dplane);
  pData = dplane.pData;
  dst = dplane.pData;
  if ( this->pData.pObject )
  {
    pObject = this->pData.pObject;
    pMorphTo = pObject->pMorphTo;
    tmpData.FocalRatio = 0.0;
    toLast = pMorphTo;
    tmpData.RecordCount = 0;
    data = pObject;
    tmpData.RefCount = 1;
    tmpData.__vftable = (Scaleform::Render::GradientData_vtbl *)&Scaleform::Render::GradientData::`vftable';
    tmpData.LinearRGB = 0;
    tmpData.Type = 0;
    tmpData.pRecords = 0;
    tmpData.pMorphTo = 0;
    Scaleform::Render::GradientData::SetRecordCount(&tmpData, 0, 0);
    if ( toLast )
    {
      Scaleform::Render::GradientData::SetLerp(&tmpData, pObject, toLast, this->MorphRatio);
      data = &tmpData;
      pObject = &tmpData;
    }
    if ( pObject->LinearRGB )
      v9 = 2.1700001;
    else
      v9 = 1.0;
    toLastc = v9;
    Scaleform::Render::GradientRamp::GradientRamp(&ramp, pObject->pRecords, pObject->RecordCount, toLastc);
    Height = this->Size.Height;
    toLasta = dplane.Pitch * (Height - 1);
    if ( pObject->Type )
    {
      Width = this->Size.Width;
      *(_DWORD *)last = *(_DWORD *)&ramp.Ramp[1020];
      if ( Width )
      {
        memset32(src, *(int *)&ramp.Ramp[1020], Width);
        pData = dst;
      }
      copyScanline(pData, src, 4 * Width, 0, arg);
      copyScanline(&pData[toLasta], src, 4 * this->Size.Width, 0, arg);
      v30 = this->Size.Width;
      v13 = v30 - 1;
      v14 = 0.5;
      *(_DWORD *)src = *(_DWORD *)last;
      center = (double)v30 * 0.5;
      *((_DWORD *)&gr.Multiplier + v30) = *(_DWORD *)last;
      v15 = center;
      toLastb = v30 - 1;
      radius = center - 1.0;
      if ( pObject->Type == 2 )
      {
        lastb = pObject->FocalRatio * radius;
        Scaleform::Render::FocalRadialGradient::Init(&gr, radius, lastb, 0.0);
        v14 = 0.5;
        v15 = center;
      }
      dsta = &pData[dplane.Pitch];
      v16 = 1;
      if ( v13 > 1 )
      {
        while ( 1 )
        {
          v17 = pObject->Type == 1;
          v18 = 1;
          if ( v17 )
          {
            lastc = (double)v16 - v15 + v14;
            v45 = lastc * lastc;
            while ( 1 )
            {
              lastd = v14 + (double)v18 - v15;
              laste = lastd * lastd + v45;
              lastf = sqrt(laste);
              lastg = lastf * 256.0 / radius + 0.5;
              lasth = floor(lastg);
              v19 = (int)lasth;
              if ( v19 > 255 )
                v19 = 255;
              *(_DWORD *)&src[4 * v18++] = *(_DWORD *)&ramp.Ramp[4 * v19];
              if ( v18 >= toLastb )
                break;
              v14 = 0.5;
              v15 = center;
            }
          }
          else
          {
            lasta = (double)v16 - v15 + v14;
            while ( 1 )
            {
              v31 = v14 + (double)v18 - v15;
              v32 = Scaleform::Render::FocalRadialGradient::Calculate(&gr, v31, lasta) * 256.0 / radius + 0.5;
              v33 = floor(v32);
              v20 = (int)v33;
              if ( v20 > 255 )
                v20 = 255;
              *(_DWORD *)&src[4 * v18++] = *(_DWORD *)&ramp.Ramp[4 * v20];
              if ( v18 >= toLastb )
                break;
              v14 = 0.5;
              v15 = center;
            }
          }
          copyScanline(dsta, src, 4 * this->Size.Width, 0, arg);
          ++v16;
          dsta += dplane.Pitch;
          if ( v16 >= toLastb )
            break;
          v14 = 0.5;
          pObject = data;
          v15 = center;
        }
      }
    }
    else
    {
      v11 = 0;
      if ( Height )
      {
        do
        {
          copyScanline(pData, ramp.Ramp, 4 * this->Size.Width, 0, arg);
          ++v11;
        }
        while ( v11 < this->Size.Height );
      }
    }
    tmpData.__vftable = (Scaleform::Render::GradientData_vtbl *)&Scaleform::Render::GradientData::`vftable';
    if ( tmpData.pRecords )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, tmpData.pRecords);
    Scaleform::RefCountImplCore::~RefCountImplCore(&tmpData);
    return 1;
  }
  else
  {
    src[3] = 0;
    src[2] = 0;
    src[1] = 0;
    src[0] = 0;
    copyScanline(dplane.pData, src, 4u, 0, arg);
    return 1;
  }
}

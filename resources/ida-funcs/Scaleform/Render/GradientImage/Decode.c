char __thiscall Scaleform::Render::GradientImage::Decode(
        Scaleform::Render::GradientImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned __int8 *pData; // edi
  Scaleform::Render::GradientData *pObject; // esi
  Scaleform::Render::GradientData *pMorphTo; // eax
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
  int v21; // [esp+4Ch] [ebp-868h]
  float fx; // [esp+4Ch] [ebp-868h]
  float v23; // [esp+4Ch] [ebp-868h]
  float v24; // [esp+4Ch] [ebp-868h]
  float v25; // [esp+4Ch] [ebp-868h]
  float v26; // [esp+4Ch] [ebp-868h]
  float v27; // [esp+4Ch] [ebp-868h]
  float v28; // [esp+4Ch] [ebp-868h]
  float v29; // [esp+4Ch] [ebp-868h]
  unsigned int v30; // [esp+50h] [ebp-864h]
  float v31; // [esp+50h] [ebp-864h]
  float v32; // [esp+50h] [ebp-864h]
  float v33; // [esp+50h] [ebp-864h]
  Scaleform::Render::GradientData *data2; // [esp+54h] [ebp-860h]
  float data2c; // [esp+54h] [ebp-860h]
  Scaleform::Render::GradientData *data2a; // [esp+54h] [ebp-860h]
  Scaleform::Render::GradientData *data2b; // [esp+54h] [ebp-860h]
  float v38; // [esp+58h] [ebp-85Ch]
  unsigned __int8 *v39; // [esp+5Ch] [ebp-858h]
  unsigned __int8 *v40; // [esp+5Ch] [ebp-858h]
  float r; // [esp+60h] [ebp-854h]
  Scaleform::Render::GradientData *v42; // [esp+64h] [ebp-850h]
  Scaleform::Render::GradientData v43; // [esp+68h] [ebp-84Ch] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+80h] [ebp-834h] BYREF
  double v45; // [esp+94h] [ebp-820h]
  Scaleform::Render::FocalRadialGradient v46; // [esp+A0h] [ebp-814h] BYREF
  _DWORD v47[256]; // [esp+B4h] [ebp-800h] BYREF
  Scaleform::Render::GradientRamp v48; // [esp+4B4h] [ebp-400h] BYREF

  memset(&pplane, 0, sizeof(pplane));
  Scaleform::Render::ImageData::GetPlane(pdest, 0, &pplane);
  pData = pplane.pData;
  v39 = pplane.pData;
  if ( this->pData.pObject )
  {
    pObject = this->pData.pObject;
    pMorphTo = (Scaleform::Render::GradientData *)pObject->pMorphTo;
    v43.FocalRatio = 0.0;
    data2 = pMorphTo;
    v43.RecordCount = 0;
    v42 = pObject;
    v43.RefCount = 1;
    v43.__vftable = (Scaleform::Render::GradientData_vtbl *)&Scaleform::Render::GradientData::`vftable';
    v43.LinearRGB = 0;
    v43.Type = 0;
    v43.pRecords = 0;
    v43.pMorphTo = 0;
    Scaleform::Render::GradientData::SetRecordCount(&v43, 0, 0);
    if ( data2 )
    {
      Scaleform::Render::GradientData::SetLerp(&v43, pObject, data2, this->MorphRatio);
      v42 = &v43;
      pObject = &v43;
    }
    if ( pObject->LinearRGB )
      v9 = 2.1700001;
    else
      v9 = 1.0;
    data2c = v9;
    Scaleform::Render::GradientRamp::GradientRamp(&v48, pObject->pRecords, pObject->RecordCount, data2c);
    Height = this->Size.Height;
    data2a = (Scaleform::Render::GradientData *)(pplane.Pitch * (Height - 1));
    if ( pObject->Type )
    {
      Width = this->Size.Width;
      v21 = *(_DWORD *)&v48.Ramp[1020];
      if ( Width )
      {
        memset32(v47, *(int *)&v48.Ramp[1020], Width);
        pData = v39;
      }
      copyScanline(pData, (const unsigned __int8 *)v47, 4 * Width, 0, arg);
      copyScanline(
        (unsigned __int8 *)data2a + (_DWORD)pData,
        (const unsigned __int8 *)v47,
        4 * this->Size.Width,
        0,
        arg);
      v30 = this->Size.Width;
      v13 = v30 - 1;
      v14 = 0.5;
      v47[0] = v21;
      v38 = (double)v30 * 0.5;
      *((_DWORD *)&v46.Multiplier + v30) = v21;
      v15 = v38;
      data2b = (Scaleform::Render::GradientData *)(v30 - 1);
      r = v38 - 1.0;
      if ( pObject->Type == 2 )
      {
        fx = pObject->FocalRatio * r;
        Scaleform::Render::FocalRadialGradient::Init(&v46, r, fx, 0.0);
        v14 = 0.5;
        v15 = v38;
      }
      v40 = &pData[pplane.Pitch];
      v16 = 1;
      if ( v13 > 1 )
      {
        while ( 1 )
        {
          v17 = pObject->Type == 1;
          v18 = 1;
          if ( v17 )
          {
            v23 = (double)v16 - v15 + v14;
            v45 = v23 * v23;
            while ( 1 )
            {
              v24 = v14 + (double)v18 - v15;
              v25 = v24 * v24 + v45;
              v26 = sqrt(v25);
              v27 = v26 * 256.0 / r + 0.5;
              v28 = floor(v27);
              v19 = (int)v28;
              if ( v19 > 255 )
                v19 = 255;
              v47[v18++] = *(_DWORD *)&v48.Ramp[4 * v19];
              if ( v18 >= (unsigned int)data2b )
                break;
              v14 = 0.5;
              v15 = v38;
            }
          }
          else
          {
            v29 = (double)v16 - v15 + v14;
            while ( 1 )
            {
              v31 = v14 + (double)v18 - v15;
              v32 = Scaleform::Render::FocalRadialGradient::Calculate(&v46, v31, v29) * 256.0 / r + 0.5;
              v33 = floor(v32);
              v20 = (int)v33;
              if ( v20 > 255 )
                v20 = 255;
              v47[v18++] = *(_DWORD *)&v48.Ramp[4 * v20];
              if ( v18 >= (unsigned int)data2b )
                break;
              v14 = 0.5;
              v15 = v38;
            }
          }
          copyScanline(v40, (const unsigned __int8 *)v47, 4 * this->Size.Width, 0, arg);
          ++v16;
          v40 += pplane.Pitch;
          if ( v16 >= (unsigned int)data2b )
            break;
          v14 = 0.5;
          pObject = v42;
          v15 = v38;
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
          copyScanline(pData, v48.Ramp, 4 * this->Size.Width, 0, arg);
          ++v11;
        }
        while ( v11 < this->Size.Height );
      }
    }
    v43.__vftable = (Scaleform::Render::GradientData_vtbl *)&Scaleform::Render::GradientData::`vftable';
    if ( v43.pRecords )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v43.pRecords);
    Scaleform::RefCountImplCore::~RefCountImplCore(&v43);
    return 1;
  }
  else
  {
    v47[0] = 0;
    copyScanline(pplane.pData, (const unsigned __int8 *)v47, 4u, 0, arg);
    return 1;
  }
}

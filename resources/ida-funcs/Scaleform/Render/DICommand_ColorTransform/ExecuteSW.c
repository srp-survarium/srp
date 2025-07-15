void __thiscall Scaleform::Render::DICommand_ColorTransform::ExecuteSW(
        Scaleform::Render::DICommand_ColorTransform *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v5; // edi
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int Height; // edx
  unsigned int Width; // ecx
  unsigned int *p_Width; // edi
  unsigned int v10; // eax
  unsigned int v11; // ecx
  Scaleform::Render::TextureManager *v12; // eax
  int v13; // eax
  Scaleform::Render::TextureManager *v14; // eax
  Scaleform::Render::ImageData *v15; // esi
  int y1; // edi
  int x1; // esi
  int v18; // edi
  double v19; // st5
  bool v20; // c0
  bool v21; // c3
  double v22; // st5
  double v23; // st4
  double v24; // rt0
  double v25; // st4
  double v26; // st5
  double v27; // rt1
  double v28; // st7
  Scaleform::Render::DrawableImage *pObject; // eax
  float v30; // [esp+24h] [ebp-DCh]
  float v31; // [esp+24h] [ebp-DCh]
  float v32; // [esp+24h] [ebp-DCh]
  float v33; // [esp+24h] [ebp-DCh]
  float v34; // [esp+24h] [ebp-DCh]
  float v35; // [esp+28h] [ebp-D8h]
  float v36; // [esp+28h] [ebp-D8h]
  Scaleform::Render::Size<unsigned long> v37; // [esp+2Ch] [ebp-D4h] BYREF
  int v38; // [esp+34h] [ebp-CCh]
  _BYTE v39[3]; // [esp+38h] [ebp-C8h] BYREF
  unsigned __int8 v40; // [esp+3Bh] [ebp-C5h]
  float v41; // [esp+3Ch] [ebp-C4h]
  float v42; // [esp+40h] [ebp-C0h]
  Scaleform::Render::Size<unsigned long> v43; // [esp+44h] [ebp-BCh] BYREF
  int v44; // [esp+4Ch] [ebp-B4h]
  float v45[8]; // [esp+50h] [ebp-B0h] BYREF
  Scaleform::Render::DICommand_ColorTransform *v46; // [esp+7Ch] [ebp-84h]
  Scaleform::Render::Rect<long> v47; // [esp+80h] [ebp-80h] BYREF
  float v48; // [esp+90h] [ebp-70h]
  float v49; // [esp+94h] [ebp-6Ch]
  float v50; // [esp+98h] [ebp-68h]
  float v51; // [esp+9Ch] [ebp-64h]
  _DWORD v52[6]; // [esp+A0h] [ebp-60h] BYREF
  _DWORD v53[6]; // [esp+B8h] [ebp-48h] BYREF
  Scaleform::Render::Point<long> v54; // [esp+D0h] [ebp-30h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+D8h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane v56; // [esp+ECh] [ebp-14h] BYREF

  v5 = *psrc;
  v46 = this;
  memset(&pplane, 0, sizeof(pplane));
  memset(&v56, 0, sizeof(v56));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &pplane);
  Scaleform::Render::ImageData::GetPlane(v5, 0, &v56);
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  Width = pPlanes->Width;
  p_Width = &v5->pPlanes->Width;
  v10 = *p_Width;
  v37.Width = Width;
  v11 = p_Width[1];
  v37.Height = Height;
  v43.Width = v10;
  v43.Height = v11;
  memset(&v47, 0, sizeof(v47));
  if ( !Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
          this,
          &v43,
          &v37,
          &this->SourceRect,
          &v47,
          &v54) )
    return;
  qmemcpy(v45, &this->Cx, sizeof(v45));
  if ( !v46->pImage.pObject->Transparent )
  {
    *(float *)&v43.Width = v45[7] + v45[3];
    v45[0] = v45[0] * *(float *)&v43.Width;
    v45[4] = v45[4] * *(float *)&v43.Width;
    v45[1] = v45[1] * *(float *)&v43.Width;
    v45[5] = v45[5] * *(float *)&v43.Width;
    v45[2] = v45[2] * *(float *)&v43.Width;
    v45[6] = *(float *)&v43.Width * v45[6];
    v45[3] = 1.0;
    v45[7] = 0.0;
  }
  v12 = context->pHAL->GetTextureManager(context->pHAL);
  v13 = (int)v12->GetImageSwizzler(v12);
  v53[2] = dest;
  v53[0] = v13;
  v53[1] = 0;
  memset(&v53[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v13 + 4))(v13, v53);
  v14 = context->pHAL->GetTextureManager(context->pHAL);
  v15 = *psrc;
  v52[0] = v14->GetImageSwizzler(v14);
  v52[1] = 0;
  v52[2] = v15;
  memset(&v52[3], 0, 12);
  (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v52[0] + 4))(v52[0], v52);
  y1 = v47.y1;
  v43.Width = v47.y1;
  if ( v47.y1 >= v47.y2 )
    return;
  v44 = v47.y1 - v54.y;
  do
  {
    (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v53[0] + 8))(v53[0], v53, y1);
    (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v52[0] + 8))(v52[0], v52, v44);
    x1 = v47.x1;
    if ( v47.x1 >= v47.x2 )
      goto LABEL_33;
    v18 = v47.x1 - v54.x;
    do
    {
      (*(void (__thiscall **)(_DWORD, _BYTE *, _DWORD *, int))(*(_DWORD *)v52[0] + 20))(v52[0], v39, v52, v18);
      if ( !v46->pSource.pObject->Transparent )
        v40 = -1;
      v48 = (double)v39[2] / 255.0 * v45[0];
      v49 = (double)v39[1] / 255.0 * v45[1];
      v50 = (double)v39[0] / 255.0 * v45[2];
      v51 = (double)v40 / 255.0 * v45[3];
      v35 = (v51 + v45[7]) * 256.0;
      v19 = v35;
      if ( v35 >= 255.0 )
      {
        v30 = 255.0;
        v23 = 255.0;
        v22 = 0.0;
      }
      else
      {
        v30 = (v51 + v45[7]) * 256.0;
        v20 = v19 > 0.0;
        v21 = 0.0 == v19;
        v22 = 0.0;
        if ( !v20 && !v21 )
        {
          v36 = 0.0;
          v23 = 255.0;
          goto LABEL_15;
        }
        v23 = 255.0;
      }
      v36 = v30;
LABEL_15:
      v42 = (v45[6] + v50) * 256.0;
      if ( v42 >= 255.0 )
      {
        v31 = v23;
      }
      else
      {
        v31 = v42;
        if ( v42 < v22 )
        {
          v24 = v23;
          v25 = v22;
          v26 = v24;
          v42 = v25;
          goto LABEL_21;
        }
      }
      v42 = v31;
      v27 = v23;
      v25 = v22;
      v26 = v27;
LABEL_21:
      v41 = (v45[5] + v49) * 256.0;
      if ( v41 >= 255.0 )
      {
        v32 = v26;
      }
      else
      {
        v32 = v41;
        if ( v41 < v25 )
        {
          v41 = v25;
          goto LABEL_26;
        }
      }
      v41 = v32;
LABEL_26:
      v33 = 256.0 * (v45[4] + v48);
      if ( v33 >= 255.0 )
      {
        v33 = v26;
      }
      else
      {
        v28 = v25;
        if ( v33 < v25 )
          goto LABEL_29;
      }
      v28 = v33;
LABEL_29:
      v34 = v28;
      BYTE2(v38) = (int)v34;
      BYTE1(v38) = (int)v41;
      LOBYTE(v38) = (int)v42;
      v37.Width = LOWORD(v34) | 0xC00;
      pObject = v46->pImage.pObject;
      v37.Width = (int)v36;
      HIBYTE(v38) = v37.Width;
      if ( !pObject->Transparent )
        HIBYTE(v38) = -1;
      (*(void (__thiscall **)(_DWORD, _DWORD *, int, int))(*(_DWORD *)v53[0] + 12))(v53[0], v53, x1++, v38);
      ++v18;
    }
    while ( x1 < v47.x2 );
    y1 = v43.Width;
LABEL_33:
    ++v44;
    v43.Width = ++y1;
  }
  while ( y1 < v47.y2 );
}

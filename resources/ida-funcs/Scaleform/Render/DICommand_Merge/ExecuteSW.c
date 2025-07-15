void __thiscall Scaleform::Render::DICommand_Merge::ExecuteSW(
        Scaleform::Render::DICommand_Merge *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v4; // ebx
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int Height; // edx
  unsigned int Width; // ecx
  unsigned int *p_Width; // ebx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  Scaleform::Render::TextureManager *v12; // eax
  Scaleform::Render::TextureManager *v13; // eax
  Scaleform::Render::ImageData *v14; // ebx
  int y1; // ebx
  int v16; // edi
  unsigned int BlueMultiplier; // eax
  int v18; // edi
  bool v19; // zf
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int AlphaMultiplier; // ebx
  unsigned int v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // eax
  bool Transparent; // [esp+37h] [ebp-B9h]
  int v27; // [esp+38h] [ebp-B8h]
  int x1; // [esp+3Ch] [ebp-B4h]
  int i; // [esp+40h] [ebp-B0h]
  int v30; // [esp+44h] [ebp-ACh]
  _BYTE v31[4]; // [esp+48h] [ebp-A8h] BYREF
  _BYTE v32[4]; // [esp+4Ch] [ebp-A4h] BYREF
  Scaleform::Render::Size<unsigned long> v33; // [esp+50h] [ebp-A0h] BYREF
  Scaleform::Render::Rect<long> v34; // [esp+58h] [ebp-98h] BYREF
  Scaleform::Render::Size<unsigned long> v35; // [esp+68h] [ebp-88h] BYREF
  int v36; // [esp+70h] [ebp-80h]
  int v37; // [esp+74h] [ebp-7Ch]
  int v38; // [esp+78h] [ebp-78h]
  int v39; // [esp+7Ch] [ebp-74h]
  _DWORD v40[6]; // [esp+80h] [ebp-70h] BYREF
  _DWORD v41[6]; // [esp+98h] [ebp-58h] BYREF
  Scaleform::Render::Point<long> v42; // [esp+B0h] [ebp-40h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+B8h] [ebp-38h] BYREF
  Scaleform::Render::ImagePlane v44; // [esp+CCh] [ebp-24h] BYREF
  unsigned int v45; // [esp+E8h] [ebp-8h]

  v4 = *psrc;
  memset(&pplane, 0, sizeof(pplane));
  memset(&v44, 0, sizeof(v44));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &pplane);
  Scaleform::Render::ImageData::GetPlane(v4, 0, &v44);
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  Width = pPlanes->Width;
  p_Width = &v4->pPlanes->Width;
  v10 = *p_Width;
  v35.Width = Width;
  v11 = p_Width[1];
  v35.Height = Height;
  v33.Width = v10;
  v33.Height = v11;
  memset(&v34, 0, sizeof(v34));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         &v33,
         &v35,
         &this->SourceRect,
         &v34,
         &v42) )
  {
    v12 = context->pHAL->GetTextureManager(context->pHAL);
    v40[0] = v12->GetImageSwizzler(v12);
    v40[1] = 0;
    v40[2] = dest;
    memset(&v40[3], 0, 12);
    (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v40[0] + 4))(v40[0], v40);
    v13 = context->pHAL->GetTextureManager(context->pHAL);
    v14 = *psrc;
    v41[0] = v13->GetImageSwizzler(v13);
    v41[1] = 0;
    v41[2] = v14;
    memset(&v41[3], 0, 12);
    (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v41[0] + 4))(v41[0], v41);
    y1 = v34.y1;
    v33.Width = v34.y1;
    if ( v34.y1 < v34.y2 )
    {
      v30 = v34.y1 - v42.y;
      do
      {
        (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v40[0] + 8))(v40[0], v40, y1);
        (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v41[0] + 8))(v41[0], v41, v30);
        x1 = v34.x1;
        if ( v34.x1 < v34.x2 )
        {
          v16 = v34.x1 - v42.x;
          for ( i = v34.x1 - v42.x; ; v16 = i )
          {
            (*(void (__thiscall **)(_DWORD, _BYTE *, _DWORD *, int))(*(_DWORD *)v40[0] + 20))(v40[0], v31, v40, x1);
            (*(void (__thiscall **)(_DWORD, _BYTE *, _DWORD *, int))(*(_DWORD *)v41[0] + 20))(v41[0], v32, v41, v16);
            BlueMultiplier = this->BlueMultiplier;
            v18 = v32[3];
            v36 = v31[2];
            v37 = v31[1];
            v38 = v31[0];
            v19 = !this->pSource.pObject->Transparent;
            v45 = BlueMultiplier;
            v39 = v31[3];
            if ( v19 )
              v18 = 255;
            Transparent = this->pImage.pObject->Transparent;
            if ( !Transparent )
              v39 = 255;
            v20 = this->RedMultiplier * v32[2] + v36 * (256 - this->RedMultiplier);
            v21 = this->GreenMultiplier * v32[1] + v37 * (256 - this->GreenMultiplier);
            AlphaMultiplier = this->AlphaMultiplier;
            BYTE2(v35.Width) = (unsigned __int16)(v45 * v32[0] + v38 * (256 - v45)) >> 8;
            v23 = v20 >> 8;
            v24 = v21 >> 8;
            v25 = (AlphaMultiplier * v18 + v39 * (256 - AlphaMultiplier)) >> 8;
            if ( !Transparent )
              LOBYTE(v25) = -1;
            BYTE2(v27) = v23;
            BYTE1(v27) = v24;
            LOBYTE(v27) = BYTE2(v35.Width);
            HIBYTE(v27) = v25;
            (*(void (__thiscall **)(_DWORD, _DWORD *, int, int))(*(_DWORD *)v40[0] + 12))(v40[0], v40, x1, v27);
            ++i;
            if ( ++x1 >= v34.x2 )
              break;
          }
          y1 = v33.Width;
        }
        ++v30;
        v33.Width = ++y1;
      }
      while ( y1 < v34.y2 );
    }
  }
}

void __thiscall Scaleform::Render::DICommand_PixelDissolve::ExecuteSW(
        Scaleform::Render::DICommand_PixelDissolve *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        unsigned int psrc)
{
  Scaleform::Render::TextureManager *v5; // eax
  int v6; // eax
  Scaleform::Render::ImageData *v7; // edi
  int *pPlanes; // edi
  int v9; // edx
  unsigned int v10; // edi
  signed int RandomSeed; // eax
  int v12; // ebp
  unsigned int v13; // et2
  unsigned int *Result; // esi
  Scaleform::Render::TextureManager *v15; // eax
  int v16; // ebp
  Scaleform::Render::ImagePlane *v17; // ecx
  int y; // ebp
  int v19; // edi
  int v20; // ecx
  int *v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // ecx
  unsigned int v25; // edi
  unsigned int v26; // ebx
  unsigned int v27; // ebp
  unsigned int *v28; // esi
  Scaleform::Render::Rect<long> v29; // [esp+10h] [ebp-50h] BYREF
  Scaleform::Render::Rect<long> v30; // [esp+20h] [ebp-40h] BYREF
  _DWORD v31[6]; // [esp+30h] [ebp-30h] BYREF
  _DWORD v32[6]; // [esp+48h] [ebp-18h] BYREF
  int v33; // [esp+64h] [ebp+4h]
  int v34; // [esp+64h] [ebp+4h]
  unsigned int i; // [esp+64h] [ebp+4h]

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = (int)v5->GetImageSwizzler(v5);
  v7 = dest;
  v31[0] = v6;
  v31[1] = 0;
  v31[2] = dest;
  memset(&v31[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v6 + 4))(v6, v31);
  if ( this->pImage.pObject == this->pSource.pObject )
  {
    pPlanes = (int *)v7->pPlanes;
    v9 = pPlanes[1];
    v30.x2 = *pPlanes;
    v30.x1 = 0;
    v30.y1 = 0;
    v30.y2 = v9;
    memset(&v29, 0, sizeof(v29));
    if ( Scaleform::Render::Rect<long>::IntersectRect(&v30, &v29, &this->SourceRect) )
    {
      v10 = v29.x2 - v29.x1;
      v33 = v29.x2 - v29.x1;
      Scaleform::Render::LFSR::LFSR((Scaleform::Render::LFSR *)&v29, (v29.x2 - v29.x1) * (v29.y2 - v29.y1));
      RandomSeed = this->RandomSeed;
      v12 = 0;
      if ( this->NumPixels )
      {
        while ( 1 )
        {
          do
            RandomSeed = Scaleform::Render::LFSR::FeedbackPoly[v29.y1] & -(RandomSeed & 1) ^ (RandomSeed >> 1);
          while ( (unsigned int)RandomSeed > v29.x1 );
          psrc = RandomSeed;
          v13 = (RandomSeed - 1) % v10;
          (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v31[0] + 8))(
            v31[0],
            v31,
            (RandomSeed - 1) / v10);
          (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int, unsigned int))(*(_DWORD *)v31[0] + 12))(
            v31[0],
            v31,
            v13,
            this->Fill.Raw);
          RandomSeed = psrc;
          if ( ++v12 >= this->NumPixels )
            break;
          v10 = v33;
        }
      }
      Result = this->Result;
      if ( Result )
        *Result = RandomSeed;
      return;
    }
LABEL_21:
    this->Result = 0;
    return;
  }
  v15 = context->pHAL->GetTextureManager(context->pHAL);
  v16 = *(_DWORD *)psrc;
  v32[0] = v15->GetImageSwizzler(v15);
  v32[1] = 0;
  v32[2] = v16;
  memset(&v32[3], 0, 12);
  (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v32[0] + 4))(v32[0], v32);
  v17 = v7->pPlanes;
  y = this->DestPoint.y;
  v19 = v17->Width - this->DestPoint.x - this->DestPoint.x;
  v20 = v17->Height - y;
  if ( v19 <= 0 )
    goto LABEL_21;
  v34 = v20 - y;
  if ( v20 - y <= 0 )
    goto LABEL_21;
  v21 = *(int **)(*(_DWORD *)psrc + 12);
  v22 = *v21;
  v23 = v21[1];
  v30.x2 = v22;
  v30.y2 = v23;
  memset(&v29, 0, sizeof(v29));
  v30.x1 = 0;
  v30.y1 = 0;
  if ( !Scaleform::Render::Rect<long>::IntersectRect(&this->SourceRect, &v29, &v30) )
    goto LABEL_21;
  v24 = v34;
  if ( v29.y2 - v29.y1 < v34 )
    v24 = v29.y2 - v29.y1;
  psrc = v29.x2 - v29.x1;
  if ( v29.x2 - v29.x1 >= v19 )
    psrc = v19;
  Scaleform::Render::LFSR::LFSR((Scaleform::Render::LFSR *)&v29, v24 * psrc);
  v25 = this->RandomSeed;
  for ( i = 0; i < this->NumPixels; ++i )
  {
    v25 = Scaleform::Render::LFSR::Next((Scaleform::Render::LFSR *)&v29, v25);
    v26 = (v25 - 1) % psrc;
    v27 = (v25 - 1) / psrc;
    (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v32[0] + 8))(
      v32[0],
      v32,
      v27 + this->SourceRect.y1);
    (*(void (__thiscall **)(_DWORD, Scaleform::Render::ImageData **, _DWORD *, unsigned int))(*(_DWORD *)v32[0] + 20))(
      v32[0],
      &dest,
      v32,
      v26 + this->SourceRect.x1);
    (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v31[0] + 8))(
      v31[0],
      v31,
      v27 + this->DestPoint.y);
    (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int, Scaleform::Render::ImageData *))(*(_DWORD *)v31[0] + 12))(
      v31[0],
      v31,
      v26 + this->DestPoint.x,
      dest);
  }
  v28 = this->Result;
  if ( v28 )
    *v28 = v25;
}

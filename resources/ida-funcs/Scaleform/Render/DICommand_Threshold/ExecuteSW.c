void __thiscall Scaleform::Render::DICommand_Threshold::ExecuteSW(
        Scaleform::Render::DICommand_Threshold *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int Width; // ecx
  unsigned int Height; // edx
  unsigned int *v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // edx
  Scaleform::Render::TextureManager *v11; // eax
  int v12; // eax
  Scaleform::Render::TextureManager *v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  int y1; // esi
  int x1; // ebx
  int v18; // ebp
  unsigned int Mask; // eax
  unsigned int v20; // ecx
  unsigned int v21; // eax
  bool v22; // dl
  unsigned int ThresholdColor; // eax
  Scaleform::Render::Size<unsigned long> v24; // [esp+30h] [ebp-84h] BYREF
  unsigned int v25; // [esp+38h] [ebp-7Ch] BYREF
  Scaleform::Render::Size<unsigned long> v26; // [esp+3Ch] [ebp-78h] BYREF
  Scaleform::Render::Rect<long> v27; // [esp+44h] [ebp-70h] BYREF
  _DWORD v28[6]; // [esp+54h] [ebp-60h] BYREF
  _DWORD v29[6]; // [esp+6Ch] [ebp-48h] BYREF
  Scaleform::Render::Point<long> v30; // [esp+84h] [ebp-30h] BYREF
  Scaleform::Render::ImagePlane v31; // [esp+8Ch] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+A0h] [ebp-14h] BYREF

  v24.Width = (unsigned int)*psrc;
  memset(&pplane, 0, sizeof(pplane));
  memset(&v31, 0, sizeof(v31));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &pplane);
  Scaleform::Render::ImageData::GetPlane((Scaleform::Render::ImageData *)v24.Width, 0, &v31);
  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v8 = *(unsigned int **)(v24.Width + 12);
  v26.Width = Width;
  v9 = *v8;
  v26.Height = Height;
  v10 = v8[1];
  v24.Width = v9;
  v24.Height = v10;
  memset(&v27, 0, sizeof(v27));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         &v24,
         &v26,
         &this->SourceRect,
         &v27,
         &v30) )
  {
    v11 = context->pHAL->GetTextureManager(context->pHAL);
    v12 = (int)v11->GetImageSwizzler(v11);
    v29[1] = 0;
    memset(&v29[3], 0, 12);
    v29[0] = v12;
    v29[2] = dest;
    (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v12 + 4))(v12, v29);
    v13 = context->pHAL->GetTextureManager(context->pHAL);
    v14 = (unsigned int)*psrc;
    v15 = (int)v13->GetImageSwizzler(v13);
    v28[1] = 0;
    memset(&v28[3], 0, 12);
    v28[0] = v15;
    v28[2] = v14;
    (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v15 + 4))(v15, v28);
    y1 = v27.y1;
    v26.Width = v27.y1;
    if ( v27.y1 < v27.y2 )
    {
      v24.Width = v27.y1 - v30.y;
      do
      {
        (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v29[0] + 8))(v29[0], v29, y1);
        (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v28[0] + 8))(v28[0], v28, v24.Width);
        x1 = v27.x1;
        if ( v27.x1 < v27.x2 )
        {
          v18 = v27.x1 - v30.x;
          do
          {
            (*(void (__thiscall **)(_DWORD, unsigned int *, _DWORD *, int))(*(_DWORD *)v28[0] + 20))(
              v28[0],
              &v25,
              v28,
              v18);
            Mask = this->Mask;
            v20 = Mask & this->Threshold;
            v21 = v25 & Mask;
            v22 = 0;
            switch ( this->Operation )
            {
              case Operator_LT:
                v22 = v21 < v20;
                break;
              case Operator_LE:
                v22 = v21 <= v20;
                break;
              case Operator_GT:
                v22 = v21 > v20;
                break;
              case Operator_GE:
                v22 = v21 >= v20;
                break;
              case Operator_EQ:
                v22 = v21 == v20;
                break;
              case Operator_NE:
                v22 = v21 != v20;
                break;
              default:
                break;
            }
            if ( !this->pSource.pObject->Transparent )
              HIBYTE(v25) = -1;
            if ( v22 )
              ThresholdColor = this->ThresholdColor;
            else
              ThresholdColor = v25;
            if ( !this->pImage.pObject->Transparent )
              ThresholdColor |= 0xFF000000;
            (*(void (__thiscall **)(_DWORD, _DWORD *, int, unsigned int))(*(_DWORD *)v29[0] + 12))(
              v29[0],
              v29,
              x1++,
              ThresholdColor);
            ++v18;
          }
          while ( x1 < v27.x2 );
          y1 = v26.Width;
        }
        ++v24.Width;
        v26.Width = ++y1;
      }
      while ( y1 < v27.y2 );
    }
  }
}

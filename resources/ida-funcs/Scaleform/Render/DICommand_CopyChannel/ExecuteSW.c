void __thiscall Scaleform::Render::DICommand_CopyChannel::ExecuteSW(
        Scaleform::Render::DICommand_CopyChannel *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v4; // esi
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int Height; // edx
  unsigned int Width; // ecx
  unsigned int *p_Width; // esi
  unsigned int v10; // eax
  unsigned int v11; // ecx
  Scaleform::Render::DrawableImage::ChannelBits SourceChannel; // eax
  Scaleform::Render::DrawableImage::ChannelBits DestChannel; // eax
  Scaleform::Render::TextureManager *v14; // eax
  Scaleform::Render::TextureManager *v15; // eax
  Scaleform::Render::ImageData *v16; // esi
  int y1; // edi
  int x1; // esi
  int v19; // edi
  Scaleform::Render::DrawableImage *pObject; // ecx
  Scaleform::Render::DrawableImage *v21; // edx
  char v22; // al
  unsigned __int8 v23; // [esp+2Eh] [ebp-9Ah]
  unsigned __int8 v24; // [esp+2Fh] [ebp-99h]
  int v25; // [esp+30h] [ebp-98h] BYREF
  char v26; // [esp+34h] [ebp-94h] BYREF
  char v27; // [esp+35h] [ebp-93h]
  char v28; // [esp+36h] [ebp-92h]
  char v29; // [esp+37h] [ebp-91h]
  _BYTE v30[3]; // [esp+38h] [ebp-90h] BYREF
  char v31; // [esp+3Bh] [ebp-8Dh]
  _BYTE v32[4]; // [esp+3Ch] [ebp-8Ch] BYREF
  int v33; // [esp+40h] [ebp-88h]
  int v34; // [esp+44h] [ebp-84h]
  Scaleform::Render::Rect<long> v35; // [esp+48h] [ebp-80h] BYREF
  Scaleform::Render::Size<unsigned long> v36; // [esp+58h] [ebp-70h] BYREF
  Scaleform::Render::Size<unsigned long> v37; // [esp+60h] [ebp-68h] BYREF
  _DWORD v38[6]; // [esp+68h] [ebp-60h] BYREF
  _DWORD v39[6]; // [esp+80h] [ebp-48h] BYREF
  Scaleform::Render::Point<long> v40; // [esp+98h] [ebp-30h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+A0h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane v42; // [esp+B4h] [ebp-14h] BYREF

  v4 = *psrc;
  memset(&pplane, 0, sizeof(pplane));
  memset(&v42, 0, sizeof(v42));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &pplane);
  Scaleform::Render::ImageData::GetPlane(v4, 0, &v42);
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  Width = pPlanes->Width;
  p_Width = &v4->pPlanes->Width;
  v10 = *p_Width;
  v37.Width = Width;
  v11 = p_Width[1];
  v37.Height = Height;
  v36.Width = v10;
  v36.Height = v11;
  memset(&v35, 0, sizeof(v35));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         &v36,
         &v37,
         &this->SourceRect,
         &v35,
         &v40) )
  {
    SourceChannel = this->SourceChannel;
    v24 = SourceChannel > Channel_Alpha ? -1 : Scaleform::Render::ChannelIndexMap[SourceChannel];
    DestChannel = this->DestChannel;
    v23 = DestChannel > Channel_Alpha ? -1 : Scaleform::Render::ChannelIndexMap[DestChannel];
    if ( v24 != 0xFF && v23 != 0xFF )
    {
      v14 = context->pHAL->GetTextureManager(context->pHAL);
      v38[0] = v14->GetImageSwizzler(v14);
      v38[1] = 0;
      v38[2] = dest;
      memset(&v38[3], 0, 12);
      (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v38[0] + 4))(v38[0], v38);
      v15 = context->pHAL->GetTextureManager(context->pHAL);
      v16 = *psrc;
      v39[0] = v15->GetImageSwizzler(v15);
      v39[1] = 0;
      v39[2] = v16;
      memset(&v39[3], 0, 12);
      (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v39[0] + 4))(v39[0], v39);
      y1 = v35.y1;
      v34 = v35.y1;
      if ( v35.y1 < v35.y2 )
      {
        v33 = v35.y1 - v40.y;
        do
        {
          (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v38[0] + 8))(v38[0], v38, y1);
          (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v39[0] + 8))(v39[0], v39, v33);
          x1 = v35.x1;
          if ( v35.x1 < v35.x2 )
          {
            v19 = v35.x1 - v40.x;
            v36.Width = (unsigned int)&v30[v24];
            v37.Width = (unsigned int)(&v26 + v23);
            do
            {
              (*(void (__thiscall **)(_DWORD, int *, _DWORD *, int))(*(_DWORD *)v38[0] + 20))(v38[0], &v25, v38, x1);
              (*(void (__thiscall **)(_DWORD, _BYTE *, _DWORD *, int))(*(_DWORD *)v39[0] + 20))(v39[0], v32, v39, v19);
              v26 = BYTE2(v25);
              v27 = BYTE1(v25);
              v28 = v25;
              v30[1] = v32[1];
              v30[2] = v32[0];
              v29 = HIBYTE(v25);
              pObject = this->pSource.pObject;
              v31 = v32[3];
              v30[0] = v32[2];
              if ( !pObject->Transparent )
                v31 = -1;
              v21 = this->pImage.pObject;
              *(_BYTE *)v37.Width = *(_BYTE *)v36.Width;
              if ( v21->Transparent )
                v22 = v29;
              else
                v22 = -1;
              BYTE2(v25) = v26;
              BYTE1(v25) = v27;
              LOBYTE(v25) = v28;
              HIBYTE(v25) = v22;
              (*(void (__thiscall **)(_DWORD, _DWORD *, int, int))(*(_DWORD *)v38[0] + 12))(v38[0], v38, x1++, v25);
              ++v19;
            }
            while ( x1 < v35.x2 );
            y1 = v34;
          }
          ++v33;
          v34 = ++y1;
        }
        while ( y1 < v35.y2 );
      }
    }
  }
}

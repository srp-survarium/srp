void __thiscall Scaleform::Render::DICommand_PaletteMap::ExecuteSW(
        Scaleform::Render::DICommand_PaletteMap *this,
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
  Scaleform::Render::TextureManager *v12; // eax
  Scaleform::Render::TextureManager *v13; // eax
  Scaleform::Render::ImageData *v14; // esi
  int y1; // esi
  int x2; // ebp
  unsigned int v17; // eax
  unsigned __int8 v18; // al
  int v19; // edx
  int v20; // eax
  int v21; // esi
  int i; // ecx
  int v23; // esi
  unsigned __int8 v24; // [esp+28h] [ebp-A0h] BYREF
  unsigned __int8 v25; // [esp+29h] [ebp-9Fh]
  unsigned __int8 v26; // [esp+2Ah] [ebp-9Eh]
  char v27; // [esp+2Bh] [ebp-9Dh]
  _BYTE v28[4]; // [esp+2Ch] [ebp-9Ch]
  int v29; // [esp+30h] [ebp-98h]
  Scaleform::Render::Size<unsigned long> v30; // [esp+34h] [ebp-94h] BYREF
  int x1; // [esp+3Ch] [ebp-8Ch]
  Scaleform::Render::Size<unsigned long> v32; // [esp+40h] [ebp-88h] BYREF
  Scaleform::Render::Rect<long> v33; // [esp+48h] [ebp-80h] BYREF
  _DWORD v34[6]; // [esp+58h] [ebp-70h] BYREF
  _DWORD v35[6]; // [esp+70h] [ebp-58h] BYREF
  Scaleform::Render::Point<long> v36; // [esp+88h] [ebp-40h] BYREF
  _DWORD v37[4]; // [esp+90h] [ebp-38h]
  Scaleform::Render::ImagePlane v38; // [esp+A0h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+B4h] [ebp-14h] BYREF

  v4 = *psrc;
  memset(&pplane, 0, sizeof(pplane));
  memset(&v38, 0, sizeof(v38));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &pplane);
  Scaleform::Render::ImageData::GetPlane(v4, 0, &v38);
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  Width = pPlanes->Width;
  p_Width = &v4->pPlanes->Width;
  v10 = *p_Width;
  v32.Width = Width;
  v11 = p_Width[1];
  v32.Height = Height;
  v30.Width = v10;
  v30.Height = v11;
  memset(&v33, 0, sizeof(v33));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         &v30,
         &v32,
         &this->SourceRect,
         &v33,
         &v36) )
  {
    v12 = context->pHAL->GetTextureManager(context->pHAL);
    v34[0] = v12->GetImageSwizzler(v12);
    v34[1] = 0;
    v34[2] = dest;
    memset(&v34[3], 0, 12);
    (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v34[0] + 4))(v34[0], v34);
    v13 = context->pHAL->GetTextureManager(context->pHAL);
    v14 = *psrc;
    v35[0] = v13->GetImageSwizzler(v13);
    v35[1] = 0;
    v35[2] = v14;
    memset(&v35[3], 0, 12);
    (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v35[0] + 4))(v35[0], v35);
    y1 = v33.y1;
    v32.Width = v33.y1;
    if ( v33.y1 < v33.y2 )
    {
      x2 = v33.x2;
      v29 = v33.y1 - v36.y;
      do
      {
        (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v34[0] + 8))(v34[0], v34, y1);
        (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v35[0] + 8))(v35[0], v35, v29);
        x1 = v33.x1;
        if ( v33.x1 < x2 )
        {
          v17 = v33.x1 - v36.x;
          v30.Width = v33.x1 - v36.x;
          do
          {
            (*(void (__thiscall **)(_DWORD, unsigned __int8 *, _DWORD *, unsigned int))(*(_DWORD *)v35[0] + 20))(
              v35[0],
              &v24,
              v35,
              v17);
            if ( this->pSource.pObject->Transparent )
            {
              v18 = v27;
            }
            else
            {
              v18 = -1;
              v27 = -1;
            }
            v28[3] = v18;
            v28[0] = v26;
            v37[3] = v18 << 24;
            v28[1] = v25;
            v37[0] = v26 << 16;
            v28[2] = v24;
            v37[1] = v25 << 8;
            v19 = 0;
            v37[2] = v24;
            v20 = 0;
            v21 = 1;
            for ( i = 0; i < 1024; i += 256 )
            {
              if ( (v21 & this->ChannelMask) != 0 )
                v37[v20] = this->Channels[i + (unsigned __int8)v28[v20]];
              v19 += v37[v20++];
              v21 = __ROL4__(v21, 1);
            }
            if ( !this->pImage.pObject->Transparent )
              v19 |= 0xFF000000;
            v23 = x1;
            (*(void (__thiscall **)(_DWORD, _DWORD *, int, int))(*(_DWORD *)v34[0] + 12))(v34[0], v34, x1, v19);
            x2 = v33.x2;
            v17 = v30.Width + 1;
            x1 = v23 + 1;
            ++v30.Width;
          }
          while ( v23 + 1 < v33.x2 );
          y1 = v32.Width;
        }
        ++v29;
        v32.Width = ++y1;
      }
      while ( y1 < v33.y2 );
    }
  }
}

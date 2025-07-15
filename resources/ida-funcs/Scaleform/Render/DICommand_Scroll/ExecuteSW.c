void __thiscall Scaleform::Render::DICommand_Scroll::ExecuteSW(
        Scaleform::Render::DICommand_Scroll *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v5; // edi
  int *pPlanes; // edi
  Scaleform::Render::Rect<long> *p_SourceRect; // eax
  int v8; // ebp
  int v9; // esi
  int v10; // edx
  Scaleform::Render::ImagePlane *v11; // ecx
  int Width; // edx
  int Height; // ecx
  Scaleform::Render::TextureManager *v14; // eax
  Scaleform::Render::TextureManager *v15; // eax
  Scaleform::Render::ImageData *v16; // edi
  int v17; // ebp
  int v18; // edi
  int v19; // esi
  int v20; // edi
  int v21; // [esp+30h] [ebp-B0h]
  int v22; // [esp+34h] [ebp-ACh] BYREF
  Scaleform::Render::Rect<long> v23; // [esp+38h] [ebp-A8h] BYREF
  Scaleform::Render::Rect<long> v24; // [esp+48h] [ebp-98h] BYREF
  Scaleform::Render::Rect<long> v25; // [esp+58h] [ebp-88h] BYREF
  Scaleform::Render::DICommand_Scroll *v26; // [esp+68h] [ebp-78h]
  int v27; // [esp+6Ch] [ebp-74h]
  _DWORD v28[6]; // [esp+70h] [ebp-70h] BYREF
  _DWORD v29[6]; // [esp+88h] [ebp-58h] BYREF
  Scaleform::Render::Rect<long> v30; // [esp+A0h] [ebp-40h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+B0h] [ebp-30h] BYREF
  Scaleform::Render::ImagePlane v32; // [esp+C4h] [ebp-1Ch] BYREF
  int v33; // [esp+D8h] [ebp-8h]

  v5 = *psrc;
  v26 = this;
  memset(&pplane, 0, sizeof(pplane));
  memset(&v32, 0, sizeof(v32));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &pplane);
  Scaleform::Render::ImageData::GetPlane(v5, 0, &v32);
  pPlanes = (int *)v5->pPlanes;
  p_SourceRect = &this->SourceRect;
  v8 = this->DestPoint.x - this->SourceRect.x1;
  v9 = this->DestPoint.y - this->SourceRect.y1;
  v10 = pPlanes[1];
  v24.x2 = *pPlanes;
  v11 = dest->pPlanes;
  v24.y2 = v10;
  Width = v11->Width;
  Height = v11->Height;
  v30.x2 = Width;
  v30.y2 = Height;
  v33 = v8;
  v24.x1 = 0;
  v24.y1 = 0;
  v30.x1 = 0;
  v30.y1 = 0;
  memset(&v25, 0, sizeof(v25));
  memset(&v23, 0, sizeof(v23));
  if ( Scaleform::Render::Rect<long>::IntersectRect(&v24, &v25, p_SourceRect) )
  {
    v24.y1 = v25.y1 + v9;
    v24.x1 = v8 + v25.x1;
    v24.x2 = v25.x2 + v8;
    v24.y2 = v9 + v25.y2;
    if ( Scaleform::Render::Rect<long>::IntersectRect(&v24, &v23, &v30) )
    {
      v14 = context->pHAL->GetTextureManager(context->pHAL);
      v28[0] = v14->GetImageSwizzler(v14);
      v28[1] = 0;
      v28[2] = dest;
      memset(&v28[3], 0, 12);
      (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v28[0] + 4))(v28[0], v28);
      v15 = context->pHAL->GetTextureManager(context->pHAL);
      v16 = *psrc;
      v29[0] = v15->GetImageSwizzler(v15);
      v29[1] = 0;
      v29[2] = v16;
      memset(&v29[3], 0, 12);
      (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v29[0] + 4))(v29[0], v29);
      v17 = v23.y2 - 1;
      if ( v23.y2 - 1 >= v23.y1 )
      {
        v18 = v17 - v9;
        v27 = v23.x2 - 1;
        v21 = v17 - v9;
        do
        {
          (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v28[0] + 8))(v28[0], v28, v17);
          (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v29[0] + 8))(v29[0], v29, v18);
          v19 = v27;
          if ( v27 >= v23.x1 )
          {
            v20 = v27 - v33;
            do
            {
              (*(void (__thiscall **)(_DWORD, int *, _DWORD *, int))(*(_DWORD *)v29[0] + 20))(v29[0], &v22, v29, v20);
              if ( !v26->pSource.pObject->Transparent || !v26->pImage.pObject->Transparent )
                HIBYTE(v22) = -1;
              (*(void (__thiscall **)(_DWORD, _DWORD *, int, int))(*(_DWORD *)v28[0] + 12))(v28[0], v28, v19--, v22);
              --v20;
            }
            while ( v19 >= v23.x1 );
            v18 = v21;
          }
          --v17;
          v21 = --v18;
        }
        while ( v17 >= v23.y1 );
      }
    }
  }
}

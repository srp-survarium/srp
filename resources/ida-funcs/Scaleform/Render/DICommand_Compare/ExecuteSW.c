void __thiscall Scaleform::Render::DICommand_Compare::ExecuteSW(
        Scaleform::Render::DICommand_Compare *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v4; // ebp
  Scaleform::Render::ImageData *v5; // edi
  Scaleform::Render::TextureManager *v7; // eax
  int v8; // eax
  Scaleform::Render::TextureManager *v9; // eax
  int v10; // eax
  Scaleform::Render::TextureManager *v11; // eax
  Scaleform::Render::ImageData *v12; // esi
  unsigned int i; // edi
  unsigned int j; // esi
  char v15; // al
  char v16; // cl
  char v17; // dl
  char v18; // [esp+3Ch] [ebp-9Ah]
  char v19; // [esp+3Dh] [ebp-99h]
  Scaleform::Render::ImageData *v20; // [esp+3Eh] [ebp-98h]
  int v21; // [esp+3Eh] [ebp-98h]
  char v22; // [esp+43h] [ebp-93h]
  _BYTE v23[2]; // [esp+46h] [ebp-90h] BYREF
  char v24; // [esp+48h] [ebp-8Eh]
  char v25; // [esp+49h] [ebp-8Dh]
  _BYTE v26[2]; // [esp+4Ah] [ebp-8Ch] BYREF
  char v27; // [esp+4Ch] [ebp-8Ah]
  char v28; // [esp+4Dh] [ebp-89h]
  Scaleform::Render::DICommand_Compare *v29; // [esp+4Eh] [ebp-88h]
  _DWORD v30[6]; // [esp+52h] [ebp-84h] BYREF
  _DWORD v31[6]; // [esp+6Ah] [ebp-6Ch] BYREF
  _DWORD v32[6]; // [esp+82h] [ebp-54h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+9Ah] [ebp-3Ch] BYREF
  Scaleform::Render::ImagePlane v34; // [esp+AEh] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane v35; // [esp+C2h] [ebp-14h] BYREF

  v4 = *psrc;
  v5 = psrc[1];
  v29 = this;
  memset(&pplane, 0, sizeof(pplane));
  memset(&v34, 0, sizeof(v34));
  memset(&v35, 0, sizeof(v35));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &pplane);
  Scaleform::Render::ImageData::GetPlane(v4, 0, &v34);
  Scaleform::Render::ImageData::GetPlane(v5, 0, &v35);
  v7 = context->pHAL->GetTextureManager(context->pHAL);
  v8 = (int)v7->GetImageSwizzler(v7);
  v31[2] = dest;
  v31[0] = v8;
  v31[1] = 0;
  memset(&v31[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v8 + 4))(v8, v31);
  v9 = context->pHAL->GetTextureManager(context->pHAL);
  v20 = *psrc;
  v10 = (int)v9->GetImageSwizzler(v9);
  v30[2] = v20;
  v30[0] = v10;
  v30[1] = 0;
  memset(&v30[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v10 + 4))(v10, v30);
  v11 = context->pHAL->GetTextureManager(context->pHAL);
  v12 = psrc[1];
  v32[0] = v11->GetImageSwizzler(v11);
  v32[1] = 0;
  v32[2] = v12;
  memset(&v32[3], 0, 12);
  (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v32[0] + 4))(v32[0], v32);
  for ( i = 0; i < v4->pPlanes->Height; ++i )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v31[0] + 8))(v31[0], v31, i);
    (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v30[0] + 8))(v30[0], v30, i);
    (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v32[0] + 8))(v32[0], v32, i);
    for ( j = 0; j < v4->pPlanes->Width; ++j )
    {
      (*(void (__thiscall **)(_DWORD, _BYTE *, _DWORD *, unsigned int))(*(_DWORD *)v30[0] + 20))(v30[0], v26, v30, j);
      (*(void (__thiscall **)(_DWORD, _BYTE *, _DWORD *, unsigned int))(*(_DWORD *)v32[0] + 20))(v32[0], v23, v32, j);
      if ( v29->pSource.pObject->Transparent )
        v18 = v28;
      else
        v18 = -1;
      if ( v29->pImageCompare1.pObject->Transparent )
        v19 = v25;
      else
        v19 = -1;
      v15 = v27 - v24;
      v22 = v26[1] - v23[1];
      v16 = v18 - v19;
      if ( v27 == v24 && !v22 && v26[0] == v23[0] && v16 )
      {
        v15 = -1;
        v22 = -1;
        v17 = -1;
      }
      else
      {
        v17 = v26[0] - v23[0];
        v16 = -1;
      }
      BYTE2(v21) = v15;
      LOBYTE(v21) = v17;
      BYTE1(v21) = v22;
      HIBYTE(v21) = v16;
      (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int, int))(*(_DWORD *)v31[0] + 12))(v31[0], v31, j, v21);
    }
  }
}

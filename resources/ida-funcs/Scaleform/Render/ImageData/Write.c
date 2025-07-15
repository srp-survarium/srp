void __thiscall Scaleform::Render::ImageData::Write(
        Scaleform::Render::ImageData *this,
        unsigned int file,
        unsigned int version)
{
  unsigned int v3; // esi
  void (__thiscall *v4)(unsigned int, Scaleform::Render::ImageFormat *, int); // edx
  void (__thiscall *v6)(unsigned int, unsigned int *, int); // edx
  void (__thiscall *v7)(unsigned int, unsigned int *, int); // edx
  void (__thiscall *v8)(unsigned int, unsigned int *, int); // edx
  void (__thiscall *v9)(unsigned int, unsigned int *, int); // edx
  Scaleform::Render::ImagePlane *pPlanes; // eax
  void (__thiscall *v11)(unsigned int, unsigned int *, int); // edx
  int v12; // edi
  void (__thiscall *v13)(unsigned int, unsigned int *, int); // edx
  void (__thiscall *v14)(unsigned int, unsigned int *, int); // edx
  void (__thiscall *v15)(unsigned int, unsigned int *, int); // edx
  unsigned int i; // ebp
  void (__thiscall *v17)(unsigned int, unsigned int *, int); // edx
  Scaleform::Render::Palette *pObject; // eax
  void (__thiscall *v19)(unsigned int, unsigned int *, int); // edx
  unsigned int v20; // edi
  void (__thiscall *v21)(unsigned int, unsigned int *, int); // edx
  Scaleform::Render::Palette *v22; // eax
  int v23; // ebp
  unsigned int v24; // edx
  int v25; // eax
  Scaleform::Render::ImageFormat Format; // [esp+58h] [ebp-4h] BYREF

  v3 = file;
  v4 = *(void (__thiscall **)(unsigned int, Scaleform::Render::ImageFormat *, int))(*(_DWORD *)file + 36);
  Format = this->Format;
  v4(file, &Format, 4);
  v6 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
  file = this->Use;
  v6(v3, &file, 4);
  v7 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
  LOBYTE(file) = this->Flags;
  v7(v3, &file, 1);
  v8 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
  LOBYTE(file) = this->LevelCount;
  v8(v3, &file, 1);
  v9 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
  file = this->RawPlaneCount;
  v9(v3, &file, 2);
  Format = Image_None;
  if ( this->RawPlaneCount )
  {
    pPlanes = this->pPlanes;
    do
    {
      v11 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
      v12 = (unsigned __int16)Format;
      file = pPlanes[v12].Width;
      v11(v3, &file, 4);
      v13 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
      file = this->pPlanes[v12].Height;
      v13(v3, &file, 4);
      v14 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
      file = this->pPlanes[v12].Pitch;
      v14(v3, &file, 4);
      v15 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
      file = this->pPlanes[v12].DataSize;
      v15(v3, &file, 4);
      pPlanes = this->pPlanes;
      for ( i = 0; i < pPlanes[v12].DataSize; ++i )
      {
        v17 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
        LOBYTE(file) = pPlanes[v12].pData[i];
        v17(v3, &file, 1);
        pPlanes = this->pPlanes;
      }
      ++Format;
    }
    while ( (unsigned __int16)Format < this->RawPlaneCount );
  }
  pObject = this->pPalette.pObject;
  v19 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
  v20 = 0;
  if ( pObject )
  {
    file = pObject->ColorCount;
    v19(v3, &file, 2);
    v21 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v3 + 36);
    LOBYTE(file) = this->pPalette.pObject->HasAlphaFlag;
    v21(v3, &file, 1);
    v22 = this->pPalette.pObject;
    if ( v22->ColorCount )
    {
      v23 = 8;
      do
      {
        v24 = *(volatile int *)((char *)&v22->RefCount.Value + v23);
        v25 = *(_DWORD *)v3;
        file = v24;
        (*(void (__thiscall **)(unsigned int, unsigned int *, int))(v25 + 36))(v3, &file, 4);
        v22 = this->pPalette.pObject;
        ++v20;
        v23 += 4;
      }
      while ( v20 < v22->ColorCount );
    }
  }
  else
  {
    file = 0;
    v19(v3, &file, 2);
  }
}

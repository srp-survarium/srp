// local variable allocation has failed, the output may be wrong!
char __thiscall Scaleform::Render::TGA::TGAFileImageSource::ReadHeader(
        Scaleform::Render::TGA::TGAFileImageSource *this,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::File *pObject; // ecx
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::File *v5; // ecx
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v7; // ecx
  int (__thiscall *v8)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::File *v9; // ecx
  int (__thiscall *v10)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v11; // edi
  Scaleform::File *v12; // ecx
  int (__thiscall *v13)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::File *v14; // ecx
  int (__thiscall *v15)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v16; // ebp
  Scaleform::File *v17; // ecx
  int (__thiscall *v18)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::File *v19; // ecx
  int (__thiscall *v20)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v21; // ecx
  int (__thiscall *v22)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::File *v23; // ecx
  int (__thiscall *v24)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v25; // ecx
  int (__thiscall *v26)(Scaleform::File *, unsigned __int8 *, int); // eax
  int v27; // eax
  unsigned int v28; // edx
  Scaleform::File *v30; // ecx
  int (__thiscall *v31)(Scaleform::File *, unsigned __int8 *, int); // eax
  unsigned __int8 v32; // al
  Scaleform::Render::ImageFormat SourceFormat; // eax
  int v34; // edi
  Scaleform::MemoryHeap *v35; // eax
  Scaleform::Render::Palette *v36; // ebp
  Scaleform::MemoryHeap *v37; // eax
  int v38; // ebp
  Scaleform::File *v39; // ecx
  int (__thiscall *v40)(Scaleform::File *, unsigned __int8 *, int); // edx
  char *v41; // edi
  Scaleform::File *v42; // ecx
  int (__thiscall *v43)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::File *v44; // ecx
  int (__thiscall *v45)(Scaleform::File *, unsigned __int8 *, int); // edx
  char v46; // cl
  char v47; // dl
  Scaleform::File *v48; // ecx
  int (__thiscall *v49)(Scaleform::File *, unsigned __int8 *, int); // eax
  unsigned __int8 v50; // [esp+7Eh] [ebp-10h] BYREF
  unsigned __int8 v51; // [esp+7Fh] [ebp-Fh] BYREF
  char v52; // [esp+80h] [ebp-Eh] BYREF
  char v53; // [esp+81h] [ebp-Dh] BYREF
  int v54; // [esp+82h] [ebp-Ch] BYREF
  int colorMapHasAlpha; // [esp+86h] [ebp-8h] OVERLAPPED BYREF
  int v56; // [esp+8Ah] [ebp-4h] BYREF

  pObject = this->pFile.pObject;
  Read = pObject->Read;
  v52 = 0;
  Read(pObject, (unsigned __int8 *)&v52, 1);
  v5 = this->pFile.pObject;
  v6 = v5->Read;
  v50 = 0;
  v6(v5, &v50, 1);
  v7 = this->pFile.pObject;
  v8 = v7->Read;
  v51 = 0;
  v8(v7, &v51, 1);
  v9 = this->pFile.pObject;
  v10 = v9->Read;
  v11 = v51;
  v56 = 0;
  v10(v9, (unsigned __int8 *)&v56, 2);
  v12 = this->pFile.pObject;
  v13 = v12->Read;
  v56 = 0;
  v13(v12, (unsigned __int8 *)&v56, 2);
  v14 = this->pFile.pObject;
  v15 = v14->Read;
  v51 = 0;
  v15(v14, &v51, 1);
  v16 = v51;
  if ( v51 && v51 != 24 && v51 != 32 )
    return 0;
  v17 = this->pFile.pObject;
  v18 = v17->Read;
  colorMapHasAlpha = 0;
  v18(v17, (unsigned __int8 *)&colorMapHasAlpha, 2);
  v19 = this->pFile.pObject;
  v20 = v19->Read;
  colorMapHasAlpha = 0;
  v20(v19, (unsigned __int8 *)&colorMapHasAlpha, 2);
  v21 = this->pFile.pObject;
  v22 = v21->Read;
  v54 = 0;
  v22(v21, (unsigned __int8 *)&v54, 2);
  v23 = this->pFile.pObject;
  v24 = v23->Read;
  colorMapHasAlpha = 0;
  v24(v23, (unsigned __int8 *)&colorMapHasAlpha, 2);
  v25 = this->pFile.pObject;
  v26 = v25->Read;
  v53 = 0;
  v26(v25, (unsigned __int8 *)&v53, 1);
  v27 = v50;
  v28 = (unsigned __int16)colorMapHasAlpha;
  this->Size.Width = (unsigned __int16)v54;
  this->Size.Height = v28;
  if ( v27 )
  {
    if ( v27 != 1 || v11 != 1 )
      return 0;
  }
  else if ( v11 != 2 )
  {
    return 0;
  }
  v30 = this->pFile.pObject;
  v31 = v30->Read;
  v51 = 0;
  v31(v30, &v51, 1);
  v32 = v52;
  this->ImageDesc = v51;
  if ( v32 )
    this->pFile.pObject->SkipBytes(this->pFile.pObject, v32);
  switch ( v53 )
  {
    case 8:
      this->SourceFormat = Image_P8;
      break;
    case 24:
      this->SourceFormat = Image_B8G8R8;
      break;
    case 32:
      this->SourceFormat = Image_B8G8R8A8;
      break;
    default:
      return 0;
  }
  if ( this->Format == Image_None )
  {
    SourceFormat = this->SourceFormat;
    if ( SourceFormat == Image_P8 )
      SourceFormat = v16 < 0x20 ? Image_B8G8R8 : Image_B8G8R8A8;
    this->Format = SourceFormat;
  }
  if ( v50 == 1 )
  {
    v34 = (unsigned __int16)v56;
    LOBYTE(colorMapHasAlpha) = v16 == 32;
    v35 = (Scaleform::MemoryHeap *)Scaleform::Render::Palette::Create((unsigned __int16)v56, v16 == 32, pheap);
    v36 = this->pColorMap.pObject;
    pheap = v35;
    if ( v36 && InterlockedExchangeAdd(&v36->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v36);
    v37 = pheap;
    this->pColorMap.pObject = (Scaleform::Render::Palette *)pheap;
    if ( !v37 )
      return 0;
    if ( v34 )
    {
      v38 = 8;
      v56 = v34;
      do
      {
        v39 = this->pFile.pObject;
        v40 = v39->Read;
        v41 = (char *)this->pColorMap.pObject + v38;
        v52 = 0;
        v40(v39, (unsigned __int8 *)&v52, 1);
        v42 = this->pFile.pObject;
        v43 = v42->Read;
        v53 = 0;
        v43(v42, (unsigned __int8 *)&v53, 1);
        v44 = this->pFile.pObject;
        v45 = v44->Read;
        LOBYTE(pheap) = 0;
        v45(v44, (unsigned __int8 *)&pheap, 1);
        v46 = v53;
        v47 = v52;
        v41[2] = (char)pheap;
        v41[1] = v46;
        *v41 = v47;
        v41[3] = -1;
        if ( (_BYTE)colorMapHasAlpha )
        {
          v48 = this->pFile.pObject;
          v49 = v48->Read;
          LOBYTE(pheap) = 0;
          v49(v48, (unsigned __int8 *)&pheap, 1);
          v41[3] = (char)pheap;
        }
        v38 += 4;
        --v56;
      }
      while ( v56 );
    }
  }
  this->FilePos = this->pFile.pObject->LTell(this->pFile.pObject);
  return 1;
}

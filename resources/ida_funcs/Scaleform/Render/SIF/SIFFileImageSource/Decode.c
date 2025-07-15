bool __thiscall Scaleform::Render::SIF::SIFFileImageSource::Decode(
        Scaleform::Render::SIF::SIFFileImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  bool result; // al
  Scaleform::Render::ImageData *v6; // edi
  Scaleform::File *pObject; // ecx
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v9; // ebx
  Scaleform::File *v10; // ecx
  int (__thiscall *v11)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::Render::ImagePlane *pPlanes; // ecx
  Scaleform::Render::ImageData *DataSize; // eax
  unsigned int v14; // ebp
  Scaleform::File *v15; // ecx
  int (__thiscall *v16)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v17; // ecx
  int (__thiscall *v18)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v19; // ecx
  int (__thiscall *v20)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::File *v21; // ecx
  int (__thiscall *v22)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::File *v23; // ecx
  int (__thiscall *v24)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::Render::ImagePlane *v25; // eax
  int v26; // ebp
  Scaleform::File *v27; // ecx
  int (__thiscall *v28)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::File *v29; // ecx
  int (__thiscall *v30)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned __int16 v31; // bp
  Scaleform::File *v32; // ecx
  int (__thiscall *v33)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::Render::Palette *v34; // eax
  Scaleform::Render::Palette *v35; // ebp
  Scaleform::Render::ImageData *v36; // eax
  int v37; // ebp
  Scaleform::File *v38; // ecx
  int (__thiscall *v39)(Scaleform::File *, unsigned __int8 *, int); // eax
  Scaleform::Render::Palette *v40; // esi
  int i; // [esp+58h] [ebp-8h] BYREF
  int v42; // [esp+5Ch] [ebp-4h] BYREF

  result = Scaleform::Render::FileImageSource::seekFileToDecodeStart(this);
  if ( result )
  {
    v6 = pdest;
    pdest->Flags |= this->HeaderInfo.Flags;
    pObject = this->pFile.pObject;
    Read = pObject->Read;
    v9 = 0;
    i = 0;
    Read(pObject, (unsigned __int8 *)&i, 4);
    v10 = this->pFile.pObject;
    v11 = v10->Read;
    pdest = 0;
    v11(v10, (unsigned __int8 *)&pdest, 4);
    pPlanes = v6->pPlanes;
    DataSize = (Scaleform::Render::ImageData *)pPlanes->DataSize;
    if ( DataSize != pdest || pPlanes->Pitch != i )
      return 0;
    v14 = 0;
    if ( DataSize )
    {
      do
      {
        v15 = this->pFile.pObject;
        v16 = v15->Read;
        LOBYTE(pdest) = 0;
        v16(v15, (unsigned __int8 *)&pdest, 1);
        v6->pPlanes->pData[v14++] = (unsigned __int8)pdest;
      }
      while ( v14 < v6->pPlanes->DataSize );
    }
    i = 1;
    if ( v6->RawPlaneCount <= 1u )
    {
LABEL_12:
      v29 = this->pFile.pObject;
      v30 = v29->Read;
      i = 0;
      v30(v29, (unsigned __int8 *)&i, 2);
      v31 = i;
      if ( (_WORD)i )
      {
        v32 = this->pFile.pObject;
        v33 = v32->Read;
        LOBYTE(pdest) = 0;
        v33(v32, (unsigned __int8 *)&pdest, 1);
        v42 = v31;
        v34 = Scaleform::Render::Palette::Create(v31, (_BYTE)pdest != 0, 0);
        v35 = v34;
        if ( v34 )
          InterlockedExchangeAdd(&v34->RefCount.Value, 1);
        v36 = (Scaleform::Render::ImageData *)v6->pPalette.pObject;
        pdest = v36;
        if ( v36 && InterlockedExchangeAdd((volatile LONG *)v36, -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pdest);
        v6->pPalette.pObject = v35;
        if ( (_WORD)i )
        {
          v37 = 8;
          do
          {
            v38 = this->pFile.pObject;
            v39 = v38->Read;
            pdest = 0;
            v39(v38, (unsigned __int8 *)&pdest, 4);
            *(volatile int *)((char *)&v6->pPalette.pObject->RefCount.Value + v37) = (volatile int)pdest;
            v37 += 4;
            --v42;
          }
          while ( v42 );
          return 1;
        }
      }
      else
      {
        v40 = v6->pPalette.pObject;
        if ( v40 && InterlockedExchangeAdd(&v40->RefCount.Value, -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v40);
        v6->pPalette.pObject = 0;
      }
      return 1;
    }
    while ( 1 )
    {
      v17 = this->pFile.pObject;
      v18 = v17->Read;
      pdest = 0;
      v18(v17, (unsigned __int8 *)&pdest, 4);
      v19 = this->pFile.pObject;
      v20 = v19->Read;
      pdest = 0;
      v20(v19, (unsigned __int8 *)&pdest, 4);
      v21 = this->pFile.pObject;
      v22 = v21->Read;
      v42 = 0;
      v22(v21, (unsigned __int8 *)&v42, 4);
      v23 = this->pFile.pObject;
      v24 = v23->Read;
      pdest = 0;
      v24(v23, (unsigned __int8 *)&pdest, 4);
      v25 = v6->pPlanes;
      if ( (Scaleform::Render::ImageData *)v25->DataSize != pdest || v25->Pitch != v42 )
        return 0;
      v26 = (unsigned __int16)i;
      if ( v25[v26].DataSize )
      {
        do
        {
          v27 = this->pFile.pObject;
          v28 = v27->Read;
          LOBYTE(pdest) = 0;
          v28(v27, (unsigned __int8 *)&pdest, 1);
          v6->pPlanes[v26].pData[v9++] = (unsigned __int8)pdest;
        }
        while ( v9 < v6->pPlanes[v26].DataSize );
      }
      v9 = 0;
      if ( (unsigned __int16)++i >= v6->RawPlaneCount )
        goto LABEL_12;
    }
  }
  return result;
}

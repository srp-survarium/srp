void __thiscall Scaleform::GFx::ExporterInfoImpl::ReadExporterInfoTag(
        Scaleform::GFx::ExporterInfoImpl *this,
        Scaleform::String pin,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::Stream *pData; // esi
  signed int v4; // eax
  unsigned int v5; // ebx
  unsigned int Pos; // eax
  int v7; // ebp
  unsigned int v8; // eax
  int v9; // ecx
  unsigned int v10; // edx
  int v11; // eax
  int v12; // edx
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned __int16 v16; // cx
  int v17; // ecx
  unsigned int v18; // ecx
  unsigned int v19; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object *v20; // edi
  unsigned int v21; // ebx
  Scaleform::GFx::FileTypeConstants::FileFormatType v22; // edi
  void *v23; // esi
  void *v24; // esi
  Scaleform::String pstr; // [esp+10h] [ebp-24h] BYREF
  int v26; // [esp+14h] [ebp-20h]
  unsigned int v27; // [esp+18h] [ebp-1Ch]
  int v28; // [esp+1Ch] [ebp-18h]
  int v29; // [esp+20h] [ebp-14h]
  Scaleform::GFx::ExporterInfoImpl *v30; // [esp+24h] [ebp-10h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+28h] [ebp-Ch] BYREF

  pData = (Scaleform::GFx::Stream *)pin.pData;
  v4 = pin.pData[4].Size - *(_DWORD *)pin.pData[3].Data;
  v5 = 0;
  v30 = this;
  v27 = 0;
  pin.pData[1].Data[1] = 0;
  if ( v4 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pData, 2);
  Pos = pData->Pos;
  v7 = (unsigned __int16)(pData->pBuffer[Pos] | (pData->pBuffer[Pos + 1] << 8));
  v8 = Pos + 2;
  v28 = v7;
  pData->Pos = v8;
  if ( (unsigned __int16)v7 >= 0x10Au )
  {
    v9 = pData->DataSize - v8;
    pData->UnusedBits = 0;
    if ( v9 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(pData, 4);
    v10 = pData->Pos;
    v11 = pData->pBuffer[v10] | ((pData->pBuffer[v10 + 1] | (*(unsigned __int16 *)&pData->pBuffer[v10 + 2] << 8)) << 8);
    pData->Pos = v10 + 4;
    v27 = v11;
  }
  v12 = pData->DataSize - pData->Pos;
  pData->UnusedBits = 0;
  if ( v12 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pData, 2);
  v13 = pData->Pos;
  v29 = *(unsigned __int16 *)&pData->pBuffer[v13];
  pData->Pos = v13 + 2;
  Scaleform::String::String(&pstr);
  Scaleform::String::String(&pin);
  Scaleform::GFx::Stream::ReadStringWithLength(pData, &pstr);
  Scaleform::GFx::Stream::ReadStringWithLength(pData, &pin);
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  if ( (unsigned __int16)v7 >= 0x401u )
  {
    v14 = pData->DataSize - pData->Pos;
    pData->UnusedBits = 0;
    if ( v14 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pData, 2);
    v15 = pData->Pos;
    v16 = *(_WORD *)&pData->pBuffer[v15];
    pData->Pos = v15 + 2;
    if ( v16 )
    {
      v26 = v16;
      do
      {
        v17 = pData->DataSize - pData->Pos;
        pData->UnusedBits = 0;
        if ( v17 < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(pData, 4);
        v18 = pData->Pos;
        v19 = v5 + 1;
        v20 = (Scaleform::GFx::AS3::Instances::fl::Object *)(pData->pBuffer[v18]
                                                           | ((pData->pBuffer[v18 + 1]
                                                             | (*(unsigned __int16 *)&pData->pBuffer[v18 + 2] << 8)) << 8));
        pData->Pos = v18 + 4;
        if ( v5 + 1 >= v5 )
        {
          if ( v19 >= pheapAddr.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              v19 + (v19 >> 2));
        }
        else if ( v19 < pheapAddr.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v5 + 1);
        }
        ++v5;
        pheapAddr.Size = v19;
        if ( &pheapAddr.Data[v19] != (Scaleform::GFx::AS3::Instances::fl::Object **)4 )
          pheapAddr.Data[v19 - 1] = v20;
        --v26;
      }
      while ( v26 );
      LOWORD(v7) = v28;
    }
  }
  v21 = v27;
  v22 = (unsigned __int16)v29;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    pData,
    "  ExportInfo: tagType = %d, tool ver = %d.%d, imgfmt = %d, prefix = '%s', swfname = '%s', flags = 0x%X\n",
    tagType,
    BYTE1(v7),
    (unsigned __int8)v7,
    (unsigned __int16)v29,
    (const char *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const char *)((pin.HeapTypeBits & 0xFFFFFFFC) + 8),
    v27);
  Scaleform::GFx::ExporterInfoImpl::SetData(
    v30,
    v7,
    v22,
    (const __m128i *)((pin.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const __m128i *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
    v21,
    (const Scaleform::Array<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr);
  if ( pheapAddr.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
  v23 = (void *)(pin.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pin.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
  v24 = (void *)(pstr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v24);
}

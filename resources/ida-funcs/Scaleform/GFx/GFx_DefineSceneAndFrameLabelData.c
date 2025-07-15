void __stdcall Scaleform::GFx::GFx_DefineSceneAndFrameLabelData(
        Scaleform::GFx::MovieDataDef::SceneInfo *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::Stream *Size; // ebx
  unsigned int v4; // ebp
  unsigned int v5; // edi
  void *v6; // edi
  unsigned int v7; // edi
  Scaleform::GFx::MovieDataDef::SceneInfo *Scene; // eax
  unsigned int v9; // edi
  unsigned int v10; // ebp
  Scaleform::GFx::MovieDataDef::SceneInfo *i; // eax
  unsigned int Offset; // ecx
  void *v13; // ebp
  unsigned int v14; // [esp+8h] [ebp-14h]
  Scaleform::StringDH v15; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::StringDH v16; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::MovieDataDef::SceneInfo *VU32; // [esp+20h] [ebp+4h]
  Scaleform::GFx::MovieDataDef::SceneInfo *v18; // [esp+20h] [ebp+4h]

  if ( !*(_DWORD *)(p[1].Name.HeapTypeBits + 320) )
  {
    Size = (Scaleform::GFx::Stream *)p[26].Labels.Data.Size;
    if ( !Size )
      Size = (Scaleform::GFx::Stream *)&p[1].Labels;
    VU32 = (Scaleform::GFx::MovieDataDef::SceneInfo *)Scaleform::GFx::Stream::ReadVU32(Size);
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->Labels.Data.Size,
      "  Scene and Frame Label Data, numscenes = %d\n",
      VU32);
    v4 = 0;
    if ( VU32 )
    {
      do
      {
        v5 = Scaleform::GFx::Stream::ReadVU32(Size);
        Scaleform::StringDH::StringDH(&v15, *(Scaleform::MemoryHeap **)(p[1].Name.HeapTypeBits + 28));
        Scaleform::GFx::Stream::ReadString(Size, &v15);
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
          (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->Labels.Data.Size,
          "   Scene[%d] = { %d, \"%s\" }\n",
          v4,
          v5,
          (const char *)((v15.HeapTypeBits & 0xFFFFFFFC) + 8));
        Scaleform::GFx::MovieDataDef::LoadTaskData::AddScene(
          (Scaleform::GFx::MovieDataDef::LoadTaskData *)p[1].Name.pData,
          &v15,
          v5);
        v6 = (void *)(v15.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v15.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
        ++v4;
      }
      while ( v4 < (unsigned int)VU32 );
    }
    v7 = Scaleform::GFx::Stream::ReadVU32(Size);
    v15.HeapTypeBits = v7;
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->Labels.Data.Size,
      "  frameLabelCount = %d\n",
      v7);
    Scene = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScene(
              (Scaleform::GFx::MovieDataDef::LoadTaskData *)p[1].Name.pData,
              0);
    v18 = Scene;
    v14 = 0;
    if ( v7 )
    {
      v9 = 1;
      do
      {
        v10 = Scaleform::GFx::Stream::ReadVU32(Size);
        Scaleform::StringDH::StringDH(&v16, *(Scaleform::MemoryHeap **)(p[1].Name.HeapTypeBits + 28));
        Scaleform::GFx::Stream::ReadString(Size, &v16);
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
          (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->Labels.Data.Size,
          "   Label[%d] = { %d, \"%s\" }\n",
          v14,
          v10,
          (const char *)((v16.HeapTypeBits & 0xFFFFFFFC) + 8));
        for ( i = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScene(
                    (Scaleform::GFx::MovieDataDef::LoadTaskData *)p[1].Name.pData,
                    v9);
              i;
              i = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScene(
                    (Scaleform::GFx::MovieDataDef::LoadTaskData *)p[1].Name.pData,
                    v9) )
        {
          Offset = i->Offset;
          if ( v10 < Offset )
            break;
          v18->NumFrames = Offset;
          ++v9;
          v18 = i;
        }
        Scaleform::GFx::MovieDataDef::SceneInfo::AddFrameLabel(v18, &v16, v10);
        v13 = (void *)(v16.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v16.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
        ++v14;
      }
      while ( v14 < v15.HeapTypeBits );
      Scene = v18;
    }
    Scene->NumFrames = *(_DWORD *)(p[1].Name.HeapTypeBits + 84) - Scene->Offset;
  }
}

void __stdcall Scaleform::GFx::GFx_DefineSceneAndFrameLabelData(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ebx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // ecx
  unsigned int j; // ebp
  unsigned int VU32; // edi
  void *v7; // edi
  unsigned int v8; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // ecx
  Scaleform::GFx::MovieDataDef::SceneInfo *Scene; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebp
  Scaleform::GFx::MovieDataDef::SceneInfo *k; // eax
  unsigned int Offset; // ecx
  void *v15; // ebp
  unsigned int i; // [esp+8h] [ebp-14h]
  Scaleform::StringDH name; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::StringDH label; // [esp+14h] [ebp-8h] BYREF
  unsigned int sceneCount; // [esp+20h] [ebp+4h]
  Scaleform::GFx::MovieDataDef::SceneInfo *sceneCounta; // [esp+20h] [ebp+4h]

  if ( !p->pLoadData.pObject->Scenes.pObject )
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !pAltStream )
      pAltStream = &p->ProcessInfo;
    sceneCount = Scaleform::GFx::Stream::ReadVU32(&pAltStream->Stream);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v4);
    for ( j = 0; j < sceneCount; ++j )
    {
      VU32 = Scaleform::GFx::Stream::ReadVU32(&pAltStream->Stream);
      Scaleform::StringDH::StringDH(&name, p->pLoadData.pObject->pHeap);
      Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &name);
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)((name.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::MovieDataDef::LoadTaskData::AddScene(p->pLoadData.pObject, &name, VU32);
      v7 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
    }
    v8 = Scaleform::GFx::Stream::ReadVU32(&pAltStream->Stream);
    name.HeapTypeBits = v8;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v9);
    Scene = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScene(p->pLoadData.pObject, 0);
    sceneCounta = Scene;
    i = 0;
    if ( v8 )
    {
      v11 = 1;
      do
      {
        v12 = Scaleform::GFx::Stream::ReadVU32(&pAltStream->Stream);
        Scaleform::StringDH::StringDH(&label, p->pLoadData.pObject->pHeap);
        Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &label);
        Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)((label.HeapTypeBits & 0xFFFFFFFC) + 8));
        for ( k = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScene(p->pLoadData.pObject, v11);
              k;
              k = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScene(p->pLoadData.pObject, v11) )
        {
          Offset = k->Offset;
          if ( v12 < Offset )
            break;
          sceneCounta->NumFrames = Offset;
          ++v11;
          sceneCounta = k;
        }
        Scaleform::GFx::MovieDataDef::SceneInfo::AddFrameLabel(sceneCounta, &label, v12);
        v15 = (void *)(label.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((label.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
        ++i;
      }
      while ( i < name.HeapTypeBits );
      Scene = sceneCounta;
    }
    Scene->NumFrames = p->pLoadData.pObject->Header.FrameCount - Scene->Offset;
  }
}

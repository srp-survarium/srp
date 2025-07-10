void __stdcall Scaleform::GFx::GFx_FrameLabelLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v3; // ecx
  void *v4; // esi
  Scaleform::GFx::LogState *pObject; // [esp+0h] [ebp-10h]
  Scaleform::StringDH name; // [esp+8h] [ebp-8h] BYREF

  Scaleform::StringDH::StringDH(&name, p->pLoadData.pObject->pHeap);
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &name);
  pObject = p->pLoadStates.pObject->pLog.pObject;
  if ( p->LoadState == LS_LoadingSprite )
    ((void (__stdcall *)(Scaleform::StringDH *, Scaleform::GFx::LogState *))p->pTimelineDef->AddFrameName)(
      &name,
      pObject);
  else
    ((void (__stdcall *)(Scaleform::StringDH *, Scaleform::GFx::LogState *))p->pLoadData.pObject->AddFrameName)(
      &name,
      pObject);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v3);
  v4 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
}

void __stdcall Scaleform::GFx::GFx_FrameLabelLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ecx
  void *v3; // esi
  Scaleform::GFx::LogState *pObject; // [esp+0h] [ebp-10h]
  Scaleform::StringDH v5; // [esp+8h] [ebp-8h] BYREF

  Scaleform::StringDH::StringDH(&v5, p->pLoadData.pObject->pHeap);
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &v5);
  pObject = p->pLoadStates.pObject->pLog.pObject;
  if ( p->LoadState == LS_LoadingSprite )
    ((void (__stdcall *)(Scaleform::StringDH *, Scaleform::GFx::LogState *))p->pTimelineDef->AddFrameName)(&v5, pObject);
  else
    ((void (__stdcall *)(Scaleform::StringDH *, Scaleform::GFx::LogState *))p->pLoadData.pObject->AddFrameName)(
      &v5,
      pObject);
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  Frame label: \"%s\"\n",
    (const char *)((v5.HeapTypeBits & 0xFFFFFFFC) + 8));
  v3 = (void *)(v5.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v5.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
}

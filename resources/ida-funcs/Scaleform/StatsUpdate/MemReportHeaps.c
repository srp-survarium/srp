void __thiscall Scaleform::StatsUpdate::MemReportHeaps(
        Scaleform::StatsUpdate *this,
        Scaleform::MemoryHeap *pHeap,
        Scaleform::MemItem *rootItem,
        Scaleform::MemoryHeap::MemReportType reportType)
{
  bool (__thiscall *GetStats)(Scaleform::MemoryHeap *, Scaleform::StatBag *); // edx
  unsigned int NextHandle; // ecx
  Scaleform::String::DataDesc *pData; // eax
  Scaleform::StringLH *v8; // ebp
  unsigned int i; // esi
  void *v10; // esi
  Scaleform::String v11; // [esp+14h] [ebp-24Ch] BYREF
  Scaleform::MemoryHeap::HeapVisitor visitor; // [esp+18h] [ebp-248h] BYREF
  Scaleform::MemoryHeap **v13; // [esp+1Ch] [ebp-244h]
  unsigned int v14; // [esp+20h] [ebp-240h]
  int v15; // [esp+24h] [ebp-23Ch]
  Scaleform::StatInfo v16; // [esp+28h] [ebp-238h] BYREF
  char *pName; // [esp+34h] [ebp-22Ch] BYREF
  _DWORD v18[2]; // [esp+38h] [ebp-228h] BYREF
  unsigned int v19; // [esp+40h] [ebp-220h]
  Scaleform::MsgFormat::Sink v20; // [esp+48h] [ebp-218h] BYREF
  Scaleform::StatBag v21; // [esp+54h] [ebp-20Ch] BYREF

  if ( (pHeap->Info.Desc.Flags & 0x1000) == 0 && pHeap->GetFootprint(pHeap) )
  {
    Scaleform::StatBag::StatBag(&v21, 0, 0x2000u);
    GetStats = pHeap->GetStats;
    memset(&v16, 0, sizeof(v16));
    v18[0] = 0;
    v18[1] = uri;
    v19 = 0;
    GetStats(pHeap, &v21);
    Scaleform::StatBag::GetStat(&v21, &v16, 0x11u);
    v16.pInterface->GetStat(v16.pInterface, v16.pData, (Scaleform::Stat::StatValue *)v18, 0);
    Scaleform::String::String(&v11);
    pName = pHeap->Info.pName;
    v20.Type = tStr;
    v20.SinkData.pStr = &v11;
    Scaleform::Format<char const *>(&v20, "[Heap] {0}", (const char **)&pName);
    NextHandle = this->NextHandle;
    pData = v11.pData;
    ++this->NextHandle;
    v8 = Scaleform::MemItem::AddChild(
           rootItem,
           NextHandle,
           (const __m128i *)(((unsigned int)pData & 0xFFFFFFFC) + 8),
           v19);
    visitor.__vftable = (Scaleform::MemoryHeap::HeapVisitor_vtbl *)&Scaleform::StatsUpdate::HolderVisitor::`vftable';
    v13 = 0;
    v14 = 0;
    v15 = 0;
    Scaleform::MemoryHeap::VisitChildHeaps(pHeap, &visitor);
    for ( i = 0; i < v14; ++i )
      Scaleform::StatsUpdate::MemReportHeaps(this, v13[i], (Scaleform::MemItem *)v8, reportType);
    if ( v13 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
    v10 = (void *)(v11.HeapTypeBits & 0xFFFFFFFC);
    visitor.__vftable = (Scaleform::MemoryHeap::HeapVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    if ( InterlockedExchangeAdd((volatile LONG *)((v11.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
    Scaleform::StatBag::~StatBag(&v21);
  }
}

void __thiscall Scaleform::StatsUpdate::MemReportHeapsDetailed(
        Scaleform::StatsUpdate *this,
        Scaleform::MemItem *rootItem,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v4; // eax
  unsigned int NextHandle; // eax
  Scaleform::StringLH *v6; // ebp
  unsigned int v7; // eax
  Scaleform::MemItem *pObject; // edx
  Scaleform::StringLH *v9; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *v10; // esi
  unsigned int Size; // eax
  _DWORD *p_pObject; // ebx
  Scaleform::MemItem *v13; // ecx
  unsigned int v14; // eax
  _DWORD *v15; // ebx
  Scaleform::MemItem *v16; // ecx
  unsigned int v17; // eax
  _DWORD *v18; // ebx
  Scaleform::MemItem *v19; // ecx
  unsigned int v20; // eax
  _DWORD *v21; // ebx
  Scaleform::MemItem *v22; // ecx
  _DWORD *v23; // esi
  Scaleform::MemItem *v24; // ecx
  unsigned int v25; // eax
  unsigned int DebugInfoFootprint; // ecx
  Scaleform::MemItem **v27; // esi
  Scaleform::MemItem *v28; // ecx
  unsigned int v29; // [esp-Ch] [ebp-78h]
  unsigned int SysMemFootprint; // [esp-4h] [ebp-70h]
  unsigned int v33; // [esp-4h] [ebp-70h]
  Scaleform::StatsUpdate::HeapTreeCreator v34; // [esp+10h] [ebp-5Ch] BYREF

  v4 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, rootItem);
  Scaleform::StatsUpdate::HeapTreeCreator::HeapTreeCreator(&v34, v4, this, &this->NextHandle);
  Scaleform::MemoryHeap::LockAndVisit(heap, &v34);
  NextHandle = this->NextHandle;
  SysMemFootprint = v34.RootHeapStats.SysMemFootprint;
  ++this->NextHandle;
  v6 = Scaleform::MemItem::AddChild(rootItem, NextHandle, (const __m128i *)"Total Footprint", SysMemFootprint);
  BYTE1(v6[4].pData) = 1;
  v7 = this->NextHandle;
  pObject = v34.UsedSpaceRoot.pObject;
  ++this->NextHandle;
  v9 = Scaleform::MemItem::AddChild((Scaleform::MemItem *)v6, v7, (const __m128i *)"Used Space", pObject->Value);
  v10 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&v9[7];
  BYTE1(v9[4].pData) = 1;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&v9[7],
    &v9[7],
    v9[8].HeapTypeBits + 1);
  Size = v10->Size;
  p_pObject = &v10->Data[Size - 1].pObject;
  if ( &v10->Data[Size] != (Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *)4 )
  {
    v13 = v34.GlobalHeap.pObject;
    if ( v34.GlobalHeap.pObject )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v34.GlobalHeap.pObject);
      v13 = v34.GlobalHeap.pObject;
    }
    *p_pObject = v13;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v10,
    v10,
    v10->Size + 1);
  v14 = v10->Size;
  v15 = &v10->Data[v14 - 1].pObject;
  if ( &v10->Data[v14] != (Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *)4 )
  {
    v16 = v34.MovieDataRoot.pObject;
    if ( v34.MovieDataRoot.pObject )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v34.MovieDataRoot.pObject);
      v16 = v34.MovieDataRoot.pObject;
    }
    *v15 = v16;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v10,
    v10,
    v10->Size + 1);
  v17 = v10->Size;
  v18 = &v10->Data[v17 - 1].pObject;
  if ( &v10->Data[v17] != (Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *)4 )
  {
    v19 = v34.MovieViewRoot.pObject;
    if ( v34.MovieViewRoot.pObject )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v34.MovieViewRoot.pObject);
      v19 = v34.MovieViewRoot.pObject;
    }
    *v18 = v19;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v10,
    v10,
    v10->Size + 1);
  v20 = v10->Size;
  v21 = &v10->Data[v20 - 1].pObject;
  if ( &v10->Data[v20] != (Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *)4 )
  {
    v22 = v34.VideoRoot.pObject;
    if ( v34.VideoRoot.pObject )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v34.VideoRoot.pObject);
      v22 = v34.VideoRoot.pObject;
    }
    *v21 = v22;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v10,
    v10,
    v10->Size + 1);
  v23 = &v10->Data[v10->Size - 1].pObject;
  if ( v23 )
  {
    v24 = v34.OtherRoot.pObject;
    if ( v34.OtherRoot.pObject )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v34.OtherRoot.pObject);
      v24 = v34.OtherRoot.pObject;
    }
    *v23 = v24;
  }
  v25 = this->NextHandle;
  DebugInfoFootprint = v34.RootHeapStats.DebugInfoFootprint;
  ++this->NextHandle;
  Scaleform::MemItem::AddChild(
    (Scaleform::MemItem *)v6,
    v25,
    (const __m128i *)"Debug Data",
    DebugInfoFootprint + v34.RootHeapStats.UserDebugFootprint);
  if ( v34.RootHeapStats.PageMapFootprint + v34.RootHeapStats.BookkeepingFootprint )
  {
    v33 = v34.RootHeapStats.PageMapFootprint + v34.RootHeapStats.BookkeepingFootprint;
    v29 = this->NextHandle++;
    Scaleform::MemItem::AddChild((Scaleform::MemItem *)v6, v29, (const __m128i *)"Heap Overhead", v33);
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&v6[7],
    &v6[7],
    v6[8].HeapTypeBits + 1);
  v27 = (Scaleform::MemItem **)(v6[7].HeapTypeBits + 4 * v6[8].HeapTypeBits - 4);
  if ( v6[7].HeapTypeBits + 4 * v6[8].HeapTypeBits != 4 )
  {
    v28 = v34.UnusedSpaceRoot.pObject;
    if ( v34.UnusedSpaceRoot.pObject )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v34.UnusedSpaceRoot.pObject);
      v28 = v34.UnusedSpaceRoot.pObject;
    }
    *v27 = v28;
  }
  Scaleform::StatsUpdate::HeapTreeCreator::~HeapTreeCreator(&v34);
}

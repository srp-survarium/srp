void __thiscall Scaleform::Render::RenderSync::~RenderSync(Scaleform::Render::RenderSync *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *FirstPage; // eax
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *pNext; // esi
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v4; // eax
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v5; // esi
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *v6; // eax
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *v7; // esi

  this->__vftable = (Scaleform::Render::RenderSync_vtbl *)&Scaleform::Render::RenderSync::`vftable';
  Scaleform::Render::RenderSync::ReleaseOutstandingFrames(this);
  FirstPage = this->FenceAlloc.FirstPage;
  if ( FirstPage )
  {
    do
    {
      pNext = FirstPage->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, FirstPage);
      FirstPage = pNext;
    }
    while ( pNext );
  }
  v4 = this->FenceImplAlloc.FirstPage;
  if ( v4 )
  {
    do
    {
      v5 = v4->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
      v4 = v5;
    }
    while ( v5 );
  }
  v6 = this->FenceFrameAlloc.FirstPage;
  if ( v6 )
  {
    do
    {
      v7 = v6->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
      v6 = v7;
    }
    while ( v7 );
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

void __thiscall Scaleform::Render::RenderSync::BeginFrame(Scaleform::Render::RenderSync *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *v2; // eax
  unsigned int v3; // esi

  v2 = Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2>>::allocate(&this->FenceFrameAlloc);
  if ( v2 )
  {
    v2->Data[0].pPrev = 0;
    v2->Data[0].pNext = 0;
    v2->Data[0].WrappedAround = 0;
    v2->Data[0].Fences.Data.Data = 0;
    v2->Data[0].Fences.Data.Size = 0;
    v2->Data[0].Fences.Data.Policy.Capacity = 0;
    v2->Data[0].FrameEndFence.pObject = 0;
  }
  v2->Data[0].RSContext = this;
  v2->Data[0].pPrev = this->FenceFrames.Root.pPrev;
  v2->Data[0].pNext = (Scaleform::Render::FenceFrame *)&this->FenceFrames;
  this->FenceFrames.Root.pPrev->pNext = (Scaleform::Render::FenceFrame *)v2;
  this->FenceFrames.Root.pPrev = (Scaleform::Render::FenceFrame *)v2;
  v3 = ++this->OutstandingFrames;
  if ( !warned )
    warned = v3 >= 0x64;
}

void __thiscall Scaleform::Render::RenderSync::ReleaseOutstandingFrames(Scaleform::Render::RenderSync *this)
{
  Scaleform::Render::FenceFrame *pNext; // esi
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *p_FenceFrames; // ebp
  Scaleform::Render::FenceFrame *v4; // ebx

  pNext = this->FenceFrames.Root.pNext;
  p_FenceFrames = &this->FenceFrames;
  if ( pNext != (Scaleform::Render::FenceFrame *)&this->FenceFrames )
  {
    do
    {
      v4 = pNext->pNext;
      pNext->pPrev->pNext = v4;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::FenceFrame>::$5C9767EADF33BDEDA33A3838A8B3522A::pPrev = pNext->pPrev;
      Scaleform::Render::FenceFrame::~FenceFrame(pNext);
      pNext->pPrev = (Scaleform::Render::FenceFrame *)this->FenceFrameAlloc.FirstEmptySlot;
      this->FenceFrameAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)pNext;
      --this->OutstandingFrames;
      pNext = v4;
    }
    while ( v4 != (Scaleform::Render::FenceFrame *)p_FenceFrames );
  }
}

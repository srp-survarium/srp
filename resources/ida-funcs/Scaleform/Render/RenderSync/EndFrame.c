char __thiscall Scaleform::Render::RenderSync::EndFrame(Scaleform::Render::RenderSync *this)
{
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *p_FenceFrames; // ebx
  Scaleform::Render::FenceFrame *pPrev; // ebp
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *inserted; // eax
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *v6; // esi
  Scaleform::Render::Fence *pObject; // ecx
  Scaleform::Render::Fence *v8; // eax
  Scaleform::Render::FenceImpl *Data; // eax
  char v10; // al
  Scaleform::Render::FenceFrame *pNext; // esi
  Scaleform::Render::Fence *v12; // eax
  Scaleform::Render::FenceImpl *v13; // eax
  Scaleform::Render::FenceFrame *v14; // ebp
  Scaleform::Render::FenceFrame *i; // edi
  char v16; // [esp+19h] [ebp-1h]

  p_FenceFrames = &this->FenceFrames;
  if ( (Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *)this->FenceFrames.Root.pNext == &this->FenceFrames )
    return 0;
  pPrev = p_FenceFrames->Root.pPrev;
  inserted = Scaleform::Render::RenderSync::InsertFence(this);
  v6 = inserted;
  if ( inserted )
    ++inserted->Data[0].RefCount;
  pObject = pPrev->FrameEndFence.pObject;
  if ( pObject )
    Scaleform::Render::Fence::Release(pObject);
  pPrev->FrameEndFence.pObject = (Scaleform::Render::Fence *)v6;
  v8 = p_FenceFrames->Root.pPrev->FrameEndFence.pObject;
  if ( v8->HasData )
    Data = v8->Data;
  else
    Data = 0;
  v10 = ((int (__thiscall *)(Scaleform::Render::RenderSync *, _DWORD, _DWORD))this->CheckWraparound)(
          this,
          Data->APIHandle,
          HIDWORD(Data->APIHandle));
  pNext = this->FenceFrames.Root.pNext;
  v16 = v10;
  if ( pNext != p_FenceFrames->Root.pPrev )
  {
    do
    {
      v12 = pNext->FrameEndFence.pObject;
      if ( !v12 )
        break;
      if ( v12->HasData )
      {
        v13 = v12->Data;
        if ( v13 )
        {
          if ( v13->Parent
            && ((unsigned __int8 (__stdcall *)(int, _DWORD, _DWORD, Scaleform::Render::FenceFrame *))v13->RSContext->IsPending)(
                 1,
                 v13->APIHandle,
                 HIDWORD(v13->APIHandle),
                 v13->Parent) )
          {
            break;
          }
        }
      }
      v14 = pNext->pNext;
      pNext->pPrev->pNext = v14;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::FenceFrame>::$2031C420DC8AC57DF0822C542663F0D9::pPrev = pNext->pPrev;
      Scaleform::Render::FenceFrame::~FenceFrame(pNext);
      pNext->pPrev = (Scaleform::Render::FenceFrame *)this->FenceFrameAlloc.FirstEmptySlot;
      this->FenceFrameAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)pNext;
      --this->OutstandingFrames;
      pNext = v14;
    }
    while ( v14 != p_FenceFrames->Root.pPrev );
  }
  if ( v16 )
  {
    for ( i = this->FenceFrames.Root.pNext; i != (Scaleform::Render::FenceFrame *)p_FenceFrames; i = i->pNext )
      i->WrappedAround = 1;
  }
  return 1;
}

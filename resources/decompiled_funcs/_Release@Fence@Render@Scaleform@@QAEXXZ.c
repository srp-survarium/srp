void __thiscall Scaleform::Render::Fence::Release(Scaleform::Render::Fence *this)
{
  Scaleform::Render::FenceImpl *Data; // ecx
  Scaleform::Render::RenderSync *RSContext; // edi
  Scaleform::Render::FenceImpl *v4; // eax
  unsigned __int64 *p_APIHandle; // eax

  if ( !--this->RefCount )
  {
    if ( this->HasData )
    {
      Data = this->Data;
      RSContext = Data->RSContext;
      ((void (__thiscall *)(Scaleform::Render::FenceImpl *, _DWORD, _DWORD))Data->RSContext->FenceFrameAlloc.pHeapOrPtr)(
        Data,
        this->Data->APIHandle,
        HIDWORD(this->Data->APIHandle));
      v4 = this->Data;
      v4->RSContext = (Scaleform::Render::RenderSync *)RSContext->FenceImplAlloc.FirstEmptySlot;
      RSContext->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v4;
      this->Data = (Scaleform::Render::FenceImpl *)RSContext->FenceAlloc.FirstEmptySlot;
      RSContext->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)this;
    }
    else
    {
      p_APIHandle = &this->Data[2].APIHandle;
      this->Data = (Scaleform::Render::FenceImpl *)HIDWORD(this->Data[2].FenceID);
      *((_DWORD *)p_APIHandle + 3) = this;
    }
  }
}

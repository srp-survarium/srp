void __thiscall Scaleform::Render::FenceFrame::~FenceFrame(Scaleform::Render::FenceFrame *this)
{
  Scaleform::Render::FenceFrame *p_Fences; // edi
  int v3; // esi
  unsigned int Size; // eax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::Render::Fence>,2,Scaleform::ArrayConstPolicy<128,64,1> > *v5; // ebx
  int v6; // eax
  int v7; // eax
  Scaleform::Render::RenderSync *RSContext; // eax
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *v9; // ecx
  unsigned int Capacity; // eax
  Scaleform::Render::Fence *pObject; // esi
  Scaleform::Render::RenderSync *v12; // edi
  Scaleform::Render::FenceImpl *Data; // eax
  int p_APIHandle; // eax
  Scaleform::Render::Fence *v15; // ebp
  Scaleform::Render::RenderSync *v16; // esi
  Scaleform::Render::FenceImpl *v17; // eax
  int v18; // eax
  int v19; // [esp+10h] [ebp-4h] BYREF

  p_Fences = (Scaleform::Render::FenceFrame *)&this->Fences;
  v3 = 0;
  while ( 1 )
  {
    Size = this->Fences.Data.Size;
    v5 = &this->Fences;
    if ( p_Fences == (Scaleform::Render::FenceFrame *)&this->Fences && v3 == Size )
      break;
    v6 = *((_DWORD *)&p_Fences->pPrev->pPrev + v3);
    if ( *(_BYTE *)(v6 + 6) )
    {
      *(_BYTE *)(v6 + 6) = 0;
      v7 = **((_DWORD **)&p_Fences->pPrev->pPrev + v3);
      ((void (__thiscall *)(Scaleform::Render::RenderSync *, _DWORD, _DWORD))this->RSContext->ReleaseFence)(
        this->RSContext,
        *(_DWORD *)(v7 + 8),
        *(_DWORD *)(v7 + 12));
      RSContext = this->RSContext;
      v9 = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)**((_DWORD **)&p_Fences->pPrev->pPrev + v3);
      v9->pNext = RSContext->FenceImplAlloc.FirstEmptySlot;
      RSContext->FenceImplAlloc.FirstEmptySlot = v9;
      **((_DWORD **)&p_Fences->pPrev->pPrev + v3) = this->RSContext;
    }
    if ( v3 < (int)p_Fences->pNext )
      ++v3;
  }
  if ( Size )
  {
    Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::Render::Fence>>::DestructArray(
      v5->Data.Data,
      this->Fences.Data.Size);
    Capacity = this->Fences.Data.Policy.Capacity;
    if ( (Capacity & 0xFFFFFFFE) != 0 && !Capacity )
    {
      if ( v5->Data.Data )
      {
        v5->Data.Data = (Scaleform::Ptr<Scaleform::Render::Fence> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                      Scaleform::Memory::pGlobalHeap,
                                                                      v5->Data.Data,
                                                                      512);
      }
      else
      {
        v19 = 2;
        v5->Data.Data = (Scaleform::Ptr<Scaleform::Render::Fence> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                      Scaleform::Memory::pGlobalHeap,
                                                                      &this->Fences,
                                                                      512,
                                                                      &v19);
      }
      this->Fences.Data.Policy.Capacity = 128;
    }
  }
  else if ( !this->Fences.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1>>::Reserve(
      &this->Fences.Data,
      &this->Fences,
      0);
  }
  this->Fences.Data.Size = 0;
  pObject = this->FrameEndFence.pObject;
  if ( pObject )
  {
    if ( !--pObject->RefCount )
    {
      if ( pObject->HasData )
      {
        v12 = pObject->Data->RSContext;
        ((void (__stdcall *)(_DWORD, _DWORD))v12->FenceFrameAlloc.pHeapOrPtr)(
          pObject->Data->APIHandle,
          HIDWORD(pObject->Data->APIHandle));
        Data = pObject->Data;
        Data->RSContext = (Scaleform::Render::RenderSync *)v12->FenceImplAlloc.FirstEmptySlot;
        v12->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)Data;
        pObject->Data = (Scaleform::Render::FenceImpl *)v12->FenceAlloc.FirstEmptySlot;
        v12->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)pObject;
      }
      else
      {
        p_APIHandle = (int)&pObject->Data[2].APIHandle;
        pObject->Data = (Scaleform::Render::FenceImpl *)HIDWORD(pObject->Data[2].FenceID);
        *(_DWORD *)(p_APIHandle + 12) = pObject;
      }
    }
  }
  this->FrameEndFence.pObject = 0;
  v15 = this->FrameEndFence.pObject;
  if ( v15 )
  {
    if ( !--v15->RefCount )
    {
      if ( v15->HasData )
      {
        v16 = v15->Data->RSContext;
        ((void (__stdcall *)(_DWORD, _DWORD))v16->FenceFrameAlloc.pHeapOrPtr)(
          v15->Data->APIHandle,
          HIDWORD(v15->Data->APIHandle));
        v17 = v15->Data;
        v17->RSContext = (Scaleform::Render::RenderSync *)v16->FenceImplAlloc.FirstEmptySlot;
        v16->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v17;
        v15->Data = (Scaleform::Render::FenceImpl *)v16->FenceAlloc.FirstEmptySlot;
        v16->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v15;
      }
      else
      {
        v18 = (int)&v15->Data[2].APIHandle;
        v15->Data = (Scaleform::Render::FenceImpl *)HIDWORD(v15->Data[2].FenceID);
        *(_DWORD *)(v18 + 12) = v15;
      }
    }
  }
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::Render::Fence>>::DestructArray(v5->Data.Data, v5->Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5->Data.Data);
}

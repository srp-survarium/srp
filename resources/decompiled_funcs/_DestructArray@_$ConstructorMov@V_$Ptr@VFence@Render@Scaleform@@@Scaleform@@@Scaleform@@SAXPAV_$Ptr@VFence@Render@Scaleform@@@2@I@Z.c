void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::Render::Fence>>::DestructArray(
        Scaleform::Ptr<Scaleform::Render::Fence> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::Fence> *v2; // ebx
  unsigned int v3; // ebp
  Scaleform::Render::Fence *pObject; // esi
  Scaleform::Render::RenderSync *RSContext; // edi
  Scaleform::Render::FenceImpl *Data; // eax
  int p_APIHandle; // eax

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pObject;
      if ( v2->pObject )
      {
        if ( !--pObject->RefCount )
        {
          if ( pObject->HasData )
          {
            RSContext = pObject->Data->RSContext;
            ((void (__stdcall *)(_DWORD, _DWORD))RSContext->FenceFrameAlloc.pHeapOrPtr)(
              pObject->Data->APIHandle,
              HIDWORD(pObject->Data->APIHandle));
            Data = pObject->Data;
            Data->RSContext = (Scaleform::Render::RenderSync *)RSContext->FenceImplAlloc.FirstEmptySlot;
            RSContext->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)Data;
            pObject->Data = (Scaleform::Render::FenceImpl *)RSContext->FenceAlloc.FirstEmptySlot;
            RSContext->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)pObject;
          }
          else
          {
            p_APIHandle = (int)&pObject->Data[2].APIHandle;
            pObject->Data = (Scaleform::Render::FenceImpl *)HIDWORD(pObject->Data[2].FenceID);
            *(_DWORD *)(p_APIHandle + 12) = pObject;
          }
        }
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}

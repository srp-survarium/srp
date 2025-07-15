void __thiscall Scaleform::Render::D3D1x::MeshCache::destroyPendingBuffers(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::D3D1x::MeshCache *thisa)
{
  Scaleform::Render::D3D1x::MeshCache *v2; // ebx
  Scaleform::Render::D3D1x::MeshBuffer *v3; // esi
  Scaleform::List<Scaleform::Render::MeshBuffer,Scaleform::Render::MeshBuffer> *p_PendingDestructionBuffers; // edx
  int v5; // eax
  Scaleform::Render::MeshCacheItem *v6; // edi
  Scaleform::Render::MeshCacheListSet::ListSlot *v7; // ebx
  Scaleform::Render::D3D1x::MeshBuffer *v8; // edx
  Scaleform::Render::MeshBuffer *pPrev; // ecx
  Scaleform::Render::Fence *pObject; // eax
  Scaleform::Render::FenceImpl *Data; // eax
  Scaleform::Render::MeshBuffer *v12; // eax
  Scaleform::Render::MeshBuffer *v13; // ecx
  Scaleform::Render::D3D1x::MeshBuffer *pNext; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::List<Scaleform::Render::MeshBuffer,Scaleform::Render::MeshBuffer> remainingBuffers; // [esp+18h] [ebp-8h]

  v2 = thisa;
  v3 = (Scaleform::Render::D3D1x::MeshBuffer *)thisa->PendingDestructionBuffers.Root.pNext;
  p_PendingDestructionBuffers = &thisa->PendingDestructionBuffers;
  remainingBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)&pNext;
  remainingBuffers.Root.pNext = (Scaleform::Render::MeshBuffer *)&pNext;
  while ( 1 )
  {
    v5 = p_PendingDestructionBuffers ? (int)&p_PendingDestructionBuffers[-1].Root.4 : 0;
    if ( v3 == (Scaleform::Render::D3D1x::MeshBuffer *)v5 )
      break;
    v6 = v2->CacheList.Slots[5].Root.pNext;
    v7 = &v2->CacheList.Slots[5];
    v8 = (Scaleform::Render::D3D1x::MeshBuffer *)v3->pNext;
    v3->pPrev->Scaleform::Render::MeshBuffer::pNext = v8;
    pPrev = v3->pPrev;
    pNext = v8;
    v3->pNext->Scaleform::Render::MeshBuffer::pPrev = pPrev;
    if ( v6 == (Scaleform::Render::MeshCacheItem *)v7 )
    {
LABEL_14:
      ((void (__thiscall *)(Scaleform::Render::D3D1x::MeshBuffer *, int))v3->~Scaleform::Render::D3D1x::MeshBuffer)(
        v3,
        1);
      v3 = pNext;
      v2 = thisa;
      p_PendingDestructionBuffers = &thisa->PendingDestructionBuffers;
    }
    else
    {
      while ( 1 )
      {
        if ( (Scaleform::Render::D3D1x::MeshBuffer *)v6[1].pPrev == v3
          || (Scaleform::Render::D3D1x::MeshBuffer *)v6[1].pNext == v3 )
        {
          pObject = v6->GPUFence.pObject;
          if ( pObject )
          {
            if ( pObject->HasData )
            {
              Data = pObject->Data;
              if ( Data )
              {
                if ( Scaleform::Render::FenceImpl::IsPending(Data, FenceType_Vertex) )
                  break;
              }
            }
          }
        }
        v6 = v6->pNext;
        if ( v6 == (Scaleform::Render::MeshCacheItem *)v7 )
          goto LABEL_14;
      }
      v2 = thisa;
      v3->pNext = remainingBuffers.Root.pNext;
      p_PendingDestructionBuffers = &thisa->PendingDestructionBuffers;
      v3->pPrev = (Scaleform::Render::MeshBuffer *)&pNext;
      remainingBuffers.Root.pNext->pPrev = v3;
      remainingBuffers.Root.pNext = v3;
      v3 = pNext;
    }
  }
  v12 = remainingBuffers.Root.pNext;
  if ( (Scaleform::Render::D3D1x::MeshBuffer **)remainingBuffers.Root.pNext != &pNext )
  {
    v13 = remainingBuffers.Root.pPrev;
    remainingBuffers.Root.pPrev->pNext = p_PendingDestructionBuffers->Root.pNext;
    v12->pPrev = (Scaleform::Render::MeshBuffer *)&p_PendingDestructionBuffers[-1].Root.4;
    thisa->PendingDestructionBuffers.Root.pNext->pPrev = v13;
    thisa->PendingDestructionBuffers.Root.pNext = v12;
  }
}

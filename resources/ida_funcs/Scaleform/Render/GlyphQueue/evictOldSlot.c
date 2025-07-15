Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphQueue::evictOldSlot(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h)
{
  Scaleform::Render::GlyphNode *result; // eax

  this->pEvictNotifier->ApplyInUseList(this->pEvictNotifier);
  result = Scaleform::Render::GlyphQueue::evictOldSlot(this, w, h, 0);
  if ( !result )
  {
    this->pEvictNotifier->UpdatePinList(this->pEvictNotifier);
    return Scaleform::Render::GlyphQueue::evictOldSlot(this, w, h, 1u);
  }
  return result;
}


Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphQueue::evictOldSlot(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h,
        unsigned int pass)
{
  Scaleform::Render::GlyphQueue *v4; // ebx
  unsigned int SlotQueueSize; // ebp
  Scaleform::Render::GlyphSlot *pNext; // esi
  int v7; // edi
  Scaleform::Render::GlyphSlot *v8; // eax
  Scaleform::Render::GlyphSlot *i; // ebp
  Scaleform::Render::Fence *pObject; // eax
  Scaleform::Render::FenceImpl *Data; // eax
  Scaleform::Render::Fence *v13; // eax
  Scaleform::Render::FenceImpl *v14; // eax
  Scaleform::Render::Fence *v15; // ecx
  unsigned int v16; // edi
  Scaleform::Render::GlyphBand *pBand; // ebx
  Scaleform::Render::GlyphSlot *j; // esi
  Scaleform::Render::Fence *v19; // eax
  Scaleform::Render::FenceImpl *v20; // eax
  Scaleform::Render::Fence *v21; // eax
  Scaleform::Render::FenceImpl *v22; // eax
  Scaleform::Render::Fence *v23; // ecx
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *p_SlotQueue; // edx
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *pPrev; // eax
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *v26; // ecx
  char v27; // al
  unsigned int v28; // eax
  unsigned __int16 RightSpace; // ax
  unsigned int v30; // eax

  v4 = this;
  SlotQueueSize = this->SlotQueueSize;
  pNext = this->SlotQueue.Root.pNext;
  if ( !pass )
    SlotQueueSize >>= 1;
  v7 = 0;
  while ( 1 )
  {
    if ( pNext == (Scaleform::Render::GlyphSlot *)&v4->SlotQueue )
      goto LABEL_9;
    if ( !Scaleform::Render::GlyphQueue::IsPinned(pNext, v4->FenceWaitOnFullCache) )
    {
      if ( pNext->w >= w )
      {
        Scaleform::Render::GlyphQueue::releaseSlot(v4, pNext);
        return Scaleform::Render::GlyphQueue::packGlyph(v4, w, h, pNext);
      }
      v8 = Scaleform::Render::GlyphQueue::mergeSlotWithNeighbor(v4, pNext);
      if ( v8 )
        break;
    }
    pNext = pNext->pNext;
    if ( ++v7 > SlotQueueSize )
      goto LABEL_9;
  }
  if ( v8->pRoot->mRect.w >= w )
    return Scaleform::Render::GlyphQueue::packGlyph(v4, w, h, v8);
LABEL_9:
  for ( i = v4->SlotQueue.Root.pNext; i != (Scaleform::Render::GlyphSlot *)&v4->SlotQueue; i = i->pNext )
  {
    if ( !i->PinCount )
    {
      if ( v4->FenceWaitOnFullCache )
      {
        pObject = i->SlotFence.pObject;
        if ( pObject )
        {
          if ( pObject->HasData )
          {
            Data = pObject->Data;
            if ( Data )
              Scaleform::Render::FenceImpl::WaitFence(Data, FenceType_Fragment);
          }
LABEL_23:
          v15 = i->SlotFence.pObject;
          if ( v15 )
            Scaleform::Render::Fence::Release(v15);
          v16 = 0;
          i->SlotFence.pObject = 0;
          pBand = i->pBand;
          for ( j = i; j != (Scaleform::Render::GlyphSlot *)&pBand->Slots; j = j->pNextInBand )
          {
            if ( j->PinCount )
              break;
            if ( this->FenceWaitOnFullCache && (v19 = j->SlotFence.pObject) != 0 )
            {
              if ( v19->HasData )
              {
                v20 = v19->Data;
                if ( v20 )
                  Scaleform::Render::FenceImpl::WaitFence(v20, FenceType_Fragment);
              }
            }
            else
            {
              v21 = j->SlotFence.pObject;
              if ( v21 )
              {
                if ( v21->HasData )
                {
                  v22 = v21->Data;
                  if ( v22 )
                  {
                    if ( Scaleform::Render::FenceImpl::IsPending(v22, FenceType_Fragment) )
                      break;
                  }
                }
              }
            }
            v23 = j->SlotFence.pObject;
            if ( v23 )
              Scaleform::Render::Fence::Release(v23);
            j->SlotFence.pObject = 0;
            if ( pass
              || (p_SlotQueue = &this->SlotQueue,
                  pPrev = (Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *)j,
                  v26 = (Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *)j,
                  j == (Scaleform::Render::GlyphSlot *)&this->SlotQueue) )
            {
LABEL_42:
              v27 = 1;
            }
            else
            {
              while ( v26 != p_SlotQueue )
              {
                pPrev = (Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *)pPrev->Root.pPrev;
                v26 = (Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *)v26->Root.pNext;
                if ( pPrev == p_SlotQueue )
                  goto LABEL_42;
              }
              v27 = 0;
            }
            if ( j != i && !v27 )
              break;
            v28 = j->w;
            if ( v28 >= w )
            {
              Scaleform::Render::GlyphQueue::releaseSlot(this, j);
              return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, j);
            }
            v16 += v28;
            RightSpace = pBand->RightSpace;
            if ( RightSpace && j == pBand->Slots.Root.pPrevInBand )
            {
              v30 = RightSpace + v16;
              if ( v30 >= w )
              {
                v16 = v30;
                pBand->RightSpace = 0;
              }
            }
            if ( v16 >= w )
            {
              Scaleform::Render::GlyphQueue::mergeSlots(this, i, j, v16);
              return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, i);
            }
          }
          v4 = this;
          continue;
        }
      }
      v13 = i->SlotFence.pObject;
      if ( !v13 )
        goto LABEL_23;
      if ( !v13->HasData )
        goto LABEL_23;
      v14 = v13->Data;
      if ( !v14 || !Scaleform::Render::FenceImpl::IsPending(v14, FenceType_Fragment) )
        goto LABEL_23;
    }
  }
  return 0;
}

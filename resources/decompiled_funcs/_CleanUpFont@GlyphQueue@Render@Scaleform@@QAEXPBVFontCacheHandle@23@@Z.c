void __thiscall Scaleform::Render::GlyphQueue::CleanUpFont(
        Scaleform::Render::GlyphQueue *this,
        const Scaleform::Render::FontCacheHandle *font)
{
  Scaleform::Render::GlyphQueue *pNext; // esi
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *p_SlotQueue; // edi
  unsigned int NumTextures; // ecx
  Scaleform::Render::GlyphQueue *FirstTexture; // ebp
  const Scaleform::Render::GlyphNode *FontInSlot; // eax
  int v7; // ecx
  Scaleform::Render::GlyphSlot *pPrev; // eax
  Scaleform::Render::FenceImpl *v9; // eax
  Scaleform::Render::Fence *v10; // ecx

  pNext = (Scaleform::Render::GlyphQueue *)this->SlotQueue.Root.pNext;
  p_SlotQueue = &this->SlotQueue;
  if ( pNext != (Scaleform::Render::GlyphQueue *)&this->SlotQueue )
  {
    do
    {
      NumTextures = pNext->NumTextures;
      FirstTexture = (Scaleform::Render::GlyphQueue *)pNext->FirstTexture;
      if ( NumTextures )
      {
        if ( *(const Scaleform::Render::FontCacheHandle **)NumTextures == font )
        {
          FontInSlot = (const Scaleform::Render::GlyphNode *)pNext->NumTextures;
        }
        else
        {
          if ( Scaleform::Render::GlyphQueue::findFontInSlot(*(Scaleform::Render::GlyphNode **)(NumTextures + 20), font) )
            goto LABEL_8;
          FontInSlot = Scaleform::Render::GlyphQueue::findFontInSlot(*(Scaleform::Render::GlyphNode **)(v7 + 24), font);
        }
        if ( FontInSlot )
        {
LABEL_8:
          if ( !pNext->Slots.NumElementsInPage )
          {
            pPrev = pNext->SlotQueue.Root.pPrev;
            if ( pPrev )
            {
              if ( BYTE2(pPrev->pVoidNext) )
              {
                v9 = (Scaleform::Render::FenceImpl *)pPrev->pPrev;
                if ( v9 )
                  Scaleform::Render::FenceImpl::WaitFence(v9, FenceType_Fragment);
              }
            }
            v10 = (Scaleform::Render::Fence *)pNext->SlotQueue.Root.pPrev;
            if ( v10 )
              Scaleform::Render::Fence::Release(v10);
            pNext->SlotQueue.Root.pPrev = 0;
          }
          Scaleform::Render::GlyphQueue::releaseSlot(this, (Scaleform::Render::GlyphSlot *)pNext);
          *(_DWORD *)(pNext->MinSlotSpace + 4) = pNext->FirstTexture;
          *(_DWORD *)pNext->FirstTexture = pNext->MinSlotSpace;
          pNext->FirstTexture = (unsigned int)p_SlotQueue->Root.pNext;
          pNext->MinSlotSpace = (unsigned int)p_SlotQueue;
          p_SlotQueue->Root.pNext->pPrev = (Scaleform::Render::GlyphSlot *)pNext;
          p_SlotQueue->Root.pNext = (Scaleform::Render::GlyphSlot *)pNext;
        }
      }
      pNext = FirstTexture;
    }
    while ( FirstTexture != (Scaleform::Render::GlyphQueue *)p_SlotQueue );
  }
}

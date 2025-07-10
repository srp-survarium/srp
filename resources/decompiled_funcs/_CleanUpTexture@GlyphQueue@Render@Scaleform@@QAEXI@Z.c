void __thiscall Scaleform::Render::GlyphQueue::CleanUpTexture(
        Scaleform::Render::GlyphQueue *this,
        unsigned int textureId)
{
  Scaleform::Render::GlyphSlot *pNext; // esi
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *p_SlotQueue; // edi
  Scaleform::Render::GlyphSlot *v5; // ebx

  pNext = this->SlotQueue.Root.pNext;
  p_SlotQueue = &this->SlotQueue;
  if ( pNext != (Scaleform::Render::GlyphSlot *)&this->SlotQueue )
  {
    do
    {
      v5 = pNext->pNext;
      if ( (pNext->TextureId & 0x7FFF) == textureId )
      {
        Scaleform::Render::GlyphQueue::releaseSlot(this, pNext);
        pNext->pPrev->pNext = pNext->pNext;
        pNext->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$5BC0278F55994A57ED32D3AA213E1041::pPrev = pNext->pPrev;
        pNext->pNext = p_SlotQueue->Root.pNext;
        pNext->pPrev = (Scaleform::Render::GlyphSlot *)p_SlotQueue;
        p_SlotQueue->Root.pNext->pPrev = pNext;
        p_SlotQueue->Root.pNext = pNext;
      }
      pNext = v5;
    }
    while ( v5 != (Scaleform::Render::GlyphSlot *)p_SlotQueue );
  }
  Scaleform::Render::GlyphQueue::MergeEmptySlots(this);
}

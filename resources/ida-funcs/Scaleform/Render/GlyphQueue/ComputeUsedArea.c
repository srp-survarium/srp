unsigned int __thiscall Scaleform::Render::GlyphQueue::ComputeUsedArea(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::Render::GlyphSlot *pNext; // esi
  unsigned int result; // eax
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *p_SlotQueue; // ebp
  Scaleform::Render::GlyphNode *pRoot; // edi
  unsigned int used; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+10h] [ebp-4h]

  pNext = this->SlotQueue.Root.pNext;
  result = 0;
  p_SlotQueue = &this->SlotQueue;
  for ( i = 0; pNext != (Scaleform::Render::GlyphSlot *)p_SlotQueue; i += used )
  {
    used = 0;
    pRoot = pNext->pRoot;
    if ( pRoot )
    {
      if ( pRoot->Param.pFont )
        used = pRoot->mRect.w * pRoot->mRect.h;
      Scaleform::Render::GlyphQueue::computeGlyphArea(this, pRoot->pNext, &used);
      Scaleform::Render::GlyphQueue::computeGlyphArea(this, pRoot->pNex2, &used);
    }
    result = used + i;
    pNext = pNext->pNext;
  }
  return result;
}

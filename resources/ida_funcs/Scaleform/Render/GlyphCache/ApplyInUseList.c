void __thiscall Scaleform::Render::GlyphCache::ApplyInUseList(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::TextMeshProvider *pNext; // esi
  Scaleform::List<Scaleform::Render::TextMeshProvider,Scaleform::Render::TextMeshProvider> *p_TextInUse; // ebp
  int v4; // eax
  Scaleform::Render::TextMeshProvider *v5; // ebx

  pNext = this->TextInUse.Root.pNext;
  p_TextInUse = &this->TextInUse;
  while ( 1 )
  {
    v4 = p_TextInUse ? (int)&p_TextInUse[-1].Root.4 : 0;
    if ( pNext == (Scaleform::Render::TextMeshProvider *)v4 )
      break;
    v5 = pNext->pNext;
    pNext->Flags &= ~2u;
    Scaleform::Render::TextMeshProvider::PinSlots(pNext);
    pNext->pPrev = this->TextInPin.Root.pPrev;
    pNext->pNext = (Scaleform::Render::TextMeshProvider *)&this->TextInUse.Root.4;
    this->TextInPin.Root.pPrev->pNext = pNext;
    this->TextInPin.Root.pPrev = pNext;
    pNext->Flags |= 4u;
    pNext = v5;
  }
  if ( p_TextInUse )
  {
    p_TextInUse->Root.pNext = (Scaleform::Render::TextMeshProvider *)&p_TextInUse[-1].Root.4;
    p_TextInUse->Root.pPrev = (Scaleform::Render::TextMeshProvider *)&p_TextInUse[-1].Root.4;
  }
  else
  {
    MEMORY[4] = 0;
    MEMORY[0] = 0;
  }
}

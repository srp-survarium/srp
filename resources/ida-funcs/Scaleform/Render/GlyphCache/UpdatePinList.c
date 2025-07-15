char __thiscall Scaleform::Render::GlyphCache::UpdatePinList(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::TextMeshProvider *pNext; // esi
  char v2; // bl
  Scaleform::List<Scaleform::Render::TextMeshProvider,Scaleform::Render::TextMeshProvider> *p_TextInPin; // ebp
  int v4; // eax
  Scaleform::Render::TextMeshProvider *v5; // edi

  pNext = this->TextInPin.Root.pNext;
  v2 = 0;
  p_TextInPin = &this->TextInPin;
  while ( 1 )
  {
    v4 = p_TextInPin ? (int)&p_TextInPin[-1].Root.4 : 0;
    if ( pNext == (Scaleform::Render::TextMeshProvider *)v4 )
      break;
    v5 = pNext->pNext;
    if ( Scaleform::Render::TextMeshProvider::GetMeshUseStatus(pNext) < 4 )
    {
      pNext->Flags &= ~4u;
      Scaleform::Render::TextMeshProvider::UnpinSlots(pNext);
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->pPrev = pNext->pPrev;
      v2 = 1;
    }
    pNext = v5;
  }
  return v2;
}

Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *__thiscall Scaleform::Render::GlyphQueue::CreateNotifier(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphNode *node,
        Scaleform::Render::TextMeshProvider *tm)
{
  Scaleform::Render::GlyphSlot *pSlot; // edi
  Scaleform::Render::TextNotifier *pPrev; // eax
  Scaleform::Render::TextNotifier *p_TextFields; // esi
  Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *result; // eax
  Scaleform::Render::TextNotifier *v7; // ecx

  pSlot = node->pSlot;
  pPrev = pSlot->TextFields.Root.pPrev;
  p_TextFields = (Scaleform::Render::TextNotifier *)&pSlot->TextFields;
  if ( pPrev != (Scaleform::Render::TextNotifier *)&pSlot->TextFields && tm == pPrev->pText )
    return 0;
  result = Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79>>::allocate(&this->Notifiers);
  result->Data[0].pText = tm;
  result->Data[0].pSlot = pSlot;
  v7 = p_TextFields->pPrev;
  result->Data[0].pNext = p_TextFields;
  result->Data[0].pPrev = v7;
  p_TextFields->pPrev->pNext = (Scaleform::Render::TextNotifier *)result;
  p_TextFields->pPrev = (Scaleform::Render::TextNotifier *)result;
  return result;
}

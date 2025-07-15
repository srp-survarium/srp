void __thiscall Scaleform::Render::GlyphQueue::RemoveNotifier(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::TextNotifier *notifier)
{
  notifier->pPrev->pNext = notifier->pNext;
  notifier->pNext->Scaleform::ListNode<Scaleform::Render::TextNotifier>::$5B8911338D9A0D339B0FDD7C8E1BA946::pPrev = notifier->pPrev;
  notifier->pPrev = (Scaleform::Render::TextNotifier *)this->Notifiers.FirstEmptySlot;
  this->Notifiers.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::NodeType *)notifier;
}

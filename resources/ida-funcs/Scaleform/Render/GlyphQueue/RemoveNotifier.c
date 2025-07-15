void __thiscall Scaleform::Render::GlyphQueue::RemoveNotifier(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::NodeType *notifier)
{
  notifier->pNext[1].pNext = notifier[1].pNext;
  notifier[1].pNext->pNext = notifier->pNext;
  notifier->pNext = this->Notifiers.FirstEmptySlot;
  this->Notifiers.FirstEmptySlot = notifier;
}

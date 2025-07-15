void __thiscall Scaleform::Render::GlyphQueue::UnpinAllSlots(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::Render::GlyphSlot *pNext; // esi
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *i; // edi
  Scaleform::Render::Fence *pObject; // eax
  Scaleform::Render::FenceImpl *Data; // eax
  Scaleform::Render::Fence *v5; // ecx

  pNext = this->SlotQueue.Root.pNext;
  for ( i = &this->SlotQueue; pNext != (Scaleform::Render::GlyphSlot *)i; pNext = pNext->pNext )
  {
    pObject = pNext->SlotFence.pObject;
    pNext->PinCount = 0;
    if ( pObject )
    {
      if ( pObject->HasData )
      {
        Data = pObject->Data;
        if ( Data )
          Scaleform::Render::FenceImpl::WaitFence(Data, FenceType_Fragment);
      }
    }
    v5 = pNext->SlotFence.pObject;
    if ( v5 )
      Scaleform::Render::Fence::Release(v5);
    pNext->SlotFence.pObject = 0;
  }
}

void __cdecl Scaleform::Render::GlyphQueue::UnpinSlot(
        Scaleform::Render::GlyphSlot *slot,
        Scaleform::Render::Fence *fence)
{
  Scaleform::Render::Fence *pObject; // eax
  const Scaleform::Render::FenceImpl *Data; // eax
  Scaleform::Render::Fence *v4; // ecx

  if ( fence )
  {
    if ( fence->HasData )
    {
      if ( fence->Data )
      {
        if ( Scaleform::Render::FenceImpl::IsPending(fence->Data, FenceType_Fragment) )
        {
          pObject = slot->SlotFence.pObject;
          if ( !pObject
            || fence->Data
            && ((Data = pObject->Data) == 0 || Scaleform::Render::FenceImpl::operator>(fence->Data, Data)) )
          {
            ++fence->RefCount;
            v4 = slot->SlotFence.pObject;
            if ( v4 )
              Scaleform::Render::Fence::Release(v4);
            slot->SlotFence.pObject = fence;
          }
        }
      }
    }
  }
  --slot->PinCount;
}

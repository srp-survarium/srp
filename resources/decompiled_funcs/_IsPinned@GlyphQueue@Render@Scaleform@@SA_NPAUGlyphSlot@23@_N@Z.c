char __cdecl Scaleform::Render::GlyphQueue::IsPinned(Scaleform::Render::GlyphSlot *slot, bool waitOn)
{
  Scaleform::Render::Fence *v3; // eax
  Scaleform::Render::FenceImpl *Data; // eax
  Scaleform::Render::Fence *pObject; // eax
  Scaleform::Render::FenceImpl *v6; // eax
  Scaleform::Render::Fence *v7; // ecx

  if ( slot->PinCount )
    return 1;
  if ( waitOn && (v3 = slot->SlotFence.pObject) != 0 )
  {
    if ( v3->HasData )
    {
      Data = v3->Data;
      if ( Data )
        Scaleform::Render::FenceImpl::WaitFence(Data, FenceType_Fragment);
    }
  }
  else
  {
    pObject = slot->SlotFence.pObject;
    if ( pObject )
    {
      if ( pObject->HasData )
      {
        v6 = pObject->Data;
        if ( v6 )
        {
          if ( Scaleform::Render::FenceImpl::IsPending(v6, FenceType_Fragment) )
            return 1;
        }
      }
    }
  }
  v7 = slot->SlotFence.pObject;
  if ( v7 )
    Scaleform::Render::Fence::Release(v7);
  slot->SlotFence.pObject = 0;
  return 0;
}

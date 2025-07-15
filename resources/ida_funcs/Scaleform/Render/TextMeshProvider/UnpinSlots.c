void __thiscall Scaleform::Render::TextMeshProvider::UnpinSlots(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::Fence *LatestFence; // eax
  Scaleform::Render::Fence *v3; // ebx
  unsigned int i; // esi

  LatestFence = Scaleform::Render::TextMeshProvider::GetLatestFence(this);
  v3 = LatestFence;
  if ( LatestFence )
    ++LatestFence->RefCount;
  for ( i = 0; i < this->Notifiers.Data.Size; ++i )
    Scaleform::Render::GlyphQueue::UnpinSlot(this->Notifiers.Data.Data[i]->pSlot, v3);
  if ( v3 )
    Scaleform::Render::Fence::Release(v3);
}

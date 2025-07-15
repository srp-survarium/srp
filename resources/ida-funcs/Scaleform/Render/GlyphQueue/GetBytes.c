unsigned int __thiscall Scaleform::Render::GlyphQueue::GetBytes(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *FirstPage; // eax
  int i; // edi
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *v3; // eax
  int j; // esi
  Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *v5; // eax
  int k; // edx

  FirstPage = this->Slots.FirstPage;
  for ( i = 0; FirstPage; i += 7116 )
    FirstPage = FirstPage->pNext;
  v3 = this->Glyphs.FirstPage;
  for ( j = 0; v3; j += 5592 )
    v3 = v3->pNext;
  v5 = this->Notifiers.FirstPage;
  for ( k = 0; v5; k += 2036 )
    v5 = v5->pNext;
  return i + j + k + (this->Bands.Capacity << 6);
}

void __thiscall Scaleform::Render::TextMeshProvider::PinSlots(Scaleform::Render::TextMeshProvider *this)
{
  unsigned int i; // esi

  for ( i = 0; i < this->Notifiers.Data.Size; ++i )
    Scaleform::Render::GlyphQueue::PinSlot(this->Notifiers.Data.Data[i]->pSlot);
}

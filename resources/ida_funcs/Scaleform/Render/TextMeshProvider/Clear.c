void __thiscall Scaleform::Render::TextMeshProvider::Clear(Scaleform::Render::TextMeshProvider *this)
{
  unsigned int Flags; // eax
  unsigned int v3; // eax
  Scaleform::Render::TextPrimitiveBundle *pBundle; // ecx

  Flags = this->Flags;
  if ( (Flags & 6) != 0 )
  {
    v3 = Flags & 0xFFFFFFFD;
    this->Flags = v3;
    if ( (v3 & 6) == 4 )
    {
      this->Flags = v3 & 0xFFFFFFFB;
      Scaleform::Render::TextMeshProvider::UnpinSlots(this);
    }
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
  }
  pBundle = this->pBundle;
  if ( pBundle )
  {
    Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(pBundle, this->pBundleEntry);
    this->pBundle = 0;
    this->pBundleEntry = 0;
  }
  Scaleform::Render::TextMeshProvider::ClearEntries(this);
  Scaleform::ConstructorMov<Scaleform::Render::TextMeshEntry>::DestructArray(
    this->Entries.Data.Data,
    this->Entries.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  Scaleform::ConstructorMov<Scaleform::Render::TextMeshLayer>::DestructArray(
    this->Layers.Data.Data,
    this->Layers.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Layers.Data.Data);
  this->Layers.Data.Data = 0;
  this->Layers.Data.Size = 0;
  this->Layers.Data.Policy.Capacity = 0;
}

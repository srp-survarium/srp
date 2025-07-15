void __thiscall Scaleform::Render::TextMeshProvider::TextMeshProvider(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::GlyphCache *cache)
{
  Scaleform::MemoryHeap *pHeap; // esi
  Scaleform::MemoryHeap *v3; // esi
  Scaleform::MemoryHeap *v4; // edx

  this->__vftable = (Scaleform::Render::TextMeshProvider_vtbl *)&Scaleform::Render::TextMeshProvider::`vftable';
  this->pCache = cache;
  this->Flags = 0;
  pHeap = cache->pHeap;
  this->Notifiers.Data.Data = 0;
  this->Notifiers.Data.Size = 0;
  this->Notifiers.Data.Policy.Capacity = 0;
  this->Notifiers.Data.pHeap = pHeap;
  v3 = cache->pHeap;
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  this->Entries.Data.pHeap = v3;
  v4 = cache->pHeap;
  this->Layers.Data.Data = 0;
  this->Layers.Data.Size = 0;
  this->Layers.Data.Policy.Capacity = 0;
  this->Layers.Data.pHeap = v4;
  this->HeightRatio = 0.0;
  this->PinCount = 0;
  this->pBundle = 0;
  this->pBundleEntry = 0;
  this->ClipBox.x1 = 0.0;
  this->ClipBox.y1 = 0.0;
  this->ClipBox.x2 = 0.0;
  this->ClipBox.y2 = 0.0;
  this->ClearBox.x1 = 0.0;
  this->ClearBox.y1 = 0.0;
  this->ClearBox.x2 = 0.0;
  this->ClearBox.y2 = 0.0;
  this->pRenderer = 0;
  this->ClearBounds.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
}

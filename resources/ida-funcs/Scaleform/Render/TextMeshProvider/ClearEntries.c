void __thiscall Scaleform::Render::TextMeshProvider::ClearEntries(Scaleform::Render::TextMeshProvider *this)
{
  unsigned int i; // edi
  unsigned int v3; // ebx
  int v4; // edi
  Scaleform::Render::TextMeshEntry *Data; // eax
  unsigned __int16 LayerType; // cx
  Scaleform::Render::TextMeshEntry *v7; // eax
  Scaleform::Ptr<Scaleform::Render::PrimitiveFill> *p_pFill; // edi
  unsigned int Size; // ebx

  for ( i = 0; i < this->Notifiers.Data.Size; ++i )
    Scaleform::Render::GlyphQueue::RemoveNotifier(
      &this->pCache->Queue,
      (Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::NodeType *)this->Notifiers.Data.Data[i]);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Notifiers.Data.Data);
  this->Notifiers.Data.Data = 0;
  this->Notifiers.Data.Size = 0;
  this->Notifiers.Data.Policy.Capacity = 0;
  v3 = 0;
  if ( this->Entries.Data.Size )
  {
    v4 = 0;
    do
    {
      Data = this->Entries.Data.Data;
      LayerType = Data[v4].LayerType;
      v7 = &Data[v4];
      if ( LayerType == 8 || LayerType == 12 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7->EntryData.VectorData.pFont);
      ++v3;
      ++v4;
    }
    while ( v3 < this->Entries.Data.Size );
  }
  if ( this->Entries.Data.Size )
  {
    p_pFill = &this->Entries.Data.Data[this->Entries.Data.Size - 1].pFill;
    Size = this->Entries.Data.Size;
    do
    {
      if ( p_pFill->pObject )
        Scaleform::RefCountNTSImpl::Release(p_pFill->pObject);
      p_pFill -= 8;
      --Size;
    }
    while ( Size );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  this->Flags &= 0xFFFFFE1F;
}

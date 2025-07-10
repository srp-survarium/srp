void __thiscall Scaleform::GFx::StaticTextRecordList::Clear(Scaleform::GFx::StaticTextRecordList *this)
{
  unsigned int Size; // ebp
  unsigned int i; // ebx
  Scaleform::GFx::StaticTextRecord *v4; // esi
  Scaleform::GFx::Resource *pResource; // ecx

  Size = this->Records.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    if ( this->Records.Data.Data[i] )
    {
      v4 = this->Records.Data.Data[i];
      if ( v4->pFont.HType == RH_Pointer )
      {
        pResource = v4->pFont.pResource;
        if ( pResource )
          Scaleform::GFx::Resource::Release(pResource);
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4->Glyphs.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  if ( !this->Records.Data.Size )
  {
    if ( !this->Records.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        0);
    goto LABEL_15;
  }
  if ( (this->Records.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_15:
    this->Records.Data.Size = 0;
    return;
  }
  if ( this->Records.Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Records.Data.Data);
    this->Records.Data.Data = 0;
  }
  this->Records.Data.Policy.Capacity = 0;
  this->Records.Data.Size = 0;
}

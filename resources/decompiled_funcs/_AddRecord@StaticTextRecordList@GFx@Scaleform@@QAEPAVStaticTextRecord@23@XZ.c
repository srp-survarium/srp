Scaleform::GFx::StaticTextRecord *__thiscall Scaleform::GFx::StaticTextRecordList::AddRecord(
        Scaleform::GFx::StaticTextRecordList *this)
{
  Scaleform::GFx::StaticTextRecord *v2; // eax
  Scaleform::GFx::StaticTextRecord *v3; // ebx
  unsigned int v4; // edi
  Scaleform::GFx::StaticTextRecord **v6; // eax
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v7 = 258;
  v2 = (Scaleform::GFx::StaticTextRecord *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             this,
                                             40,
                                             &v7);
  v3 = v2;
  if ( !v2 )
    return 0;
  v2->Glyphs.Data.Data = 0;
  v2->Glyphs.Data.Size = 0;
  v2->Glyphs.Data.Policy.Capacity = 0;
  v2->pFont.HType = RH_Pointer;
  v2->pFont.BindIndex = 0;
  v2->Offset.y = 0.0;
  v2->Offset.x = 0.0;
  v2->FontId = 0;
  v2->TextHeight = 1.0;
  v4 = this->Records.Data.Size + 1;
  if ( v4 >= this->Records.Data.Size )
  {
    if ( v4 >= this->Records.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Records.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Records.Data.Size + 1);
  }
  v6 = &this->Records.Data.Data[v4 - 1];
  this->Records.Data.Size = v4;
  if ( v6 )
    *v6 = v3;
  return v3;
}

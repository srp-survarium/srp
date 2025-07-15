Scaleform::GFx::StaticTextDef *__thiscall Scaleform::GFx::StaticTextDef::`vector deleting destructor'(
        Scaleform::GFx::StaticTextDef *this,
        char a2)
{
  Scaleform::GFx::StaticTextRecordList *p_TextRecords; // edi

  p_TextRecords = &this->TextRecords;
  Scaleform::GFx::StaticTextRecordList::Clear(&this->TextRecords);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_TextRecords->Records.Data.Data);
  this->__vftable = (Scaleform::GFx::StaticTextDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}

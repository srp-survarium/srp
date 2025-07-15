Scaleform::GFx::AS2::AvmTextField::CSSHolder *__thiscall Scaleform::GFx::AS2::AvmTextField::CSSHolder::`scalar deleting destructor'(
        Scaleform::GFx::AS2::AvmTextField::CSSHolder *this,
        char a2)
{
  Scaleform::GFx::AS2::StyleSheetObject *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->pASStyleSheet.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->__vftable = (Scaleform::GFx::AS2::AvmTextField::CSSHolder_vtbl *)&Scaleform::GFx::TextField::CSSHolderBase::`vftable';
  Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>>::DestructArray(
    this->UrlZones.Ranges.Data.Data,
    this->UrlZones.Ranges.Data.Size);
  if ( this->UrlZones.Ranges.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->UrlZones.Ranges.Data.Data);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}

Scaleform::GFx::TextField::CSSHolderBase *__thiscall Scaleform::GFx::TextField::CSSHolderBase::`scalar deleting destructor'(
        Scaleform::GFx::TextField::CSSHolderBase *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::TextField::CSSHolderBase_vtbl *)&Scaleform::GFx::TextField::CSSHolderBase::`vftable';
  Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>>::DestructArray(
    this->UrlZones.Ranges.Data.Data,
    this->UrlZones.Ranges.Data.Size);
  if ( this->UrlZones.Ranges.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->UrlZones.Ranges.Data.Data);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}

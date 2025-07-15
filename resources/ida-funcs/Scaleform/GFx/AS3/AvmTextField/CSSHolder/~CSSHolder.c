void __thiscall Scaleform::GFx::AS3::AvmTextField::CSSHolder::~CSSHolder(
        Scaleform::GFx::AS3::AvmTextField::CSSHolder *this)
{
  Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *Data; // esi

  pObject = this->pASStyleSheet.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pASStyleSheet.pObject = (Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  this->__vftable = (Scaleform::GFx::AS3::AvmTextField::CSSHolder_vtbl *)&Scaleform::GFx::TextField::CSSHolderBase::`vftable';
  Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>>::DestructArray(
    this->UrlZones.Ranges.Data.Data,
    this->UrlZones.Ranges.Data.Size);
  Data = this->UrlZones.Ranges.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}

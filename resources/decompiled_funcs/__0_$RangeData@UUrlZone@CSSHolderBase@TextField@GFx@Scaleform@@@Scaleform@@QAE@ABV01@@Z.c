void __thiscall Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>(
        Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *this,
        const Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *__that)
{
  unsigned int Length; // edx
  Scaleform::Render::Text::StyledText *pObject; // edx

  Length = __that->Length;
  this->Index = __that->Index;
  this->Length = Length;
  pObject = __that->Data.SavedFmt.pObject;
  if ( pObject )
    ++pObject->RefCount;
  this->Data = __that->Data;
}

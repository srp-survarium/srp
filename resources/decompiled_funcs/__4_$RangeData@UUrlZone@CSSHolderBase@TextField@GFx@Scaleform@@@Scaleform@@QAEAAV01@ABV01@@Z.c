Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *__thiscall Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>::operator=(
        Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *this,
        const Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *__that)
{
  Scaleform::Render::Text::StyledText *pObject; // eax
  Scaleform::Render::Text::StyledText *v4; // ecx

  this->Index = __that->Index;
  this->Length = __that->Length;
  pObject = __that->Data.SavedFmt.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v4 = this->Data.SavedFmt.pObject;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  this->Data = __that->Data;
  return this;
}

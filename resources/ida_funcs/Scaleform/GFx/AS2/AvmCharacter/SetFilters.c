void __thiscall Scaleform::GFx::AS2::AvmCharacter::SetFilters(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::Ptr<Scaleform::Render::FilterSet> filters)
{
  this->pDispObj->SetFilters(this->pDispObj, filters.pObject);
  if ( filters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)filters.pObject);
}

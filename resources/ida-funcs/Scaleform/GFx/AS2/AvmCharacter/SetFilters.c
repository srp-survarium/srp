void __thiscall Scaleform::GFx::AS2::AvmCharacter::SetFilters(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::RefCountVImpl *filters)
{
  this->pDispObj->SetFilters(this->pDispObj, (const Scaleform::Render::FilterSet *)filters);
  if ( filters )
    Scaleform::RefCountImpl::Release(filters);
}

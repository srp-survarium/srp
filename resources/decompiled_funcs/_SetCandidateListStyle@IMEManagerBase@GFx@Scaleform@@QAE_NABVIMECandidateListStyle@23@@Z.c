char __thiscall Scaleform::GFx::IMEManagerBase::SetCandidateListStyle(
        Scaleform::GFx::IMEManagerBase *this,
        const Scaleform::GFx::IMECandidateListStyle *st)
{
  Scaleform::GFx::MovieImpl *pMovie; // ecx
  Scaleform::GFx::ASIMEManager *pObject; // ecx

  pMovie = (Scaleform::GFx::MovieImpl *)this->pMovie;
  if ( pMovie )
    Scaleform::GFx::MovieImpl::SetIMECandidateListStyle(pMovie, st);
  pObject = this->pASIMEManager.pObject;
  if ( !pObject || !pObject->IsCandidateListLoaded(pObject) )
    return 0;
  this->OnCandidateListStyleChanged(this, st);
  return 1;
}

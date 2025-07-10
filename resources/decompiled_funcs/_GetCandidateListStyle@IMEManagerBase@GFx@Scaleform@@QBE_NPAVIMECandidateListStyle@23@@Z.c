char __thiscall Scaleform::GFx::IMEManagerBase::GetCandidateListStyle(
        Scaleform::GFx::IMEManagerBase *this,
        Scaleform::GFx::IMECandidateListStyle *pst)
{
  Scaleform::GFx::MovieImpl *pMovie; // ecx

  pMovie = (Scaleform::GFx::MovieImpl *)this->pMovie;
  if ( !pMovie )
    return 0;
  Scaleform::GFx::MovieImpl::GetIMECandidateListStyle(pMovie, pst);
  return 1;
}

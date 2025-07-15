Scaleform::GFx::LogState *__thiscall Scaleform::GFx::AS3::ASVM::GetLogState(Scaleform::GFx::AS3::ASVM *this)
{
  Scaleform::GFx::LogState *pObject; // esi
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [esp+0h] [ebp-4h] BYREF

  result.pObject = (Scaleform::GFx::LogState *)this;
  pObject = Scaleform::GFx::StateBag::GetLogState(&this->pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  return pObject;
}

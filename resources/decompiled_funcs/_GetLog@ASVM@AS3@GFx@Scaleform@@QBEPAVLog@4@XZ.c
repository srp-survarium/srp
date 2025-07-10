Scaleform::Log *__thiscall Scaleform::GFx::AS3::ASVM::GetLog(Scaleform::GFx::AS3::ASVM *this)
{
  Scaleform::Log *pObject; // esi
  Scaleform::Ptr<Scaleform::Log> result; // [esp+0h] [ebp-4h] BYREF

  result.pObject = (Scaleform::Log *)this;
  pObject = Scaleform::GFx::StateBag::GetLog(&this->pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  return pObject;
}

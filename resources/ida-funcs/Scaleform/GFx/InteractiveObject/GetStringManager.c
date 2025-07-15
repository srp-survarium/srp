Scaleform::GFx::ASStringManager *__thiscall Scaleform::GFx::InteractiveObject::GetStringManager(
        Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // ecx

  pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  return pObject->GetStringManager(pObject);
}

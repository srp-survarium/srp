Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::CharacterHandle::ResolveCharacter(
        Scaleform::GFx::CharacterHandle *this,
        Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::InteractiveObject *result; // eax

  result = (Scaleform::GFx::InteractiveObject *)this->pCharacter;
  if ( !result )
    return proot->pASMovieRoot.pObject->FindTarget(proot->pASMovieRoot.pObject, &this->NamePath);
  return result;
}

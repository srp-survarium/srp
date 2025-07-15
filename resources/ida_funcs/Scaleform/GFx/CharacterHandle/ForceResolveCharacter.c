Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::CharacterHandle::ForceResolveCharacter(
        Scaleform::GFx::CharacterHandle *this,
        Scaleform::GFx::MovieImpl *proot)
{
  return proot->pASMovieRoot.pObject->FindTarget(proot->pASMovieRoot.pObject, &this->NamePath);
}

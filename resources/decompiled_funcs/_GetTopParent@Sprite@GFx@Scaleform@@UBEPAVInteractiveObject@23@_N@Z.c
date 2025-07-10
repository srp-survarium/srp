Scaleform::GFx::Sprite *__thiscall Scaleform::GFx::Sprite::GetTopParent(
        Scaleform::GFx::Sprite *this,
        BOOL ignoreLockRoot)
{
  Scaleform::GFx::Sprite *result; // eax
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  unsigned __int8 Flags; // dl

  result = this;
  pParent = this->pParent;
  if ( pParent )
  {
    if ( ignoreLockRoot || (Flags = result->Flags, (Flags & 0x10) == 0) || (Flags & 0x20) == 0 )
    {
      if ( (result->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
          & 0x10) != 0 )
        return (Scaleform::GFx::Sprite *)result->pASRoot->pMovieImpl->pMainMovie;
      else
        return (Scaleform::GFx::Sprite *)pParent->GetTopParent(pParent, ignoreLockRoot);
    }
  }
  return result;
}

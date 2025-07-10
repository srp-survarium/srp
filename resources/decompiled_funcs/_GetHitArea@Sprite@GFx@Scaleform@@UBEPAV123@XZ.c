Scaleform::GFx::Sprite *__thiscall Scaleform::GFx::Sprite::GetHitArea(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // ecx
  Scaleform::GFx::InteractiveObject *v3; // eax

  pObject = this->pHitAreaHandle.pObject;
  if ( pObject && (v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pObject, this->pASRoot->pMovieImpl)) != 0 )
    return (v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
         ? (Scaleform::GFx::Sprite *)v3
         : 0;
  else
    return 0;
}

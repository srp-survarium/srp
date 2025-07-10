Scaleform::GFx::Sprite *__thiscall Scaleform::GFx::MovieImpl::GetModalClip(
        Scaleform::GFx::MovieImpl *this,
        unsigned int controllerIdx)
{
  Scaleform::GFx::CharacterHandle *pObject; // ecx
  Scaleform::GFx::DisplayObject *v4; // eax
  Scaleform::GFx::DisplayObject *v5; // esi

  pObject = this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].ModalClip.pObject;
  if ( !pObject )
    return 0;
  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pObject, this);
  v5 = v4;
  if ( !v4 )
    return 0;
  ++v4->RefCount;
  Scaleform::RefCountNTSImpl::Release(v4);
  return (Scaleform::GFx::Sprite *)v5;
}

Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS3::AvmInteractiveObj::FindInsertToPlayList(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  Scaleform::GFx::InteractiveObject *pParent; // eax
  Scaleform::GFx::InteractiveObject *result; // eax

  pDispObj = this->pDispObj;
  if ( (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
    return 0;
  if ( (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) != 0 )
    return 0;
  if ( pDispObj->Depth < -1 )
    return 0;
  pParent = ch->pParent;
  if ( !pParent )
    return 0;
  result = pParent->pPlayPrev;
  if ( !result )
    return 0;
  return result;
}

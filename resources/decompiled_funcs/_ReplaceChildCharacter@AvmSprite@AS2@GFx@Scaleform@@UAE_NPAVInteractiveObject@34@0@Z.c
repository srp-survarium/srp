char __thiscall Scaleform::GFx::AS2::AvmSprite::ReplaceChildCharacter(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::InteractiveObject *poldChar,
        Scaleform::GFx::InteractiveObject *pnewChar)
{
  char pIndXFormData; // al
  char v6; // al
  unsigned int DisplayIndex; // eax

  Scaleform::GFx::DisplayObject::SetMask(poldChar, 0);
  if ( (poldChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x8000u) != 0 )
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(this->pDispObj->pASRoot->pMovieImpl, poldChar);
  if ( Scaleform::GFx::DisplayList::GetDisplayIndex((Scaleform::GFx::DisplayList *)&this->pDispObj[1], poldChar->Depth) == -1 )
    return 0;
  Scaleform::GFx::InteractiveObject::CopyPhysicalProperties(pnewChar, poldChar);
  if ( (pnewChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
    && (poldChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
  {
    pIndXFormData = (char)pnewChar[1].pIndXFormData;
    if ( ((int)poldChar[1].pIndXFormData & 0x20) != 0 )
      v6 = pIndXFormData | 0x20;
    else
      v6 = pIndXFormData & 0xDF;
    LOBYTE(pnewChar[1].pIndXFormData) = v6;
  }
  poldChar->OnUnloading(poldChar);
  this->pDispObj->pASRoot->DoActions(this->pDispObj->pASRoot);
  Scaleform::GFx::InteractiveObject::MoveNameHandle(pnewChar, poldChar);
  DisplayIndex = Scaleform::GFx::DisplayList::GetDisplayIndex(
                   (Scaleform::GFx::DisplayList *)&this->pDispObj[1],
                   poldChar->Depth);
  if ( DisplayIndex == -1 )
    return 0;
  Scaleform::GFx::DisplayList::ReplaceDisplayObjectAtIndex(
    (Scaleform::GFx::DisplayList *)&this->pDispObj[1],
    this->pDispObj,
    DisplayIndex,
    pnewChar);
  return 1;
}

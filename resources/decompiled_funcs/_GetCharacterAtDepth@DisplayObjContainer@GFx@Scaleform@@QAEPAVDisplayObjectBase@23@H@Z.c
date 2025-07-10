Scaleform::GFx::DisplayObjectBase *__thiscall Scaleform::GFx::DisplayObjContainer::GetCharacterAtDepth(
        Scaleform::GFx::DisplayObjContainer *this,
        int depth)
{
  Scaleform::GFx::DisplayList *p_mDisplayList; // esi
  unsigned int DisplayIndex; // eax

  p_mDisplayList = &this->mDisplayList;
  DisplayIndex = Scaleform::GFx::DisplayList::GetDisplayIndex(&this->mDisplayList, depth);
  if ( DisplayIndex == -1 )
    return 0;
  else
    return p_mDisplayList->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter;
}

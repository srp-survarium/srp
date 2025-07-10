Scaleform::GFx::DisplayObjectBase *__thiscall Scaleform::GFx::DisplayObjContainer::GetChildAt(
        Scaleform::GFx::DisplayObjContainer *this,
        unsigned int index)
{
  if ( index < this->mDisplayList.DisplayObjectArray.Data.Size )
    return this->mDisplayList.DisplayObjectArray.Data.Data[index].pCharacter;
  else
    return 0;
}

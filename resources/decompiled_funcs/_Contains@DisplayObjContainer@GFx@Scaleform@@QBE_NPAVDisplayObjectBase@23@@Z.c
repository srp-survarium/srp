char __thiscall Scaleform::GFx::DisplayObjContainer::Contains(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::DisplayObjContainer *ch)
{
  Scaleform::GFx::DisplayObjContainer *v2; // edx
  unsigned int Size; // ebx
  int v6; // edi
  int i; // esi
  Scaleform::GFx::DisplayObjContainer *pCharacter; // eax

  v2 = ch;
  if ( this == ch )
    return 1;
  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  v6 = 0;
  if ( !Size )
    return 0;
  for ( i = 0; ; ++i )
  {
    pCharacter = (Scaleform::GFx::DisplayObjContainer *)this->mDisplayList.DisplayObjectArray.Data.Data[i].pCharacter;
    if ( v2 == pCharacter )
      break;
    if ( ((pCharacter->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
         & 0x200) != 0
        ? (unsigned int)pCharacter
        : 0) != 0 )
    {
      if ( Scaleform::GFx::DisplayObjContainer::Contains(
             (pCharacter->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
            & 0x200) != 0
           ? pCharacter
           : 0,
             v2) )
      {
        return 1;
      }
      v2 = ch;
    }
    if ( ++v6 >= Size )
      return 0;
  }
  return 1;
}

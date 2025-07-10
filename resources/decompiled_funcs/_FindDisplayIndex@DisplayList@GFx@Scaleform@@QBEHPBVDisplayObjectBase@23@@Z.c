int __thiscall Scaleform::GFx::DisplayList::FindDisplayIndex(
        Scaleform::GFx::DisplayList *this,
        const Scaleform::GFx::DisplayObjectBase *ch)
{
  unsigned int Size; // edx
  int result; // eax
  Scaleform::GFx::DisplayList::DisplayEntry *i; // ecx

  Size = this->DisplayObjectArray.Data.Size;
  result = 0;
  if ( !Size )
    return -1;
  for ( i = this->DisplayObjectArray.Data.Data; i->pCharacter != ch; ++i )
  {
    if ( ++result >= Size )
      return -1;
  }
  return result;
}

unsigned int __thiscall Scaleform::GFx::DisplayList::GetDisplayIndex(Scaleform::GFx::DisplayList *this, int depth)
{
  unsigned int result; // eax

  result = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  if ( result >= this->DisplayObjectArray.Data.Size
    || this->DisplayObjectArray.Data.Data[result].pCharacter->Depth != depth )
  {
    return -1;
  }
  return result;
}

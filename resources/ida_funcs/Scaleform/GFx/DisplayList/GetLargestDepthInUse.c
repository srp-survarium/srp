int __thiscall Scaleform::GFx::DisplayList::GetLargestDepthInUse(Scaleform::GFx::DisplayList *this)
{
  unsigned int Size; // eax

  Size = this->DisplayObjectArray.Data.Size;
  if ( Size )
    return this->DisplayObjectArray.Data.Data[Size - 1].pCharacter->Depth;
  else
    return -1;
}

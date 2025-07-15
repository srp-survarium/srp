void __thiscall Scaleform::GFx::DisplayObjContainer::SetStateChangeFlags(
        Scaleform::GFx::DisplayObjContainer *this,
        int flags)
{
  unsigned int Size; // ebp
  int v4; // esi

  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  this->Scaleform::GFx::InteractiveObject::Flags ^= (unsigned int)&locret_F0000
                                                  & (this->Scaleform::GFx::InteractiveObject::Flags
                                                   ^ ((unsigned __int8)flags << 16));
  if ( Size )
  {
    v4 = 0;
    do
    {
      this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter->SetStateChangeFlags(
        this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter,
        flags);
      ++v4;
      --Size;
    }
    while ( Size );
  }
}

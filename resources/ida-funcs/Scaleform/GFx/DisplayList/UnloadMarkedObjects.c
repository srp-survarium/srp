void __thiscall Scaleform::GFx::DisplayList::UnloadMarkedObjects(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner)
{
  unsigned int v3; // esi
  int v4; // ebx
  Scaleform::GFx::DisplayObjectBase *pCharacter; // eax

  v3 = 0;
  this->pCachedChar = 0;
  if ( this->DisplayObjectArray.Data.Size )
  {
    v4 = 0;
    do
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v4].pCharacter;
      if ( (pCharacter->Flags & 0x40) != 0 )
      {
        pCharacter->Flags &= ~0x40u;
        if ( Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(this, owner, v3) )
        {
          --v3;
          --v4;
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->DisplayObjectArray.Data.Size );
    this->pCachedChar = 0;
  }
  else
  {
    this->pCachedChar = 0;
  }
}

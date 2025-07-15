char __thiscall Scaleform::GFx::DisplayList::UnloadAll(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner)
{
  unsigned int v3; // esi
  char v4; // bl

  v3 = 0;
  this->pCachedChar = 0;
  v4 = 1;
  while ( v3 < this->DisplayObjectArray.Data.Size )
  {
    if ( !Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(this, owner, v3) )
    {
      ++v3;
      v4 = 0;
    }
  }
  return v4;
}

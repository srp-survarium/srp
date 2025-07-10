void __thiscall Scaleform::GFx::DisplayObjContainer::UpdateViewAndPerspective(
        Scaleform::GFx::DisplayObjContainer *this)
{
  int v2; // esi
  unsigned int Size; // ebx
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx

  Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
  if ( this->mDisplayList.DisplayObjectArray.Data.Size )
  {
    v2 = 0;
    Size = this->mDisplayList.DisplayObjectArray.Data.Size;
    do
    {
      pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[v2].pCharacter;
      if ( pCharacter )
        pCharacter->UpdateViewAndPerspective(pCharacter);
      ++v2;
      --Size;
    }
    while ( Size );
  }
}

void __thiscall Scaleform::GFx::DisplayObjContainer::PropagateScale9GridExists(
        Scaleform::GFx::DisplayObjContainer *this)
{
  bool HasScale9Grid; // al
  bool v3; // dl
  int v4; // edi
  unsigned int Size; // ebp
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx
  bool v7; // [esp+Bh] [ebp-1h]

  HasScale9Grid = Scaleform::GFx::DisplayObjectBase::HasScale9Grid(this);
  v3 = HasScale9Grid;
  v7 = HasScale9Grid;
  if ( ((this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
       & 1) != 0
     || !HasScale9Grid)
    && this->mDisplayList.DisplayObjectArray.Data.Size )
  {
    v4 = 0;
    Size = this->mDisplayList.DisplayObjectArray.Data.Size;
    while ( 1 )
    {
      pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter;
      if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
          & 1) != 0
        || v3 )
      {
        pCharacter->Flags |= 1u;
      }
      else
      {
        pCharacter->Flags &= ~1u;
      }
      pCharacter->PropagateScale9GridExists(pCharacter);
      ++v4;
      if ( !--Size )
        break;
      v3 = v7;
    }
  }
}

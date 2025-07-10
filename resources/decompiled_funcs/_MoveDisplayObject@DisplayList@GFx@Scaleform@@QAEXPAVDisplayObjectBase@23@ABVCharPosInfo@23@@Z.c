void __thiscall Scaleform::GFx::DisplayList::MoveDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        const Scaleform::GFx::CharPosInfo *pos)
{
  int Depth; // ebx
  unsigned int Size; // esi
  unsigned int DisplayIndex; // eax
  Scaleform::GFx::DisplayObjectBase *pCharacter; // esi
  Scaleform::GFx::DisplayList::DisplayEntry *v8; // ecx

  Depth = pos->Depth;
  Size = this->DisplayObjectArray.Data.Size;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, Depth);
  if ( DisplayIndex < Size )
  {
    pCharacter = this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter;
    v8 = &this->DisplayObjectArray.Data.Data[DisplayIndex];
    if ( pCharacter->Depth == Depth )
    {
      pCharacter->Flags &= ~0x40u;
      if ( v8->TreeIndex == -1 )
        Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, DisplayIndex);
      if ( !pCharacter->GetAcceptAnimMoves(pCharacter) )
      {
        if ( !pCharacter->GetContinueAnimationFlag(pCharacter) )
          return;
        pCharacter->SetAcceptAnimMoves(pCharacter, 1);
      }
      if ( (pos->Flags.Flags & 8) != 0 )
        Scaleform::GFx::DisplayObjectBase::SetCxform(pCharacter, &pos->ColorTransform);
      if ( (pos->Flags.Flags & 4) != 0 )
        pCharacter->SetMatrix(pCharacter, &pos->Matrix_1);
      if ( SLOBYTE(pos->Flags.Flags) < 0 )
        pCharacter->SetBlendMode(pCharacter, (Scaleform::Render::BlendMode)pos->BlendMode);
      pCharacter->SetFilters(pCharacter, pos->pFilters.pObject);
      pCharacter->SetRatio(pCharacter, pos->Ratio);
    }
  }
}

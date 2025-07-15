void __thiscall Scaleform::GFx::DisplayList::AddDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        const Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::DisplayObjectBase *ch,
        char addFlags)
{
  int v6; // esi
  unsigned int DisplayIndex; // eax
  unsigned int v9; // ebp
  void (__thiscall *SetBlendMode)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::BlendMode); // edx
  void (__thiscall *OnEventLoad)(Scaleform::GFx::DisplayObjectBase *); // eax
  int depth; // [esp+18h] [ebp-4h]
  unsigned int size; // [esp+24h] [ebp+8h]

  v6 = pos->Depth;
  depth = v6;
  size = this->DisplayObjectArray.Data.Size;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, v6);
  v9 = DisplayIndex;
  this->pCachedChar = 0;
  if ( (addFlags & 1) != 0
    && DisplayIndex < size
    && this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Depth == v6 )
  {
    Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(this, owner, DisplayIndex);
    v9 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, v6);
  }
  ch->Depth = depth;
  Scaleform::GFx::DisplayObjectBase::SetCxform(ch, &pos->ColorTransform);
  ch->SetMatrix(ch, &pos->Matrix_1);
  ((void (__thiscall *)(_DWORD, _DWORD))ch->SetRatio)(ch, pos->Ratio);
  SetBlendMode = ch->SetBlendMode;
  ch->ClipDepth = pos->ClipDepth;
  SetBlendMode(ch, (Scaleform::Render::BlendMode)pos->BlendMode);
  ch->SetFilters(ch, pos->pFilters.pObject);
  Scaleform::GFx::DisplayList::AddEntryAtIndex(this, owner, v9, ch);
  OnEventLoad = ch->OnEventLoad;
  ch->Flags &= 0xEFEFu;
  OnEventLoad(ch);
}

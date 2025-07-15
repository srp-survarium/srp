void __thiscall Scaleform::GFx::DisplayList::AddDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        const Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::DisplayObjectBase *ch,
        char addFlags)
{
  int Depth; // esi
  unsigned int DisplayIndex; // eax
  Scaleform::GFx::DisplayObjectBase *v9; // ebp
  void (__thiscall *SetBlendMode)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::BlendMode); // edx
  void (__thiscall *OnEventLoad)(Scaleform::GFx::DisplayObjectBase *); // eax
  int v13; // [esp+18h] [ebp-4h]
  Scaleform::Render::Cxform *Size; // [esp+24h] [ebp+8h]

  Depth = pos->Depth;
  v13 = Depth;
  Size = (Scaleform::Render::Cxform *)this->DisplayObjectArray.Data.Size;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, Depth);
  v9 = (Scaleform::GFx::DisplayObjectBase *)DisplayIndex;
  this->pCachedChar = 0;
  if ( (addFlags & 1) != 0
    && DisplayIndex < (unsigned int)Size
    && this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Depth == Depth )
  {
    Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(this, owner, DisplayIndex);
    v9 = (Scaleform::GFx::DisplayObjectBase *)Scaleform::GFx::DisplayList::FindDisplayIndex(this, Depth);
  }
  ch->Depth = v13;
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

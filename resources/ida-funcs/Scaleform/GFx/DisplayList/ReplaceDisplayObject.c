void __thiscall Scaleform::GFx::DisplayList::ReplaceDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        const Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  int Depth; // esi
  unsigned int Size; // ebx
  unsigned int DisplayIndex; // eax
  Scaleform::GFx::DisplayList::DisplayEntry *v9; // ebx
  Scaleform::RefCountNTSImpl *pCharacter; // eax
  Scaleform::GFx::DisplayObjectBase_vtbl *v11; // edx
  const Scaleform::Render::Cxform *p_ColorTransform; // eax
  $38A6493503F00953CE568FABD41EE254 *p_Matrix_1; // eax
  Scaleform::Render::BlendMode BlendMode; // eax
  void (__thiscall *SetFilters)(Scaleform::GFx::DisplayObjectBase *, const Scaleform::Render::FilterSet *); // edx
  unsigned __int8 Flags; // al
  Scaleform::GFx::DisplayObjectBase *v17; // [esp+1Ch] [ebp-8h]
  Scaleform::GFx::DisplayObjectBase *v18; // [esp+2Ch] [ebp+8h]

  Depth = pos->Depth;
  Size = this->DisplayObjectArray.Data.Size;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, Depth);
  v17 = (Scaleform::GFx::DisplayObjectBase *)DisplayIndex;
  if ( DisplayIndex < Size
    && (v9 = &this->DisplayObjectArray.Data.Data[DisplayIndex],
        pCharacter = v9->pCharacter,
        v18 = v9->pCharacter,
        v9->pCharacter->Depth == Depth) )
  {
    if ( pCharacter )
      ++pCharacter->RefCount;
    v11 = ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    ch->Depth = Depth;
    v11->Restart(ch);
    v9->pCharacter->Flags &= ~0x40u;
    if ( v9->TreeIndex == -1 )
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, v17);
    if ( v9->pCharacter )
      Scaleform::RefCountNTSImpl::Release(v9->pCharacter);
    v9->pCharacter = ch;
    ++ch->RefCount;
    if ( (pos->Flags.Flags & 8) != 0 )
      p_ColorTransform = &pos->ColorTransform;
    else
      p_ColorTransform = Scaleform::GFx::DisplayObjectBase::GetCxform(v18);
    Scaleform::GFx::DisplayObjectBase::SetCxform(ch, p_ColorTransform);
    if ( (pos->Flags.Flags & 4) != 0 )
      p_Matrix_1 = ($38A6493503F00953CE568FABD41EE254 *)&pos->Matrix_1;
    else
      p_Matrix_1 = ($38A6493503F00953CE568FABD41EE254 *)v18->GetMatrix(v18);
    ch->SetMatrix(ch, (const Scaleform::Render::Matrix2x4<float> *)p_Matrix_1);
    if ( SLOBYTE(pos->Flags.Flags) >= 0 )
      BlendMode = v18->GetBlendMode(v18);
    else
      BlendMode = pos->BlendMode;
    ch->SetBlendMode(ch, BlendMode);
    ((void (__thiscall *)(_DWORD, _DWORD))ch->SetRatio)(ch, pos->Ratio);
    SetFilters = ch->SetFilters;
    ch->ClipDepth = pos->ClipDepth;
    SetFilters(ch, pos->pFilters.pObject);
    Scaleform::GFx::DisplayList::ReplaceRenderTreeNode(this, owner, v17);
    Flags = this->Flags;
    if ( (Flags & 2) != 0 )
      this->Flags = Flags | 1;
    this->pCachedChar = 0;
    v18->OnEventUnload(v18);
    ch->OnEventLoad(ch);
    Scaleform::RefCountNTSImpl::Release(v18);
  }
  else
  {
    Scaleform::GFx::DisplayList::AddDisplayObject(this, owner, pos, ch, 1);
  }
}

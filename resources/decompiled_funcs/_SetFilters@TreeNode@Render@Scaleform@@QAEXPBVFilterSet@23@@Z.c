void __thiscall Scaleform::Render::TreeNode::SetFilters(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::FilterSet *filters)
{
  Scaleform::RefCountVImpl *v3; // ebx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // esi
  Scaleform::Render::ContextImpl::EntryData *v5; // esi

  if ( filters && filters->Filters.Data.Size )
  {
    v3 = (Scaleform::RefCountVImpl *)Scaleform::Render::FilterSet::Clone(filters, 1, 0);
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x200002u);
    Scaleform::Render::StateBag::SetStateVoid(
      (Scaleform::Render::StateBag *)&WritableData[8],
      &Scaleform::Render::FilterState::InterfaceImpl,
      v3);
    WritableData->Flags |= 0x400u;
    if ( v3 )
      Scaleform::RefCountImpl::Release(v3);
  }
  else
  {
    if ( (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                               + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                               + 20)
                   + 6)
        & 0x400) == 0 )
      return;
    v5 = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x200002u);
    Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&v5[8], State_ActionControl);
    v5->Flags &= ~0x400u;
  }
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

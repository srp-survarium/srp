void __thiscall Scaleform::Render::TreeNode::SetOrigScale9Parent(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::TreeNode *origParent)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // esi
  Scaleform::Render::StateBag *v4; // ecx

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, (unsigned int)&_sbh_sizeHeaderList);
  v4 = (Scaleform::Render::StateBag *)&WritableData[8];
  if ( origParent )
  {
    Scaleform::Render::StateBag::SetStateVoid(v4, &Scaleform::Render::OrigScale9ParentState::InterfaceImpl, origParent);
    WritableData->Flags |= 0x2000u;
  }
  else
  {
    Scaleform::Render::StateBag::RemoveState(v4, State_VirtualKeyboardInterface);
    WritableData->Flags &= ~0x2000u;
  }
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

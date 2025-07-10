void __thiscall Scaleform::Render::TreeText::NotifyLayoutChanged(Scaleform::Render::TreeText *this)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

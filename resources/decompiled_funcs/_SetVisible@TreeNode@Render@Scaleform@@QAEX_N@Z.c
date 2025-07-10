void __thiscall Scaleform::Render::TreeNode::SetVisible(Scaleform::Render::TreeNode *this, bool visible)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax
  Scaleform::Render::ContextImpl::Entry *pParent; // ecx

  if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 1) != visible )
  {
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 4u);
    WritableData->Flags = WritableData->Flags & 0xFFFE | visible;
    pParent = this->pParent;
    if ( pParent )
    {
      if ( !pParent->PNode.pPrev )
        Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(pParent);
    }
  }
}

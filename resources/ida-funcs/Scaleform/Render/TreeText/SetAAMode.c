void __thiscall Scaleform::Render::TreeText::SetAAMode(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::AAMode aa)
{
  int v3; // eax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 144);
  if ( v3 )
  {
    if ( aa == AA_Readability )
      *(_BYTE *)(v3 + 261) |= 0x40u;
    else
      *(_BYTE *)(v3 + 261) &= ~0x40u;
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

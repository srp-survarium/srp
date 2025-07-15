void __thiscall Scaleform::Render::TreeText::SetBackgroundColor(
        Scaleform::Render::TreeText *this,
        const Scaleform::Render::Color *bkgColor)
{
  Scaleform::Render::TreeText::SetBackgroundColor(this, bkgColor->Raw);
}


void __thiscall Scaleform::Render::TreeText::SetBackgroundColor(
        Scaleform::Render::TreeText *this,
        unsigned int bkgColor)
{
  int v3; // eax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 144);
  if ( v3 )
    *(_DWORD *)(v3 + 248) = bkgColor;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

void __thiscall Scaleform::Render::TreeText::SetWordWrap(Scaleform::Render::TreeText *this, bool wordWrap)
{
  Scaleform::Render::Text::DocView *v3; // ecx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  v3 = *(Scaleform::Render::Text::DocView **)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                        + 4
                                                        * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                         / 28)
                                                        + 20)
                                            + 144);
  if ( v3 )
  {
    if ( wordWrap )
      Scaleform::Render::Text::DocView::SetWordWrap(v3);
    else
      Scaleform::Render::Text::DocView::ClearWordWrap(v3);
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

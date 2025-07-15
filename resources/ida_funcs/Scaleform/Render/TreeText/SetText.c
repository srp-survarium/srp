void __thiscall Scaleform::Render::TreeText::SetText(
        Scaleform::Render::TreeText *this,
        const char *putf8Str,
        unsigned int lengthInBytes)
{
  Scaleform::Render::Text::DocView *v4; // ecx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  v4 = *(Scaleform::Render::Text::DocView **)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                        + 4
                                                        * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                         / 28)
                                                        + 20)
                                            + 144);
  if ( v4 )
    Scaleform::Render::Text::DocView::SetText(v4, putf8Str, lengthInBytes);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}


void __thiscall Scaleform::Render::TreeText::SetText(
        Scaleform::Render::TreeText *this,
        const wchar_t *pstr,
        unsigned int lengthInChars)
{
  Scaleform::Render::Text::DocView *v4; // ecx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  v4 = *(Scaleform::Render::Text::DocView **)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                        + 4
                                                        * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                         / 28)
                                                        + 20)
                                            + 144);
  if ( v4 )
    Scaleform::Render::Text::DocView::SetText(v4, pstr, lengthInChars);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

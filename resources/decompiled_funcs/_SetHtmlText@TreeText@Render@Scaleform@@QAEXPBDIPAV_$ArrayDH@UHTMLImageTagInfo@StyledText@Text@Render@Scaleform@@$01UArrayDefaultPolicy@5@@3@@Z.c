void __thiscall Scaleform::Render::TreeText::SetHtmlText(
        Scaleform::Render::TreeText *this,
        const char *putf8Str,
        unsigned int lengthInBytes,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  Scaleform::Render::Text::DocView *v5; // ecx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  v5 = *(Scaleform::Render::Text::DocView **)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                        + 4
                                                        * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                         / 28)
                                                        + 20)
                                            + 144);
  if ( v5 )
    Scaleform::Render::Text::DocView::ParseHtml(v5, putf8Str, lengthInBytes, 0, pimgInfoArr, 0, 0, 0);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

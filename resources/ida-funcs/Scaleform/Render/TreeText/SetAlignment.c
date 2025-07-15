void __thiscall Scaleform::Render::TreeText::SetAlignment(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::Alignment a)
{
  int v3; // esi
  Scaleform::Render::Text::DocView *v4; // ecx
  char v5; // al
  int v6; // esi
  const Scaleform::Render::Text::ParagraphFormat *v7; // eax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax
  Scaleform::Render::Text::ParagraphFormat parafmt; // [esp+8h] [ebp-28h] BYREF
  Scaleform::Render::Text::ParagraphFormat result; // [esp+1Ch] [ebp-14h] BYREF

  v3 = *(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                 + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                 + 20);
  v4 = *(Scaleform::Render::Text::DocView **)(v3 + 144);
  if ( v4 )
  {
    switch ( a )
    {
      case Align_TopCenter:
        v5 = 1;
        break;
      case Align_BottomCenter:
        v5 = 3;
        break;
      case Align_CenterLeft:
        v5 = 2;
        break;
      default:
        v5 = 0;
        break;
    }
    parafmt.PresentMask = ((v5 & 3) << 9) | 1;
    parafmt.RefCount = 1;
    memset(&parafmt.pTabStops, 0, 14);
    Scaleform::Render::Text::DocView::SetParagraphFormat(v4, &parafmt, 0, 0xFFFFFFFF);
    v6 = *(_DWORD *)(v3 + 144);
    v7 = Scaleform::Render::Text::ParagraphFormat::Merge(
           *(Scaleform::Render::Text::ParagraphFormat **)(*(_DWORD *)(v6 + 8) + 24),
           &result,
           &parafmt);
    Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
      *(Scaleform::Render::Text::StyledText **)(v6 + 8),
      v7);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&result);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&parafmt);
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

char __thiscall Scaleform::GFx::TextField::TextDocumentListener::View_OnLineFormat(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::DocView *__formal,
        Scaleform::Render::Text::DocView::LineFormatDesc *desc)
{
  Scaleform::RefCountVImpl *v3; // edi
  float *pWidths; // edx
  unsigned int LineStartPos; // ecx
  double v6; // st6
  unsigned int ProposedWordWrapPoint; // eax
  unsigned int ParaTextLen; // edx
  double v9; // st6
  unsigned int NumCharsInLine; // ecx
  double LineWidthBeforeWordWrap; // st6
  unsigned int v12; // eax
  double VisibleRectWidth; // st6
  float *v14; // ecx
  double v15; // st6
  float *v16; // ecx
  unsigned int v17; // eax
  Scaleform::GFx::Translator::LineFormatDesc tdesc; // [esp+8h] [ebp-30h] BYREF

  v3 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(char *, int))(*((_DWORD *)this[-13].View_OnHScroll + 2) + 12))(
                                     (char *)this[-13].View_OnHScroll + 8,
                                     1);
  if ( v3 )
  {
    pWidths = desc->pWidths;
    LineStartPos = desc->LineStartPos;
    v6 = desc->CurrentLineWidth * 0.05000000074505806;
    tdesc.pParaText = desc->pParaText;
    ProposedWordWrapPoint = desc->ProposedWordWrapPoint;
    tdesc.CurrentLineWidth = v6;
    tdesc.pWidths = pWidths;
    ParaTextLen = desc->ParaTextLen;
    v9 = desc->DashSymbolWidth * 0.05000000074505806;
    tdesc.ProposedWordWrapPoint = ProposedWordWrapPoint;
    LOBYTE(ProposedWordWrapPoint) = desc->Alignment;
    tdesc.LineStartPos = LineStartPos;
    NumCharsInLine = desc->NumCharsInLine;
    tdesc.DashSymbolWidth = v9;
    LineWidthBeforeWordWrap = desc->LineWidthBeforeWordWrap;
    tdesc.ParaTextLen = ParaTextLen;
    LOBYTE(ParaTextLen) = desc->UseHyphenation;
    tdesc.Alignment = ProposedWordWrapPoint;
    v12 = 0;
    tdesc.LineWidthBeforeWordWrap = LineWidthBeforeWordWrap * 0.05000000074505806;
    tdesc.NumCharsInLine = NumCharsInLine;
    VisibleRectWidth = desc->VisibleRectWidth;
    tdesc.UseHyphenation = ParaTextLen;
    for ( tdesc.VisibleRectWidth = VisibleRectWidth * 0.05000000074505806;
          v12 < tdesc.NumCharsInLine;
          *v16 = v15 * 0.05000000074505806 )
    {
      v14 = desc->pWidths;
      v15 = v14[v12];
      v16 = &v14[v12++];
    }
    if ( ((unsigned __int8 (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::Translator::LineFormatDesc *))v3->__vftable[1].~Scaleform::RefCountVImpl)(
           v3,
           &tdesc) )
    {
      v17 = tdesc.ProposedWordWrapPoint;
      desc->UseHyphenation = tdesc.UseHyphenation;
      desc->ProposedWordWrapPoint = v17;
      Scaleform::RefCountImpl::Release(v3);
      return 1;
    }
    Scaleform::RefCountImpl::Release(v3);
  }
  return 0;
}

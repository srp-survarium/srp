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
  _DWORD v19[4]; // [esp+8h] [ebp-30h] BYREF
  unsigned int v20; // [esp+18h] [ebp-20h]
  float i; // [esp+1Ch] [ebp-1Ch]
  float v22; // [esp+20h] [ebp-18h]
  float v23; // [esp+24h] [ebp-14h]
  float v24; // [esp+28h] [ebp-10h]
  int v25; // [esp+2Ch] [ebp-Ch]
  unsigned int v26; // [esp+30h] [ebp-8h]
  bool v27; // [esp+34h] [ebp-4h]

  v3 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(char *, int))(*((_DWORD *)this[-13].View_OnHScroll + 2) + 12))(
                                     (char *)this[-13].View_OnHScroll + 8,
                                     1);
  if ( v3 )
  {
    pWidths = desc->pWidths;
    LineStartPos = desc->LineStartPos;
    v6 = desc->CurrentLineWidth * 0.05000000074505806;
    v19[0] = desc->pParaText;
    ProposedWordWrapPoint = desc->ProposedWordWrapPoint;
    v22 = v6;
    v19[2] = pWidths;
    ParaTextLen = desc->ParaTextLen;
    v9 = desc->DashSymbolWidth * 0.05000000074505806;
    v26 = ProposedWordWrapPoint;
    LOBYTE(ProposedWordWrapPoint) = desc->Alignment;
    v19[3] = LineStartPos;
    NumCharsInLine = desc->NumCharsInLine;
    v24 = v9;
    LineWidthBeforeWordWrap = desc->LineWidthBeforeWordWrap;
    v19[1] = ParaTextLen;
    LOBYTE(ParaTextLen) = desc->UseHyphenation;
    LOBYTE(v25) = ProposedWordWrapPoint;
    v12 = 0;
    v23 = LineWidthBeforeWordWrap * 0.05000000074505806;
    v20 = NumCharsInLine;
    VisibleRectWidth = desc->VisibleRectWidth;
    v27 = ParaTextLen;
    for ( i = VisibleRectWidth * 0.05000000074505806; v12 < v20; *v16 = v15 * 0.05000000074505806 )
    {
      v14 = desc->pWidths;
      v15 = v14[v12];
      v16 = &v14[v12++];
    }
    if ( ((unsigned __int8 (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *))v3->__vftable[1].~Scaleform::RefCountVImpl)(
           v3,
           v19) )
    {
      v17 = v26;
      desc->UseHyphenation = v27;
      desc->ProposedWordWrapPoint = v17;
      Scaleform::RefCountImpl::Release(v3);
      return 1;
    }
    Scaleform::RefCountImpl::Release(v3);
  }
  return 0;
}

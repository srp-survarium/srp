char __thiscall Scaleform::Render::Text::DocView::ContainsNonLeftAlignment(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // edx
  unsigned int Size; // esi
  unsigned int v3; // eax
  Scaleform::Render::Text::Paragraph *v4; // ecx

  pObject = this->pDocument.pObject;
  Size = pObject->Paragraphs.Data.Size;
  v3 = 0;
  if ( !Size )
    return 0;
  while ( 1 )
  {
    v4 = v3 >= Size ? 0 : pObject->Paragraphs.Data.Data[v3].pPara;
    if ( (v4->pFormat.pObject->PresentMask & 0x600) != 0 )
      break;
    if ( ++v3 >= Size )
      return 0;
  }
  return 1;
}

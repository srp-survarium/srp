void __thiscall Scaleform::Render::Text::DocView::AppendHtml(
        Scaleform::Render::Text::DocView *this,
        const char *putf8Str,
        unsigned int utf8Len,
        bool condenseWhite,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  unsigned int v5; // eax

  v5 = utf8Len;
  if ( utf8Len == -1 )
    v5 = strlen(putf8Str);
  Scaleform::Render::Text::StyledText::ParseHtml(
    this->pDocument.pObject,
    putf8Str,
    v5,
    pimgInfoArr,
    (this->Flags & 4) != 0,
    condenseWhite,
    0,
    0,
    0);
  this->OnDocumentChanged(this, 6u);
}

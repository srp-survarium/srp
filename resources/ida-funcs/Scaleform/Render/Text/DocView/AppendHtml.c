void __userpurge Scaleform::Render::Text::DocView::AppendHtml(
        Scaleform::Render::Text::DocView *this@<ecx>,
        int a2@<ebp>,
        char *putf8Str,
        unsigned int utf8Len,
        bool condenseWhite,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  int v6; // eax

  v6 = utf8Len;
  if ( utf8Len == -1 )
    v6 = strlen(putf8Str);
  Scaleform::Render::Text::StyledText::ParseHtml(
    this->pDocument.pObject,
    a2,
    putf8Str,
    v6,
    pimgInfoArr,
    (this->Flags & 4) != 0,
    condenseWhite,
    0,
    0,
    0);
  this->OnDocumentChanged(this, 6u);
}

void __thiscall Scaleform::GFx::TextField::AppendHtml(
        Scaleform::GFx::TextField *this,
        const char *putf8Str,
        unsigned int utf8Len,
        bool condenseWhite,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  Scaleform::Render::Text::DocView::AppendHtml(this->pDocument.pObject, putf8Str, utf8Len, condenseWhite, pimgInfoArr);
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
}

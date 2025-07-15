void __thiscall Scaleform::GFx::TextField::AppendText(
        Scaleform::GFx::TextField *this,
        char *putf8Str,
        unsigned int utf8Len)
{
  Scaleform::Render::Text::DocView::AppendText(this->pDocument.pObject, putf8Str, utf8Len);
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
}

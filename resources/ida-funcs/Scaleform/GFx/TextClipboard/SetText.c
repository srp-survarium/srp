void __thiscall Scaleform::GFx::TextClipboard::SetText(
        Scaleform::GFx::TextClipboard *this,
        wchar_t *ptext,
        unsigned int len)
{
  Scaleform::Render::Text::StyledText *pStyledText; // ecx
  wchar_t *v5; // edi

  pStyledText = this->pStyledText;
  if ( pStyledText )
  {
    Scaleform::RefCountNTSImpl::Release(pStyledText);
    this->pStyledText = 0;
  }
  Scaleform::WStringBuffer::SetString(&this->PlainText, ptext, len);
  v5 = this->PlainText.pText;
  if ( !v5 )
    v5 = (wchar_t *)&unk_6E53BC;
  this->OnTextStore(this, v5, this->PlainText.Length);
}

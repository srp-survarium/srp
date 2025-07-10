void __thiscall Scaleform::GFx::TextClipboard::SetTextAndStyledText(
        Scaleform::GFx::TextClipboard *this,
        const wchar_t *ptext,
        unsigned int len,
        Scaleform::Render::Text::StyledText *pstyledText)
{
  Scaleform::Render::Text::StyledText *v5; // ecx
  wchar_t *v6; // edi

  Scaleform::GFx::TextClipboard::SetStyledText(this, (int)this, pstyledText);
  v5 = this->pStyledText;
  if ( v5 )
  {
    Scaleform::RefCountNTSImpl::Release(v5);
    this->pStyledText = 0;
  }
  Scaleform::WStringBuffer::SetString(&this->PlainText, ptext, len);
  v6 = this->PlainText.pText;
  if ( !v6 )
    v6 = (wchar_t *)&word_96B534;
  this->OnTextStore(this, v6, this->PlainText.Length);
}

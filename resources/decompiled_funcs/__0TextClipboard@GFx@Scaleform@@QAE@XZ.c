void __thiscall Scaleform::GFx::TextClipboard::TextClipboard(Scaleform::GFx::TextClipboard *this)
{
  this->__vftable = (Scaleform::GFx::TextClipboard_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->SType = State_TextClipboard;
  this->__vftable = (Scaleform::GFx::TextClipboard_vtbl *)&Scaleform::GFx::TextClipboard::`vftable';
  this->PlainText.pText = 0;
  this->PlainText.Length = 0;
  this->PlainText.Reserved.pBuffer = 0;
  this->PlainText.Reserved.Size = 0;
  this->pStyledText = 0;
}

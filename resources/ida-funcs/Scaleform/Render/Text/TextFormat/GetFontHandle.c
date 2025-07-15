Scaleform::Render::Text::FontHandle *__thiscall Scaleform::Render::Text::TextFormat::GetFontHandle(
        Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Ptr<Scaleform::Render::Text::FontHandle> *p_pFontHandle; // eax
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = 0;
  if ( (this->PresentMask & 0x800) != 0 )
  {
    p_pFontHandle = &this->pFontHandle;
  }
  else
  {
    v3 = 0;
    p_pFontHandle = (Scaleform::Ptr<Scaleform::Render::Text::FontHandle> *)&v3;
  }
  return p_pFontHandle->pObject;
}

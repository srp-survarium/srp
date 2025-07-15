Scaleform::Render::Text::HTMLImageTagDesc *__thiscall Scaleform::Render::Text::TextFormat::GetImageDesc(
        Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Ptr<Scaleform::Render::Text::HTMLImageTagDesc> *p_pImageDesc; // eax
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = 0;
  if ( (this->PresentMask & 0x200) != 0 )
  {
    p_pImageDesc = &this->pImageDesc;
  }
  else
  {
    v3 = 0;
    p_pImageDesc = (Scaleform::Ptr<Scaleform::Render::Text::HTMLImageTagDesc> *)&v3;
  }
  return p_pImageDesc->pObject;
}

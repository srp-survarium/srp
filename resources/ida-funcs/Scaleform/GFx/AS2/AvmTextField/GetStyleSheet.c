const Scaleform::GFx::Text::StyleManager *__thiscall Scaleform::GFx::AS2::AvmTextField::GetStyleSheet(
        Scaleform::GFx::AS2::AvmTextField *this)
{
  unsigned int CSSData; // edi

  CSSData = Scaleform::GFx::TextField::GetCSSData(*((Scaleform::GFx::AS3::SocketThreadMgr **)&this[-1].VariableVal.NV + 3));
  if ( this->GetGC(this) )
    return (const Scaleform::GFx::Text::StyleManager *)(*(_DWORD *)(CSSData + 64) + 52);
  else
    return 0;
}

const Scaleform::GFx::Text::StyleManager *__thiscall Scaleform::GFx::AS3::AvmTextField::GetStyleSheet(
        Scaleform::GFx::AS3::AvmTextField *this)
{
  unsigned int CSSData; // edi

  CSSData = Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)this[-1].pClassName);
  if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AS3::AvmTextField *))this->GetAvmTopParent)(this) )
    return (const Scaleform::GFx::Text::StyleManager *)(*(_DWORD *)(CSSData + 64) + 44);
  else
    return 0;
}

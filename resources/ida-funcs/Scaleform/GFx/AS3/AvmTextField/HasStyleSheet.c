BOOL __thiscall Scaleform::GFx::AS3::AvmTextField::HasStyleSheet(Scaleform::GFx::AS3::AvmTextField *this)
{
  unsigned int CSSData; // eax

  CSSData = Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)this[-1].pClassName);
  return CSSData && *(_DWORD *)(CSSData + 64);
}

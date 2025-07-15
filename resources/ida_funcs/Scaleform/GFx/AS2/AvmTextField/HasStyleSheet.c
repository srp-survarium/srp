BOOL __thiscall Scaleform::GFx::AS2::AvmTextField::HasStyleSheet(Scaleform::GFx::AS2::AvmTextField *this)
{
  unsigned int CSSData; // eax

  CSSData = Scaleform::GFx::TextField::GetCSSData(*((Scaleform::GFx::AS3::SocketThreadMgr **)&this[-1].VariableVal.NV + 3));
  return CSSData && *(_DWORD *)(CSSData + 64);
}

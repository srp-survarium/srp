int __thiscall Scaleform::GFx::TextField::GetTextColor32(Scaleform::GFx::TextField *this)
{
  unsigned int ColorV; // ecx

  ColorV = this->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject->ColorV;
  return (unsigned __int8)ColorV | ((BYTE1(ColorV) | (BYTE2(ColorV) << 8)) << 8);
}

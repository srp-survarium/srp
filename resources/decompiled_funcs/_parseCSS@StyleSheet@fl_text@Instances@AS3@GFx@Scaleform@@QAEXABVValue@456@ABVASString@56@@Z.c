void __thiscall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::parseCSS(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *CSSText)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  _DWORD *v5; // eax

  if ( Scaleform::GFx::Text::StyleManager::ParseCSS(&this->CSS, CSSText->pNode->pData, CSSText->pNode->Size) )
  {
    pObject = this->pTraits.pObject;
    this->CSS.State = LoadingFinished;
    v5 = (_DWORD *)((char *)pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 16244);
    *v5 |= 0x80000u;
  }
  else
  {
    this->CSS.State = Error;
  }
}

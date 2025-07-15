char __thiscall Scaleform::GFx::FontManagerStates::CheckStateChange(
        Scaleform::GFx::FontManagerStates *this,
        Scaleform::GFx::FontLib *pfontLib,
        Scaleform::GFx::FontMap *pfontMap,
        Scaleform::GFx::FontProvider *pfontProvider,
        Scaleform::GFx::Translator *ptranslator)
{
  char v6; // bl
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ecx

  v6 = 0;
  if ( this->pFontLib.pObject != pfontLib )
  {
    v6 = 1;
    if ( pfontLib )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pfontLib);
    pObject = (Scaleform::RefCountVImpl *)this->pFontLib.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFontLib.pObject = pfontLib;
  }
  if ( this->pFontMap.pObject != pfontMap )
  {
    v6 |= 2u;
    if ( pfontMap )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pfontMap);
    v8 = (Scaleform::RefCountVImpl *)this->pFontMap.pObject;
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    this->pFontMap.pObject = pfontMap;
  }
  if ( this->pFontProvider.pObject != pfontProvider )
  {
    v6 |= 4u;
    if ( pfontProvider )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pfontProvider);
    v9 = (Scaleform::RefCountVImpl *)this->pFontProvider.pObject;
    if ( v9 )
      Scaleform::RefCountImpl::Release(v9);
    this->pFontProvider.pObject = pfontProvider;
  }
  if ( this->pTranslator.pObject != ptranslator )
  {
    v6 |= 8u;
    if ( ptranslator )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)ptranslator);
    v10 = (Scaleform::RefCountVImpl *)this->pTranslator.pObject;
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    this->pTranslator.pObject = ptranslator;
  }
  return v6;
}

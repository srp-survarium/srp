char __thiscall Scaleform::GFx::FontManagerStates::CheckStateChange(
        Scaleform::GFx::FontManagerStates *this,
        Scaleform::GFx::Resource *pfontLib,
        Scaleform::GFx::Resource *pfontMap,
        Scaleform::GFx::Resource *pfontProvider,
        Scaleform::GFx::Resource *ptranslator)
{
  char v6; // bl
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ecx

  v6 = 0;
  if ( (Scaleform::GFx::Resource *)this->pFontLib.pObject != pfontLib )
  {
    v6 = 1;
    if ( pfontLib )
      Scaleform::RefCountImpl::AddRef(pfontLib);
    pObject = (Scaleform::RefCountVImpl *)this->pFontLib.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFontLib.pObject = (Scaleform::GFx::FontLib *)pfontLib;
  }
  if ( (Scaleform::GFx::Resource *)this->pFontMap.pObject != pfontMap )
  {
    v6 |= 2u;
    if ( pfontMap )
      Scaleform::RefCountImpl::AddRef(pfontMap);
    v8 = (Scaleform::RefCountVImpl *)this->pFontMap.pObject;
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    this->pFontMap.pObject = (Scaleform::GFx::FontMap *)pfontMap;
  }
  if ( (Scaleform::GFx::Resource *)this->pFontProvider.pObject != pfontProvider )
  {
    v6 |= 4u;
    if ( pfontProvider )
      Scaleform::RefCountImpl::AddRef(pfontProvider);
    v9 = (Scaleform::RefCountVImpl *)this->pFontProvider.pObject;
    if ( v9 )
      Scaleform::RefCountImpl::Release(v9);
    this->pFontProvider.pObject = (Scaleform::GFx::FontProvider *)pfontProvider;
  }
  if ( (Scaleform::GFx::Resource *)this->pTranslator.pObject != ptranslator )
  {
    v6 |= 8u;
    if ( ptranslator )
      Scaleform::RefCountImpl::AddRef(ptranslator);
    v10 = (Scaleform::RefCountVImpl *)this->pTranslator.pObject;
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    this->pTranslator.pObject = (Scaleform::GFx::Translator *)ptranslator;
  }
  return v6;
}

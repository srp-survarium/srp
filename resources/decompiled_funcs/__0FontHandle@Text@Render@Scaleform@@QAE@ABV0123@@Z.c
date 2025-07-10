void __thiscall Scaleform::Render::Text::FontHandle::FontHandle(
        Scaleform::Render::Text::FontHandle *this,
        const Scaleform::Render::Text::FontHandle *f)
{
  Scaleform::GFx::Resource *pObject; // ecx

  this->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::Render::Text::FontHandle::`vftable';
  this->pFontManager = f->pFontManager;
  this->OverridenFontFlags = f->OverridenFontFlags;
  Scaleform::StringLH::CopyConstructHelper(&this->FontName, &f->FontName);
  this->FontScaleFactor = f->FontScaleFactor;
  pObject = (Scaleform::GFx::Resource *)f->pFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  this->pFont.pObject = f->pFont.pObject;
}

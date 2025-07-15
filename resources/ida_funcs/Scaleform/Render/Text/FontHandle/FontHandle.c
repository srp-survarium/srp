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


void __thiscall Scaleform::Render::Text::FontHandle::FontHandle(
        Scaleform::Render::Text::FontHandle *this,
        Scaleform::Render::Text::FontManagerBase *pmanager,
        Scaleform::GFx::Resource *pfont,
        char *pfontName,
        unsigned int overridenFontFlags)
{
  const char *v6; // eax

  this->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->OverridenFontFlags = overridenFontFlags;
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::Render::Text::FontHandle::`vftable';
  this->pFontManager = pmanager;
  Scaleform::StringLH::StringLH(&this->FontName);
  this->FontScaleFactor = 1.0;
  if ( pfont )
    Scaleform::RefCountImpl::AddRef(pfont);
  this->pFont.pObject = (Scaleform::Render::Font *)pfont;
  if ( pfontName )
  {
    v6 = (const char *)((int (__thiscall *)(Scaleform::GFx::Resource *))pfont->GetKey)(pfont);
    if ( Scaleform::String::CompareNoCase(v6, pfontName) )
      Scaleform::String::operator=(&this->FontName, pfontName);
  }
}

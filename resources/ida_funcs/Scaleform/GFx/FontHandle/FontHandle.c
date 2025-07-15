void __thiscall Scaleform::GFx::FontHandle::FontHandle(
        Scaleform::GFx::FontHandle *this,
        const Scaleform::GFx::FontHandle *f)
{
  Scaleform::GFx::MovieDef *pObject; // ecx

  Scaleform::Render::Text::FontHandle::FontHandle(this, f);
  this->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
  pObject = f->pSourceMovieDef.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  this->pSourceMovieDef.pObject = f->pSourceMovieDef.pObject;
}


void __thiscall Scaleform::GFx::FontHandle::FontHandle(
        Scaleform::GFx::FontHandle *this,
        Scaleform::Render::Text::FontManagerBase *pmanager,
        Scaleform::GFx::Resource *pfont,
        char *pfontName,
        unsigned int overridenFontFlags,
        Scaleform::GFx::MovieDef *pdefImpl)
{
  Scaleform::Render::Text::FontHandle::FontHandle(this, pmanager, pfont, pfontName, overridenFontFlags);
  this->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
  if ( pdefImpl )
    Scaleform::RefCountImpl::AddRef(pdefImpl);
  this->pSourceMovieDef.pObject = pdefImpl;
}

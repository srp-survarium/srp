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

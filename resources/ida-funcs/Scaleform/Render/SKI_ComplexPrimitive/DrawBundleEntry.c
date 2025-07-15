void __thiscall Scaleform::Render::SKI_ComplexPrimitive::DrawBundleEntry(
        Scaleform::Render::SKI_ComplexPrimitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::Render::ComplexPrimitiveBundle *pObject; // ecx

  pObject = (Scaleform::Render::ComplexPrimitiveBundle *)p->pBundle.pObject;
  if ( pObject )
    Scaleform::Render::ComplexPrimitiveBundle::Draw(pObject, r->pHal.pObject);
}

void __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::ForEachChild_GC(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Traits::ForEachChild_GC(this, prcc, op);
  if ( this->Ns.pObject )
    op(prcc, &this->Ns.pObject, this);
}

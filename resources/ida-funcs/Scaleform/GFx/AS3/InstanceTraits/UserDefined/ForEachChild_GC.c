void __thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::ForEachChild_GC(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::ClassTraits::Traits::ForEachChild_GC(this, prcc, op);
  if ( this->Script.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Script.pObject, this);
}

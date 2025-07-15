void __thiscall Scaleform::GFx::AS3::ClassTraits::Function::ForEachChild_GC(
        Scaleform::GFx::AS3::ClassTraits::Function *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::InstanceTraits::Traits::ForEachChild_GC(
    (Scaleform::GFx::AS3::InstanceTraits::Traits *)this,
    prcc,
    op);
  if ( this->ThunkTraits.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->ThunkTraits.pObject);
  if ( this->ThunkFunctionTraits.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->ThunkFunctionTraits.pObject);
  if ( this->MethodIndTraits.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->MethodIndTraits.pObject);
  if ( this->VTableTraits.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->VTableTraits.pObject);
}

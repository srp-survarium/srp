void __thiscall Scaleform::GFx::AS3::ClassTraits::UserDefined::ForEachChild_GC(
        Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::ClassTraits::Traits::ForEachChild_GC(
    (Scaleform::GFx::AS3::InstanceTraits::Traits *)this,
    prcc,
    op);
  if ( this->EnclosedClassTraits.pObject )
    op(prcc, &this->EnclosedClassTraits.pObject, this);
}

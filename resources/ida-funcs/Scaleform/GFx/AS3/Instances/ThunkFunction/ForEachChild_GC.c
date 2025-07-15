void __thiscall Scaleform::GFx::AS3::Instances::ThunkFunction::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::ThunkFunction *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->OriginationTraits.pObject )
    op(prcc, &this->OriginationTraits.pObject, this);
}

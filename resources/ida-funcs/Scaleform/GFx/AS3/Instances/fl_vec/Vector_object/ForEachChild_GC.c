void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ForEachChild_GC(&this->V, prcc, op, this);
}

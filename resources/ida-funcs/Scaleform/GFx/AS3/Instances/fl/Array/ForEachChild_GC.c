void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  Scaleform::GFx::AS3::Impl::SparseArray::ForEachChild_GC(&this->SA, prcc, op, this);
}

void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::ForEachChild_GC(
        Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::InstanceTraits::CTraits::ForEachChild_GC(this, prcc, op);
  if ( this->File.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->File.pObject, this);
}

void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->DataObj.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->DataObj.pObject);
}

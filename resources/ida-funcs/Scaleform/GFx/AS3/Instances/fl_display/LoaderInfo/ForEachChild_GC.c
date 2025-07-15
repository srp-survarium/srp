void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ForEachChild_GC(this, prcc, op);
  if ( this->Content.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Content.pObject, this);
  if ( this->pLoader.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->pLoader.pObject, this);
}

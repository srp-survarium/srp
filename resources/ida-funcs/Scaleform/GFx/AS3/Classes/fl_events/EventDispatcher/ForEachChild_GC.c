void __thiscall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::ForEachChild_GC(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Class::ForEachChild_GC(this, prcc, op);
  if ( this->EventTraits.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->EventTraits.pObject);
  if ( this->MouseEventTraits.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->MouseEventTraits.pObject);
}

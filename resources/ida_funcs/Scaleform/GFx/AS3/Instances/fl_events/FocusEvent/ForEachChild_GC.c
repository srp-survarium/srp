void __thiscall Scaleform::GFx::AS3::Instances::fl_events::FocusEvent::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->CurrentTarget.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->CurrentTarget.pObject);
  if ( this->Target.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Target.pObject);
  if ( this->RelatedObj.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->RelatedObj.pObject);
}

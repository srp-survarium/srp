void __thiscall Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->CurrentTarget.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->CurrentTarget.pObject, this);
  if ( this->Target.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Target.pObject, this);
  if ( this->RelatedObj.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->RelatedObj.pObject, this);
}

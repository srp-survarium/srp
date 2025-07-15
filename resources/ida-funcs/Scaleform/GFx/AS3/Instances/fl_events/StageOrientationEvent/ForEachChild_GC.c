void __thiscall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->CurrentTarget.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->CurrentTarget.pObject);
  if ( this->Target.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Target.pObject);
  if ( (this->BeforeOrientation.Flags & 0x1F) > 0xA && (this->BeforeOrientation.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->BeforeOrientation, op);
  if ( (this->AfterOrientation.Flags & 0x1F) > 0xA && (this->AfterOrientation.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->AfterOrientation, op);
}

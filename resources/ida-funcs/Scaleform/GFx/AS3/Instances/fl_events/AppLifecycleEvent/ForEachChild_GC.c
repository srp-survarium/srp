void __thiscall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Value *p_Status; // eax
  unsigned int Flags; // esi

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->CurrentTarget.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->CurrentTarget.pObject);
  if ( this->Target.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Target.pObject);
  p_Status = &this->Status;
  Flags = this->Status.Flags;
  if ( (Flags & 0x1F) > 0xA && (Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, p_Status, op);
}

void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // ecx

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  pObject = this->pImpl.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::ForEachChild_GC(
      &pObject->CaptureListeners,
      prcc,
      op,
      this->VMRef,
      this,
      1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::ForEachChild_GC(
      &this->pImpl.pObject->Listeners,
      prcc,
      op,
      this->VMRef,
      this,
      0);
  }
}

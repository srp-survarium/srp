void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ForEachChild_GC(this, prcc, op);
  if ( this->pChannel.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->pChannel.pObject, this);
}

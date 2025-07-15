void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::ForEachChild_GC(this, prcc, op);
  if ( this->pGraphics.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->pGraphics.pObject, this);
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::ForEachChild_GC(
    &this->mFrameScript,
    prcc,
    op,
    this);
}

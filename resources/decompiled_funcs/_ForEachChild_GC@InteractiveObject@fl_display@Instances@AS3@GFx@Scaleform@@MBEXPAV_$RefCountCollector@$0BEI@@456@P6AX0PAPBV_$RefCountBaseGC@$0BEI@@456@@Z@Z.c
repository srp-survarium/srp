void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ForEachChild_GC(this, prcc, op);
  if ( this->pLoaderInfo.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->pLoaderInfo.pObject);
  if ( this->pBitmapData.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->pBitmapData.pObject);
}

void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::disableBatching(
        Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o,
        bool b)
{
  if ( o )
    Scaleform::GFx::DisplayObjectBase::DisableBatching(o->pDispObj.pObject, b);
}

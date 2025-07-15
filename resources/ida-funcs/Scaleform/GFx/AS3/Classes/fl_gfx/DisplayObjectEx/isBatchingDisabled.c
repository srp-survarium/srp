void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::isBatchingDisabled(
        Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o)
{
  if ( o )
    *result = Scaleform::GFx::DisplayObjectBase::IsBatchingDisabled(o->pDispObj.pObject);
}

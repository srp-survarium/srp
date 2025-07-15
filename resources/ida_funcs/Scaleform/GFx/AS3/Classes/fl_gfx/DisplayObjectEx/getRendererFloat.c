void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::getRendererFloat(
        Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this,
        long double *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o)
{
  if ( o )
    *result = Scaleform::GFx::DisplayObjectBase::GetRendererFloat(o->pDispObj.pObject);
}

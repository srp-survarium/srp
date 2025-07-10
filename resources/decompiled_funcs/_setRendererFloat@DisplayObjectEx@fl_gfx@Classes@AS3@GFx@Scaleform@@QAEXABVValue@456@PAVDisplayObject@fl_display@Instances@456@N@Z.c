void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::setRendererFloat(
        Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o,
        long double f)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  float oa; // [esp+Ch] [ebp+8h]

  if ( o )
  {
    pObject = o->pDispObj.pObject;
    oa = f;
    Scaleform::GFx::DisplayObjectBase::SetRendererFloat(pObject, (Scaleform::String::DataDesc *)LODWORD(oa));
  }
}

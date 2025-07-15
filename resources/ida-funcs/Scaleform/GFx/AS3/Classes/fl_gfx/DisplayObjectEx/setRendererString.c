void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::setRendererString(
        Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o,
        const Scaleform::GFx::ASString *s)
{
  if ( o )
    Scaleform::GFx::DisplayObjectBase::SetRendererString(o->pDispObj.pObject, (const __m128i *)s->pNode->pData);
}

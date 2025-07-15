void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::colorSet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::Render::Filter_vtbl *value)
{
  Scaleform::Render::Filter *pObject; // eax
  char v4; // cl

  pObject = this->FilterData.pObject;
  v4 = *(&pObject[2].Frozen + 3);
  pObject = (Scaleform::Render::Filter *)((char *)pObject + 44);
  pObject->__vftable = value;
  HIBYTE(pObject->__vftable) = v4;
}

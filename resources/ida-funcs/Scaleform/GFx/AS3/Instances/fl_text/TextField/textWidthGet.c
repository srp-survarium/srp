void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::textWidthGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        long double *result)
{
  *result = Scaleform::GFx::TextField::GetTextWidth((Scaleform::GFx::TextField *)this->pDispObj.pObject);
}

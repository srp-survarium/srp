void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::textHeightGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        long double *result)
{
  *result = Scaleform::GFx::TextField::GetTextHeight((Scaleform::GFx::TextField *)this->pDispObj.pObject);
}

void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::textColorGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        unsigned int *result)
{
  *result = Scaleform::GFx::TextField::GetTextColor32((Scaleform::GFx::TextField *)this->pDispObj.pObject);
}

void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::selectionBeginIndexGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result)
{
  *result = (int)Scaleform::GFx::TextField::GetBeginIndex((Scaleform::GFx::TextField *)this->pDispObj.pObject);
}

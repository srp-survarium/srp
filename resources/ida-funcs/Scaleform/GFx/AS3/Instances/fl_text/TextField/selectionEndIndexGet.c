void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::selectionEndIndexGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result)
{
  *result = (int)Scaleform::GFx::TextField::GetEndIndex((Scaleform::GFx::TextField *)this->pDispObj.pObject);
}

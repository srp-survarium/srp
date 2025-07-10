void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::caretIndexGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result)
{
  *result = (int)Scaleform::GFx::TextField::GetCaretIndex((Scaleform::GFx::TextField *)this->pDispObj.pObject);
}

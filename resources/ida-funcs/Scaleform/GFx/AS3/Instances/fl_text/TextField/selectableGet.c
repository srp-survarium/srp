void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::selectableGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        bool *result)
{
  *result = Scaleform::GFx::TextField::IsSelectable((Scaleform::GFx::TextField *)this->pDispObj.pObject);
}

void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::lengthGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result)
{
  *result = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)this->pDispObj.pObject[1].pRenNode.pObject->pNative);
}

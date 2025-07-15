void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getParagraphLength(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result,
        unsigned int charIndex)
{
  *result = Scaleform::Render::Text::DocView::GetParagraphLength(
              (Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject,
              charIndex);
}

void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getFirstCharInParagraph(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result,
        int charIndex)
{
  int FirstCharInParagraph; // eax

  if ( charIndex < 0
    || (FirstCharInParagraph = Scaleform::Render::Text::DocView::GetFirstCharInParagraph(
                                 (Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject,
                                 charIndex),
        FirstCharInParagraph == -1) )
  {
    *result = -1;
  }
  else
  {
    *result = FirstCharInParagraph;
  }
}

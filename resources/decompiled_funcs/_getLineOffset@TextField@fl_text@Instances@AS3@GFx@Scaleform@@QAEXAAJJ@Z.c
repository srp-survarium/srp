void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineOffset(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result,
        int lineIndex)
{
  unsigned int LineOffset; // eax

  if ( lineIndex < 0
    || (LineOffset = Scaleform::Render::Text::DocView::GetLineOffset(
                       (Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject,
                       lineIndex),
        LineOffset == -1) )
  {
    *result = -1;
  }
  else
  {
    *result = LineOffset;
  }
}

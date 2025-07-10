void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineLength(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result,
        int lineIndex)
{
  unsigned int LineLength; // eax

  if ( lineIndex < 0
    || (LineLength = Scaleform::Render::Text::DocView::GetLineLength(
                       (Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject,
                       lineIndex,
                       0),
        LineLength == -1) )
  {
    *result = -1;
  }
  else
  {
    *result = LineLength;
  }
}

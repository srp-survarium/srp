void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineIndexOfChar(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result,
        int charIndex)
{
  int LineIndexOfChar; // eax

  if ( charIndex < 0
    || (LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(
                            (Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject,
                            charIndex),
        LineIndexOfChar == -1) )
  {
    *result = -1;
  }
  else
  {
    *result = LineIndexOfChar;
  }
}

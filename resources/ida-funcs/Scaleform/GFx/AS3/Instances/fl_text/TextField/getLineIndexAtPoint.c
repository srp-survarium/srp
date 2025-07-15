void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineIndexAtPoint(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result,
        long double x,
        long double y)
{
  int LineIndexAtPoint; // eax
  float v5; // [esp+4h] [ebp-4h]
  float ya; // [esp+18h] [ebp+10h]
  float yb; // [esp+18h] [ebp+10h]

  ya = y * 20.0;
  v5 = ya;
  yb = 20.0 * x;
  LineIndexAtPoint = Scaleform::Render::Text::DocView::GetLineIndexAtPoint(
                       (Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject,
                       yb,
                       v5);
  if ( LineIndexAtPoint == -1 )
    *result = -1;
  else
    *result = LineIndexAtPoint;
}

void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getCharIndexAtPoint(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        int *result,
        long double x,
        long double y)
{
  int CharIndexAtPoint; // eax
  float v5; // [esp+4h] [ebp-4h]
  float ya; // [esp+18h] [ebp+10h]
  float yb; // [esp+18h] [ebp+10h]

  ya = y * 20.0;
  v5 = ya;
  yb = 20.0 * x;
  CharIndexAtPoint = Scaleform::Render::Text::DocView::GetCharIndexAtPoint(
                       (Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject,
                       yb,
                       v5);
  if ( CharIndexAtPoint == -1 )
    *result = -1;
  else
    *result = CharIndexAtPoint;
}

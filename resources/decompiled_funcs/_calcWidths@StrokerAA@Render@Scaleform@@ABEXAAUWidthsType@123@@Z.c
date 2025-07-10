void __thiscall Scaleform::Render::StrokerAA::calcWidths(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::StrokerAA::WidthsType *w)
{
  double v3; // st6
  double v4; // st5
  bool v5; // c0
  bool v6; // al
  double totalWidthR; // st7
  bool v8; // al
  double v9; // st7
  bool wa; // [esp+4h] [ebp+4h]

  w->solidWidthL = this->WidthLeft;
  w->solidWidthR = this->WidthRight;
  if ( w->solidWidthL < 0.0 )
    w->solidWidthL = 0.0;
  if ( w->solidWidthR < 0.0 )
    w->solidWidthR = 0.0;
  w->totalWidthL = this->AaWidthLeft + w->solidWidthL;
  w->totalWidthR = this->AaWidthRight + w->solidWidthR;
  v3 = 1.0;
  if ( 0.0 == w->totalWidthL )
    v4 = 1.0;
  else
    v4 = w->solidWidthL / w->totalWidthL;
  w->solidCoeffL = v4;
  if ( 0.0 != w->totalWidthR )
    v3 = w->solidWidthR / w->totalWidthR;
  w->solidCoeffR = v3;
  w->solidLimitL = this->MiterLimit * w->solidWidthL;
  w->solidLimitR = w->solidWidthR * this->MiterLimit;
  w->totalLimitL = this->MiterLimit * w->totalWidthL;
  w->totalLimitR = w->totalWidthR * this->MiterLimit;
  w->totalWidth = (w->totalWidthR + w->totalWidthL) * 0.5;
  w->solidWidth = 0.5 * (w->solidWidthR + w->solidWidthL);
  wa = w->solidWidthL > 0.0;
  v5 = w->solidWidthR > 0.0;
  w->solidFlagL = wa;
  w->solidFlagR = v5;
  w->aaFlagL = this->AaWidthLeft > 0.0;
  w->aaFlagR = this->AaWidthRight > 0.0;
  v6 = wa || v5 || this->StyleLeft != this->StyleRight;
  totalWidthR = w->totalWidthR;
  w->solidFlag = v6;
  v8 = w->totalWidthL < totalWidthR;
  w->rightSideCalc = v8;
  if ( v8 )
    v9 = w->totalWidthL / w->totalWidthR;
  else
    v9 = w->totalWidthR / w->totalWidthL;
  w->widthCoeff = v9;
}

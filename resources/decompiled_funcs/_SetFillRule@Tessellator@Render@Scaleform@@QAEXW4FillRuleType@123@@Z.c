void __thiscall Scaleform::Render::Tessellator::SetFillRule(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::FillRuleType f)
{
  if ( f == FillStroker )
  {
    this->FillRule = FillNonZero;
    this->StrokerMode = 1;
  }
  else
  {
    this->FillRule = f;
    this->StrokerMode = 0;
  }
}

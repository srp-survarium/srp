void __thiscall Scaleform::GFx::DrawingContext::FinishPath(Scaleform::GFx::DrawingContext *this)
{
  unsigned __int8 States; // al
  double Ex; // st7
  double StX; // st6

  States = this->States;
  if ( (States & 0x10) != 0 )
  {
    Ex = this->Ex;
    StX = this->StX;
    this->States = States & 0xEF;
    if ( StX != Ex || this->StY != this->Ey )
      Scaleform::GFx::DrawingContext::LineTo(this, this->StX, this->StY);
  }
}

void __thiscall Scaleform::GFx::DrawingContext::MoveTo(Scaleform::GFx::DrawingContext *this, float x, float y)
{
  unsigned __int8 States; // al
  Scaleform::Render::ShapePosInfo pos; // [esp+14h] [ebp-38h] BYREF

  pos.Sfactor = 1.0;
  memset(&pos, 0, 48);
  pos.Initialized = 0;
  States = this->States;
  qmemcpy(&this->PosInfo, &pos, sizeof(this->PosInfo));
  if ( (States & 4) == 0 && (States & 0x10) != 0 && (this->StX != this->Ex || this->StY != this->Ey) )
    Scaleform::GFx::DrawingContext::LineTo(this, this->StX, this->StY);
  Scaleform::GFx::DrawingContext::NewPath(this, x, y);
  this->States &= ~4u;
  this->StX = x;
  this->StY = y;
}

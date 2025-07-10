void __thiscall Scaleform::Render::StrokerAA::ClosePath(Scaleform::Render::StrokerAA *this)
{
  Scaleform::Render::StrokePath::ClosePath(&this->Path);
  this->Closed = 1;
}

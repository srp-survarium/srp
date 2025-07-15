void __thiscall Scaleform::GFx::AMP::ViewStats::DebugGo(Scaleform::GFx::AMP::ViewStats *this)
{
  this->CallstackDepthPause = -1;
  Scaleform::Event::SetEvent(&this->DebugEvent);
}

void __thiscall Scaleform::GFx::AMP::ViewStats::DebugPause(Scaleform::GFx::AMP::ViewStats *this)
{
  this->CallstackDepthPause = -1;
  Scaleform::Event::ResetEvent(&this->DebugEvent);
}

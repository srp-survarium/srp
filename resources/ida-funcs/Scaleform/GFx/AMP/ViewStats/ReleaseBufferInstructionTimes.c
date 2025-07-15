void __thiscall Scaleform::GFx::AMP::ViewStats::ReleaseBufferInstructionTimes(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Mutex::Unlock(&this->InstructionTimingMutex);
}

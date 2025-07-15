void __thiscall Scaleform::GFx::AMP::ViewStats::DebugStep(Scaleform::GFx::AMP::ViewStats *this, int depth)
{
  Scaleform::Waitable::HandlerArray *v2; // eax
  Scaleform::Event *p_DebugEvent; // ecx

  v2 = (Scaleform::Waitable::HandlerArray *)(depth + this->Callstack.Data.Size);
  p_DebugEvent = &this->DebugEvent;
  p_DebugEvent[-5].StateMutex.pHandlers = v2;
  Scaleform::Event::PulseEvent(p_DebugEvent);
}

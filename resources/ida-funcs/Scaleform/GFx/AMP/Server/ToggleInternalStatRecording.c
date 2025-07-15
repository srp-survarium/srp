void __thiscall Scaleform::GFx::AMP::Server::ToggleInternalStatRecording(Scaleform::GFx::AMP::Server *this)
{
  Scaleform::MemoryHeap **p_ReportHeap; // edi

  p_ReportHeap = &this->ReportHeap;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->ReportHeap);
  if ( this->AppControlCaps.pObject == (Scaleform::GFx::AMP::MessageAppControl *)1 )
    this->AppControlCaps.pObject = (Scaleform::GFx::AMP::MessageAppControl *)2;
  else
    this->AppControlCaps.pObject = (Scaleform::GFx::AMP::MessageAppControl *)1;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_ReportHeap);
}

void __thiscall Scaleform::GFx::AMP::ViewStats::RefreshActiveLine(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::GFx::AMP::ViewStats::CallInfo *v2; // edi

  if ( this->Callstack.Data.Size )
  {
    v2 = &this->Callstack.Data.Data[this->Callstack.Data.Size - 1];
    EnterCriticalSection(&this->ActiveLock.cs);
    this->ActiveFileId = v2->FileId;
    this->ActiveLineNumber = v2->LineNumber;
    LeaveCriticalSection(&this->ActiveLock.cs);
  }
}

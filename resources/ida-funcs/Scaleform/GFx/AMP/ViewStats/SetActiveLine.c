void __thiscall Scaleform::GFx::AMP::ViewStats::SetActiveLine(
        Scaleform::GFx::AMP::ViewStats *this,
        unsigned int lineNumber)
{
  Scaleform::GFx::AMP::ViewStats::CallInfo *v3; // edi

  if ( this->Callstack.Data.Size )
  {
    this->Callstack.Data.Data[this->Callstack.Data.Size - 1].LineNumber = lineNumber;
    if ( this->Callstack.Data.Size )
    {
      v3 = &this->Callstack.Data.Data[this->Callstack.Data.Size - 1];
      EnterCriticalSection(&this->ActiveLock.cs);
      this->ActiveFileId = v3->FileId;
      this->ActiveLineNumber = v3->LineNumber;
      LeaveCriticalSection(&this->ActiveLock.cs);
    }
  }
  else
  {
    EnterCriticalSection(&this->ActiveLock.cs);
    this->ActiveLineNumber = lineNumber;
    LeaveCriticalSection(&this->ActiveLock.cs);
  }
}

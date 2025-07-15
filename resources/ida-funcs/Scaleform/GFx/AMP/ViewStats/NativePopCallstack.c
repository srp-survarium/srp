void __thiscall Scaleform::GFx::AMP::ViewStats::NativePopCallstack(
        Scaleform::GFx::AMP::ViewStats *this,
        unsigned __int64 time)
{
  Scaleform::Lock *p_ViewLock; // edi
  Scaleform::GFx::AMP::FuncTreeItem *pObject; // eax

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  if ( this->Callstack.Data.Size )
  {
    pObject = this->Callstack.Data.Data[this->Callstack.Data.Size - 1].FunctionInfo.pObject;
    Scaleform::GFx::AMP::ViewStats::PopCallstack(
      this,
      *(Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> *)((char *)&pObject->FunctionId + 4),
      pObject->FunctionId,
      time);
  }
  LeaveCriticalSection(&p_ViewLock->cs);
}

void __thiscall Scaleform::GFx::AMP::ViewStats::CollectTimingStats(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::GFx::AMP::ProfileFrame *pFrameInfo)
{
  Scaleform::Lock *p_ViewLock; // esi
  bool v4; // zf
  Scaleform::GFx::AMP::FuncTreeItem *pObject; // esi
  unsigned int j; // edi
  unsigned int i; // [esp+10h] [ebp-10h]
  Scaleform::Lock *locker; // [esp+14h] [ebp-Ch]
  Scaleform::GFx::AMP::FuncStatsVisitor visitor; // [esp+18h] [ebp-8h] BYREF

  p_ViewLock = &this->ViewLock;
  locker = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  v4 = this->FunctionRoots.Data.Size == 0;
  visitor.FrameInfo = pFrameInfo;
  visitor.CallingView = this;
  i = 0;
  if ( !v4 )
  {
    do
    {
      pObject = this->FunctionRoots.Data.Data[i].pObject;
      Scaleform::GFx::AMP::ViewStats::UpdateStats(
        visitor.CallingView,
        pObject->FunctionId,
        LODWORD(pObject->EndTime) - LODWORD(pObject->BeginTime),
        1u,
        visitor.FrameInfo);
      for ( j = 0; j < pObject->Children.Data.Size; ++j )
        Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::FuncStatsVisitor>(
          pObject->Children.Data.Data[j].pObject,
          &visitor);
      ++i;
    }
    while ( i < this->FunctionRoots.Data.Size );
    p_ViewLock = locker;
  }
  LeaveCriticalSection(&p_ViewLock->cs);
}

void __thiscall Scaleform::GFx::AMP::ViewStats::PushCallstack(
        Scaleform::GFx::AMP::ViewStats *this,
        unsigned int swdHandle,
        unsigned int swfOffset,
        unsigned __int64 funcTime)
{
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  Scaleform::GFx::AMP::ViewStats::CallInfo *v7; // ebp
  Scaleform::GFx::AMP::ViewStats::CallInfo *v8; // ebx
  int v9; // [esp+10h] [ebp-8h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+14h] [ebp-4h]

  lpCriticalSection = &this->ViewLock.cs;
  EnterCriticalSection(&this->ViewLock.cs);
  v9 = 2;
  v5 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 48, &v9);
  if ( v5 )
  {
    *v5 = &Scaleform::RefCountImplCore::`vftable';
    v5[1] = 1;
    *v5 = &Scaleform::GFx::AMP::FuncTreeItem::`vftable';
    v5[9] = 0;
    v5[10] = 0;
    v5[11] = 0;
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  *((_QWORD *)v6 + 2) = funcTime;
  *((_QWORD *)v6 + 1) = swfOffset + ((unsigned __int64)swdHandle << 32);
  v6[8] = ++this->NextTreeItemId;
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
  Scaleform::ArrayDataBase<Scaleform::GFx::AMP::ViewStats::CallInfo,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::CallInfo,581>,Scaleform::ArrayConstPolicy<0,4,1>>::ResizeNoConstruct(
    &this->Callstack.Data,
    &this->Callstack,
    this->Callstack.Data.Size + 1);
  v7 = &this->Callstack.Data.Data[this->Callstack.Data.Size - 1];
  if ( &this->Callstack.Data.Data[this->Callstack.Data.Size] != (Scaleform::GFx::AMP::ViewStats::CallInfo *)24 )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
    v7->FunctionInfo.pObject = (Scaleform::GFx::AMP::FuncTreeItem *)v6;
    LODWORD(v7->FileId) = 0;
    HIDWORD(v7->FileId) = 0;
    v7->LineNumber = 0;
  }
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
  if ( this->Callstack.Data.Size )
  {
    v8 = &this->Callstack.Data.Data[this->Callstack.Data.Size - 1];
    EnterCriticalSection(&this->ActiveLock.cs);
    LODWORD(this->ActiveFileId) = v8->FileId;
    HIDWORD(this->ActiveFileId) = HIDWORD(v8->FileId);
    this->ActiveLineNumber = v8->LineNumber;
    LeaveCriticalSection(&this->ActiveLock.cs);
  }
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
  LeaveCriticalSection(lpCriticalSection);
}

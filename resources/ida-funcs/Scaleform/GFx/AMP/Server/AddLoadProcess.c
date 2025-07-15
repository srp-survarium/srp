void __thiscall Scaleform::GFx::AMP::Server::AddLoadProcess(Scaleform::GFx::AMP::Server *this, int loadProcess)
{
  unsigned int *p_Size; // ebp
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_LockSemaphore; // edi
  unsigned int v5; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v6; // eax
  int v7; // esi
  Scaleform::GFx::AMP::Server::RenderProfile *v8; // eax
  Scaleform::GFx::Resource *v9; // eax
  Scaleform::GFx::Resource *v10; // edi
  Scaleform::GFx::Resource *v11; // ecx
  Scaleform::RefCountVImpl *pLib; // ecx
  Scaleform::GFx::Resource **v13; // esi

  p_Size = &this->LoadProcesses.Data.Size;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->LoadProcesses.Data.Size);
  p_LockSemaphore = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ImageLock.cs.LockSemaphore;
  v5 = this->ImageLock.cs.SpinCount + 1;
  if ( v5 >= this->ImageLock.cs.SpinCount )
  {
    if ( (Scaleform::GFx::LoadProcess **)v5 >= this->LoadProcesses.Data.Data )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_LockSemaphore,
        p_LockSemaphore,
        v5 + (v5 >> 2));
  }
  else if ( v5 < (unsigned int)this->LoadProcesses.Data.Data >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_LockSemaphore,
      p_LockSemaphore,
      this->ImageLock.cs.SpinCount + 1);
  }
  v6 = &p_LockSemaphore->Data[v5 - 1];
  this->ImageLock.cs.SpinCount = v5;
  v7 = loadProcess;
  if ( v6 )
    v6->pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)loadProcess;
  loadProcess = 579;
  v8 = (Scaleform::GFx::AMP::Server::RenderProfile *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       &this[-1].RecordingStateLock.cs.LockSemaphore,
                                                       12,
                                                       &loadProcess);
  if ( v8 )
  {
    Scaleform::GFx::AMP::Server::RenderProfile::RenderProfile(v8);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  v11 = *(Scaleform::GFx::Resource **)(v7 + 856);
  if ( v11 )
    Scaleform::RefCountImpl::AddRef(v11);
  pLib = (Scaleform::RefCountVImpl *)v10->pLib;
  if ( pLib )
    Scaleform::RefCountImpl::Release(pLib);
  v10->pLib = *(Scaleform::GFx::ResourceLibBase **)(v7 + 856);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LoadProcessLock.cs.LockSemaphore,
    &this->LoadProcessLock.cs.LockSemaphore,
    this->LoadProcessLock.cs.SpinCount + 1);
  v13 = (Scaleform::GFx::Resource **)((char *)this->LoadProcessLock.cs.LockSemaphore
                                    + 4 * this->LoadProcessLock.cs.SpinCount
                                    - 4);
  if ( (char *)this->LoadProcessLock.cs.LockSemaphore + 4 * this->LoadProcessLock.cs.SpinCount != (void *)4 )
  {
    if ( v10 )
      Scaleform::RefCountImpl::AddRef(v10);
    *v13 = v10;
  }
  if ( v10 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
  LeaveCriticalSection((LPCRITICAL_SECTION)p_Size);
}

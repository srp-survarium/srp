void __thiscall Scaleform::Thread::Thread(Scaleform::Thread *this, unsigned int stackSize, int processor)
{
  Scaleform::Thread::CreateParams params; // [esp+4h] [ebp-18h] BYREF

  Scaleform::Waitable::Waitable(this, 1);
  params.threadFunction = 0;
  params.userHandle = 0;
  params.initialState = NotRunning;
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  params.processor = processor;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Thread_vtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::Waitable'};
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::AcquireInterface'};
  params.priority = NormalPriority;
  params.stackSize = stackSize;
  Scaleform::Thread::Init(this, &params);
}

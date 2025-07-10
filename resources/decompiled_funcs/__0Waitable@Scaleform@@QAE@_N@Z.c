void __thiscall Scaleform::Waitable::Waitable(Scaleform::Waitable *this, bool enable)
{
  Scaleform::Waitable::HandlerArray *v3; // eax
  Scaleform::Waitable::HandlerArray *v4; // edi

  this->__vftable = (Scaleform::Waitable_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Waitable_vtbl *)&Scaleform::Waitable::`vftable';
  if ( enable )
  {
    v3 = (Scaleform::Waitable::HandlerArray *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                40,
                                                0);
    v4 = v3;
    if ( v3 )
    {
      v3->Handlers.Data.Data = 0;
      v3->Handlers.Data.Size = 0;
      v3->Handlers.Data.Policy.Capacity = 0;
      Scaleform::Lock::Lock(&v3->HandlersLock, 0);
      v4->RefCount.Value = 1;
      this->pHandlers = v4;
    }
    else
    {
      this->pHandlers = 0;
    }
  }
  else
  {
    this->pHandlers = 0;
  }
}

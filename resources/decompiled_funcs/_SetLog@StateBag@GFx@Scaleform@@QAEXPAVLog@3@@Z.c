void __thiscall Scaleform::GFx::StateBag::SetLog(Scaleform::GFx::StateBag *this, Scaleform::GFx::Resource *log)
{
  Scaleform::GFx::State *v3; // eax
  Scaleform::GFx::State *v4; // esi

  v3 = (Scaleform::GFx::State *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 20, 0);
  v4 = v3;
  if ( v3 )
  {
    v3->__vftable = (Scaleform::GFx::State_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v3->RefCount = 1;
    v3->SType = State_Log;
    v3[1].__vftable = (Scaleform::GFx::State_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
    v3->__vftable = (Scaleform::GFx::State_vtbl *)&Scaleform::GFx::LogState::`vftable'{for `Scaleform::GFx::State'};
    v3[1].__vftable = (Scaleform::GFx::State_vtbl *)&Scaleform::GFx::LogState::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::LogState>'};
    if ( log )
      Scaleform::RefCountImpl::AddRef(log);
    v4[1].RefCount = (volatile int)log;
  }
  else
  {
    v4 = 0;
  }
  this->SetState(this, State_Log, v4);
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
}

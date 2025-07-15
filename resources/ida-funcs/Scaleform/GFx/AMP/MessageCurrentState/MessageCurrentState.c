void __thiscall Scaleform::GFx::AMP::MessageCurrentState::MessageCurrentState(
        Scaleform::GFx::AMP::MessageCurrentState *this,
        const Scaleform::GFx::AMP::ServerState *state)
{
  Scaleform::GFx::AMP::ServerState *v3; // eax
  Scaleform::GFx::AMP::ServerState *v4; // eax
  Scaleform::GFx::AMP::ServerState *v5; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  int v7; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::AMP::MessageCurrentState_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageCurrentState_vtbl *)&Scaleform::GFx::AMP::MessageCurrentState::`vftable';
  this->State.pObject = 0;
  v7 = 578;
  v3 = (Scaleform::GFx::AMP::ServerState *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             this,
                                             80,
                                             &v7);
  if ( v3 )
  {
    Scaleform::GFx::AMP::ServerState::ServerState(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->State.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->State.pObject = v5;
  if ( state )
    Scaleform::GFx::AMP::ServerState::operator=(v5, state);
}

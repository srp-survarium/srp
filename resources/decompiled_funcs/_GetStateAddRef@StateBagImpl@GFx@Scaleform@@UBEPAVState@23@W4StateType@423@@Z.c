Scaleform::GFx::Resource *__thiscall Scaleform::GFx::StateBagImpl::GetStateAddRef(
        Scaleform::GFx::StateBagImpl *this,
        Scaleform::GFx::State::StateType state)
{
  _RTL_CRITICAL_SECTION *p_pDelegate; // ebx
  Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>_vtbl *v4; // esi
  Scaleform::GFx::State::StateType v5; // ebp
  int v6; // eax
  Scaleform::GFx::Resource **v7; // esi
  Scaleform::GFx::Resource *v8; // esi
  Scaleform::GFx::StateBag_vtbl *v10; // edi

  p_pDelegate = (_RTL_CRITICAL_SECTION *)&this->pDelegate;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  v4 = this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::__vftable;
  v5 = state;
  if ( v4
    && (v6 = Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::findIndexCore<enum Scaleform::GFx::State::StateType>(
               (Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> > *)&this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>,
               &state,
               state & (__int32)v4->IsVerboseActionErrors),
        v6 >= 0)
    && (v7 = (Scaleform::GFx::Resource **)&v4[2] + 3 * v6) != 0 )
  {
    Scaleform::RefCountImpl::AddRef(*v7);
    v8 = *v7;
    LeaveCriticalSection(p_pDelegate);
    return v8;
  }
  else
  {
    LeaveCriticalSection(p_pDelegate);
    v10 = this->Scaleform::GFx::StateBag::__vftable;
    if ( v10 )
      return (Scaleform::GFx::Resource *)(*((int (__thiscall **)(void (__thiscall **)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType, Scaleform::GFx::State *), Scaleform::GFx::State::StateType))v10->SetState
                                          + 3))(
                                           &v10->SetState,
                                           v5);
    else
      return 0;
  }
}

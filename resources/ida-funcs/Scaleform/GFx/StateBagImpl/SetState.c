void __thiscall Scaleform::GFx::StateBagImpl::SetState(
        Scaleform::GFx::StateBagImpl *this,
        Scaleform::GFx::State::StateType state,
        Scaleform::GFx::Resource *pstate)
{
  _RTL_CRITICAL_SECTION *p_pDelegate; // ebx
  Scaleform::GFx::Resource *v5; // esi

  p_pDelegate = (_RTL_CRITICAL_SECTION *)&this->pDelegate;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  v5 = pstate;
  if ( pstate )
  {
    Scaleform::RefCountImpl::AddRef(pstate);
    pstate = v5;
    Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::Set<Scaleform::GFx::StateBagImpl::StatePtr>(
      (Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> > *)&this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>,
      &this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>,
      (const Scaleform::GFx::StateBagImpl::StatePtr *)&pstate);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::RemoveAlt<enum Scaleform::GFx::State::StateType>(
      (Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> > *)&this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>,
      &state);
  }
  LeaveCriticalSection(p_pDelegate);
}

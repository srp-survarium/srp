void __thiscall Scaleform::GFx::StateBagImpl::GetStatesAddRef(
        Scaleform::GFx::StateBagImpl *this,
        Scaleform::GFx::State **pstateList,
        const Scaleform::GFx::State::StateType *pstates,
        unsigned int count)
{
  unsigned int v5; // esi
  Scaleform::GFx::State **v6; // edi
  Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>_vtbl *v7; // esi
  int v8; // eax
  Scaleform::GFx::Resource **v9; // esi
  Scaleform::GFx::StateBag_vtbl *v10; // eax
  char v11; // [esp+Bh] [ebp-5h]
  unsigned int v12; // [esp+Ch] [ebp-4h]

  v11 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  v5 = count;
  if ( count )
  {
    v6 = pstateList;
    v12 = count;
    do
    {
      if ( !*v6 )
      {
        v7 = this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::__vftable;
        if ( v7
          && (v8 = Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::findIndexCore<enum Scaleform::GFx::State::StateType>(
                     (Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> > *)&this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>,
                     (const Scaleform::GFx::State::StateType *)((char *)v6 + (char *)pstates - (char *)pstateList),
                     *(unsigned int *)((char *)v6 + (char *)pstates - (char *)pstateList)
                   & (unsigned int)v7->IsVerboseActionErrors),
              v8 >= 0)
          && (v9 = (Scaleform::GFx::Resource **)&v7[2] + 3 * v8) != 0 )
        {
          Scaleform::RefCountImpl::AddRef(*v9);
          *v6 = (Scaleform::GFx::State *)*v9;
        }
        else
        {
          v11 = 1;
        }
      }
      ++v6;
      --v12;
    }
    while ( v12 );
    v5 = count;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  if ( v11 )
  {
    v10 = this->Scaleform::GFx::StateBag::__vftable;
    if ( v10 )
      (*((void (__thiscall **)(void (__thiscall **)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType, Scaleform::GFx::State *), Scaleform::GFx::State **, const Scaleform::GFx::State::StateType *, unsigned int))v10->SetState
       + 4))(
        &v10->SetState,
        pstateList,
        pstates,
        v5);
  }
}

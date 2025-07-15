void __thiscall Scaleform::GFx::StateBag::GetStatesAddRef(
        Scaleform::GFx::StateBag *this,
        Scaleform::GFx::State **pstateList,
        const Scaleform::GFx::State::StateType *pstates,
        unsigned int count)
{
  int v4; // eax

  v4 = this->GetStateBagImpl(this);
  if ( v4 )
    (*(void (__thiscall **)(int, Scaleform::GFx::State **, const Scaleform::GFx::State::StateType *, unsigned int))(*(_DWORD *)v4 + 16))(
      v4,
      pstateList,
      pstates,
      count);
}

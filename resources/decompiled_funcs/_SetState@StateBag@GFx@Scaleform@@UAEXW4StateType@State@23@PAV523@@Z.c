void __thiscall Scaleform::GFx::StateBag::SetState(
        Scaleform::GFx::StateBag *this,
        Scaleform::GFx::State::StateType state,
        Scaleform::GFx::State *pstate)
{
  int v3; // eax

  v3 = this->GetStateBagImpl(this);
  if ( v3 )
    (*(void (__thiscall **)(int, Scaleform::GFx::State::StateType, Scaleform::GFx::State *))(*(_DWORD *)v3 + 8))(
      v3,
      state,
      pstate);
}

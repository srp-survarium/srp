Scaleform::GFx::State *__thiscall Scaleform::GFx::StateBag::GetStateAddRef(
        Scaleform::GFx::StateBag *this,
        Scaleform::GFx::State::StateType state)
{
  int v2; // eax

  v2 = this->GetStateBagImpl(this);
  if ( v2 )
    return (Scaleform::GFx::State *)(*(int (__thiscall **)(int, Scaleform::GFx::State::StateType))(*(_DWORD *)v2 + 12))(
                                      v2,
                                      state);
  else
    return 0;
}

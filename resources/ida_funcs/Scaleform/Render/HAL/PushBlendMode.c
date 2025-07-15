void __thiscall Scaleform::Render::HAL::PushBlendMode(Scaleform::Render::HAL *this, Scaleform::Render::BlendMode mode)
{
  Scaleform::ArrayLH<enum Scaleform::Render::BlendMode,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_BlendModeStack; // edi
  unsigned int v4; // esi
  Scaleform::Render::BlendMode *Data; // edx

  if ( (this->HALState & 8) != 0 )
  {
    p_BlendModeStack = &this->BlendModeStack;
    v4 = this->BlendModeStack.Data.Size + 1;
    if ( v4 >= this->BlendModeStack.Data.Size )
    {
      if ( v4 >= this->BlendModeStack.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)p_BlendModeStack,
          p_BlendModeStack,
          v4 + (v4 >> 2));
    }
    else if ( v4 < this->BlendModeStack.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)p_BlendModeStack,
        p_BlendModeStack,
        v4);
    }
    Data = p_BlendModeStack->Data.Data;
    this->BlendModeStack.Data.Size = v4;
    if ( &Data[v4] != (Scaleform::Render::BlendMode *)4 )
      Data[v4 - 1] = mode;
    Scaleform::Render::HAL::applyBlendMode(this, mode, 0, (Scaleform::String::DataDesc *)((this->HALState & 0x10) != 0));
  }
}

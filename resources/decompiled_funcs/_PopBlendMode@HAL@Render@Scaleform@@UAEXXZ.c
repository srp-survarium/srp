void __thiscall Scaleform::Render::HAL::PopBlendMode(Scaleform::Render::HAL *this)
{
  unsigned int Size; // eax
  unsigned int v3; // ebp
  Scaleform::ArrayLH<enum Scaleform::Render::BlendMode,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_BlendModeStack; // esi
  unsigned int v5; // edi
  Scaleform::Render::BlendMode v6; // eax

  if ( (this->HALState & 8) != 0 )
  {
    Size = this->BlendModeStack.Data.Size;
    v3 = Size;
    p_BlendModeStack = &this->BlendModeStack;
    v5 = Size - 1;
    if ( Size )
    {
      if ( v5 < this->BlendModeStack.Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&this->BlendModeStack,
          &this->BlendModeStack,
          v5);
    }
    else if ( v5 >= this->BlendModeStack.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&this->BlendModeStack,
        &this->BlendModeStack,
        v5 + (v5 >> 2));
    }
    this->BlendModeStack.Data.Size = v5;
    if ( v3 <= 1 )
      v6 = Blend_Normal;
    else
      v6 = p_BlendModeStack->Data.Data[v3 - 2];
    Scaleform::Render::HAL::applyBlendMode(this, v6, 0, (Scaleform::String::DataDesc *)((this->HALState & 0x10) != 0));
  }
}

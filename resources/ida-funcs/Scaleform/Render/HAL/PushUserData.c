void __thiscall Scaleform::Render::HAL::PushUserData(
        Scaleform::Render::HAL *this,
        const Scaleform::Render::UserDataState::Data *data)
{
  Scaleform::ArrayLH<Scaleform::Render::UserDataState::Data const *,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_UserDataStack; // edi
  unsigned int v3; // esi
  const Scaleform::Render::UserDataState::Data **v4; // edx

  p_UserDataStack = &this->UserDataStack;
  v3 = this->UserDataStack.Data.Size + 1;
  if ( v3 >= this->UserDataStack.Data.Size )
  {
    if ( v3 >= this->UserDataStack.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        &p_UserDataStack->Data,
        p_UserDataStack,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->UserDataStack.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
      &p_UserDataStack->Data,
      p_UserDataStack,
      this->UserDataStack.Data.Size + 1);
  }
  v4 = p_UserDataStack->Data.Data;
  p_UserDataStack->Data.Size = v3;
  if ( &v4[v3] != (const Scaleform::Render::UserDataState::Data **)4 )
    v4[v3 - 1] = data;
}

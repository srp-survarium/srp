void __thiscall Scaleform::Render::HAL::PopUserData(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::Pop(&this->UserDataStack);
}

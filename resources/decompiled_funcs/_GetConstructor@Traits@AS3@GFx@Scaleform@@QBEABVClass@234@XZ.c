Scaleform::GFx::AS3::Class *__thiscall Scaleform::GFx::AS3::Traits::GetConstructor(Scaleform::GFx::AS3::Traits *this)
{
  if ( !this->pConstructor.pObject )
    this->InitOnDemand(this);
  return this->pConstructor.pObject;
}

Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::AvmButton::GetOverStateObject(
        Scaleform::GFx::AS3::AvmButton *this)
{
  if ( this->pDispObj[1].pNameHandle.pObject )
    return **(Scaleform::GFx::DisplayObject ***)&this->pDispObj[1].BlendMode;
  else
    return 0;
}

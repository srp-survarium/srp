Scaleform::GFx::AS3::Stage *__thiscall Scaleform::GFx::AS3::Stage::GetTopParent(
        Scaleform::GFx::AS3::Stage *this,
        BOOL ignoreLockRoot)
{
  Scaleform::GFx::AS3::Stage *result; // eax

  result = this;
  if ( this->pParent )
    return (Scaleform::GFx::AS3::Stage *)this->pParent->GetTopParent(this->pParent, ignoreLockRoot);
  return result;
}

const Scaleform::GFx::AS3::Value *__cdecl Scaleform::GFx::AS3::Value::GetUndefined()
{
  if ( (_S15 & 1) == 0 )
  {
    _S15 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  return &v;
}

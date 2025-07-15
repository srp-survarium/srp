const Scaleform::GFx::AS3::Value *__cdecl Scaleform::GFx::AS3::Value::GetNull()
{
  if ( (_S16 & 1) == 0 )
  {
    _S16 |= 1u;
    v_0.Flags = 12;
    v_0.Bonus.pWeakProxy = 0;
    v_0.value.VS._1.VInt = 0;
    atexit(Scaleform::GFx::AS3::Value::GetNull_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  return &v_0;
}

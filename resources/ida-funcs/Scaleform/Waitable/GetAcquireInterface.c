Scaleform::AcquireInterface *__thiscall Scaleform::Waitable::GetAcquireInterface(Scaleform::Waitable *this)
{
  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    dword_8E6BC0 = (int)&Scaleform::DefaultAcquireInterface::`vftable';
    atexit(Scaleform::DefaultAcquireInterface::GetDefaultAcquireInterface_::_2_::_dynamic_atexit_destructor_for__di__);
  }
  return (Scaleform::AcquireInterface *)&dword_8E6BC0;
}

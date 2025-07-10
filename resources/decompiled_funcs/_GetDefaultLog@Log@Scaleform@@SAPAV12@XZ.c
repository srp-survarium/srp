Scaleform::Log *__cdecl Scaleform::Log::GetDefaultLog()
{
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    defaultLog.RefCount = 1;
    defaultLog.__vftable = (Scaleform::Log_vtbl *)&Scaleform::Log::`vftable';
    atexit(Scaleform::Log::GetDefaultLog_::_2_::_dynamic_atexit_destructor_for__defaultLog__);
  }
  return &defaultLog;
}

Scaleform::AmpServer *__stdcall Scaleform::AmpServer::GetInstance()
{
  Scaleform::AmpServer *result; // eax

  result = Scaleform::AmpServer::AmpServerSingleton;
  if ( !Scaleform::AmpServer::AmpServerSingleton )
  {
    if ( (_S1_2 & 1) == 0 )
    {
      _S1_2 |= 1u;
      dword_8E6BA8 = (int)&Scaleform::DefaultAmpServer::`vftable';
      atexit(Scaleform::AmpServer::Init_::_2_::_dynamic_atexit_destructor_for__ampSingleton__);
    }
    result = (Scaleform::AmpServer *)&dword_8E6BA8;
    Scaleform::AmpServer::AmpServerSingleton = (Scaleform::AmpServer *)&dword_8E6BA8;
  }
  return result;
}

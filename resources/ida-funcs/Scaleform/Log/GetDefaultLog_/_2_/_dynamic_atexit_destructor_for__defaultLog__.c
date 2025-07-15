void Scaleform::Log::GetDefaultLog_::_2_::_dynamic_atexit_destructor_for__defaultLog__()
{
  defaultLog.__vftable = (Scaleform::Log_vtbl *)&Scaleform::Log::`vftable';
  if ( Scaleform::SF_GlobalLog == &defaultLog )
    Scaleform::SF_GlobalLog = 0;
  Scaleform::RefCountImplCore::~RefCountImplCore(&defaultLog);
}

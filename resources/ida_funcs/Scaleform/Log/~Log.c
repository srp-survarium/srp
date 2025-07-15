void __thiscall Scaleform::Log::~Log(Scaleform::Log *this)
{
  this->__vftable = (Scaleform::Log_vtbl *)&Scaleform::Log::`vftable';
  if ( this == Scaleform::SF_GlobalLog )
    Scaleform::SF_GlobalLog = 0;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

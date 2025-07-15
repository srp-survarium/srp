void __thiscall Scaleform::GFx::AMP::MessagePort::MessagePort(
        Scaleform::GFx::AMP::MessagePort *this,
        unsigned int port,
        const __m128i *appName,
        const __m128i *fileName)
{
  this->__vftable = (Scaleform::GFx::AMP::MessagePort_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessagePort_vtbl *)&Scaleform::GFx::AMP::MessagePort::`vftable';
  this->Port = port;
  Scaleform::StringLH::StringLH(&this->PeerName);
  Scaleform::StringLH::StringLH(&this->AppName);
  Scaleform::StringLH::StringLH(&this->FileName);
  if ( appName )
    Scaleform::String::operator=(&this->AppName, appName);
  if ( fileName )
    Scaleform::String::operator=(&this->FileName, fileName);
  this->Platform = PlatformWindows;
}

void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::Socket_9_Scaleform::GFx::ASString_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::Socket *this, Scaleform::GFx::ASString *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::ASString *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::Socket::remoteAddressGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,9,Scaleform::GFx::ASString>::Method) = Scaleform::GFx::AS3::Instances::fl_net::Socket::remoteAddressGet;
  dword_8F0D84 = 0;
  return result;
}

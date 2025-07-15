void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::Socket_10_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::Socket *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::Socket::remotePortGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,10,long>::Method) = Scaleform::GFx::AS3::Instances::fl_net::Socket::remotePortGet;
  dword_8F0D6C = 0;
  return result;
}

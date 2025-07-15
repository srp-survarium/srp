void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::Socket_25_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::Socket *this, unsigned int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, unsigned int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::Socket::readUnsignedByte;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,25,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_net::Socket::readUnsignedByte;
  dword_8F0CA4 = 0;
  return result;
}

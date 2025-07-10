void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::Socket_26_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::Socket *this, unsigned int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, unsigned int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::Socket::readUnsignedInt;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,26,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_net::Socket::readUnsignedInt;
  dword_AAC544 = 0;
  return result;
}

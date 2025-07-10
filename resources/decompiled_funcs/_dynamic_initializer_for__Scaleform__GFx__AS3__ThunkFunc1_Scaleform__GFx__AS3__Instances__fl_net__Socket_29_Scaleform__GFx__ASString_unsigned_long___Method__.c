void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_net::Socket_29_Scaleform::GFx::ASString_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::Socket *this, Scaleform::GFx::ASString *result, unsigned int length)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::ASString *, unsigned int); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::Socket::readUTFBytes;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,29,Scaleform::GFx::ASString,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_net::Socket::readUTFBytes;
  dword_AAC57C = 0;
  return result;
}

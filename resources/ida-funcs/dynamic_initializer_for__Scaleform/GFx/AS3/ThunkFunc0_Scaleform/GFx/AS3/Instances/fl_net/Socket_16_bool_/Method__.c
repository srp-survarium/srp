void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::Socket_16_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::Socket *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::Socket::readBoolean;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,16,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_net::Socket::readBoolean;
  dword_8F0C7C = 0;
  return result;
}

void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::Socket_2_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::Socket *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::Socket::connectedGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,2,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_net::Socket::connectedGet;
  dword_AAC53C = 0;
  return result;
}

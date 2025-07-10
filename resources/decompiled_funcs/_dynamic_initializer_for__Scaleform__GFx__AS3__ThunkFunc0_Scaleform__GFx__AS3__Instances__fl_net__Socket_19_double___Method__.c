void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::Socket_19_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::Socket *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::Socket::readDouble;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,19,double>::Method) = Scaleform::GFx::AS3::Instances::fl_net::Socket::readDouble;
  dword_AAC524 = 0;
  return result;
}

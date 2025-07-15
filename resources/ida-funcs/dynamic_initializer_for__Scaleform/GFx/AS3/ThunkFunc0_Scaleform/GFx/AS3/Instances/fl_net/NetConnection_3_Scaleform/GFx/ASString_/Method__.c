void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::NetConnection_3_Scaleform::GFx::ASString_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *this, Scaleform::GFx::ASString *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, Scaleform::GFx::ASString *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::NetConnection::connectedProxyTypeGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,3,Scaleform::GFx::ASString>::Method) = Scaleform::GFx::AS3::Instances::fl_net::NetConnection::connectedProxyTypeGet;
  dword_8F0C94 = 0;
  return result;
}

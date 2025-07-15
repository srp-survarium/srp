void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::NetConnection_10_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::NetConnection::usingTLSGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,10,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_net::NetConnection::usingTLSGet;
  dword_8F0C4C = 0;
  return result;
}

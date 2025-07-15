void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::URLRequest_10_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_net::URLRequest::followRedirectsGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,10,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_net::URLRequest::followRedirectsGet;
  dword_AAC56C = 0;
  return result;
}

void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain_2_bool_Scaleform::GFx::ASString_const___::Method__())(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this, bool *result, const Scaleform::GFx::ASString *name)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *, bool *, const Scaleform::GFx::ASString *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::hasDefinition;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain,2,bool,Scaleform::GFx::ASString const &>::Method) = Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::hasDefinition;
  dword_AAE9AC = 0;
  return result;
}

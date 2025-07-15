void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    this->AppDomain = appDomain;
}

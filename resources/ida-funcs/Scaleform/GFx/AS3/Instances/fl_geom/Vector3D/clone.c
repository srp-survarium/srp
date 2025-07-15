void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::clone(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  long double y; // st7
  long double z; // st7
  long double w; // st7
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value *v6; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value args[4]; // [esp+4h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+44h] [ebp+0h] BYREF

  args[0].value.VNumber = this->x;
  y = this->y;
  args[0].Bonus.pWeakProxy = 0;
  args[1].value.VNumber = y;
  z = this->z;
  args[1].Bonus.pWeakProxy = 0;
  args[2].Bonus.pWeakProxy = 0;
  args[2].value.VNumber = z;
  w = this->w;
  pObject = this->pTraits.pObject;
  args[3].Bonus.pWeakProxy = 0;
  args[3].value.VNumber = w;
  args[0].Flags = 4;
  args[1].Flags = 4;
  args[2].Flags = 4;
  args[3].Flags = 4;
  Scaleform::GFx::AS3::VM::constructBuiltinObject(
    pObject->pVM,
    (Scaleform::GFx::AS3::CheckResult *)&result,
    result,
    "flash.geom.Vector3D",
    4u,
    args);
  v6 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 3; i >= 0; --i )
  {
    Flags = v6[-1].Flags;
    --v6;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v6);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v6);
    }
  }
}

void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Point::clone(
        Scaleform::GFx::AS3::Instances::fl_geom::Point *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  long double y; // st7
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value *v4; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value args[2]; // [esp+4h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+24h] [ebp+0h] BYREF

  args[0].value.VNumber = this->x;
  y = this->y;
  pObject = this->pTraits.pObject;
  args[1].value.VNumber = y;
  args[0].Bonus.pWeakProxy = 0;
  args[1].Bonus.pWeakProxy = 0;
  args[0].Flags = 4;
  args[1].Flags = 4;
  Scaleform::GFx::AS3::VM::constructBuiltinObject(
    pObject->pVM,
    (Scaleform::GFx::AS3::CheckResult *)&result,
    result,
    "flash.geom.Point",
    2u,
    args);
  v4 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 1; i >= 0; --i )
  {
    Flags = v4[-1].Flags;
    --v4;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v4);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v4);
    }
  }
}

void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::bottomRightGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  long double v2; // st7
  long double v3; // st7
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value *v5; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value args[2]; // [esp+8h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+28h] [ebp+0h] BYREF

  v2 = this->x + this->width;
  args[0].Bonus.pWeakProxy = 0;
  args[1].Bonus.pWeakProxy = 0;
  args[0].value.VNumber = v2;
  v3 = this->y + this->height;
  pObject = this->pTraits.pObject;
  args[1].value.VNumber = v3;
  args[0].Flags = 4;
  args[1].Flags = 4;
  Scaleform::GFx::AS3::VM::constructBuiltinObject(
    pObject->pVM,
    (Scaleform::GFx::AS3::CheckResult *)&result,
    result,
    "flash.geom.Point",
    2u,
    args);
  v5 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 1; i >= 0; --i )
  {
    Flags = v5[-1].Flags;
    --v5;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v5);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v5);
    }
  }
}

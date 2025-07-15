void __thiscall Scaleform::GFx::AS3::Classes::fl_geom::Point::interpolate(
        Scaleform::GFx::AS3::Classes::fl_geom::Point *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *pt1,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *pt2,
        long double f)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  long double v6; // st7
  long double v7; // st6
  Scaleform::GFx::AS3::Value *v8; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value args[2]; // [esp+4h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+24h] [ebp+0h] BYREF

  pObject = this->pTraits.pObject;
  v6 = pt1->x - pt2->x;
  args[0].Flags = 4;
  args[0].Bonus.pWeakProxy = 0;
  v7 = v6 * f + pt2->x;
  args[1].Flags = 4;
  args[1].Bonus.pWeakProxy = 0;
  args[0].value.VNumber = v7;
  args[1].value.VNumber = f * (pt1->y - pt2->y) + pt2->y;
  Scaleform::GFx::AS3::VM::constructBuiltinObject(
    pObject->pVM,
    (Scaleform::GFx::AS3::CheckResult *)&pt2,
    result,
    "flash.geom.Point",
    2u,
    args);
  v8 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 1; i >= 0; --i )
  {
    Flags = v8[-1].Flags;
    --v8;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v8);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v8);
    }
  }
}

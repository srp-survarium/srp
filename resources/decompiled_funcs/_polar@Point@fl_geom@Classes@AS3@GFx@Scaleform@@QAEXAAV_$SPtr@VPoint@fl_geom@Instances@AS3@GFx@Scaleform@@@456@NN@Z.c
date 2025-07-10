void __thiscall Scaleform::GFx::AS3::Classes::fl_geom::Point::polar(
        Scaleform::GFx::AS3::Classes::fl_geom::Point *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        long double len,
        long double angle)
{
  Scaleform::GFx::AS3::Value *v4; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value args[2]; // [esp+0h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+20h] [ebp+0h] BYREF

  args[0].Flags = 4;
  args[0].Bonus.pWeakProxy = 0;
  args[1].Flags = 4;
  args[1].Bonus.pWeakProxy = 0;
  args[0].value.VNumber = cos(angle) * len;
  args[1].value.VNumber = sin(angle) * len;
  Scaleform::GFx::AS3::VM::constructBuiltinObject(
    this->pTraits.pObject->pVM,
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

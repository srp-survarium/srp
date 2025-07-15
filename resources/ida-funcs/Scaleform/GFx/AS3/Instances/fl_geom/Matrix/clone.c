void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::clone(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  long double c; // st7
  long double d; // st7
  long double tx; // st7
  long double ty; // st7
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value *v7; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value args[6]; // [esp+0h] [ebp-60h] BYREF
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h] BYREF

  args[0].value.VNumber = this->a;
  args[1].value.VNumber = this->b;
  args[0].Bonus.pWeakProxy = 0;
  c = this->c;
  args[1].Bonus.pWeakProxy = 0;
  args[2].value.VNumber = c;
  args[2].Bonus.pWeakProxy = 0;
  d = this->d;
  args[3].Bonus.pWeakProxy = 0;
  args[4].Bonus.pWeakProxy = 0;
  args[3].value.VNumber = d;
  tx = this->tx;
  args[5].Bonus.pWeakProxy = 0;
  args[4].value.VNumber = tx;
  ty = this->ty;
  pObject = this->pTraits.pObject;
  args[5].value.VNumber = ty;
  args[0].Flags = 4;
  args[1].Flags = 4;
  args[2].Flags = 4;
  args[3].Flags = 4;
  args[4].Flags = 4;
  args[5].Flags = 4;
  Scaleform::GFx::AS3::VM::constructBuiltinObject(
    pObject->pVM,
    (Scaleform::GFx::AS3::CheckResult *)&result,
    result,
    "flash.geom.Matrix",
    6u,
    args);
  v7 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 5; i >= 0; --i )
  {
    Flags = v7[-1].Flags;
    --v7;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v7);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v7);
    }
  }
}

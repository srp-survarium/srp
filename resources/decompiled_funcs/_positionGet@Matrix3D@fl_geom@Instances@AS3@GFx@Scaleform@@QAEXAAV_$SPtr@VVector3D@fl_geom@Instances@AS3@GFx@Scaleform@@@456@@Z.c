void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::positionGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  long double v2; // st6
  long double v3; // st6
  Scaleform::GFx::AS3::Traits *pObject; // eax
  long double v5; // st7
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Value *v8; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::StringDataPtr gname; // [esp+8h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value params[4]; // [esp+10h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h] BYREF

  v2 = this->mat4.M[0][3] * 0.05;
  params[0].Bonus.pWeakProxy = 0;
  params[0].value.VNumber = v2;
  params[1].Bonus.pWeakProxy = 0;
  v3 = this->mat4.M[1][3];
  params[2].Bonus.pWeakProxy = 0;
  params[3].Bonus.pWeakProxy = 0;
  pObject = this->pTraits.pObject;
  params[0].Flags = 4;
  params[1].value.VNumber = v3 * 0.05;
  params[1].Flags = 4;
  params[2].Flags = 4;
  v5 = 0.05 * this->mat4.M[2][3];
  params[3].Flags = 4;
  gname.pStr = "flash.geom.Vector3D";
  params[2].value.VNumber = v5;
  gname.Size = 19;
  params[3].value.VNumber = 0.0;
  pVM = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  Class = Scaleform::GFx::AS3::VM::GetClass(pVM, &gname, pVM->CurrentDomain);
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, Class, 4u, params);
  v8 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 3; i >= 0; --i )
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

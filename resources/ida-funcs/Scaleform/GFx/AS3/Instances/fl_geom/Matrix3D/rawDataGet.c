void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::rawDataGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // edx
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::AS3::Classes::fl_vec::Vector_double *ClassVectorNumber; // eax
  unsigned int v6; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v7; // eax
  Scaleform::GFx::AS3::CheckResult v8; // [esp+Fh] [ebp-A1h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+10h] [ebp-A0h] BYREF
  Scaleform::GFx::AS3::Value params[1]; // [esp+20h] [ebp-90h] BYREF
  Scaleform::Render::Matrix4x4<double> m4d; // [esp+30h] [ebp-80h] BYREF

  memcpy((int)&m4d, (const __m128i *)&this->mat4, sizeof(m4d));
  m4d.M[0][3] = m4d.M[0][3] * 0.05;
  m4d.M[1][3] = m4d.M[1][3] * 0.05;
  m4d.M[2][3] = 0.05 * m4d.M[2][3];
  Scaleform::Render::Matrix4x4<double>::Transpose(&m4d);
  pObject = this->pTraits.pObject;
  params[0].value.VNumber = 0.0;
  params[0].Flags = 4;
  params[0].Bonus.pWeakProxy = 0;
  pVM = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  ClassVectorNumber = Scaleform::GFx::AS3::VM::GetClassVectorNumber(pVM);
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, ClassVectorNumber, 1u, params);
  v6 = 0;
  while ( 1 )
  {
    v7 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)result->pObject;
    v.value.VNumber = m4d.M[0][v6];
    v.Flags = 4;
    v.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::VectorBase<double>::Set(&v7->V, &v8, v6, &v, v7->pTraits.pObject->pVM->TraitsNumber.pObject);
    if ( !v8.Result )
      break;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
    if ( (int)++v6 >= 16 )
      goto LABEL_13;
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
LABEL_13:
  if ( (params[0].Flags & 0x1F) > 9 )
  {
    if ( (params[0].Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(params);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(params);
  }
}

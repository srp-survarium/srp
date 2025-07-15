void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::transformVectors(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *vin,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *vout)
{
  Scaleform::GFx::AS3::ClassTraits::fl::Number *pObject; // edi
  Scaleform::GFx::AS3::VectorBase<double> *p_V; // ebx
  unsigned int Flags; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  double v10; // st7
  long double v11; // st6
  long double v12; // st4
  long double v13; // st3
  long double v14; // st4
  unsigned int ind; // [esp+10h] [ebp-B0h]
  int v16; // [esp+14h] [ebp-ACh]
  Scaleform::GFx::AS3::CheckResult v17; // [esp+1Ah] [ebp-A6h] BYREF
  Scaleform::GFx::AS3::CheckResult v18; // [esp+1Bh] [ebp-A5h] BYREF
  Scaleform::GFx::AS3::CheckResult v19; // [esp+1Ch] [ebp-A4h] BYREF
  Scaleform::GFx::AS3::CheckResult v20; // [esp+1Dh] [ebp-A3h] BYREF
  Scaleform::GFx::AS3::CheckResult v21; // [esp+1Eh] [ebp-A2h] BYREF
  Scaleform::GFx::AS3::CheckResult v22; // [esp+1Fh] [ebp-A1h] BYREF
  Scaleform::GFx::AS3::Value v1; // [esp+20h] [ebp-A0h] BYREF
  Scaleform::GFx::AS3::Value v3; // [esp+30h] [ebp-90h] BYREF
  Scaleform::GFx::AS3::Value v2; // [esp+40h] [ebp-80h] BYREF
  unsigned int sz; // [esp+54h] [ebp-6Ch] BYREF
  long double v27; // [esp+58h] [ebp-68h]
  Scaleform::GFx::AS3::Value v28; // [esp+60h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+70h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value v30; // [esp+80h] [ebp-40h] BYREF
  double n3; // [esp+90h] [ebp-30h] BYREF
  double n1; // [esp+98h] [ebp-28h] BYREF
  double n2; // [esp+A0h] [ebp-20h] BYREF
  Scaleform::Render::Point3<double> pdOut; // [esp+A8h] [ebp-18h]

  v1.Flags = 0;
  v1.Bonus.pWeakProxy = 0;
  v2.Flags = 0;
  v2.Bonus.pWeakProxy = 0;
  v3.Flags = 0;
  v3.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthGet(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)vin,
    &sz);
  pObject = vout->pTraits.pObject->pVM->TraitsNumber.pObject;
  if ( (int)sz > 0 )
  {
    p_V = &vout->V;
    ind = 2;
    v16 = 2;
    do
    {
      if ( ind - 2 < vin->V.ValueA.Data.Size )
      {
        Flags = v1.Flags;
        v27 = vin->V.ValueA.Data.Data[v16 - 2];
        if ( (v1.Flags & 0x1F) > 9 )
        {
          if ( (v1.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v1);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v1);
          Flags = v1.Flags;
        }
        v1.value.VNumber = v27;
        v1.Flags = Flags & 0xFFFFFFE0 | 4;
      }
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(&v1, &v19, &n1)->Result )
        n1 = 0.0;
      if ( ind - 1 < vin->V.ValueA.Data.Size )
      {
        v8 = v2.Flags;
        v27 = vin->V.ValueA.Data.Data[v16 - 1];
        if ( (v2.Flags & 0x1F) > 9 )
        {
          if ( (v2.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v2);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v2);
          v8 = v2.Flags;
        }
        v2.value.VNumber = v27;
        v2.Flags = v8 & 0xFFFFFFE0 | 4;
      }
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(&v2, &v17, &n2)->Result )
        n2 = 0.0;
      if ( ind < vin->V.ValueA.Data.Size )
      {
        v9 = v3.Flags;
        v27 = vin->V.ValueA.Data.Data[v16];
        if ( (v3.Flags & 0x1F) > 9 )
        {
          if ( (v3.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v3);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v3);
          v9 = v3.Flags;
        }
        v3.value.VNumber = v27;
        v3.Flags = v9 & 0xFFFFFFE0 | 4;
      }
      if ( Scaleform::GFx::AS3::Value::Convert2Number(&v3, &v22, &n3)->Result )
      {
        v10 = n3;
      }
      else
      {
        v10 = 0.0;
        n3 = 0.0;
      }
      v11 = this->mat4.M[0][0];
      v12 = this->mat4.M[0][1];
      v13 = this->mat4.M[0][2];
      v.Flags = 4;
      v.Bonus.pWeakProxy = 0;
      v14 = v12 * n2 + v11 * n1 + v13 * v10 + this->mat4.M[0][3];
      pdOut.y = this->mat4.M[1][1] * n2 + this->mat4.M[1][0] * n1 + this->mat4.M[1][2] * v10 + this->mat4.M[1][3];
      pdOut.z = v10 * this->mat4.M[2][2] + n2 * this->mat4.M[2][1] + n1 * this->mat4.M[2][0] + this->mat4.M[2][3];
      v.value.VNumber = v14;
      Scaleform::GFx::AS3::VectorBase<double>::Set(p_V, &v20, ind - 2, &v, pObject);
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
      v30.value.VNumber = pdOut.y;
      v30.Flags = 4;
      v30.Bonus.pWeakProxy = 0;
      Scaleform::GFx::AS3::VectorBase<double>::Set(p_V, &v21, ind - 1, &v30, pObject);
      if ( (v30.Flags & 0x1F) > 9 )
      {
        if ( (v30.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v30);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v30);
      }
      v28.value.VNumber = pdOut.z;
      v28.Flags = 4;
      v28.Bonus.pWeakProxy = 0;
      Scaleform::GFx::AS3::VectorBase<double>::Set(p_V, &v18, ind, &v28, pObject);
      if ( (v28.Flags & 0x1F) > 9 )
      {
        if ( (v28.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v28);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v28);
      }
      v16 += 3;
      ind += 3;
    }
    while ( (int)(ind - 2) < (int)sz );
  }
  if ( (v3.Flags & 0x1F) > 9 )
  {
    if ( (v3.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v3);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v3);
  }
  if ( (v2.Flags & 0x1F) > 9 )
  {
    if ( (v2.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v2);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v2);
  }
  if ( (v1.Flags & 0x1F) > 9 )
  {
    if ( (v1.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v1);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v1);
  }
}

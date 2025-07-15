void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::globalToLocal3D(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *point)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::Render::Point3<float> *v5; // eax
  Scaleform::GFx::AS3::Traits *v6; // eax
  Scaleform::GFx::AS3::Value *v7; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::Render::Point<float> ptIn; // [esp+8h] [ebp-60h] BYREF
  Scaleform::Render::Point3<float> ptOut; // [esp+10h] [ebp-58h]
  Scaleform::Render::Point3<float> v12; // [esp+1Ch] [ebp-4Ch] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+28h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value params[3]; // [esp+38h] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+68h] [ebp+0h] BYREF
  float pointa; // [esp+70h] [ebp+8h]
  float pointb; // [esp+70h] [ebp+8h]
  float pointc; // [esp+70h] [ebp+8h]

  pObject = this->pDispObj.pObject;
  ptIn.x = point->x * 20.0;
  ptIn.y = 20.0 * point->y;
  v5 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal3D(pObject, &v12, &ptIn);
  ptOut.x = v5->x;
  ptOut.y = v5->y;
  ptOut.z = v5->z;
  params[0].Bonus.pWeakProxy = 0;
  params[1].Bonus.pWeakProxy = 0;
  params[2].Bonus.pWeakProxy = 0;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  v6 = this->pTraits.pObject;
  pointa = ptOut.x * 0.05000000074505806;
  params[0].Flags = 4;
  params[1].Flags = 4;
  params[0].value.VNumber = pointa;
  params[2].Flags = 4;
  pointb = ptOut.y * 0.05000000074505806;
  params[1].value.VNumber = pointb;
  pointc = 0.05000000074505806 * ptOut.z;
  params[2].value.VNumber = pointc;
  (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS3::Value *, int, Scaleform::GFx::AS3::Value *, int))(*(_DWORD *)v6->pVM[1].ExceptionObj.Flags + 36))(
    v6->pVM[1].ExceptionObj.Flags,
    &r,
    3,
    params,
    1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)r.value.VS._1.VInt);
  if ( (r.Flags & 0x1F) > 9 )
  {
    if ( (r.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
  }
  v7 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 2; i >= 0; --i )
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

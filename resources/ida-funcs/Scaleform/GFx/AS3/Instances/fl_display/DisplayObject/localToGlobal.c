void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::localToGlobal(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Point> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *point)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::AS3::Traits *v5; // edx
  Scaleform::GFx::AS3::Value *v6; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::Render::Point<float> pt; // [esp+8h] [ebp-44h] BYREF
  Scaleform::Render::Point3<float> ptIn; // [esp+10h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value params[2]; // [esp+2Ch] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+4Ch] [ebp+0h] BYREF
  float pointa; // [esp+54h] [ebp+8h]
  float pointb; // [esp+54h] [ebp+8h]

  pt.x = point->x * 20.0;
  pObject = this->pDispObj.pObject;
  pt.y = 20.0 * point->y;
  ptIn.x = pt.x;
  ptIn.y = pt.y;
  ptIn.z = 0.0;
  Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(pObject, &pt, &ptIn);
  v5 = this->pTraits.pObject;
  params[0].Bonus.pWeakProxy = 0;
  params[1].Bonus.pWeakProxy = 0;
  r.Flags = 0;
  pointa = pt.x * 0.05000000074505806;
  r.Bonus.pWeakProxy = 0;
  params[0].value.VNumber = pointa;
  params[0].Flags = 4;
  params[1].Flags = 4;
  pointb = 0.05000000074505806 * pt.y;
  params[1].value.VNumber = pointb;
  (*(void (__thiscall **)(Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, int, Scaleform::GFx::AS3::Value *, int))(v5->pVM[1].ScopeStack.Data.Data->Flags + 48))(
    v5->pVM[1].ScopeStack.Data.Data,
    &r,
    2,
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
  v6 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 1; i >= 0; --i )
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

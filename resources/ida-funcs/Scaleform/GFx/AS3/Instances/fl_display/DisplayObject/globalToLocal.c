void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::globalToLocal(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Point> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *point)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::Render::Point<float> *v5; // eax
  Scaleform::GFx::AS3::Traits *v6; // eax
  Scaleform::GFx::AS3::Value *v7; // esi
  int i; // edi
  unsigned int Flags; // eax
  float ptOut; // [esp+8h] [ebp-48h]
  float ptOut_4; // [esp+Ch] [ebp-44h]
  Scaleform::Render::Point<float> ptIn; // [esp+10h] [ebp-40h] BYREF
  Scaleform::Render::Point<float> v13; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value params[2]; // [esp+30h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h] BYREF
  float pointa; // [esp+58h] [ebp+8h]
  float pointb; // [esp+58h] [ebp+8h]

  pObject = this->pDispObj.pObject;
  ptIn.x = point->x * 20.0;
  ptIn.y = 20.0 * point->y;
  v5 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal(pObject, &v13, &ptIn);
  ptOut = v5->x;
  ptOut_4 = v5->y;
  params[0].Bonus.pWeakProxy = 0;
  params[1].Bonus.pWeakProxy = 0;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  v6 = this->pTraits.pObject;
  params[0].Flags = 4;
  pointa = ptOut * 0.05000000074505806;
  params[1].Flags = 4;
  params[0].value.VNumber = pointa;
  pointb = 0.05000000074505806 * ptOut_4;
  params[1].value.VNumber = pointb;
  (*(void (__thiscall **)(Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, int, Scaleform::GFx::AS3::Value *, int))(v6->pVM[1].ScopeStack.Data.Data->Flags + 48))(
    v6->pVM[1].ScopeStack.Data.Data,
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
  v7 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 1; i >= 0; --i )
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

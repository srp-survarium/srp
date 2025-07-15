void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection::projectionCenterGet(
        Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Point> *result)
{
  long double y; // st7
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Value *v4; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value params[2]; // [esp+20h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+40h] [ebp+0h] BYREF

  params[0].value.VNumber = this->projectionCenter.x;
  params[0].Bonus.pWeakProxy = 0;
  y = this->projectionCenter.y;
  params[1].Bonus.pWeakProxy = 0;
  r.Flags = 0;
  params[1].value.VNumber = y;
  r.Bonus.pWeakProxy = 0;
  pObject = this->pTraits.pObject;
  params[0].Flags = 4;
  params[1].Flags = 4;
  (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS3::Value *, int, Scaleform::GFx::AS3::Value *, int))(*(_DWORD *)pObject->pVM[1].ScopeStack.Data.Size + 36))(
    pObject->pVM[1].ScopeStack.Data.Size,
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

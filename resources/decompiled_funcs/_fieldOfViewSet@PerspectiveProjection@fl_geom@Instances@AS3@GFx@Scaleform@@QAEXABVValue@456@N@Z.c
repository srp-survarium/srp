void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection::fieldOfViewSet(
        Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  float valuea; // [esp+10h] [ebp+8h]

  valuea = value;
  this->fieldOfView = valuea;
  pDispObj = this->pDispObj;
  if ( pDispObj )
    ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD, _DWORD))pDispObj->SetFOV)(
      pDispObj,
      COERCE_UNSIGNED_INT64(valuea),
      HIDWORD(COERCE_UNSIGNED_INT64(valuea)));
}

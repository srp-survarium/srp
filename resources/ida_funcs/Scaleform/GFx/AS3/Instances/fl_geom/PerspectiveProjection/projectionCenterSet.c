void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection::projectionCenterSet(
        Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *value)
{
  bool v3; // zf
  float v4; // [esp+8h] [ebp-8h]
  float v5; // [esp+Ch] [ebp-4h]

  v3 = this->pDispObj == 0;
  this->projectionCenter.x = value->x;
  this->projectionCenter.y = value->y;
  if ( !v3 )
  {
    v4 = this->projectionCenter.x * 20.0;
    v5 = 20.0 * this->projectionCenter.y;
    ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD, _DWORD))this->pDispObj->SetProjectionCenter)(
      this->pDispObj,
      LODWORD(v4),
      LODWORD(v5));
  }
}

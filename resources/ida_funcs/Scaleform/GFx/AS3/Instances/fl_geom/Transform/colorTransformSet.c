void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::colorTransformSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *value)
{
  const Scaleform::Render::Cxform *CxformFromColorTransform; // eax
  Scaleform::Render::Cxform v5; // [esp+10h] [ebp-20h] BYREF

  if ( this->pDispObj )
  {
    CxformFromColorTransform = Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(
                                 &v5,
                                 value);
    Scaleform::GFx::DisplayObjectBase::SetCxform(this->pDispObj, CxformFromColorTransform);
    this->pDispObj->SetAcceptAnimMoves(this->pDispObj, 0);
  }
}

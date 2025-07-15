long double __thiscall Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection::CalculateFocalLength(
        Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *this,
        float stageWidth)
{
  return stageWidth * 0.5 / tan(0.5 * this->fieldOfView * 0.0174532925199433);
}

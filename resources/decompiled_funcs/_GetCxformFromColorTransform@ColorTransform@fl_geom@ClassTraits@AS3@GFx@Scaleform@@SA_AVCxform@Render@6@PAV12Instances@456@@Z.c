Scaleform::Render::Cxform *__cdecl Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(
        Scaleform::Render::Cxform *result,
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *value)
{
  Scaleform::Render::Cxform::Cxform(result);
  if ( value )
  {
    result->M[0][0] = value->redMultiplier;
    result->M[0][1] = value->greenMultiplier;
    result->M[0][2] = value->blueMultiplier;
    result->M[0][3] = value->alphaMultiplier;
    result->M[1][0] = value->redOffset;
    result->M[1][1] = value->greenOffset;
    result->M[1][2] = value->blueOffset;
    result->M[1][3] = value->alphaOffset;
    Scaleform::Render::Cxform::Normalize(result);
  }
  return result;
}

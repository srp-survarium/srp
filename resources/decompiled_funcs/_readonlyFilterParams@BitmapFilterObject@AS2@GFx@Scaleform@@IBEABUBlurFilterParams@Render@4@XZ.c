const Scaleform::Render::BlurFilterParams *__thiscall Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams(
        Scaleform::GFx::AS2::BitmapFilterObject *this)
{
  Scaleform::Render::Filter *pObject; // ecx
  int Type; // edx
  const Scaleform::Render::BlurFilterParams *result; // eax

  if ( (`Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::`local static guard' & 1) == 0 )
  {
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::`local static guard' |= 1u;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.BlurX = 100.0;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Mode = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.BlurY = 100.0;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Passes = 1;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Offset.x = 0.0;
    *(_WORD *)&`Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Colors[0].Channels.Green = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Offset.y = 0.0;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Colors[0].Channels.Blue = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Colors[0].Channels.Alpha = -1;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Strength = 1.0;
    *(_WORD *)&`Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Colors[1].Channels.Green = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Colors[1].Channels.Blue = 0;
    `Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams.Colors[1].Channels.Alpha = 0;
  }
  pObject = this->pFilter.pObject;
  if ( !pObject )
    return &`Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams;
  Type = pObject->Type;
  if ( Type < 0 )
    return &`Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams;
  result = (const Scaleform::Render::BlurFilterParams *)&pObject[1];
  if ( Type > 5 )
    return &`Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams'::`2'::unavailableParams;
  return result;
}

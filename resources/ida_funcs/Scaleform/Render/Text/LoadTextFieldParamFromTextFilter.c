void __cdecl Scaleform::Render::Text::LoadTextFieldParamFromTextFilter(
        Scaleform::Render::TextFieldParam *params,
        const Scaleform::Render::Text::TextFilter *filter)
{
  params->TextParam.BlurX = (int)(filter->BlurX * 16.0 + 0.5);
  params->TextParam.BlurY = (int)(filter->BlurY * 16.0 + 0.5);
  params->TextParam.Flags = 128;
  params->TextParam.BlurStrength = (int)(filter->BlurStrength * 16.0 + 0.5);
  if ( (filter->ShadowFlags & 1) == 0 )
  {
    params->ShadowParam.Flags = filter->ShadowFlags & 0xFFFE;
    params->ShadowParam.BlurX = (int)(filter->ShadowParams.BlurX * 16.0 + 0.5);
    params->ShadowParam.BlurY = (int)(filter->ShadowParams.BlurX * 16.0 + 0.5);
    params->ShadowParam.BlurStrength = (int)(16.0 * filter->ShadowParams.Strength + 0.5);
    params->ShadowColor = filter->ShadowParams.Colors[0].Raw;
    *(Scaleform::Render::Point<float> *)&params->ShadowOffsetX = filter->ShadowParams.Offset;
  }
}

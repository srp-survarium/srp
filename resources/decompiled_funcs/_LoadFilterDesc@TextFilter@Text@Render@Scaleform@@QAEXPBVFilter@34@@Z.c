void __thiscall Scaleform::Render::Text::TextFilter::LoadFilterDesc(
        Scaleform::Render::Text::TextFilter *this,
        const Scaleform::Render::Filter *filter)
{
  Scaleform::Render::FilterType Type; // eax

  Type = filter->Type;
  if ( Type )
  {
    if ( (Type == Filter_Shadow || Type == Filter_Glow)
      && (!this->ShadowParams.Colors[0].Raw || 0.0 == this->ShadowDistance) )
    {
      this->ShadowFlags = 0;
      if ( ((int)filter[1].__vftable & 0x10) != 0 )
        this->ShadowFlags = 32;
      if ( ((int)filter[1].__vftable & 0x40) != 0 )
        this->ShadowFlags |= 0x40u;
      if ( filter[1].RefCount )
        this->ShadowFlags |= 0x80u;
      this->ShadowParams.Mode = 0;
      this->ShadowParams.BlurX = *(float *)&filter[1].Type;
      this->ShadowParams.BlurY = *(float *)&filter[1].Frozen;
      this->ShadowParams.Strength = *(float *)&filter[2].Type;
      *(_QWORD *)&this->ShadowParams.Colors[0].Channels.Blue = *(_QWORD *)&filter[2].Frozen;
      this->ShadowAlpha = this->ShadowParams.Colors[0].Channels.Alpha;
      this->ShadowAngle = *(float *)&filter[3].Type;
      this->ShadowDistance = *(float *)&filter[3].RefCount;
      Scaleform::Render::Text::TextFilter::UpdateShadowOffset(this);
    }
  }
  else
  {
    this->BlurX = *(float *)&filter[1].Type;
    this->BlurY = *(float *)&filter[1].Frozen;
    this->BlurStrength = *(float *)&filter[2].Type;
  }
}

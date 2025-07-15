void __thiscall Scaleform::Render::TreeText::Filter::InitByDefaultValues(Scaleform::Render::TreeText::Filter *this)
{
  int ShadowAlpha; // ecx
  unsigned int Raw; // edx
  unsigned __int8 v4; // al
  double v5; // st7
  Scaleform::Render::Text::TextFilter v6; // [esp+4h] [ebp-48h] BYREF

  Scaleform::Render::Text::TextFilter::TextFilter(&v6);
  this->Blur.BlurX = v6.BlurX;
  ShadowAlpha = v6.ShadowAlpha;
  Raw = v6.ShadowParams.Colors[0].Raw;
  this->Blur.BlurY = v6.BlurY;
  v4 = LOBYTE(v6.ShadowFlags) | 0x80;
  this->Blur.Strength = v6.BlurStrength * 100.0;
  this->Glow.Color = Raw & 0xFFFFFF | (ShadowAlpha << 24);
  v5 = v6.ShadowAngle / 10.0;
  this->Glow.Flags = v4;
  this->DropShadow.Angle = v5;
  this->DropShadow.Distance = v6.ShadowDistance * 0.05000000074505806;
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&v6);
}

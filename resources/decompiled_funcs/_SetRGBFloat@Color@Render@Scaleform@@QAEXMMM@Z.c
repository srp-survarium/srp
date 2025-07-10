void __thiscall Scaleform::Render::Color::SetRGBFloat(Scaleform::Render::Color *this, float r, float g, float b)
{
  this->Channels.Red = (int)(r * 255.0);
  this->Channels.Green = (int)(g * 255.0);
  this->Channels.Blue = (int)(255.0 * b);
}

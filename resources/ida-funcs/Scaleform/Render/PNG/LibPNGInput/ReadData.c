int __thiscall Scaleform::Render::PNG::LibPNGInput::ReadData(Scaleform::Render::PNG::LibPNGInput *this, void **ppData)
{
  png_read_image(this->Context.png_ptr, ppData);
  return 1;
}

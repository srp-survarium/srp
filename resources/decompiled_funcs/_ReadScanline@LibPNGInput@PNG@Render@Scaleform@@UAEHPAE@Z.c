int __thiscall Scaleform::Render::PNG::LibPNGInput::ReadScanline(
        Scaleform::Render::PNG::LibPNGInput *this,
        unsigned __int8 *prgbData)
{
  png_read_row((int)this->Context.png_ptr, prgbData, 0);
  return 1;
}

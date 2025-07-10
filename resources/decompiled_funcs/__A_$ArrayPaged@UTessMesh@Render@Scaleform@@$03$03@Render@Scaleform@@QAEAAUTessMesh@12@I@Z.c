Scaleform::Render::TessMesh *__thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::operator[](
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *this,
        unsigned int i)
{
  return &this->Pages[i >> 4][i & 0xF];
}

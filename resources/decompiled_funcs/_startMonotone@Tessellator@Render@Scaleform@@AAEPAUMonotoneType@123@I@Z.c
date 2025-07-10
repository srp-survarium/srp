Scaleform::Render::Tessellator::MonotoneType *__thiscall Scaleform::Render::Tessellator::startMonotone(
        Scaleform::Render::Tessellator *this,
        unsigned int style)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16> *p_Monotones; // esi
  Scaleform::Render::Tessellator::MonotoneType m; // [esp+4h] [ebp-18h] BYREF

  p_Monotones = &this->Monotones;
  memset(&m.d, 255, sizeof(m.d));
  m.start = 0;
  m.style = style;
  m.lowerBase = 0;
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::PushBack(&this->Monotones, &m);
  return &p_Monotones->Pages[(p_Monotones->Size - 1) >> 4][(p_Monotones->Size - 1) & 0xF];
}

void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *this,
        const Scaleform::Render::TessMesh *val)
{
  unsigned int v3; // esi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::allocPage(this, this->Size >> 4);
  qmemcpy(&this->Pages[v3][this->Size++ & 0xF], val, sizeof(this->Pages[v3][this->Size++ & 0xF]));
}

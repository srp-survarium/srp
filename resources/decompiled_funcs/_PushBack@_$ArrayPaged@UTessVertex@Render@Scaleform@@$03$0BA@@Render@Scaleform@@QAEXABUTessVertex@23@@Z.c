void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *this,
        const Scaleform::Render::TessVertex *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(this, this->Size >> 4);
  this->Pages[v3][this->Size++ & 0xF] = *val;
}

void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2> *this,
        Scaleform::Render::Tessellator::MonoVertexType *const *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
      this,
      this->Size >> 4);
  this->Pages[v3][this->Size++ & 0xF] = *val;
}

void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4> *this,
        const Scaleform::Render::Tessellator::PendingEndType *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4> *)this,
      this->Size >> 4);
  this->Pages[v3][this->Size++ & 0xF] = *val;
}

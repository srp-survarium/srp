void __thiscall Scaleform::Render::ArrayPaged<unsigned int,3,4>::PushBack(
        Scaleform::Render::ArrayPaged<unsigned int,3,4> *this,
        const unsigned int *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 3;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)this,
      this->Size >> 3);
  this->Pages[v3][this->Size++ & 7] = *val;
}

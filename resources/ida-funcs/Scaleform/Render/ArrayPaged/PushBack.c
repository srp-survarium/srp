void __thiscall Scaleform::Render::ArrayPaged<unsigned int,3,4>::PushBack(
        Scaleform::Render::ArrayPaged<unsigned int,3,4> *this,
        unsigned int *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 3;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)this,
      this->Size >> 3);
  this->Pages[v3][this->Size++ & 7] = *val;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2> *this,
        Scaleform::Render::Tessellator::MonoVertexType **val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
      this,
      this->Size >> 4);
  this->Pages[v3][this->Size++ & 0xF] = *val;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16> *this,
        const Scaleform::Render::Tessellator::MonotoneType *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::allocPage(this, this->Size >> 4);
  this->Pages[v3][this->Size++ & 0xF] = *val;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *this,
        const Scaleform::Render::Tessellator::MonoVertexType *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(this, this->Size >> 4);
  this->Pages[v3][this->Size++ & 0xF] = *val;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PathType,4,4>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PathType,4,4> *this,
        const Scaleform::Render::Tessellator::PathType *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PathType,4,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshLayer,4,4> *)this,
      this->Size >> 4);
  this->Pages[v3][this->Size++ & 0xF] = *val;
}


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


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *this,
        const Scaleform::Render::TmpTextMeshEntry *val)
{
  unsigned int v3; // esi

  v3 = this->Size >> 6;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(this, this->Size >> 6);
  qmemcpy(&this->Pages[v3][this->Size++ & 0x3F], val, sizeof(this->Pages[v3][this->Size++ & 0x3F]));
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *this,
        const Scaleform::Render::GlyphFitter::VertexType *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<unsigned int,4,16> *)this,
      this->Size >> 4);
  this->Pages[v3][this->Size++ & 0xF] = *val;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *this,
        const Scaleform::Render::StrokeSorter::VertexType *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 4;
  if ( v3 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::allocPage(this, this->Size >> 4);
  this->Pages[v3][this->Size++ & 0xF] = *val;
}

void __thiscall Scaleform::Render::Tessellator::removeLastMonoVertex(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonotoneType *m)
{
  unsigned int lastIdx; // eax
  unsigned int Size; // eax
  unsigned int v4; // eax

  lastIdx = m->d.m.lastIdx;
  if ( lastIdx != -1 )
  {
    if ( lastIdx == this->MonoVertices.Size - 1 )
    {
      Size = this->MonoVertices.Size;
      if ( Size )
        this->MonoVertices.Size = Size - 1;
    }
    *(_QWORD *)&m->d.m.lastIdx = *(_QWORD *)&m->d.t.numTriangles;
    v4 = m->d.m.lastIdx;
    m->d.m.prevIdx2 = -1;
    if ( v4 == -1 )
      m->start = 0;
    else
      this->MonoVertices.Pages[v4 >> 4][v4 & 0xF].next = 0;
  }
}

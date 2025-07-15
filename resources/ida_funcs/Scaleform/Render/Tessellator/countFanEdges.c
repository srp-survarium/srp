unsigned int __thiscall Scaleform::Render::Tessellator::countFanEdges(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonotoneType *m)
{
  Scaleform::Render::Tessellator::MonotoneType *v2; // eax
  Scaleform::Render::Tessellator::MonoVertexType *start; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v5; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *next; // edi
  int v8; // edx
  int v9; // eax
  int v10; // esi
  Scaleform::Render::Tessellator::MonoVertexType *v11; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v12; // esi
  Scaleform::Render::TessVertex *v13; // esi
  Scaleform::Render::Tessellator::MonoVertexType *v14; // eax
  unsigned int lastIdx; // eax
  unsigned int style; // ecx
  unsigned int prevIdx2; // eax
  unsigned int totalEdges; // [esp+8h] [ebp-1Ch]
  Scaleform::Render::Tessellator::MonotoneType m2; // [esp+Ch] [ebp-18h] BYREF

  v2 = m;
  start = m->start;
  totalEdges = 0;
  if ( m->start && (v5 = start->next) != 0 )
  {
    next = v5->next;
    if ( next )
    {
      while ( 1 )
      {
        v8 = start->srcVer & 0xFFFFFFF;
        v9 = v5->srcVer & 0xFFFFFFF;
        v10 = next->srcVer & 0xFFFFFFF;
        if ( v8 != v9 && v9 != v10 && v10 != v8 )
          break;
        start = v5;
        v5 = next;
        next = next->next;
        if ( !next )
        {
          v2 = m;
          goto LABEL_10;
        }
      }
      v11 = start;
      v12 = 0;
      m->start = start;
      if ( start )
      {
        while ( !v12 || ((v12->srcVer ^ v11->srcVer) & 0xFFFFFFF) != 0 )
        {
          totalEdges += 2;
          v13 = this->MeshVertices.Pages[(v11->srcVer & 0xFFFFFFF) >> 4];
          v13[v11->srcVer & 0xF].Mesh += 2;
          v12 = v11;
          v11 = v11->next;
          if ( !v11 )
            return totalEdges;
        }
        v14 = v11->next;
        if ( v14 )
        {
          if ( v14->next )
          {
            lastIdx = m->d.m.lastIdx;
            m2.start = m->start;
            m2.d.m.prevIdx1 = m->d.m.prevIdx1;
            style = m->style;
            m2.d.m.lastIdx = lastIdx;
            prevIdx2 = m->d.m.prevIdx2;
            m2.style = style;
            m2.d.m.prevIdx2 = prevIdx2;
            m2.lowerBase = m->lowerBase;
            m2.start = v11;
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::PushBack(
              &this->Monotones,
              &m2);
          }
        }
        v12->next = 0;
      }
      return totalEdges;
    }
    else
    {
LABEL_10:
      v2->start = 0;
      return 0;
    }
  }
  else
  {
    m->start = 0;
    return 0;
  }
}

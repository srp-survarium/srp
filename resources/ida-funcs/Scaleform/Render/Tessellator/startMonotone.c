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


void __thiscall Scaleform::Render::Tessellator::startMonotone(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        int vertex)
{
  Scaleform::Render::Tessellator::MonoChainType *chain; // eax
  unsigned __int16 rightAbove; // ax
  Scaleform::Render::Tessellator::MonotoneType *started; // eax
  Scaleform::Render::Tessellator::MonotoneType *v7; // esi
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // edx
  unsigned int v9; // ebp
  unsigned int v10; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v11; // eax
  Scaleform::Render::Tessellator::MonoVertexType *next; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v13; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v14; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v15; // ebp
  unsigned int lastIdx; // ecx
  Scaleform::Render::Tessellator::MonoVertexType val; // [esp+Ch] [ebp-Ch] BYREF

  chain = scan->chain;
  scan->monotone = 0;
  rightAbove = chain->rightAbove;
  if ( rightAbove )
  {
    started = Scaleform::Render::Tessellator::startMonotone(this, rightAbove);
    v7 = started;
    scan->monotone = started;
    if ( started )
    {
      lowerBase = started->lowerBase;
      if ( lowerBase )
      {
        if ( this->MeshVertices.Pages[(vertex & 0xFFFFFFFu) >> 4][vertex & 0xF].y == lowerBase->y )
        {
          lowerBase->vertexRight = vertex & 0xFFFFFFF;
        }
        else if ( vertex >= 0 )
        {
          Scaleform::Render::Tessellator::connectPendingToRight(this, scan, vertex);
        }
        else
        {
          Scaleform::Render::Tessellator::connectPendingToLeft(this, scan, vertex);
        }
      }
      else
      {
        val.next = 0;
        val.srcVer = vertex;
        val.aaVer = vertex;
        if ( started->start )
        {
          v15 = &this->MonoVertices.Pages[started->d.m.lastIdx >> 4][started->d.m.lastIdx & 0xF];
          if ( v15->srcVer != vertex )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              &val);
            v15->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
            lastIdx = v7->d.m.lastIdx;
            v7->d.m.prevIdx2 = v7->d.m.prevIdx1;
            v7->d.m.prevIdx1 = lastIdx;
            v7->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
        }
        else
        {
          v9 = this->MonoVertices.Size >> 4;
          if ( v9 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v10 = this->MonoVertices.Size & 0xF;
          v11 = this->MonoVertices.Pages[v9];
          v11[v10].srcVer = val.srcVer;
          next = val.next;
          v13 = &v11[v10];
          v13->aaVer = val.aaVer;
          v13->next = next;
          ++this->MonoVertices.Size;
          v14 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v7->d.m.prevIdx2 = -1;
          v7->d.m.prevIdx1 = -1;
          v7->start = v14;
          v7->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
      }
    }
  }
}

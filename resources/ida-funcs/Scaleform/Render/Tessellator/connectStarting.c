void __thiscall Scaleform::Render::Tessellator::connectStarting(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        Scaleform::Render::Tessellator::BaseLineType *upperBase)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // eax
  unsigned int lastIdx; // eax
  signed int srcVer; // edi
  Scaleform::Render::Tessellator::BaseLineType *v7; // ebp
  unsigned int vertexRight; // eax
  Scaleform::Render::Tessellator::MonotoneType *v9; // esi
  bool v10; // zf
  unsigned int v11; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v12; // ecx
  unsigned int v13; // eax
  Scaleform::Render::Tessellator::MonoVertexType *next; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v15; // eax
  unsigned int prevIdx1; // ecx
  unsigned int i; // [esp+10h] [ebp-10h]
  unsigned int v18; // [esp+10h] [ebp-10h]
  Scaleform::Render::Tessellator::MonoVertexType val; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::Render::Tessellator::BaseLineType *upperBasea; // [esp+28h] [ebp+8h]

  if ( !scan || (monotone = scan->monotone) == 0 )
  {
    upperBase->numChains = 0;
    return;
  }
  lastIdx = monotone->d.m.lastIdx;
  if ( lastIdx == -1 )
    srcVer = -1;
  else
    srcVer = this->MonoVertices.Pages[lastIdx >> 4][lastIdx & 0xF].srcVer;
  v7 = upperBase;
  upperBase->vertexLeft = -1;
  upperBase->vertexRight = -1;
  for ( i = 0; i < 2; ++i )
  {
    if ( srcVer == -1 || upperBase->y > (double)this->MeshVertices.Pages[(srcVer & 0xFFFFFFFu) >> 4][srcVer & 0xF].y )
      break;
    if ( srcVer >= 0 )
      upperBase->vertexRight = srcVer;
    else
      upperBase->vertexLeft = srcVer & 0xFFFFFFF;
    Scaleform::Render::Tessellator::removeLastMonoVertex(this, scan->monotone);
    srcVer = scan->monotone->d.m.lastIdx == -1
           ? -1
           : this->MonoVertices.Pages[scan->monotone->d.m.lastIdx >> 4][scan->monotone->d.m.lastIdx & 0xF].srcVer;
  }
  if ( scan->monotone->lowerBase )
  {
    Scaleform::Render::Tessellator::connectStartingToPending(this, scan, upperBase);
    return;
  }
  if ( srcVer == -1 )
  {
    vertexRight = upperBase->vertexRight;
    if ( vertexRight == -1 )
    {
      vertexRight = upperBase->vertexLeft;
      if ( vertexRight == -1 )
        goto LABEL_30;
      upperBase->vertexLeft = -1;
    }
    else
    {
      upperBase->vertexRight = -1;
    }
    v9 = scan->monotone;
    v10 = v9->start == 0;
    srcVer = vertexRight;
    val.next = 0;
    val.srcVer = vertexRight;
    val.aaVer = vertexRight;
    if ( v10 )
    {
      v11 = this->MonoVertices.Size >> 4;
      v18 = v11;
      if ( v11 >= this->MonoVertices.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          &this->MonoVertices,
          v11);
        v11 = v18;
      }
      v12 = this->MonoVertices.Pages[v11];
      v13 = this->MonoVertices.Size & 0xF;
      v12[v13].srcVer = val.srcVer;
      next = val.next;
      v15 = &v12[v13];
      v15->aaVer = val.aaVer;
      v15->next = next;
      ++this->MonoVertices.Size;
      v7 = upperBase;
      v9->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      v9->d.m.prevIdx2 = -1;
      v9->d.m.prevIdx1 = -1;
      goto LABEL_29;
    }
    upperBasea = (Scaleform::Render::Tessellator::BaseLineType *)&this->MonoVertices.Pages[v9->d.m.lastIdx >> 4][v9->d.m.lastIdx & 0xF];
    if ( LODWORD(upperBasea->y) != vertexRight )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        &this->MonoVertices,
        &val);
      upperBasea->vertexLeft = (unsigned int)&this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      prevIdx1 = v9->d.m.prevIdx1;
      v9->d.m.prevIdx1 = v9->d.m.lastIdx;
      v9->d.m.prevIdx2 = prevIdx1;
LABEL_29:
      v9->d.m.lastIdx = this->MonoVertices.Size - 1;
    }
  }
LABEL_30:
  if ( srcVer >= 0 )
    Scaleform::Render::Tessellator::connectStartingToRight(
      this,
      (Scaleform::Render::Tessellator::PendingEndType *)scan,
      v7,
      srcVer);
  else
    Scaleform::Render::Tessellator::connectStartingToLeft(
      this,
      (Scaleform::Render::Tessellator::PendingEndType *)scan,
      v7,
      srcVer & 0xFFFFFFF);
  v7->numChains = 0;
}

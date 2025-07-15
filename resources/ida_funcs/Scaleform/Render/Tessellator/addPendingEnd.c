void __thiscall Scaleform::Render::Tessellator::addPendingEnd(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *dst,
        Scaleform::Render::Tessellator::ScanChainType *pending,
        float y)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // edi
  unsigned int leftBelow; // edx
  unsigned int vertex; // eax
  unsigned int Size; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v9; // eax
  Scaleform::Render::Tessellator::PendingEndType pe; // [esp+4h] [ebp-24h] BYREF
  Scaleform::Render::Tessellator::BaseLineType lowerBase; // [esp+Ch] [ebp-1Ch] BYREF

  if ( dst )
  {
    monotone = dst->monotone;
    if ( monotone )
    {
      if ( monotone->style )
      {
        if ( !monotone->lowerBase )
        {
          leftBelow = pending->chain->leftBelow;
          lowerBase.y = y;
          vertex = dst->vertex;
          Size = this->PendingEnds.Size;
          lowerBase.styleLeft = leftBelow;
          lowerBase.vertexLeft = vertex;
          lowerBase.firstChain = Size;
          lowerBase.vertexRight = -1;
          lowerBase.numChains = 0;
          lowerBase.leftAbove = -1;
          Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *)&this->BaseLines,
            (const Scaleform::Render::TessMesh *)&lowerBase);
          monotone->lowerBase = &this->BaseLines.Pages[(this->BaseLines.Size - 1) >> 4][(this->BaseLines.Size - 1) & 0xF];
        }
        v9 = pending->monotone;
        pe.vertex = pending->vertex;
        pe.monotone = v9;
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4>::PushBack(
          &this->PendingEnds,
          &pe);
        ++monotone->lowerBase->numChains;
      }
    }
  }
}

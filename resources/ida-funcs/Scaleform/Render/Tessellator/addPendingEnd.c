void __thiscall Scaleform::Render::Tessellator::addPendingEnd(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *dst,
        Scaleform::Render::Tessellator::ScanChainType *pending,
        unsigned int y)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // edi
  unsigned int leftBelow; // edx
  unsigned int vertex; // eax
  unsigned int Size; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v9; // eax
  Scaleform::Render::Tessellator::PendingEndType v10; // [esp+4h] [ebp-24h] BYREF
  Scaleform::Render::TessMesh val; // [esp+Ch] [ebp-1Ch] BYREF

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
          val.MeshIdx = y;
          vertex = dst->vertex;
          Size = this->PendingEnds.Size;
          val.Style1 = leftBelow;
          val.Style2 = vertex;
          val.Flags2 = Size;
          val.Flags1 = -1;
          val.StartVertex = 0;
          val.VertexCount = -1;
          Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *)&this->BaseLines,
            &val);
          monotone->lowerBase = &this->BaseLines.Pages[(this->BaseLines.Size - 1) >> 4][(this->BaseLines.Size - 1) & 0xF];
        }
        v9 = pending->monotone;
        v10.vertex = pending->vertex;
        v10.monotone = v9;
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4>::PushBack(
          &this->PendingEnds,
          &v10);
        ++monotone->lowerBase->numChains;
      }
    }
  }
}

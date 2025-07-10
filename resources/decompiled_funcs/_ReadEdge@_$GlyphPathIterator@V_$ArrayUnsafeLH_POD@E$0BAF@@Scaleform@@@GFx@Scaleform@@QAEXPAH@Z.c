void __thiscall Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(
        Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        int *edge)
{
  int v3; // eax
  unsigned int NumEdges; // eax

  this->EdgePos += Scaleform::GFx::PathDataDecoder<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(
                     &this->Data,
                     this->EdgePos,
                     edge);
  switch ( *edge )
  {
    case 0:
      this->MoveX += edge[1];
      goto LABEL_3;
    case 1:
      this->MoveY += edge[1];
LABEL_3:
      *edge = 2;
      edge[1] = this->MoveX;
      edge[2] = this->MoveY;
      break;
    case 2:
      this->MoveX += edge[1];
      this->MoveY += edge[2];
      edge[1] = this->MoveX;
      edge[2] = this->MoveY;
      break;
    case 3:
      this->MoveX += edge[1];
      this->MoveY += edge[2];
      v3 = edge[3];
      edge[1] = this->MoveX;
      edge[2] = this->MoveY;
      this->MoveX += v3;
      this->MoveY += edge[4];
      edge[3] = this->MoveX;
      edge[4] = this->MoveY;
      break;
    default:
      break;
  }
  NumEdges = this->NumEdges;
  if ( NumEdges )
    this->NumEdges = NumEdges - 1;
  if ( !this->NumEdges && this->JumpToPos )
    this->Pos = this->EdgePos;
}

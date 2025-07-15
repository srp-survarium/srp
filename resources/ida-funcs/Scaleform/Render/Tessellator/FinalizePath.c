void __thiscall Scaleform::Render::Tessellator::FinalizePath(
        Scaleform::Render::Tessellator *this,
        unsigned int leftStyle,
        unsigned int rightStyle,
        bool leftComplex,
        bool rightComplex)
{
  unsigned int LastVertex; // ebp
  unsigned int v7; // ebx
  unsigned int v8; // edi
  unsigned int v9; // eax
  Scaleform::Render::Tessellator::PathType path; // [esp+10h] [ebp-10h] BYREF

  LastVertex = this->LastVertex;
  if ( this->SrcVertices.Size >= LastVertex + 2 )
  {
    v7 = leftStyle;
    v8 = rightStyle;
    if ( leftStyle != rightStyle )
    {
      if ( !this->StrokerMode )
      {
LABEL_10:
        Scaleform::Render::Tessellator::addStyle(this, v7, leftComplex);
        Scaleform::Render::Tessellator::addStyle(this, v8, rightComplex);
        v9 = this->SrcVertices.Size - 1;
        path.start = this->LastVertex;
        path.end = v9;
        path.leftStyle = v7;
        path.rightStyle = v8;
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PathType,4,4>::PushBack(&this->Paths, &path);
        this->LastVertex = this->SrcVertices.Size;
        return;
      }
      if ( (leftStyle == 0) != (rightStyle == 0) )
      {
        if ( leftStyle )
          v7 = 1;
        if ( rightStyle )
          v8 = 1;
        rightComplex = 0;
        leftComplex = 0;
        goto LABEL_10;
      }
    }
  }
  if ( LastVertex < this->SrcVertices.Size )
    this->SrcVertices.Size = LastVertex;
}

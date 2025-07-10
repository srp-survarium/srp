void __thiscall Scaleform::Render::RectPacker::packRects(
        Scaleform::Render::RectPacker *this,
        unsigned int nodeIdx,
        unsigned int start)
{
  unsigned int Node2; // ecx
  Scaleform::Render::RectPacker::NodeType *v5; // ebp
  Scaleform::Render::RectPacker::RectType *v7; // edx
  Scaleform::Render::RectPacker::RectType *v8; // edi

  Node2 = nodeIdx;
  v5 = &this->PackTree.Pages[nodeIdx >> 8][(unsigned __int8)nodeIdx];
  if ( v5->Width >= this->MinWidth )
  {
LABEL_2:
    if ( v5->Height >= this->MinHeight )
    {
      while ( start < this->SrcRects.Size )
      {
        v7 = this->SrcRects.Pages[start >> 8];
        v8 = &v7[(unsigned __int8)start];
        if ( (v8->Id & 0x80000000) == 0 && v8->x <= v5->Width && v8->y <= v5->Height )
        {
          Scaleform::Render::RectPacker::splitSpace(this, Node2, &v7[(unsigned __int8)start]);
          v8->Id |= 0x80000000;
          ++this->NumPacked;
          Scaleform::Render::RectPacker::packRects(this, v5->Node1, start);
          Node2 = v5->Node2;
          v5 = &this->PackTree.Pages[Node2 >> 8][(unsigned __int8)Node2];
          if ( v5->Width >= this->MinWidth )
            goto LABEL_2;
          return;
        }
        ++start;
      }
    }
  }
}

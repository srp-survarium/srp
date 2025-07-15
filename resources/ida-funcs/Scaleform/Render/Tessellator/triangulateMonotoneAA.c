void __thiscall Scaleform::Render::Tessellator::triangulateMonotoneAA(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonoVertexType *m)
{
  Scaleform::Render::Tessellator::MonoVertexType *v2; // ebx
  unsigned int v4; // eax
  Scaleform::Render::TessMesh **Pages; // edx
  unsigned int v6; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v7; // ebp
  Scaleform::Render::Tessellator::MonoVertexType *next; // ebp
  Scaleform::Render::Tessellator::MonoVertexType *v9; // ecx
  unsigned int v10; // ebp
  unsigned int v11; // ebp
  unsigned int v12; // ebp
  Scaleform::Render::Tessellator::MonoVertexType *v13; // edx
  unsigned int aaVer; // [esp-4h] [ebp-18h]
  Scaleform::Render::Tessellator::MonoVertexType *v15; // [esp+10h] [ebp-4h]

  v2 = m;
  m = (Scaleform::Render::Tessellator::MonoVertexType *)m->srcVer;
  aaVer = v2[1].aaVer;
  this->MonoStyle = aaVer;
  v4 = Scaleform::Render::Tessellator::setMesh(this, aaVer);
  Pages = this->Meshes.Pages;
  this->MeshIdx = v4;
  v6 = (Pages[v4 >> 4][v4 & 0xF].Style1 != this->MonoStyle ? 0 : 8) | 2;
  this->FactorOneFlag = v6;
  v7 = m;
  Pages[v4 >> 4][v4 & 0xF].Flags1 |= v6 & 8;
  v2->aaVer = -1;
  v2->next = 0;
  v2[1].srcVer = this->MeshIdx;
  if ( v7 && v7->next && v7->next->next )
  {
    v2->aaVer = this->MeshTriangles.Arrays[this->MeshIdx].Size;
    this->MonoStack.Size = 0;
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::PushBack(&this->MonoStack, &m);
    next = v7->next;
    m = next;
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::PushBack(&this->MonoStack, &m);
    v9 = next->next;
    m = v9;
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = this->MonoStack.Size >> 4;
        v15 = this->MonoStack.Pages[(this->MonoStack.Size - 1) >> 4][(this->MonoStack.Size - 1) & 0xF];
        if ( v10 >= this->MonoStack.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
            &this->MonoStack,
            v10);
          v9 = m;
        }
        this->MonoStack.Pages[v10][this->MonoStack.Size++ & 0xF] = v9;
        if ( ((v9->srcVer & 0x80000000) != 0) != ((v15->srcVer & 0x80000000) != 0) )
        {
          Scaleform::Render::Tessellator::triangulateMountainAA(this);
          this->MonoStack.Size = 0;
          v11 = this->MonoStack.Size >> 4;
          if ( v11 >= this->MonoStack.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
              &this->MonoStack,
              this->MonoStack.Size >> 4);
          this->MonoStack.Pages[v11][this->MonoStack.Size++ & 0xF] = v15;
          v12 = this->MonoStack.Size >> 4;
          if ( v12 >= this->MonoStack.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
              &this->MonoStack,
              this->MonoStack.Size >> 4);
          v13 = m;
          this->MonoStack.Pages[v12][this->MonoStack.Size++ & 0xF] = m;
          v9 = v13;
        }
        m = v9->next;
        if ( !m )
          break;
        v9 = m;
      }
    }
    Scaleform::Render::Tessellator::triangulateMountainAA(this);
    v2->next = (Scaleform::Render::Tessellator::MonoVertexType *)(this->MeshTriangles.Arrays[this->MeshIdx].Size
                                                                - v2->aaVer);
  }
}

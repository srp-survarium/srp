void __thiscall Scaleform::Render::Tessellator::swapChains(
        Scaleform::Render::Tessellator *this,
        unsigned int startIn,
        unsigned int endIn)
{
  unsigned int i; // ebp
  unsigned int **Pages; // esi
  Scaleform::Render::Tessellator::IntersectionType *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // esi
  unsigned int v9; // edi
  int v10; // edx
  Scaleform::Render::Tessellator::MonoChainType *v11; // eax
  Scaleform::Render::Tessellator::MonoChainType ***v12; // eax
  Scaleform::Render::Tessellator::MonoChainType **v13; // esi
  Scaleform::Render::Tessellator::MonoChainType **v14; // edi
  Scaleform::Render::Tessellator::MonoChainType *v15; // eax
  unsigned int **v16; // edx
  unsigned int *v17; // eax
  unsigned int *v18; // ebx
  unsigned int v19; // edx
  unsigned int startIna; // [esp+8h] [ebp+4h]

  for ( i = startIn; i < endIn; *v17 = v19 )
  {
    Pages = this->InteriorOrder.Pages;
    v5 = &this->Intersections.Pages[i >> 4][i & 0xF];
    v6 = Pages[v5->pos1 >> 4][v5->pos1 & 0xF];
    v7 = Pages[v5->pos2 >> 4][v5->pos2 & 0xF];
    v8 = v6 >> 4;
    startIna = v6 & 0xF;
    this->InteriorChains.Pages[v8][startIna]->flags |= 0x10u;
    v9 = v7 >> 4;
    v10 = v7 & 0xF;
    v9 *= 4;
    v11 = (*(Scaleform::Render::Tessellator::MonoChainType ***)((char *)this->InteriorChains.Pages + v9))[v10];
    v11->flags |= 0x10u;
    v12 = this->InteriorChains.Pages;
    v13 = &v12[v8][startIna];
    v14 = &(*(Scaleform::Render::Tessellator::MonoChainType ***)((char *)v12 + v9))[v10];
    v15 = *v13;
    *v13 = *v14;
    *v14 = v15;
    v16 = this->InteriorOrder.Pages;
    v17 = &v16[v5->pos2 >> 4][v5->pos2 & 0xF];
    v18 = &v16[v5->pos1 >> 4][v5->pos1 & 0xF];
    v19 = *v18;
    ++i;
    *v18 = *v17;
  }
}

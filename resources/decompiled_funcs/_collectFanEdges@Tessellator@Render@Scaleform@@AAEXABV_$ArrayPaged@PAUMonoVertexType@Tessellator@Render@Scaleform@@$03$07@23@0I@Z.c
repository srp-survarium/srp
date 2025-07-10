void __thiscall Scaleform::Render::Tessellator::collectFanEdges(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *chain,
        const Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *oppos,
        unsigned __int16 style)
{
  const Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *v4; // edx
  const Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *v5; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v6; // ebp
  Scaleform::Render::Tessellator::MonoVertexType *v7; // esi
  unsigned int Size; // eax
  unsigned int v9; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *v10; // edi
  unsigned int v11; // eax
  Scaleform::Render::TessVertex *v12; // edx
  Scaleform::Render::Tessellator::EdgeAAType *v13; // eax

  v4 = oppos;
  v5 = chain;
  if ( oppos->Size )
    v6 = **oppos->Pages;
  else
    v6 = chain->Pages[(chain->Size - 1) >> 4][(chain->Size - 1) & 0xF];
  v7 = **chain->Pages;
  Size = chain->Size;
  if ( Size )
  {
    v9 = 1;
    while ( 1 )
    {
      if ( v9 >= Size )
      {
        v11 = v4->Size;
        v10 = v11 ? v4->Pages[(v11 - 1) >> 4][(v11 - 1) & 0xF] : **v5->Pages;
      }
      else
      {
        v10 = v5->Pages[v9 >> 4][v9 & 0xF];
      }
      v12 = &this->MeshVertices.Pages[(v7->srcVer & 0xFFFFFFF) >> 4][v7->srcVer & 0xF];
      v13 = &this->EdgeFans.Array[v12->Idx + v12->Mesh];
      v13->slope = 0;
      v13->style = style;
      v13->cntVer = v7;
      v13->rayVer = v6;
      ++v13;
      v13->slope = 0;
      v13->style = style ^ 0x8000;
      v5 = chain;
      v13->cntVer = v7;
      v13->rayVer = v10;
      v12->Mesh += 2;
      Size = chain->Size;
      ++v9;
      v6 = v7;
      v7 = v10;
      if ( v9 - 1 >= Size )
        break;
      v4 = oppos;
    }
  }
}

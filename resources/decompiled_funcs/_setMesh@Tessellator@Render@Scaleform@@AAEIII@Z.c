unsigned int __thiscall Scaleform::Render::Tessellator::setMesh(
        Scaleform::Render::Tessellator *this,
        unsigned int style1,
        unsigned int style2)
{
  unsigned int v5; // ebx
  unsigned int v6; // edi
  unsigned int *Array; // edx
  unsigned int v8; // eax
  unsigned int v9; // ebp
  unsigned int v10; // eax
  unsigned __int16 v11; // cx
  unsigned __int16 v12; // ax
  unsigned __int16 *v13; // edx
  unsigned __int16 *v14; // edx
  unsigned __int16 *v15; // ecx
  unsigned __int16 v16; // dx
  unsigned int v17; // eax
  unsigned __int16 meshSt1; // [esp+4h] [ebp-20h]
  Scaleform::Render::TessMesh mesh; // [esp+8h] [ebp-1Ch] BYREF
  unsigned int cf1; // [esp+28h] [ebp+4h]
  unsigned __int16 meshIdx; // [esp+2Ch] [ebp+8h]

  if ( !this->HasComplexFill )
    return 0;
  v5 = style2;
  v6 = style1;
  if ( this->StyleMatrix.Array[style2 + style1 * this->StyleMatrix.Size] != 0xFFFF )
    return this->StyleMatrix.Array[v5 + v6 * this->StyleMatrix.Size];
  Array = this->ComplexFlags.Array;
  v8 = Array[style1 >> 5] & (1 << (style1 & 0x1F));
  cf1 = v8;
  v9 = Array[style2 >> 5] & (1 << (style2 & 0x1F));
  if ( !(v8 | v9) )
  {
    v16 = 0;
    this->StyleMatrix.Array[v6 * (this->StyleMatrix.Size + 1)] = 0;
    this->StyleMatrix.Array[style2 * (this->StyleMatrix.Size + 1)] = 0;
    this->StyleMatrix.Array[style2 + v6 * this->StyleMatrix.Size] = 0;
    v15 = this->StyleMatrix.Array;
    v17 = v6 + style2 * this->StyleMatrix.Size;
    goto LABEL_27;
  }
  if ( v8 )
  {
    cf1 = 0x8000;
    v8 = 0x8000;
  }
  if ( v9 )
    v9 = 0x8000;
  if ( !v8 )
  {
    v10 = v6;
    cf1 = v9;
    v6 = style2;
    v5 = v10;
    v8 = v9;
    v9 = 0;
  }
  meshIdx = this->Meshes.Size;
  v11 = this->StyleMatrix.Array[v6 * (this->StyleMatrix.Size + 1)];
  meshSt1 = this->StyleMatrix.Array[v6 * (this->StyleMatrix.Size + 1)];
  if ( !v9 && v11 != 0xFFFF )
  {
    if ( (Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::operator[](&this->Meshes, v11)->Flags2 & 0x8000) == 0 )
    {
      v12 = meshSt1;
      meshIdx = meshSt1;
      goto LABEL_17;
    }
    v8 = cf1;
  }
  mesh.MeshIdx = this->Meshes.Size;
  mesh.Flags1 = v8;
  mesh.Style2 = v9 != 0 ? v5 : 0;
  mesh.Style1 = v6;
  mesh.Flags2 = v9;
  mesh.VertexCount = 0;
  mesh.StartVertex = 0;
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::PushBack(&this->Meshes, &mesh);
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&this->MeshTriangles);
  v12 = meshIdx;
LABEL_17:
  this->StyleMatrix.Array[v5 + v6 * this->StyleMatrix.Size] = v12;
  this->StyleMatrix.Array[v6 + v5 * this->StyleMatrix.Size] = v12;
  if ( this->InvasiveMerge )
  {
    v13 = this->StyleMatrix.Array;
    if ( v13[v6 * (this->StyleMatrix.Size + 1)] == 0xFFFF )
      v13[v6 * (this->StyleMatrix.Size + 1)] = v12;
    v14 = this->StyleMatrix.Array;
    if ( v14[v5 * (this->StyleMatrix.Size + 1)] == 0xFFFF )
      v14[v5 * (this->StyleMatrix.Size + 1)] = v12;
    return this->StyleMatrix.Array[v5 + v6 * this->StyleMatrix.Size];
  }
  v15 = this->StyleMatrix.Array;
  if ( v15[v6 * (this->StyleMatrix.Size + 1)] == 0xFFFF && cf1 && !v9 )
  {
    v16 = meshIdx;
    v17 = v6 * (this->StyleMatrix.Size + 1);
LABEL_27:
    v15[v17] = v16;
  }
  return this->StyleMatrix.Array[v5 + v6 * this->StyleMatrix.Size];
}

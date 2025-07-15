unsigned int __thiscall Scaleform::Render::Tessellator::setMesh(
        Scaleform::Render::Tessellator *this,
        unsigned int style)
{
  Scaleform::Render::TessMesh val; // [esp+4h] [ebp-1Ch] BYREF

  if ( !this->HasComplexFill )
    return 0;
  if ( this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)] == 0xFFFF )
  {
    if ( ((1 << (style & 0x1F)) & this->ComplexFlags.Array[style >> 5]) != 0 )
    {
      this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)] = this->Meshes.Size;
      val.MeshIdx = this->Meshes.Size;
      val.Style2 = style;
      val.Style1 = style;
      val.Flags2 = 0x8000;
      val.Flags1 = 0x8000;
      val.VertexCount = 0;
      val.StartVertex = 0;
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::PushBack(&this->Meshes, &val);
      Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&this->MeshTriangles);
    }
    else
    {
      this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)] = 0;
    }
  }
  return this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)];
}


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
  unsigned __int16 v18; // [esp+4h] [ebp-20h]
  Scaleform::Render::TessMesh val; // [esp+8h] [ebp-1Ch] BYREF
  int v20; // [esp+28h] [ebp+4h]
  unsigned __int16 Size; // [esp+2Ch] [ebp+8h]

  if ( !this->HasComplexFill )
    return 0;
  v5 = style2;
  v6 = style1;
  if ( this->StyleMatrix.Array[style2 + style1 * this->StyleMatrix.Size] != 0xFFFF )
    return this->StyleMatrix.Array[v5 + v6 * this->StyleMatrix.Size];
  Array = this->ComplexFlags.Array;
  v8 = Array[style1 >> 5] & (1 << (style1 & 0x1F));
  v20 = v8;
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
    v20 = 0x8000;
    v8 = 0x8000;
  }
  if ( v9 )
    v9 = 0x8000;
  if ( !v8 )
  {
    v10 = v6;
    v20 = v9;
    v6 = style2;
    v5 = v10;
    v8 = v9;
    v9 = 0;
  }
  Size = this->Meshes.Size;
  v11 = this->StyleMatrix.Array[v6 * (this->StyleMatrix.Size + 1)];
  v18 = this->StyleMatrix.Array[v6 * (this->StyleMatrix.Size + 1)];
  if ( !v9 && v11 != 0xFFFF )
  {
    if ( (Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::operator[](&this->Meshes, v11)->Flags2 & 0x8000) == 0 )
    {
      v12 = v18;
      Size = v18;
      goto LABEL_17;
    }
    v8 = v20;
  }
  val.MeshIdx = this->Meshes.Size;
  val.Flags1 = v8;
  val.Style2 = v9 != 0 ? v5 : 0;
  val.Style1 = v6;
  val.Flags2 = v9;
  val.VertexCount = 0;
  val.StartVertex = 0;
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::PushBack(&this->Meshes, &val);
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&this->MeshTriangles);
  v12 = Size;
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
  if ( v15[v6 * (this->StyleMatrix.Size + 1)] == 0xFFFF && v20 && !v9 )
  {
    v16 = Size;
    v17 = v6 * (this->StyleMatrix.Size + 1);
LABEL_27:
    v15[v17] = v16;
  }
  return this->StyleMatrix.Array[v5 + v6 * this->StyleMatrix.Size];
}

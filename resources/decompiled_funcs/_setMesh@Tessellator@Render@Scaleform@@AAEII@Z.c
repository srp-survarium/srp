unsigned int __thiscall Scaleform::Render::Tessellator::setMesh(
        Scaleform::Render::Tessellator *this,
        unsigned int style)
{
  Scaleform::Render::TessMesh mesh; // [esp+4h] [ebp-1Ch] BYREF

  if ( !this->HasComplexFill )
    return 0;
  if ( this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)] == 0xFFFF )
  {
    if ( ((1 << (style & 0x1F)) & this->ComplexFlags.Array[style >> 5]) != 0 )
    {
      this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)] = this->Meshes.Size;
      mesh.MeshIdx = this->Meshes.Size;
      mesh.Style2 = style;
      mesh.Style1 = style;
      mesh.Flags2 = 0x8000;
      mesh.Flags1 = 0x8000;
      mesh.VertexCount = 0;
      mesh.StartVertex = 0;
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::PushBack(&this->Meshes, &mesh);
      Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&this->MeshTriangles);
    }
    else
    {
      this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)] = 0;
    }
  }
  return this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)];
}

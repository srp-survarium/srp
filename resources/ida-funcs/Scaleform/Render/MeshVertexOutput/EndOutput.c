void __thiscall Scaleform::Render::MeshVertexOutput::EndOutput(Scaleform::Render::MeshVertexOutput *this)
{
  if ( (this->Result.Value & 1) != 0 )
    this->pCache->PostUpdateMesh(this->pCache, this->batchData);
}

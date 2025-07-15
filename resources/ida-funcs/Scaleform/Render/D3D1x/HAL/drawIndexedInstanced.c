void __userpurge Scaleform::Render::D3D1x::HAL::drawIndexedInstanced(
        Scaleform::Render::D3D1x::HAL *this@<esi>,
        unsigned int meshCount@<edi>,
        unsigned int indexCount,
        unsigned int indexOffset,
        int vertexBaseIndex)
{
  this->pDeviceContext->DrawIndexedInstanced(
    this->pDeviceContext,
    indexCount,
    meshCount,
    indexOffset,
    vertexBaseIndex,
    0);
  this->AccumulatedStats.Meshes += meshCount;
  this->AccumulatedStats.Triangles += meshCount * (indexCount / 3);
  ++this->AccumulatedStats.Primitives;
}

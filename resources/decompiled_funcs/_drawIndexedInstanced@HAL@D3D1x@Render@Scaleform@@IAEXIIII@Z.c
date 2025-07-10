void __userpurge Scaleform::Render::D3D1x::HAL::drawIndexedInstanced(
        Scaleform::Render::D3D1x::HAL *this@<eax>,
        int vertexBaseIndex@<edx>,
        unsigned int indexCount,
        unsigned int meshCount,
        unsigned int indexOffset)
{
  this->pDeviceContext->DrawIndexedInstanced(
    this->pDeviceContext,
    indexCount,
    meshCount,
    indexOffset,
    vertexBaseIndex,
    0);
}

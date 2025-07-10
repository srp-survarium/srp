void __userpurge Scaleform::Render::D3D1x::HAL::drawIndexedPrimitive(
        Scaleform::Render::D3D1x::HAL *this@<eax>,
        int vertexBaseIndex@<edx>,
        unsigned int indexCount,
        unsigned int meshCount,
        unsigned int indexOffset)
{
  this->pDeviceContext->DrawIndexed(this->pDeviceContext, indexCount, meshCount, vertexBaseIndex);
}

void __thiscall Scaleform::Render::D3D1x::HAL::drawPrimitive(
        Scaleform::Render::D3D1x::HAL *this,
        unsigned int indexCount,
        unsigned int meshCount)
{
  this->pDeviceContext->Draw(this->pDeviceContext, indexCount, 0);
  this->AccumulatedStats.Meshes += meshCount;
  this->AccumulatedStats.Triangles += indexCount / 3;
  ++this->AccumulatedStats.Primitives;
}

ID3D11Buffer *__thiscall Scaleform::Render::D3D1x::HAL::getNextConstantBuffer(Scaleform::Render::D3D1x::HAL *this)
{
  unsigned int v1; // eax

  v1 = ((unsigned __int8)this->CurrentConstantBuffer + 1) & 7;
  this->CurrentConstantBuffer = v1;
  return this->ConstantBuffers[v1];
}

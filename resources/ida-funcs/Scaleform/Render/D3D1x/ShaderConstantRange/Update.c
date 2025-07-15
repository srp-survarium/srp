void __userpurge Scaleform::Render::D3D1x::ShaderConstantRange::Update(
        Scaleform::Render::D3D1x::ShaderConstantRange *this@<esi>,
        int offset@<eax>,
        int size,
        int shadowLocation)
{
  Scaleform::Render::D3D1x::HAL *pHal; // ecx
  int v6; // eax
  ID3D11Buffer *v7; // eax
  Scaleform::Render::D3D1x::HAL *v8; // ecx

  if ( offset >= 0 )
  {
    if ( !this->pConstantBuffer )
    {
      pHal = this->pHal;
      v6 = ((unsigned __int8)pHal->CurrentConstantBuffer + 1) & 7;
      pHal->CurrentConstantBuffer = v6;
      v7 = pHal->ConstantBuffers[v6];
      v8 = this->pHal;
      this->pConstantBuffer = v7;
      v8->pDeviceContext->Map(v8->pDeviceContext, v7, 0, D3D11_MAP_WRITE_DISCARD, 0, &this->MappedBuffer);
    }
    memcpy(
      (unsigned __int8 *)this->MappedBuffer.pData + 4 * ((unsigned int)offset >> 2),
      (unsigned __int8 *)&this->UniformData[shadowLocation],
      4 * size);
  }
}

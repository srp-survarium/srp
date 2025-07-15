char __userpurge Scaleform::Render::D3D1x::ShaderManager::Initialize@<al>(
        Scaleform::Render::D3D1x::HAL *phal@<eax>,
        Scaleform::Render::D3D1x::ShaderManager *this)
{
  ID3D11Device *pDevice; // esi
  ID3D11Device *pObject; // eax
  ID3D11Device *v5; // eax
  int v6; // eax
  Scaleform::Render::D3D1x::VertexShader *StaticVShaders; // edi
  const Scaleform::Render::D3D1x::VertexShaderDesc *v8; // esi
  int *UniformOffset; // edi
  const Scaleform::Render::D3D1x::FragShaderDesc *v10; // esi
  ID3D11Device *v11; // eax
  unsigned int v12; // eax
  int *v13; // ecx
  unsigned int v15; // [esp+14h] [ebp+8h]
  unsigned int v16; // [esp+14h] [ebp+8h]

  pDevice = phal->pDevice;
  if ( pDevice )
    pDevice->AddRef(pDevice);
  pObject = this->pDevice.pObject;
  if ( pObject )
    pObject->Release(this->pDevice.pObject);
  this->pDevice.pObject = pDevice;
  v5 = this->pDevice.pObject;
  this->ShaderModel = ShaderVersion_D3D1xFL1x;
  v6 = v5->GetFeatureLevel(v5);
  if ( v6 == 37120 || v6 == 37376 )
  {
    this->ShaderModel = ShaderVersion_D3D1xFL91;
  }
  else if ( v6 == 37632 )
  {
    this->ShaderModel = ShaderVersion_D3D1xFL93;
  }
  v15 = 0;
  StaticVShaders = this->StaticVShaders;
  do
  {
    v8 = Scaleform::Render::D3D1x::VertexShaderDesc::Descs[v15];
    if ( v8
      && v8->Version == this->ShaderModel
      && v8->pBinary
      && !Scaleform::Render::D3D1x::VertexShader::Init(StaticVShaders, this->pDevice.pObject, v8) )
    {
      return 0;
    }
    ++v15;
    ++StaticVShaders;
  }
  while ( v15 < 232 );
  v16 = 0;
  UniformOffset = this->StaticFShaders[0].UniformOffset;
  do
  {
    v10 = Scaleform::Render::D3D1x::FragShaderDesc::Descs[v16];
    if ( v10 && v10->Version == this->ShaderModel && v10->pBinary )
    {
      v11 = this->pDevice.pObject;
      *(UniformOffset - 3) = (int)v10;
      if ( v11->CreatePixelShader(v11, v10->pBinary, v10->BinarySize, 0, (ID3D11PixelShader **)UniformOffset - 2) < 0 )
        return 0;
      v12 = 0;
      v13 = UniformOffset;
      do
        *v13++ = 16 * v10->Uniforms[v12++].Location;
      while ( v12 < 15 );
    }
    ++v16;
    UniformOffset += 18;
  }
  while ( v16 < 598 );
  return 1;
}

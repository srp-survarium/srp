char __userpurge Scaleform::Render::D3D1x::ShaderManager::Initialize@<al>(
        Scaleform::Render::D3D1x::HAL *phal@<eax>,
        Scaleform::Render::D3D1x::ShaderManager *this)
{
  ID3D11Device *pDevice; // esi
  unsigned int v3; // ebp
  ID3D11Device *pObject; // eax
  ID3D11Device *v5; // eax
  int v6; // eax
  Scaleform::Render::D3D1x::VertexShader *StaticVShaders; // edi
  const Scaleform::Render::D3D1x::VertexShaderDesc *v8; // esi
  Scaleform::Render::D3D1x::FragShader *StaticFShaders; // edi
  unsigned int v10; // ebp
  const Scaleform::Render::D3D1x::FragShaderDesc *v11; // esi

  pDevice = phal->pDevice;
  v3 = 0;
  if ( pDevice )
    pDevice->AddRef(phal->pDevice);
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
  StaticVShaders = this->StaticVShaders;
  while ( 1 )
  {
    v8 = Scaleform::Render::D3D1x::VertexShaderDesc::Descs[v3];
    if ( v8 )
    {
      if ( v8->Version == this->ShaderModel
        && v8->pBinary
        && !Scaleform::Render::D3D1x::VertexShader::Init(StaticVShaders, this->pDevice.pObject, v8) )
      {
        break;
      }
    }
    ++v3;
    ++StaticVShaders;
    if ( v3 >= 232 )
    {
      StaticFShaders = this->StaticFShaders;
      v10 = 0;
      while ( 1 )
      {
        v11 = Scaleform::Render::D3D1x::FragShaderDesc::Descs[v10];
        if ( v11 )
        {
          if ( v11->Version == this->ShaderModel
            && v11->pBinary
            && !Scaleform::Render::D3D1x::FragShader::Init(StaticFShaders, this->pDevice.pObject, v11) )
          {
            break;
          }
        }
        ++v10;
        ++StaticFShaders;
        if ( v10 >= 598 )
          return 1;
      }
      return 0;
    }
  }
  return 0;
}

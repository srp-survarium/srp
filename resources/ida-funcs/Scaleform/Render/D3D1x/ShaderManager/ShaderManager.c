void __usercall Scaleform::Render::D3D1x::ShaderManager::ShaderManager(
        Scaleform::Render::D3D1x::ShaderManager *this@<esi>,
        Scaleform::Render::ProfileViews *prof@<eax>)
{
  Scaleform::Render::D3D1x::VertexShader *StaticVShaders; // eax
  int j; // edx
  int i; // [esp+8h] [ebp-8h]
  Scaleform::Render::D3D1x::FragShader *StaticFShaders; // [esp+Ch] [ebp-4h]

  this->VFormats.KeyBuffer.pPages = 0;
  this->VFormats.KeyBuffer.pLast = 0;
  this->VFormats.ValueBuffer.pPages = 0;
  this->VFormats.ValueBuffer.pLast = 0;
  this->Profiler = prof;
  this->VertexFormatComputedHash = 0;
  StaticFShaders = this->StaticFShaders;
  for ( i = 597; i >= 0; --i )
    Scaleform::Render::D3D1x::FragShader::FragShader(StaticFShaders++);
  StaticVShaders = this->StaticVShaders;
  for ( j = 231; j >= 0; --j )
  {
    StaticVShaders->pDesc = 0;
    StaticVShaders->pProg.pObject = 0;
    ++StaticVShaders;
  }
  this->pDevice.pObject = 0;
  this->ShaderModel = ShaderVersion_D3D1xFL91;
  memset((int)this->StaticVShaders, 0, sizeof(this->StaticVShaders));
  memset((int)this->StaticFShaders, 0, sizeof(this->StaticFShaders));
}

void __usercall Scaleform::Render::D3D1x::ShaderManager::ShaderManager(
        Scaleform::Render::D3D1x::ShaderManager *this@<esi>,
        Scaleform::Render::ProfileViews *prof@<eax>)
{
  this->VFormats.KeyBuffer.pPages = 0;
  this->VFormats.KeyBuffer.pLast = 0;
  this->VFormats.ValueBuffer.pPages = 0;
  this->VFormats.ValueBuffer.pLast = 0;
  this->Profiler = prof;
  this->VertexFormatComputedHash = 0;
  `vector constructor iterator'(
    (char *)this->StaticFShaders,
    0x48u,
    598,
    (void *(__thiscall *)(void *))Scaleform::Render::D3D1x::FragShader::FragShader);
  `vector constructor iterator'(
    (char *)this->StaticVShaders,
    0x44u,
    232,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  this->pDevice.pObject = 0;
  this->ShaderModel = ShaderVersion_D3D1xFL91;
  memset((int)this->StaticVShaders, 0, sizeof(this->StaticVShaders));
  memset((int)this->StaticFShaders, 0, sizeof(this->StaticFShaders));
}

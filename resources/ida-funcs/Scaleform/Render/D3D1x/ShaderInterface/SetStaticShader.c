BOOL __userpurge Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader@<eax>(
        Scaleform::Render::D3D1x::ShaderInterface *this@<ecx>,
        _DWORD *a2@<eax>,
        Scaleform::Render::D3D1x::ShaderDesc::ShaderType shader,
        const Scaleform::Render::VertexFormat *pformat)
{
  int v5; // edx
  Scaleform::Render::D3D1x::VertexShaderDesc::ShaderIndex ShaderIndex; // eax
  int v7; // edx
  _DWORD *v8; // eax
  const Scaleform::Render::D3D1x::VertexShaderDesc ***v9; // edi
  Scaleform::Render::D3D1x::FragShaderDesc::ShaderIndex v10; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  int v12; // edx
  _DWORD *v13; // eax
  Scaleform::Render::D3D1x::SysVertexFormat *v14; // eax
  Scaleform::Render::SystemVertexFormat *v15; // eax
  Scaleform::Render::SystemVertexFormat *v16; // esi
  const Scaleform::Render::VertexFormat *v18; // [esp+0h] [ebp-Ch]

  v5 = a2[1096];
  a2[1101] = pformat;
  ShaderIndex = Scaleform::Render::D3D1x::VertexShaderDesc::GetShaderIndex(
                  shader,
                  *(Scaleform::Render::D3D1x::ShaderDesc::ShaderVersion *)(v5 + 59504));
  v8 = (_DWORD *)(v7 + 68 * (ShaderIndex + 643));
  v9 = (const Scaleform::Render::D3D1x::VertexShaderDesc ***)(a2 + 1097);
  a2[1097] = v8;
  a2[1098] = *v8;
  v10 = Scaleform::Render::D3D1x::FragShaderDesc::GetShaderIndex(
          shader,
          *(Scaleform::Render::D3D1x::ShaderDesc::ShaderVersion *)(v7 + 59504));
  v13 = (_DWORD *)(72 * v10 + v12 + 668);
  a2[1099] = v13;
  a2[1100] = *v13;
  if ( pformat && !pformat->pSysFormat.pObject )
  {
    v14 = (Scaleform::Render::D3D1x::SysVertexFormat *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         240,
                                                         0);
    if ( v14 )
    {
      Scaleform::Render::D3D1x::SysVertexFormat::SysVertexFormat(**v9, v14, *(ID3D11Device **)(a2[1096] + 63952), v18);
      v16 = v15;
    }
    else
    {
      v16 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)pformat->pSysFormat.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    pformat->pSysFormat.pObject = v16;
  }
  return Scaleform::Render::D3D1x::ShaderPair::operator bool((Scaleform::Render::D3D1x::ShaderPair *)pObject, v9);
}

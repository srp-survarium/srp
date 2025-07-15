BOOL __userpurge Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader@<eax>(
        Scaleform::Render::D3D1x::ShaderInterface *this@<ecx>,
        int a2@<esi>,
        Scaleform::Render::D3D1x::ShaderDesc::ShaderType shader,
        const Scaleform::Render::VertexFormat *pformat)
{
  int v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  Scaleform::Render::D3D1x::SysVertexFormat *v7; // eax
  Scaleform::Render::SystemVertexFormat *v8; // eax
  Scaleform::Render::SystemVertexFormat *v9; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  int v11; // ecx
  int v12; // eax
  BOOL result; // eax

  v4 = *(_DWORD *)(a2 + 4384);
  *(_DWORD *)(a2 + 4404) = pformat;
  v5 = (_DWORD *)(v4
                + 68
                * Scaleform::Render::D3D1x::VertexShaderDesc::GetShaderIndex(
                    shader,
                    *(Scaleform::Render::D3D1x::ShaderDesc::ShaderVersion *)(v4 + 59344))
                + 43564);
  *(_DWORD *)(a2 + 4388) = v5;
  *(_DWORD *)(a2 + 4392) = *v5;
  v6 = (_DWORD *)(v4
                + 72
                * Scaleform::Render::D3D1x::FragShaderDesc::GetShaderIndex(
                    shader,
                    *(Scaleform::Render::D3D1x::ShaderDesc::ShaderVersion *)(v4 + 59344))
                + 508);
  *(_DWORD *)(a2 + 4396) = v6;
  *(_DWORD *)(a2 + 4400) = *v6;
  if ( pformat && !pformat->pSysFormat.pObject )
  {
    v7 = (Scaleform::Render::D3D1x::SysVertexFormat *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        240,
                                                        0);
    if ( v7 )
    {
      Scaleform::Render::D3D1x::SysVertexFormat::SysVertexFormat(
        pformat,
        v7,
        *(ID3D11Device **)(*(_DWORD *)(a2 + 4384) + 63792),
        **(const Scaleform::Render::D3D1x::VertexShaderDesc ***)(a2 + 4388));
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)pformat->pSysFormat.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    pformat->pSysFormat.pObject = v9;
  }
  v11 = *(_DWORD *)(a2 + 4388);
  result = 0;
  if ( v11 )
  {
    v12 = *(_DWORD *)(a2 + 4396);
    if ( v12 )
    {
      if ( *(_DWORD *)(v11 + 4) && *(_DWORD *)(v12 + 4) && *(_DWORD *)(a2 + 4404) )
        return 1;
    }
  }
  return result;
}

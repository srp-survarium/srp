const Scaleform::Render::D3D1x::VertexShaderDesc *__usercall Scaleform::Render::D3D1x::VertexShaderDesc::GetDesc@<eax>(
        int shader@<eax>)
{
  return Scaleform::Render::D3D1x::VertexShaderDesc::Descs[Scaleform::Render::D3D1x::VertexShaderDesc::GetShaderIndex(
                                                             shader,
                                                             ShaderVersion_D3D1xFL91)];
}

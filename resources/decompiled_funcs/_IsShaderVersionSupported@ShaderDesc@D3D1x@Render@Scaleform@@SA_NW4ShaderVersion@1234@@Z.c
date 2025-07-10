bool __usercall Scaleform::Render::D3D1x::ShaderDesc::IsShaderVersionSupported@<al>(
        Scaleform::Render::D3D1x::ShaderDesc::ShaderVersion ver@<eax>)
{
  return ver == ShaderVersion_D3D1xFL91 || (unsigned int)(ver - 1) < 2;
}

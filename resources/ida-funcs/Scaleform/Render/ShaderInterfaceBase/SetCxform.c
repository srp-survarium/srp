void __userpurge Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
        Scaleform::Render::Cxform *cx@<eax>,
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        const Scaleform::Render::D3D1x::ShaderPair *sd,
        unsigned int index,
        unsigned int batch)
{
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    sd,
    this,
    1u,
    (float *)cx,
    4u,
    0,
    index);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    sd,
    this,
    0,
    cx->M[1],
    4u,
    0,
    index);
}

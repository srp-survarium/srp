void __userpurge Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
        unsigned int batch@<edi>,
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        const Scaleform::Render::D3D1x::ShaderPair *sd,
        const Scaleform::Render::Cxform *cx,
        unsigned int index)
{
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    sd,
    1u,
    0,
    this,
    (const float *)cx,
    4u,
    batch);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    sd,
    0,
    0,
    this,
    cx->M[1],
    4u,
    batch);
}

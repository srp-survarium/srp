void __userpurge Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetColor(
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this@<ecx>,
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *sd,
        const Scaleform::Render::D3D1x::ShaderPair *var,
        Scaleform::Render::Color c,
        unsigned int index,
        unsigned int batch)
{
  float v6[4]; // [esp+0h] [ebp-10h] BYREF

  v6[0] = (float)c.Channels.Red * 0.0039215689;
  v6[1] = (float)c.Channels.Green * 0.0039215689;
  v6[2] = (float)c.Channels.Blue * 0.0039215689;
  v6[3] = (float)HIBYTE(c.Raw) * 0.0039215689;
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    var,
    sd,
    1u,
    v6,
    4u,
    0,
    index);
}

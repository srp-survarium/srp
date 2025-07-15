void __thiscall Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this)
{
  *(_DWORD *)this->UniformSet = 0;
  *(_DWORD *)&this->UniformSet[4] = 0;
  *(_DWORD *)&this->UniformSet[8] = 0;
  *(_WORD *)&this->UniformSet[12] = 0;
  this->UniformSet[14] = 0;
  this->Textures[0] = 0;
  this->Textures[1] = 0;
  this->Textures[2] = 0;
  this->Textures[3] = 0;
}

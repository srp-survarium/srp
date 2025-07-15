void __usercall Scaleform::Render::D3D1x::ShaderInterface::ShaderInterface(
        Scaleform::Render::D3D1x::ShaderInterface *this@<eax>,
        Scaleform::Render::D3D1x::HAL *phal@<edx>)
{
  *(_QWORD *)this->Textures = 0;
  *(_QWORD *)&this->Textures[2] = 0;
  *(_QWORD *)this->UniformSet = 0;
  *(_DWORD *)&this->UniformSet[8] = 0;
  *(_WORD *)&this->UniformSet[12] = 0;
  this->UniformSet[14] = 0;
  this->pHal = phal;
  this->CurShaders.pVS = 0;
  this->CurShaders.pVDesc = 0;
  this->CurShaders.pFS = 0;
  this->CurShaders.pFDesc = 0;
  this->CurShaders.pVFormat = 0;
  this->pLastVS = 0;
  this->pLastFS = 0;
  this->pLastDecl = 0;
}

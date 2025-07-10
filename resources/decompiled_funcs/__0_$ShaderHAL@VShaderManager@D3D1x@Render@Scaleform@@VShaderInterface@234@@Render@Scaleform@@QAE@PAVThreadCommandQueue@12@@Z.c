void __usercall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this@<edi>,
        Scaleform::Render::ThreadCommandQueue *commandQueue@<eax>)
{
  Scaleform::Render::HAL::HAL(this, commandQueue);
  this->__vftable = (Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>_vtbl *)&Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::`vftable';
  this->Shader.pVS = 0;
  this->Shader.pVDesc = 0;
  this->Shader.pFS = 0;
  this->Shader.pFDesc = 0;
  this->Shader.pVFormat = 0;
  Scaleform::Render::D3D1x::ShaderManager::ShaderManager(&this->SManager, &this->Profiler);
  Scaleform::Render::D3D1x::ShaderInterface::ShaderInterface(&this->ShaderData, (Scaleform::Render::D3D1x::HAL *)this);
  *(_QWORD *)this->MappedXY16iAlphaTexture = 0;
  this->MappedXY16iAlphaTexture[2] = 0;
  *(_QWORD *)this->MappedXY16iAlphaSolid = 0;
  this->MappedXY16iAlphaSolid[2] = 0;
}

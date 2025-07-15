void __userpurge Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
        unsigned int var@<eax>,
        Scaleform::Render::Texture *ptexture@<ecx>,
        Scaleform::Render::D3D1x::ShaderInterface *this,
        const Scaleform::Render::D3D1x::ShaderPair __formal,
        Scaleform::Render::ImageFillMode fm,
        unsigned int index)
{
  ptexture->ApplyTexture(ptexture, index + this->CurShaders.pFDesc->Uniforms[var].Location, &fm);
}

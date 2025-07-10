void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyChannel(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen,
        const Scaleform::Render::Matrix4x4<float> *cxmul)
{
  this->DrawableMerge(this, tex, texgen, cxmul);
}

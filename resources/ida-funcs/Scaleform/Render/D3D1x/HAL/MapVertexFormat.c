void __thiscall Scaleform::Render::D3D1x::HAL::MapVertexFormat(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::VertexFormat *fill,
        const Scaleform::Render::VertexFormat **sourceFormat,
        const Scaleform::Render::VertexFormat **single,
        const Scaleform::Render::VertexFormat **batch,
        const Scaleform::Render::VertexFormat **instanced,
        unsigned int __formal)
{
  Scaleform::Render::D3D1x::ShaderManager::MapVertexFormat(
    &this->SManager,
    (Scaleform::Render::PrimitiveFillType)&this->SManager,
    fill,
    sourceFormat,
    single,
    batch,
    (unsigned int)instanced);
}

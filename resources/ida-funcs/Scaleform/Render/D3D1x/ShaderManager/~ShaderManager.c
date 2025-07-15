void __usercall Scaleform::Render::D3D1x::ShaderManager::~ShaderManager(
        Scaleform::Render::D3D1x::ShaderManager *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *v4; // ecx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *v5; // ecx

  v3 = *(_DWORD *)(a2 + 58856);
  if ( v3 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
  `vector destructor iterator'(
    (char *)(a2 + 43080),
    0x44u,
    232,
    (void (__thiscall *)(void *))Scaleform::Render::D3D1x::FragShader::~FragShader);
  `vector destructor iterator'(
    (char *)(a2 + 24),
    0x48u,
    598,
    (void (__thiscall *)(void *))Scaleform::Render::D3D1x::FragShader::~FragShader);
  __1__HashSetBase_U__HashNode_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform__UResultFormat_234_V__FixedSizeHash_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform___4__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform___01_2_V__HashsetCachedNodeEntry_U__HashNode_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform__UResultFormat_234_V__FixedSizeHash_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform___4__Scaleform__UNodeHashF_12__2__Scaleform__QAE_XZ((int *)(a2 + 20));
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    v4,
    a2 + 8);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::freePages(v5, a2);
}

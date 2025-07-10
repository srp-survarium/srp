void __usercall Scaleform::Render::D3D1x::ShaderManager::~ShaderManager(
        Scaleform::Render::D3D1x::ShaderManager *this@<ecx>,
        _DWORD *a2@<eax>)
{
  int v3; // eax
  int v4; // ebx
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // ebx
  _DWORD *v8; // esi
  int v9; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *v10; // ecx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *v11; // ecx
  bool v12; // [esp+0h] [ebp-Ch]

  v3 = a2[14714];
  if ( v3 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
  v4 = 231;
  v5 = a2 + 14715;
  do
  {
    v6 = *(v5 - 17);
    v5 -= 17;
    if ( v6 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
    *v5 = 0;
    if ( *v5 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v5 + 8))(*v5);
    --v4;
  }
  while ( v4 >= 0 );
  v7 = 597;
  v8 = a2 + 10771;
  do
  {
    v9 = *(v8 - 18);
    v8 -= 18;
    if ( v9 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v9 + 8))(v9);
    *v8 = 0;
    if ( *v8 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v8 + 8))(*v8);
    --v7;
  }
  while ( v7 >= 0 );
  __1__HashSetBase_U__HashNode_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform__UResultFormat_234_V__FixedSizeHash_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform___4__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform___01_2_V__HashsetCachedNodeEntry_U__HashNode_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform__UResultFormat_234_V__FixedSizeHash_USourceFormatHash___StaticShaderManager_UShaderDesc_D3D1x_Render_Scaleform__UVertexShaderDesc_234_UUniform_234_VShaderInterface_234_VTexture_234__Render_Scaleform___4__Scaleform__UNodeHashF_12__2__Scaleform__QAE_XZ(this);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    v10,
    (_BYTE)a2 + 8);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::freePages(v11, v12);
}

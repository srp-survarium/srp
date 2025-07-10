void __usercall vostok::render::render_target::destroy(vostok::render::render_target *this@<ecx>, int a2@<edi>)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v7; // eax
  volatile signed __int32 *v8; // eax
  volatile signed __int32 *v9; // esi
  const char *v10; // eax
  volatile signed __int32 *v11; // eax
  volatile signed __int32 *v12; // esi
  const char *v13; // eax
  int v14; // eax
  int v15; // eax

  v2 = *(_DWORD *)(a2 + 24);
  if ( v2 )
  {
    *(_DWORD *)(v2 + 432) = 0;
    v3 = *(_DWORD *)(v2 + 420);
    if ( v3 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(v2 + 420));
      *(_DWORD *)(v2 + 420) = 0;
    }
    v4 = *(_DWORD *)(v2 + 428);
    if ( v4 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(*(_DWORD *)(v2 + 428));
      *(_DWORD *)(v2 + 428) = 0;
    }
    *(_DWORD *)(v2 + 420) = 0;
    *(_BYTE *)(v2 + 436) = 0;
    *(_BYTE *)(v2 + 437) = 0;
    v5 = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(a2 + 24) = 0;
    if ( v5 )
    {
      if ( (*(_DWORD *)(v5 + 4))-- == 1 )
        vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
    }
  }
  v7 = *(_DWORD *)(a2 + 16);
  if ( v7 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(*(_DWORD *)(a2 + 16));
    *(_DWORD *)(a2 + 16) = 0;
  }
  if ( *(_DWORD *)(a2 + 8) )
  {
    v8 = *(volatile signed __int32 **)(a2 + 4);
    v9 = 0;
    if ( v8
      && (v9 = *(volatile signed __int32 **)(a2 + 4),
          _InterlockedExchangeAdd(v8, 1u),
          vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
    {
      v10 = (const char *)(v8 + 4);
    }
    else
    {
      v10 = 0;
    }
    log_ref_count<ID3D11Texture2D>(*(ID3D11Texture2D **)(a2 + 8), v10);
    if ( v9 )
    {
      if ( !_InterlockedExchangeAdd(v9, 0xFFFFFFFF) )
        vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  if ( *(_DWORD *)(a2 + 12) )
  {
    v11 = *(volatile signed __int32 **)(a2 + 4);
    v12 = 0;
    if ( v11
      && (v12 = *(volatile signed __int32 **)(a2 + 4),
          _InterlockedExchangeAdd(v11, 1u),
          vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
    {
      v13 = (const char *)(v11 + 4);
    }
    else
    {
      v13 = 0;
    }
    log_ref_count<ID3D11Texture3D>(*(ID3D11Texture3D **)(a2 + 12), v13);
    if ( v12 )
    {
      if ( !_InterlockedExchangeAdd(v12, 0xFFFFFFFF) )
        vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v14 = *(_DWORD *)(a2 + 8);
  if ( v14 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14 + 8))(*(_DWORD *)(a2 + 8));
    *(_DWORD *)(a2 + 8) = 0;
  }
  v15 = *(_DWORD *)(a2 + 12);
  if ( v15 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v15 + 8))(*(_DWORD *)(a2 + 12));
    *(_DWORD *)(a2 + 12) = 0;
  }
}

void __userpurge vostok::render::backend::clear_render_targets(
        vostok::render::backend *this@<ecx>,
        int a2@<eax>,
        int a3@<xmm0>,
        float g,
        float b,
        float a)
{
  ID3D11RenderTargetView **v6; // esi
  int v7; // edi
  _DWORD v8[4]; // [esp+0h] [ebp-10h] BYREF

  if ( s_debug_enabled_rt_clearing_value )
  {
    v8[0] = a3;
    *(float *)&v8[1] = g;
    *(float *)&v8[2] = b;
    *(float *)&v8[3] = a;
    v6 = (ID3D11RenderTargetView **)(a2 + 7368);
    v7 = 4;
    do
    {
      if ( *v6 )
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->ClearRenderTargetView(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          *v6,
          (const float *)v8);
      ++v6;
      --v7;
    }
    while ( v7 );
  }
}


void __userpurge vostok::render::backend::clear_render_targets(
        vostok::render::backend *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::math::color color0,
        vostok::math::color color1,
        vostok::math::color color2,
        vostok::math::color color3)
{
  ID3D11RenderTargetView *v7; // edi
  ID3D11RenderTargetView *v8; // edi
  ID3D11RenderTargetView *v9; // edi
  ID3D11RenderTargetView *v10; // esi
  float v11; // [esp+4h] [ebp-10h] BYREF
  float v12; // [esp+8h] [ebp-Ch] BYREF
  float v13; // [esp+Ch] [ebp-8h] BYREF
  float v14; // [esp+10h] [ebp-4h] BYREF

  if ( s_debug_enabled_rt_clearing_value )
  {
    v7 = (ID3D11RenderTargetView *)a2[1842];
    if ( v7 )
    {
      vostok::math::color::get_RGBA((vostok::math::color *)this, (unsigned __int8 *)&color0, &v11, &v12, &v13, &v14);
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context->ClearRenderTargetView(
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
        v7,
        &v11);
    }
    v8 = (ID3D11RenderTargetView *)a2[1843];
    if ( v8 )
    {
      vostok::math::color::get_RGBA((vostok::math::color *)this, (unsigned __int8 *)&color1, &v11, &v12, &v13, &v14);
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context->ClearRenderTargetView(
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
        v8,
        &v11);
    }
    v9 = (ID3D11RenderTargetView *)a2[1844];
    if ( v9 )
    {
      vostok::math::color::get_RGBA((vostok::math::color *)this, (unsigned __int8 *)&color2, &v11, &v12, &v13, &v14);
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context->ClearRenderTargetView(
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
        v9,
        &v11);
    }
    v10 = (ID3D11RenderTargetView *)a2[1845];
    if ( v10 )
    {
      vostok::math::color::get_RGBA((vostok::math::color *)this, (unsigned __int8 *)&color3, &v11, &v12, &v13, &v14);
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context->ClearRenderTargetView(
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
        v10,
        &v11);
    }
  }
}


void __thiscall vostok::render::backend::clear_render_targets(
        vostok::render::backend *this,
        vostok::math::color color,
        unsigned __int8 a3)
{
  ID3D11RenderTargetView **v3; // esi
  int v4; // edi
  float v5; // [esp+0h] [ebp-10h] BYREF
  float v6; // [esp+4h] [ebp-Ch] BYREF
  float v7; // [esp+8h] [ebp-8h] BYREF
  float v8; // [esp+Ch] [ebp-4h] BYREF

  if ( s_debug_enabled_rt_clearing_value )
  {
    vostok::math::color::get_RGBA((vostok::math::color *)this, &a3, &v5, &v6, &v7, &v8);
    v3 = (ID3D11RenderTargetView **)(*(_DWORD *)&color + 7368);
    v4 = 4;
    do
    {
      if ( *v3 )
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->ClearRenderTargetView(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          *v3,
          &v5);
      ++v3;
      --v4;
    }
    while ( v4 );
  }
}

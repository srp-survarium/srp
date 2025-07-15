void __thiscall vostok::render::render_model_instance_impl::get_all_surfaces(
        vostok::render::render_model_instance_impl *this,
        vostok::buffer_vector<vostok::render::render_surface_instance *> *out_surfaces,
        int a3)
{
  vostok::math::float4x4 *v3; // esi
  vostok::render::render_surface_instance **m_begin; // eax
  _DWORD v5[3]; // [esp+0h] [ebp-8Ch] BYREF
  _BYTE v6[64]; // [esp+Ch] [ebp-80h] BYREF
  vostok::math::float4x4 v7; // [esp+4Ch] [ebp-40h] BYREF

  memset(v5, 0, sizeof(v5));
  v3 = vostok::math::float4x4::identity((vostok::math::float4x4 *)this, &v7);
  m_begin = out_surfaces->m_begin;
  qmemcpy(v6, v3, sizeof(v6));
  ((void (__thiscall *)(vostok::buffer_vector<vostok::render::render_surface_instance *> *, _BYTE *, _DWORD *, int, _DWORD, int, int))m_begin[19])(
    out_surfaces,
    v6,
    v5,
    a3,
    0,
    170,
    3);
}

vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__userpurge vostok::render::surfaces_cache::get_tex@<eax>(
        vostok::render::surfaces_cache *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *result,
        unsigned int width,
        const D3D11_SUBRESOURCE_DATA *height,
        vostok::render::res_texture *format,
        const unsigned int usage)
{
  vostok::timing::timer *p_m_cached_textures; // ecx
  int m_current_time_high; // eax
  vostok::timing::timer *v8; // edx
  vostok::render::resource_manager *v9; // ecx
  vostok::render::res_texture *texture2d; // eax
  float *v11; // esi
  vostok::timing::timer *v12; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v13; // esi
  vostok::render::resource_manager *v14; // ecx
  vostok::render::res_texture *v15; // eax
  LARGE_INTEGER v18[3]; // [esp+10h] [ebp-20h] BYREF
  unsigned __int64 v19; // [esp+28h] [ebp-8h]

  LOWORD(v19) = width;
  WORD1(v19) = (_WORD)height;
  WORD2(v19) = (_WORD)format;
  p_m_cached_textures = (vostok::timing::timer *)&this->m_cached_textures;
  HIWORD(v19) = 3;
  m_current_time_high = HIDWORD(p_m_cached_textures->m_current_time);
  v8 = p_m_cached_textures;
  if ( m_current_time_high )
  {
    do
    {
      if ( *(_QWORD *)(m_current_time_high + 16) < v19 )
      {
        m_current_time_high = *(_DWORD *)(m_current_time_high + 12);
      }
      else
      {
        v8 = (vostok::timing::timer *)m_current_time_high;
        m_current_time_high = *(_DWORD *)(m_current_time_high + 8);
      }
    }
    while ( m_current_time_high );
    if ( v8 == p_m_cached_textures )
      goto LABEL_10;
    if ( v19 < *(_QWORD *)&v8->m_time_factor )
      v8 = p_m_cached_textures;
  }
  if ( v8 != p_m_cached_textures )
  {
    v13 = result;
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      result,
      (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v8[1]);
    return v13;
  }
LABEL_10:
  vostok::timing::timer::timer(p_m_cached_textures, v18);
  v18[1] = vostok::timing::get_QPC();
  v18[0].QuadPart = 0;
  texture2d = vostok::render::resource_manager::create_texture2d(
                v9,
                (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                0,
                width,
                height,
                0,
                (DXGI_FORMAT)format,
                D3D11_USAGE_STAGING,
                1u,
                0);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&format,
    texture2d);
  v11 = (float *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7396);
  *v11 = vostok::timing::timer::get_elapsed_sec(v12, (int)v18) + *v11;
  v13 = result;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    result,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&format);
  v15 = format;
  if ( format )
  {
    if ( format->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        v14,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v15);
  }
  return v13;
}

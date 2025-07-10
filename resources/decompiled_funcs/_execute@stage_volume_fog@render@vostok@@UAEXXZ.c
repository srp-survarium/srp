void __thiscall vostok::render::stage_volume_fog::execute(vostok::render::stage_volume_fog *this)
{
  const vostok::math::float4x4 *v2; // eax
  const char *m_conflicted_key_name; // esi
  vostok::render::backend *v4; // ecx
  int v5; // eax
  bool v6; // zf
  vostok::math::float4x4 result; // [esp+E8h] [ebp-40h] BYREF

  if ( this->m_exponential_volume_fog_effect.m_object && this->m_simple_fog_effect.m_object )
  {
    if ( this->is_enabled(this) )
    {
      vostok::render::scene::select_volume_fog_instances(
        (vostok::render::scene *)&this->m_context->m_vp,
        (const vostok::math::float4x4 *)this->m_context->m_scene,
        (vostok::render::vector<vostok::render::volume_fog_parameters> *)&this->m_context->m_vp);
      v2 = vostok::math::float4x4::identity(&result);
      vostok::render::renderer_context::set_w(this->m_context, v2);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::reset_render_targets(
        v4,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      v5 = *((_DWORD *)m_conflicted_key_name + 547);
      v6 = *((_DWORD *)m_conflicted_key_name + 539) == v5;
      *((_DWORD *)m_conflicted_key_name + 539) = v5;
      *((_BYTE *)m_conflicted_key_name + 167) |= !v6;
    }
    else
    {
      this->execute_disabled(this);
    }
  }
}

void __userpurge vostok::render::stage_screen_image::execute(
        vostok::render::stage_screen_image *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> t_image)
{
  vostok::render::backend *v4; // ecx
  vostok::render::backend *m_conflicted_key_name; // esi
  int v6; // eax
  vostok::render::backend *v7; // ecx
  _DWORD *v8; // eax
  int v9; // ecx
  const vostok::render::res_texture **v10; // eax
  vostok::render::res_texture *m_object; // ecx
  const vostok::render::res_texture *v12; // esi
  bool v13; // zf
  const char *v14; // esi
  int v15; // edi
  const char *v16; // eax
  unsigned __int64 *v17; // eax
  unsigned int v18; // xmm0_4
  survarium::game *m_game; // ecx
  unsigned __int64 v20; // xmm2_8
  const char *v21; // eax
  const char *v22; // edi
  bool v23; // al
  unsigned int base_offset; // [esp+18h] [ebp-14h] BYREF
  unsigned __int64 v25; // [esp+1Ch] [ebp-10h]
  unsigned __int64 v26; // [esp+24h] [ebp-8h]

  if ( a2[4] )
  {
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*a2 + 20))(a2) )
    {
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::reset_render_targets(
        v4,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      m_conflicted_key_name->m_dirty_targets.depth_stencil |= m_conflicted_key_name->m_zb != 0;
      m_conflicted_key_name->m_zb = 0;
      v6 = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(0.5), 0.5, 0.5);
      vostok::render::backend::clear_render_targets(v7, m_conflicted_key_name, (vostok::math::color)v6);
      v8 = (_DWORD *)a2[4];
      v9 = (v8[71] - v8[70]) >> 2;
      if ( v9 )
      {
        v8[69] = 0;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v9, (int)v8);
      }
      v10 = (const vostok::render::res_texture **)a2[7];
      m_object = 0;
      if ( t_image.m_object )
      {
        ++t_image.m_object->m_reference_count;
        m_object = t_image.m_object;
      }
      v12 = *v10;
      *v10 = m_object;
      if ( v12 )
      {
        v13 = v12->m_reference_count-- == 1;
        if ( v13 )
          vostok::render::res_texture::destroy_impl(m_object, v12);
      }
      v14 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v14 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                (vostok::render::textures_handler<0> *)m_object,
                                (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                              + 1488,
                                (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                t_image.m_object);
      v15 = a2[5];
      v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 533) == v15 )
      {
        *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 145) = 0;
      }
      else
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 533) = v15;
        *((_BYTE *)v16 + 144) = 1;
        *((_DWORD *)v16 + 534) = 0;
        *((_BYTE *)v16 + 145) = 1;
      }
      v17 = (unsigned __int64 *)vostok::render::vertex_buffer::lock(
                                  (vostok::render::vertex_buffer *)(v16 + 40),
                                  4u,
                                  0x10u,
                                  &base_offset);
      v18 = (unsigned int)clear_value;
      HIDWORD(v25) = clear_value;
      LODWORD(v25) = -1082130432;
      *v17 = v25;
      v17[1] = 0;
      LODWORD(v25) = v18;
      HIDWORD(v25) = v18;
      v17[2] = v25;
      m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
      LODWORD(v26) = 0;
      v17[4] = 0xBF800000BF800000uLL;
      HIDWORD(v26) = v18;
      v20 = v26;
      v17[3] = v18;
      v17[5] = v20;
      v25 = v18 | 0xBF80000000000000uLL;
      LODWORD(v26) = v18;
      HIDWORD(v26) = v18;
      v17[6] = v25;
      v17[7] = v26;
      v21 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 12) += *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 14) * *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 15);
      (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 60))(
        m_game->m_game_world.m_mouse_pos.y,
        *(_DWORD *)(*((_DWORD *)v21 + 10) + 4),
        0);
      v22 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::set_vb(
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
        *((vostok::render::untyped_buffer **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
        + 10),
        0x10u);
      v23 = *((_DWORD *)v22 + 529) != 5;
      *((_BYTE *)v22 + 162) = v23;
      if ( v23 )
        *((_DWORD *)v22 + 529) = 5;
      vostok::render::backend::flush((vostok::render::backend *)5, (int)v22);
      if ( v22[104] )
        ++*((_DWORD *)v22 + 25);
      (*(void (__stdcall **)(int, int, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 52))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        4,
        base_offset);
    }
    else
    {
      (*(void (__thiscall **)(_DWORD *))(*a2 + 8))(a2);
    }
  }
  if ( t_image.m_object )
  {
    v13 = t_image.m_object->m_reference_count-- == 1;
    if ( v13 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, t_image.m_object);
  }
}

void __userpurge vostok::render::batched_geometry<vostok::render::lpv_vertex>::for_each_batch_render(
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *this@<ecx>,
        int a2@<eax>,
        vostok::render::renderer_context *context,
        boost::function<void __cdecl(vostok::render::geometry_batch const &)> *pre_render_predicate,
        boost::function<void __cdecl(vostok::render::geometry_batch const &)> *post_render_predicate)
{
  const vostok::render::geometry_batch *v5; // edi
  int v6; // ebx
  vostok::math::cuboid *v7; // ecx
  boost::function1<void,vostok::collision::object const &> *v8; // ecx
  const char *m_conflicted_key_name; // edi
  unsigned int v10; // ebp
  const char *v11; // esi
  bool v12; // al
  boost::function1<void,vostok::collision::object const &> *v13; // ecx
  const vostok::render::geometry_batch *end; // [esp+14h] [ebp-7Ch]
  vostok::math::frustum view_frustum; // [esp+18h] [ebp-78h] BYREF

  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)(a2 + 4)) / 36 )
  {
    v5 = *(const vostok::render::geometry_batch **)(a2 + 8);
    v6 = *(_DWORD *)(a2 + 4);
    end = v5;
    vostok::math::frustum::frustum(&view_frustum, &context->m_vp);
    for ( ; (const vostok::render::geometry_batch *)v6 != v5; v6 += 36 )
    {
      if ( vostok::math::cuboid::test_inexact(v7, (const vostok::math::aabb *)v6) != intersection_outside )
      {
        vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(v6 + 28));
        boost::function1<void,vostok::collision::object const &>::operator()(
          v8,
          pre_render_predicate,
          (const vostok::collision::object *)v6);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v10 = *(_DWORD *)(v6 + 32);
        v11 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v12 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
        *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v12;
        if ( v12 )
          *((_DWORD *)m_conflicted_key_name + 529) = 4;
        vostok::render::backend::flush((vostok::render::backend *)4);
        if ( v11[104] )
        {
          ++*((_DWORD *)v11 + 25);
          v13 = 3 * s_max_triagles_per_dip_value < v10
              ? (boost::function1<void,vostok::collision::object const &> *)(3 * s_max_triagles_per_dip_value - v10)
              : 0;
          v10 += (unsigned int)v13;
        }
        if ( !v11[37] )
          (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
            `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
            v10,
            0,
            0);
        *((_DWORD *)v11 + 21) += v10 / 3;
        boost::function1<void,vostok::collision::object const &>::operator()(
          v13,
          post_render_predicate,
          (const vostok::collision::object *)v6);
        v5 = end;
      }
    }
  }
}

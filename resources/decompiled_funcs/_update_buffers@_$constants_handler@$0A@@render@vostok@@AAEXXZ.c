void __usercall vostok::render::constants_handler<0>::update_buffers(
        vostok::render::constants_handler<0> *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax
  int *v3; // ebp
  int *i; // edi
  int v5; // esi

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v3 = *(int **)(v2 + 20);
      for ( i = *(int **)(v2 + 16); i != v3; ++i )
      {
        v5 = *i;
        if ( *(_BYTE *)(*i + 100) )
        {
          if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 96) )
            (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                       + 192))(
              `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
              *(_DWORD *)(v5 + 96),
              0,
              0,
              *(_DWORD *)(v5 + 88),
              0,
              0);
          *(_BYTE *)(v5 + 100) = 0;
        }
      }
    }
  }
}

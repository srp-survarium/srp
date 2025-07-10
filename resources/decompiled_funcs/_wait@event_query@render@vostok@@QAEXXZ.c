void __thiscall vostok::render::event_query::wait(
        vostok::render::event_query *this,
        unsigned int is_rendering_finished)
{
  ID3D11Query **v2; // ebx
  unsigned int v3; // [esp+0h] [ebp-Ch]
  bool v4; // [esp+4h] [ebp-8h]

  v2 = (ID3D11Query **)is_rendering_finished;
  is_rendering_finished = 0;
  while ( vostok::render::device::get_query_data(
            (vostok::render::device *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game,
            *v2,
            &is_rendering_finished,
            v3,
            v4)
       && !is_rendering_finished )
    ;
}

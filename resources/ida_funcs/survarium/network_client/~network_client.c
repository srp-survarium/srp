void __thiscall survarium::network_client::~network_client(survarium::network_client *this)
{
  survarium::game *m_game; // eax
  survarium::flash_text_manager *m_text_manager; // esi
  vostok::resources::unmanaged_resource *v4; // ebx
  survarium::stats_row *v5; // ecx
  survarium::stats_row *v6; // ecx
  survarium::stats_row *v7; // ecx
  survarium::stats_row *v8; // ecx
  boost::array<survarium::player_desc,20> *v9; // ecx
  survarium::player *m_object; // eax
  survarium::player *v11; // eax
  survarium::messaging_client *v12; // ecx
  survarium::lobby_client *v13; // ecx

  m_game = this->m_game;
  this->__vftable = (survarium::network_client_vtbl *)&survarium::network_client::`vftable';
  m_text_manager = m_game->m_game_world.m_text_manager;
  v4 = 0;
  if ( m_text_manager )
  {
    Scaleform::RefCountNTSImpl::Release(this->m_unacknowledged_packets_value.text_impl);
    this->m_unacknowledged_packets_value.text_impl = 0;
    this->m_unacknowledged_packets_value.owner = 0;
    this->m_unacknowledged_packets_value.visible = 0;
    m_text_manager->need_capture = 1;
    Scaleform::RefCountNTSImpl::Release(this->m_unacknowledged_packets_caption.text_impl);
    this->m_unacknowledged_packets_caption.text_impl = 0;
    this->m_unacknowledged_packets_caption.owner = 0;
    this->m_unacknowledged_packets_caption.visible = 0;
    m_text_manager->need_capture = 1;
    Scaleform::RefCountNTSImpl::Release(this->m_max_local_sequence_difference_value.text_impl);
    this->m_max_local_sequence_difference_value.text_impl = 0;
    this->m_max_local_sequence_difference_value.owner = 0;
    this->m_max_local_sequence_difference_value.visible = 0;
    m_text_manager->need_capture = 1;
    Scaleform::RefCountNTSImpl::Release(this->m_max_local_sequence_difference_caption.text_impl);
    this->m_max_local_sequence_difference_caption.text_impl = 0;
    this->m_max_local_sequence_difference_caption.owner = 0;
    this->m_max_local_sequence_difference_caption.visible = 0;
    m_text_manager->need_capture = 1;
  }
  survarium::stats_row::~stats_row(&this->m_received_duplicated);
  survarium::stats_row::~stats_row(v5);
  survarium::stats_row::~stats_row(v6);
  survarium::stats_row::~stats_row(&this->m_resent);
  survarium::stats_row::~stats_row(v7);
  survarium::stats_row::~stats_row(v8);
  m_object = this->m_local_player.m_object;
  if ( m_object )
  {
    v9 = (boost::array<survarium::player_desc,20> *)_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v9 )
    {
      v11 = this->m_local_player.m_object;
      if ( v11 )
        v4 = &v11->vostok::resources::unmanaged_resource;
      vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v4);
    }
  }
  boost::array<survarium::player_desc,20>::~array<survarium::player_desc,20>(v9, (int)&this->m_net_players);
  this->m_player_inputs.m_end = this->m_player_inputs.m_begin;
  vostok::network::http_client::~http_client(&this->m_http_client);
  survarium::messaging_client::~messaging_client(v12);
  vostok::network::match_client::~match_client(&this->m_match_client.m_client);
  survarium::lobby_client::~lobby_client(v13, (int)this->m_lobby_client.account_nickname_);
  vostok::network::login_client::~login_client(&this->m_login_client);
  survarium::base_network_client::~base_network_client(this);
}

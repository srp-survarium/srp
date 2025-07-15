void __thiscall survarium::match_client::disconnect(survarium::match_client *this)
{
  vostok::network::match_client::disconnect(&this->m_client, (int)&this->m_client);
}

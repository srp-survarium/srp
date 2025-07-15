// attributes: thunk
void __thiscall survarium::match_client::~match_client(survarium::match_client *this)
{
  vostok::network::match_client::~match_client(&this->m_client);
}

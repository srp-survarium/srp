survarium::match_client *__thiscall survarium::match_client::`vector deleting destructor'(
        survarium::match_client *this,
        char a2)
{
  vostok::network::match_client::~match_client((vostok::network::match_client *)this, (int)&this->m_client);
  survarium::base_match_client::~base_match_client(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

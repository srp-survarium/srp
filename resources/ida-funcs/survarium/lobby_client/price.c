const survarium::faction_price *__usercall survarium::lobby_client::price@<eax>(
        survarium::lobby_client *this@<ecx>,
        const unsigned __int8 faction_id@<al>)
{
  return &this->m_prices[faction_id];
}

void __usercall survarium::shop_item::deserialize(
        survarium::shop_item *this@<ecx>,
        vostok::network_core::buffer_reader *reader@<eax>)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v3; // esi
  const unsigned __int8 *v4; // esi
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // esi
  unsigned int v9; // [esp+8h] [ebp-8h]
  unsigned int v10; // [esp+8h] [ebp-8h]
  unsigned int v11; // [esp+8h] [ebp-8h]
  unsigned int v12; // [esp+8h] [ebp-8h]
  unsigned int v13; // [esp+8h] [ebp-8h]
  unsigned int v14; // [esp+8h] [ebp-8h]
  unsigned __int8 v15; // [esp+Fh] [ebp-1h]
  unsigned __int8 v16; // [esp+Fh] [ebp-1h]

  m_pointer = reader->m_pointer;
  v9 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->id = v9;
  v3 = reader->m_pointer;
  v10 = *(_DWORD *)v3;
  reader->m_pointer = v3 + 4;
  this->base_cost = v10;
  v4 = reader->m_pointer;
  v11 = *(_DWORD *)v4;
  reader->m_pointer = v4 + 4;
  this->amount = v11;
  v5 = reader->m_pointer;
  v12 = *(_DWORD *)v5;
  reader->m_pointer = v5 + 4;
  this->base_amount = v12;
  v6 = reader->m_pointer;
  v13 = *(_DWORD *)v6;
  reader->m_pointer = v6 + 4;
  this->ttl = v13;
  v7 = reader->m_pointer;
  v14 = *(_DWORD *)v7;
  reader->m_pointer = v7 + 4;
  this->base_ttl = v14;
  v8 = reader->m_pointer;
  v15 = *v8;
  reader->m_pointer = v8 + 1;
  this->ttl_type = v15;
  v16 = *reader->m_pointer++;
  this->item_type = v16;
}

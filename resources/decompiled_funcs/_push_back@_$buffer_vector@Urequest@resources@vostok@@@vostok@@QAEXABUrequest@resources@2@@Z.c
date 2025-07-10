void __fastcall vostok::buffer_vector<vostok::resources::request>::push_back(
        vostok::buffer_vector<vostok::resources::request> *this,
        const vostok::resources::request *value)
{
  vostok::resources::request *m_end; // eax

  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}

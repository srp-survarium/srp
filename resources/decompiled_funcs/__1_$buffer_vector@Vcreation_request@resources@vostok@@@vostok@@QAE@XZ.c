void __thiscall vostok::buffer_vector<vostok::resources::creation_request>::~buffer_vector<vostok::resources::creation_request>(
        vostok::buffer_vector<vostok::resources::creation_request> *this)
{
  vostok::resources::creation_request *i; // [esp+4h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = this->m_begin;
}

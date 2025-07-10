char __userpurge vostok::render::device::get_query_data@<al>(
        ID3D11Query *in_query@<edi>,
        void *in_out_data@<esi>,
        vostok::render::device *this,
        unsigned int in_data_size,
        bool in_wait)
{
  HRESULT i; // eax

  for ( i = this->m_context->GetData(this->m_context, in_query, in_out_data, 4u, 0);
        i == 1;
        i = this->m_context->GetData(this->m_context, in_query, in_out_data, 4u, 0) )
  {
    ;
  }
  if ( !i )
    return 1;
  if ( i == -2005270523 || i == -2005270521 || i == -2005270496 )
    this->m_device_removed = 1;
  return 0;
}

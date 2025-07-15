boost::asio::mutable_buffers_1 *__userpurge boost::asio::ssl::detail::engine::get_output@<eax>(
        const boost::asio::mutable_buffer *data@<eax>,
        _DWORD *a2@<edi>,
        boost::asio::ssl::detail::engine *this)
{
  int v4; // eax
  unsigned int size; // ecx
  void *v6; // esi

  v4 = BIO_read(this->ext_bio_, (char *)data->data_, data->size_);
  if ( v4 <= 0 )
    v4 = 0;
  size = data->size_;
  v6 = data->data_;
  if ( size < v4 )
    v4 = size;
  *a2 = v6;
  a2[1] = v4;
  return (boost::asio::mutable_buffers_1 *)a2;
}

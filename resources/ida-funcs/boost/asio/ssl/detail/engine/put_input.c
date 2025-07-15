boost::asio::const_buffer *__userpurge boost::asio::ssl::detail::engine::put_input@<eax>(
        const boost::asio::mutable_buffer *data@<esi>,
        _DWORD *a2@<edi>,
        boost::asio::ssl::detail::engine *this)
{
  signed int v3; // eax
  boost::asio::mutable_buffer *v4; // eax
  void *v5; // ecx
  boost::asio::mutable_buffer v7; // [esp+0h] [ebp-8h] BYREF

  v3 = BIO_write(this->ext_bio_, (const char *)data->data_, data->size_);
  if ( v3 <= 0 )
    v3 = 0;
  v4 = boost::asio::operator+(data, &v7, v3);
  v5 = v4->data_;
  a2[1] = v4->size_;
  *a2 = v5;
  return (boost::asio::const_buffer *)a2;
}

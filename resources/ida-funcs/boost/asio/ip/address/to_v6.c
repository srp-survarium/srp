boost::asio::ip::address_v6 *__userpurge boost::asio::ip::address::to_v6@<eax>(
        boost::asio::ip::address *this@<ecx>,
        _DWORD *a2@<eax>,
        boost::asio::ip::address_v6 *result)
{
  _DWORD *v4; // esi
  unsigned int v5; // eax
  std::bad_cast v7; // [esp+Ch] [ebp-Ch] BYREF

  if ( *a2 != 1 )
  {
    std::bad_cast::bad_cast(&v7, "bad cast");
    boost::throw_exception(&v7);
    std::bad_cast::~bad_cast(&v7);
  }
  v4 = a2 + 2;
  v5 = v4[4];
  *(_DWORD *)result->addr_.u.Byte = *v4++;
  *(_DWORD *)&result->addr_.u.Word[2] = *v4;
  *(_QWORD *)&result->addr_.u.Word[4] = *(_QWORD *)(v4 + 1);
  result->scope_id_ = v5;
  return result;
}

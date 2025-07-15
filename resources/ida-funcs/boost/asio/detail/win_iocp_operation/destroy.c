void __usercall boost::asio::detail::win_iocp_operation::destroy(
        boost::asio::detail::win_iocp_operation *this@<ecx>,
        int a2@<esi>)
{
  _DWORD v2[2]; // [esp+0h] [ebp-8h] BYREF

  v2[0] = 0;
  v2[1] = boost::system::system_category();
  (*(void (__cdecl **)(_DWORD, int, _DWORD *, _DWORD))(a2 + 24))(0, a2, v2, 0);
}

void __usercall boost::asio::detail::win_fenced_block::~win_fenced_block(
        boost::asio::detail::win_fenced_block *this@<ecx>,
        __int32 a2@<eax>)
{
  boost::asio::detail::win_fenced_block *v2; // [esp+0h] [ebp-4h] BYREF

  v2 = this;
  _InterlockedExchange((volatile __int32 *)&v2, a2);
}

void __usercall boost::asio::detail::win_fenced_block::~win_fenced_block(
        boost::asio::detail::win_fenced_block *this@<ecx>,
        __int32 a2@<eax>)
{
  int barrier; // [esp+4h] [ebp-4h] BYREF

  _InterlockedExchange(&barrier, a2);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}

void __cdecl stlp_std::_Copy_Construct<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>(
        stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *__p,
        const stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *__val)
{
  char *v2; // [esp+8h] [ebp-8h]

  v2 = (char *)operator new(0xCu, __p);
  if ( v2 )
  {
    *(_DWORD *)v2 = __val->first;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)(v2 + 4));
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
  }
}

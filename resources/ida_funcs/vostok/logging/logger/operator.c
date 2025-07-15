void __thiscall vostok::logging::logger::operator()(vostok::logging::logger *this, char *format, char *const args)
{
  unsigned int v3; // eax
  survarium::game_camera *v4; // ecx
  vostok::logging::logger *v5; // [esp+0h] [ebp-103Ch]
  vostok::logging::logger_predicate predicate; // [esp+Ch] [ebp-1030h] BYREF
  char destination[4100]; // [esp+14h] [ebp-1028h] BYREF
  vostok::logging::path_parts v8; // [esp+1018h] [ebp-24h] BYREF

  vostok::debug::disable_log_callback((vostok::debug *)this);
  vostok::vsnprintf(format, args, destination, 0x1000u, 0xFFFu);
  vostok::logging::path_parts::path_parts(&v8, v5->m_initiator);
  predicate.m_path = &v8;
  predicate.m_helper = v5;
  v3 = vostok::strings::length(destination);
  vostok::strings::iterate_items<vostok::logging::logger_predicate,char *>(destination, v3, &predicate, 10);
  survarium::weapon_user_dead_state::finalize(v4);
  vostok::logging::path_parts::~path_parts(&v8);
  vostok::debug::enable_log_callback((vostok::debug *)v5);
}

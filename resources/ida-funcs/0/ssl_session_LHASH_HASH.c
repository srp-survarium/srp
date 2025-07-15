int __cdecl ssl_session_LHASH_HASH(unsigned __int8 *arg)
{
  return arg[72] | ((arg[73] | (*((unsigned __int16 *)arg + 37) << 8)) << 8);
}

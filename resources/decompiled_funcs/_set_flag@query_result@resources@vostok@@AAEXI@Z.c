void __thiscall vostok::resources::query_result::set_flag(vostok::resources::query_result *this)
{
  unsigned int v2; // [esp+0h] [ebp-4h]

  vostok::threading::interlocked_or(&this->m_flags, v2);
}

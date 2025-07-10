void __thiscall vostok::buffer_vector<vostok::apc::callback>::resize(
        vostok::buffer_vector<vostok::apc::callback> *this)
{
  unsigned int v1; // eax
  bool v2; // cc
  unsigned int v3; // eax
  vostok::apc::callback *end; // [esp+0h] [ebp-4h] BYREF

  end = (vostok::apc::callback *)this;
  v1 = g_threads.m_end - g_threads.m_begin;
  v2 = v1 <= 0xB;
  if ( v1 != 11 )
  {
    v3 = v1;
    if ( v2 )
    {
      end = g_threads.m_begin + 11;
      vostok::buffer_vector<vostok::apc::callback>::construct(&g_threads.m_begin[v3], &end);
    }
    else
    {
      end = &g_threads.m_begin[v3];
      vostok::buffer_vector<vostok::apc::callback>::destroy(g_threads.m_begin + 11, &end);
    }
    g_threads.m_end = g_threads.m_begin + 11;
  }
}

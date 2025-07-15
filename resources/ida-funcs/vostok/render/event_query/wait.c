void __thiscall vostok::render::event_query::wait(vostok::render::event_query *this, ID3D11Query **a2)
{
  unsigned int v2; // [esp+0h] [ebp-Ch]
  bool v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h] BYREF

  v4 = 0;
  while ( vostok::render::device::get_query_data(
            (vostok::render::device *)this,
            (int)vostok::quasi_singleton<vostok::render::device>::pinst,
            *a2,
            &v4,
            v2,
            v3)
       && !v4 )
    ;
}

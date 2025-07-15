void __usercall vostok::render::event_query::event_query(vostok::render::event_query *this@<ecx>, _DWORD *a2@<esi>)
{
  ID3D11Query **v2; // [esp+0h] [ebp-Ch]
  _DWORD v3[2]; // [esp+4h] [ebp-8h] BYREF

  *a2 = 0;
  v3[1] = 0;
  v3[0] = 0;
  vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateQuery(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
    (const D3D11_QUERY_DESC *)v3,
    v2);
}

void __usercall survarium::messaging_client::~messaging_client(survarium::messaging_client *this@<ecx>, int a2@<eax>)
{
  char *v3; // eax
  vostok::vectora<survarium::account_list_item> *v4; // ecx
  vostok::vectora<survarium::account_list_item> *v5; // ecx
  vostok::network::tcp_packet_client *v6; // ecx
  const char *v7; // [esp+0h] [ebp-Ch]
  const char *v8; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  v3 = *(char **)(a2 + 404);
  if ( v3 )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      v3,
      v7,
      v8,
      v9);
  vostok::vectora<survarium::account_list_item>::~vectora<survarium::account_list_item>(
    (vostok::vectora<survarium::account_list_item> *)this,
    a2 + 384);
  vostok::vectora<survarium::account_list_item>::~vectora<survarium::account_list_item>(v4, a2 + 368);
  vostok::vectora<survarium::account_list_item>::~vectora<survarium::account_list_item>(v5, a2 + 352);
  vostok::network::tcp_packet_client::~tcp_packet_client(v6, a2 + 144);
}

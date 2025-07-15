void __thiscall vostok::network::match_client::create_responses_packets_allocator(vostok::network::match_client *this)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  vostok::network_core::udp_match_packets_allocator *v5; // ecx
  char *v6; // edi
  vostok::network_core::udp_match_packets_allocator *v7; // eax
  const char *v8; // [esp+0h] [ebp-Ch]
  const char *v9; // [esp+4h] [ebp-8h]
  unsigned int v10; // [esp+8h] [ebp-4h]

  v1 = vostok::network::g_allocator;
  v3 = type_info::raw_name(&vostok::network::udp_match_fixed_packets_allocator<4096> `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(
         v4,
         (int)v1,
         (unsigned int)Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,3,Scaleform::GFx::ASString>::Func,
         v3,
         v8,
         v9,
         v10);
  if ( v6 )
  {
    vostok::network_core::udp_match_packets_allocator::udp_match_packets_allocator(
      v5,
      (int)v6,
      vostok::network::g_allocator,
      (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *)(v6 + 64),
      (unsigned int)&loc_553FFC + 4);
    v7 = (vostok::network_core::udp_match_packets_allocator *)v6;
  }
  else
  {
    v7 = 0;
  }
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::operator=(
    &this->m_response_packets_allocator,
    v7,
    (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)v5);
}

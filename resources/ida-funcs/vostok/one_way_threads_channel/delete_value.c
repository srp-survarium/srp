void __usercall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>>::delete_value(
        vostok::sound::sound_order *value@<esi>)
{
  vostok::memory::base_allocator *allocator; // edi
  _BYTE *v2; // ebx

  allocator = value->allocator;
  v2 = __RTCastToVoid((void **)&value->__vftable);
  ((void (__thiscall *)(vostok::sound::sound_order *, _DWORD))value->~vostok::sound::sound_order)(value, 0);
  allocator->call_free(
    allocator,
    v2,
    "vostok::one_way_threads_channel<class vostok::intrusive_spsc_queue<struct vostok::sound::sound_order,struct vostok::"
    "sound::sound_order,8>,class vostok::intrusive_spsc_queue<struct vostok::sound::sound_order,struct vostok::sound::sou"
    "nd_order,8> >::delete_value",
    &stru_7F94B0.m_string.m_buffer[44],
    115u);
}


void __usercall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,8>>::delete_value(
        vostok::sound::sound_response *value@<esi>)
{
  vostok::memory::base_allocator *allocator; // edi
  _BYTE *v2; // ebx

  allocator = value->allocator;
  v2 = __RTCastToVoid((void **)&value->__vftable);
  ((void (__thiscall *)(vostok::sound::sound_response *, _DWORD))value->~vostok::sound::sound_response)(value, 0);
  allocator->call_free(
    allocator,
    v2,
    "vostok::one_way_threads_channel<class vostok::intrusive_spsc_queue<struct vostok::sound::sound_response,struct vosto"
    "k::sound::sound_response,8>,class vostok::intrusive_spsc_queue<struct vostok::sound::sound_response,struct vostok::s"
    "ound::sound_response,8> >::delete_value",
    &stru_7F94B0.m_string.m_buffer[44],
    115u);
}


void __usercall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>>::delete_value(
        vostok::network::order *value@<esi>)
{
  vostok::memory::base_allocator *allocator; // edi
  _BYTE *v2; // ebx

  allocator = value->allocator;
  v2 = __RTCastToVoid((void **)&value->__vftable);
  ((void (__thiscall *)(vostok::network::order *, _DWORD))value->~vostok::network::order)(value, 0);
  allocator->call_free(
    allocator,
    v2,
    "vostok::one_way_threads_channel<class vostok::intrusive_spsc_queue<class vostok::network::order,class vostok::networ"
    "k::order,8>,class vostok::intrusive_spsc_queue<class vostok::network::order,class vostok::network::order,8> >::delete_value",
    &stru_7F94B0.m_string.m_buffer[44],
    115u);
}


void __usercall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::delete_value(
        vostok::network::response *value@<esi>)
{
  vostok::memory::base_allocator *allocator; // edi
  _BYTE *v2; // ebx

  allocator = value->allocator;
  v2 = __RTCastToVoid((void **)&value->__vftable);
  ((void (__thiscall *)(vostok::network::response *, _DWORD))value->~vostok::network::response)(value, 0);
  allocator->call_free(
    allocator,
    v2,
    "vostok::one_way_threads_channel<class vostok::intrusive_spsc_queue<class vostok::network::response,class vostok::net"
    "work::response,8>,class vostok::intrusive_spsc_queue<class vostok::network::response,class vostok::network::response"
    ",8> >::delete_value",
    &stru_7F94B0.m_string.m_buffer[44],
    115u);
}

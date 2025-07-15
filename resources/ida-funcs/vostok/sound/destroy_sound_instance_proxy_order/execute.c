void __thiscall vostok::sound::destroy_sound_instance_proxy_order::execute(
        vostok::sound::destroy_sound_instance_proxy_order *this)
{
  vostok::sound::sound_instance_proxy_internal *m_proxy; // esi
  void **p_vtable; // edi
  _BYTE *v3; // ebx
  vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex> *v4; // ecx
  _DWORD *v5; // [esp+Ch] [ebp-4h] BYREF

  m_proxy = this->m_proxy;
  vostok::sound::sound_scene::stop_propagate_sound(m_proxy->m_scene, m_proxy);
  p_vtable = (void **)&m_proxy->m_scene->m_proxies_allocator.m_variable->m_on_out_of_memory.vtable;
  v3 = __RTCastToVoid((void **)&m_proxy->__vftable);
  ((void (__thiscall *)(vostok::sound::sound_instance_proxy_internal *, _DWORD))m_proxy->~vostok::sound::sound_instance_proxy_internal)(
    m_proxy,
    0);
  v5 = v3;
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::deallocate(
    v4,
    p_vtable,
    &v5);
}

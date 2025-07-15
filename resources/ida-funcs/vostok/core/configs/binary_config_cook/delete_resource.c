void __thiscall vostok::core::configs::binary_config_cook::delete_resource(
        vostok::core::configs::binary_config_cook *this,
        vostok::resources::resource_base *resource)
{
  unsigned int m_lock; // edi
  _BYTE *v3; // ebx

  m_lock = resource[1].m_parent_resources.m_lock;
  v3 = __RTCastToVoid((void **)&resource->__vftable);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  (*(void (__thiscall **)(unsigned int, _BYTE *, const char *, const char *, int))(*(_DWORD *)m_lock + 24))(
    m_lock,
    v3,
    "vostok::core::configs::binary_config_cook::delete_resource",
    ".\\configs_binary_config_cook.cpp",
    266);
}

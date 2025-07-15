signed __int32 __thiscall vostok::threading::interlocked_increment(vostok::resources::unmanaged_intrusive_base *object)
{
  return _InterlockedIncrement(&object->m_reference_count);
}

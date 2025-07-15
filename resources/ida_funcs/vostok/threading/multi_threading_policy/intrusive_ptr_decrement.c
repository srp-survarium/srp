signed __int32 __thiscall vostok::threading::multi_threading_policy::intrusive_ptr_decrement<vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::unmanaged_intrusive_base *object)
{
  return _InterlockedDecrement(&object->m_reference_count);
}

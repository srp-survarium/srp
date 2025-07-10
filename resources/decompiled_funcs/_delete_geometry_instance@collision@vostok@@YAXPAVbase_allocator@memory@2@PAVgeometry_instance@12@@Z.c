void __usercall vostok::collision::delete_geometry_instance(
        vostok::memory::base_allocator *allocator@<edi>,
        vostok::collision::geometry_instance *object@<esi>)
{
  _BYTE *v2; // ebx

  if ( object )
  {
    object->destroy(object, allocator);
    v2 = __RTCastToVoid((void **)&object->__vftable);
    ((void (__thiscall *)(vostok::collision::geometry_instance *, _DWORD))object->~vostok::collision::geometry_instance)(
      object,
      0);
    allocator->call_free(allocator, v2);
  }
}

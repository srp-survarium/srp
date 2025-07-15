void __usercall vostok::collision::delete_object(
        vostok::memory::base_allocator *allocator@<edi>,
        vostok::collision::object *object@<esi>)
{
  _BYTE *v2; // ebx

  if ( object )
  {
    v2 = __RTCastToVoid((void **)&object->__vftable);
    ((void (__thiscall *)(vostok::collision::object *, _DWORD))object->~vostok::collision::object)(object, 0);
    allocator->call_free(allocator, v2, "vostok::collision::delete_object", ".\\api.cpp", 265u);
  }
}

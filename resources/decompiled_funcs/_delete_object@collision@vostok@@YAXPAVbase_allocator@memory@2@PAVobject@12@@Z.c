void __cdecl vostok::collision::delete_object(
        vostok::memory::base_allocator *allocator,
        vostok::collision::object *object)
{
  _BYTE *v2; // edi

  if ( object )
  {
    v2 = __RTCastToVoid((void **)&object->__vftable);
    ((void (__thiscall *)(vostok::collision::object *, _DWORD))object->~vostok::collision::object)(object, 0);
    allocator->call_free(allocator, v2);
  }
}

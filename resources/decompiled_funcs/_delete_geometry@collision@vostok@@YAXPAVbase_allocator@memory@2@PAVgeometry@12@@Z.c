void __usercall vostok::collision::delete_geometry(
        vostok::memory::base_allocator *allocator@<edi>,
        vostok::collision::geometry *geometry@<esi>)
{
  _BYTE *v2; // ebx

  if ( allocator )
  {
    if ( geometry )
    {
      geometry->destroy(geometry, allocator);
      v2 = __RTCastToVoid((void **)&geometry->__vftable);
      ((void (__thiscall *)(vostok::collision::geometry *, _DWORD))geometry->~vostok::resources::resource_base)(
        geometry,
        0);
      allocator->call_free(allocator, v2);
    }
  }
}

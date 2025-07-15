void __thiscall survarium::scaleform_movie_cook::delete_resource(
        survarium::scaleform_movie_cook *this,
        vostok::resources::resource_base *resource)
{
  int f; // ebp
  _BYTE *v3; // edi
  void *v4; // esi
  vostok::resources::resource_link *m_last; // [esp-4h] [ebp-10h]

  m_last = resource[1].m_children_resources.m_last;
  m_last->resource = 0;
  m_last->next_link = 0;
  m_last->quality_value = 0;
  operator delete(m_last);
  f = (int)survarium::g_allocator.f_.f_;
  v3 = __RTCastToVoid((void **)&resource->__vftable);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  if ( v3 )
  {
    v4 = *(void **)(f + 20);
    *(_BYTE *)(f + 42) = 0;
    vostok_mspace_free(v4, v3);
  }
}

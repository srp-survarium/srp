void __thiscall vostok::render::scene::remove_decal(vostok::render::scene *this, unsigned int id)
{
  vostok::render::decal_instance_node *i; // edi
  vostok::render::decal_instance **p_m_object; // ebx
  const char *v5; // esi
  char *v6; // edi
  vostok::memory::doug_lea_allocator *v7; // ecx
  vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // [esp-4h] [ebp-14h]
  const char *v9; // [esp+0h] [ebp-10h]
  const char *v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]

  for ( i = *(vostok::render::decal_instance_node **)((char *)&dword_8B654C + (_DWORD)this); i; i = i->next )
  {
    if ( i->decal.m_object->m_id == id )
    {
      p_m_object = &i->decal.m_object;
      vostok::render::scene::remove_streamable_texture_instance(this, (int)this, i->decal.m_object);
      i->remove(i);
      vostok::intrusive_list<vostok::render::decal_instance_node,vostok::render::decal_instance_node *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        (vostok::intrusive_list<vostok::render::decal_instance_node,vostok::render::decal_instance_node *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)&dword_8B6544 + (_DWORD)this),
        i);
      v5 = (const char *)vostok::render::g_allocator;
      v6 = __RTCastToVoid((void **)&i->__vftable);
      vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        v8,
        p_m_object,
        v6,
        v5);
      vostok::memory::doug_lea_allocator::free_impl(v7, (int)v5, v6, v9, v10, v11);
      return;
    }
  }
}

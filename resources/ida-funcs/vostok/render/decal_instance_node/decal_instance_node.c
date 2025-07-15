void __userpurge vostok::render::decal_instance_node::decal_instance_node(
        vostok::render::decal_instance_node *this@<ecx>,
        vostok::render::decal_instance **a2@<edi>,
        vostok::render::decal_instance *in_decal)
{
  char *v3; // esi

  v3 = (char *)(a2 + 1);
  *a2 = (vostok::render::decal_instance *)&vostok::render::decal_instance_node::`vftable';
  a2[1] = 0;
  if ( in_decal )
  {
    vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
      (vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)this,
      a2 + 1,
      (const char *)a2,
      v3);
    *(_DWORD *)v3 = in_decal;
    ++in_decal->m_reference_count;
  }
  a2[2] = 0;
}

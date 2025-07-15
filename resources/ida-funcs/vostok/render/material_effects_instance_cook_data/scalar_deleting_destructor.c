vostok::resources::unmanaged_resource **__userpurge vostok::render::material_effects_instance_cook_data::`scalar deleting destructor'@<eax>(
        vostok::render::material_effects_instance_cook_data *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>,
        char a3)
{
  vostok::resources::unmanaged_resource *v3; // eax

  v3 = a2[1];
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&a2[1]->vostok::resources::unmanaged_intrusive_base, a2[1]);
  if ( (a3 & 1) != 0 )
    operator delete(a2);
  return a2;
}

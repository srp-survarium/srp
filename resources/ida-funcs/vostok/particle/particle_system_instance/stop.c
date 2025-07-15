void __usercall vostok::particle::particle_system_instance::stop(
        vostok::particle::particle_system_instance *this@<ecx>,
        survarium::pure_game_effect_emitter_base *a2@<eax>)
{
  vostok::resources::resource_link **p_m_last; // ebx
  vostok::resources::resource_base *resource; // ebp
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v4; // [esp-4h] [ebp-18h] BYREF
  float v5; // [esp+0h] [ebp-14h]

  v4.m_object = (survarium::pure_game_effect_emitter_base *)this;
  p_m_last = &a2[2].m_children_resources.m_last;
  v5 = 0.0;
  resource = a2[2].m_children_resources.m_last->resource;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v4,
    a2);
  ((void (__thiscall *)(vostok::resources::resource_link *, survarium::pure_game_effect_emitter_base *, float))resource->m_children_resources.m_last)(
    *p_m_last,
    v4.m_object,
    COERCE_FLOAT(LODWORD(v5)));
}

void __userpurge vostok::resources::queries_result::on_child_query_end(
        vostok::resources::query_result *child@<eax>,
        vostok::resources::queries_result *this,
        bool result)
{
  vostok::resources::queries_result *v3; // ebx
  signed __int32 v4; // esi
  vostok::resources::queries_result *v5; // ecx
  int v6; // eax
  vostok::resources::queries_result *v7; // ecx
  char v8; // al
  vostok::resources::queries_result *v9; // ecx

  v3 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&child->m_unmanaged_resource);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  v4 = _InterlockedIncrement(&v3->m_children_ended);
  v6 = vostok::resources::queries_result::calculate_fs_iterator_requests_count(v5, (int)v3);
  v7 = (vostok::resources::queries_result *)(v3->m_size - v6);
  if ( (vostok::resources::queries_result *)v4 == v7 )
  {
    if ( v6 )
    {
      vostok::resources::queries_result::query_fs_iterators(v7, v3);
    }
    else
    {
      v8 = vostok::resources::queries_result::calculate_result_from_children(v7, (int)v3);
      vostok::resources::queries_result::on_query_end(v9, v8);
    }
  }
}

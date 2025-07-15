void __usercall stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_DWORD *)a2 )
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, const char *, int))(**(_DWORD **)(a2 + 8) + 24))(
      *(_DWORD *)(a2 + 8),
      *(_DWORD *)a2,
      "vostok::detail::std_allocator<void const *>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102);
}


void __usercall stlp_std::priv::_Impl_vector<survarium::game_world::bullet_tracer,survarium::std_allocator<survarium::game_world::bullet_tracer>>::~_Impl_vector<survarium::game_world::bullet_tracer,survarium::std_allocator<survarium::game_world::bullet_tracer>>(
        stlp_std::priv::_Impl_vector<survarium::game_world::bullet_tracer,survarium::std_allocator<survarium::game_world::bullet_tracer> > *this@<ecx>,
        char **a2@<eax>)
{
  char *v3; // ebx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // esi
  char *v5; // edi
  const char *v6; // [esp+0h] [ebp-Ch]
  const char *v7; // [esp+4h] [ebp-8h]
  unsigned int v8; // [esp+8h] [ebp-4h]

  v3 = *a2;
  for ( i = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2[1];
        i != (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3;
        i -= 2 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i - 1);
  }
  v5 = *a2;
  if ( v5 )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      v5,
      v6,
      v7,
      v8);
}


void __usercall stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::~_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>(
        stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *this@<ecx>,
        stlp_std::reverse_iterator<survarium::scheduler::record *> *a2@<esi>)
{
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<survarium::scheduler::record *>,survarium::scheduler::record>(
    a2[1],
    (stlp_std::reverse_iterator<survarium::scheduler::record *>)a2->current);
  if ( a2->current )
    ((void (__thiscall *)(survarium::scheduler::record *, survarium::scheduler::record *, const char *, const char *, int))a2[2].current->m_id[6])(
      a2[2].current,
      a2->current,
      "vostok::detail::std_allocator<struct survarium::scheduler::record>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102);
}


void __usercall stlp_std::priv::_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers>>::~_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers>>(
        stlp_std::priv::_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers> > *this@<ecx>,
        stlp_std::reverse_iterator<vostok::ui::typed_handlers *> *a2@<esi>)
{
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::ui::typed_handlers *>,vostok::ui::typed_handlers>(
    a2[1],
    (stlp_std::reverse_iterator<vostok::ui::typed_handlers *>)a2->current);
  if ( a2->current )
    (*(void (__thiscall **)(vostok::ui::typed_handlers *, vostok::ui::typed_handlers *, const char *, const char *, int))(a2[2].current->type + 24))(
      a2[2].current,
      a2->current,
      "vostok::detail::std_allocator<struct vostok::ui::typed_handlers>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102);
}

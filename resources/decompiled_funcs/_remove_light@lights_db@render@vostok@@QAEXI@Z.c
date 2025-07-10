void __thiscall vostok::render::lights_db::remove_light(
        vostok::render::lights_db *this,
        vostok::render::lights_db *id,
        unsigned int ida)
{
  vostok::render::light_data *v3; // esi
  vostok::render::light *flags; // ecx
  stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data> > *v5; // ecx
  const stlp_std::__false_type *v6; // [esp+0h] [ebp-Ch]

  v3 = stlp_std::priv::__find<vostok::render::light_data *,unsigned int>(
         id->m_lights._M_impl._M_start,
         id->m_lights._M_impl._M_finish,
         &ida);
  flags = (vostok::render::light *)v3->light.m_object->flags;
  LOBYTE(flags) = (unsigned __int8)flags & 0xF;
  if ( (_BYTE)flags == 4 )
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      &id->m_sun);
  vostok::render::light::remove_collision(flags, v3->light.m_object);
  stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data>>::_M_erase(
    v5,
    (int)id,
    v3,
    v6);
}

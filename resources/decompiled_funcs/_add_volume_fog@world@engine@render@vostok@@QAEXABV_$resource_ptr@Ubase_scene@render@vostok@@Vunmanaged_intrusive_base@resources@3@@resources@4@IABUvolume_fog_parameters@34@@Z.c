void __thiscall vostok::render::engine::world::add_volume_fog(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        unsigned int id,
        const vostok::render::volume_fog_parameters *in_parameters)
{
  vostok::render::base_scene *m_object; // esi
  associative_vector<unsigned int,vostok::render::volume_fog_parameters,vostok::render::vector,stlp_std::less<unsigned int> > *v5; // ecx
  stlp_std::pair<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,bool> result; // [esp+8h] [ebp-80h] BYREF
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> value; // [esp+10h] [ebp-78h] BYREF

  m_object = in_scene->m_object;
  value.first = id;
  vostok::render::volume_fog_parameters::volume_fog_parameters(&value.second, in_parameters);
  associative_vector<unsigned int,vostok::render::volume_fog_parameters,vostok::render::vector,stlp_std::less<unsigned int>>::insert(
    v5,
    (stlp_std::priv::_Impl_vector<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)&m_object[1].m_children_resources,
    &result,
    &value);
}

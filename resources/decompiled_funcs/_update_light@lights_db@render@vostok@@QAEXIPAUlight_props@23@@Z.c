void __userpurge vostok::render::lights_db::update_light(
        vostok::render::lights_db *this@<ecx>,
        vostok::render::light_data **a2@<eax>,
        unsigned int id,
        vostok::render::light_props *props)
{
  vostok::render::light_data *v4; // eax

  v4 = stlp_std::priv::__lower_bound<vostok::render::light_data *,unsigned int,stlp_std::priv::__less_2<vostok::render::light_data,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::render::light_data>,int>(
         a2[1],
         &id,
         *a2);
  vostok::render::fill_light(v4->light.m_object, props);
}

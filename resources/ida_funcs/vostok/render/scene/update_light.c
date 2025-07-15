void __userpurge vostok::render::scene::update_light(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        vostok::render::light_props *id,
        vostok::render::light_props *props)
{
  vostok::render::light_data **v4; // eax
  vostok::render::light_data *v5; // edx
  vostok::render::light_data *v6; // eax
  vostok::render::light_data *v7; // eax
  unsigned int __val; // [esp+Ch] [ebp-4h] BYREF

  v4 = *(vostok::render::light_data ***)(a2 + 944);
  v5 = v4[1];
  v6 = *v4;
  __val = (unsigned int)this;
  v7 = stlp_std::priv::__lower_bound<vostok::render::light_data *,unsigned int,stlp_std::priv::__less_2<vostok::render::light_data,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::render::light_data>,int>(
         v5,
         &__val,
         v6);
  vostok::render::fill_light(v7->light.m_object, id);
}

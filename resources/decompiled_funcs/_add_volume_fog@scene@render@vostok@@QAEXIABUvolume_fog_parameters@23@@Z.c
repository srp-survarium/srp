void __userpurge vostok::render::scene::add_volume_fog(
        unsigned int id@<eax>,
        const vostok::render::volume_fog_parameters *in_parameters@<edx>,
        vostok::render::scene *this)
{
  stlp_std::pair<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,bool> result; // [esp+0h] [ebp-80h] BYREF
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> value; // [esp+8h] [ebp-78h] BYREF

  value.first = id;
  vostok::render::volume_fog_parameters::volume_fog_parameters(&value.second, in_parameters);
  associative_vector<unsigned int,vostok::render::volume_fog_parameters,vostok::render::vector,stlp_std::less<unsigned int>>::insert(
    (associative_vector<unsigned int,vostok::render::volume_fog_parameters,vostok::render::vector,stlp_std::less<unsigned int> > *)&value,
    &this->m_volume_fogs._M_impl,
    &result,
    &value);
}

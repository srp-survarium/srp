void __userpurge vostok::render::scene::update_volume_fog(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        unsigned int id,
        const vostok::render::volume_fog_parameters *in_parameters)
{
  stlp_std::priv::_Impl_vector<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v5; // edi
  _BYTE *v6; // eax
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *M_finish; // ebx
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *v8; // eax
  stlp_std::pair<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,bool> __comp1; // [esp+10h] [ebp-80h] BYREF
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> value; // [esp+18h] [ebp-78h] BYREF

  v5 = (stlp_std::priv::_Impl_vector<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)(a2 + 316);
  if ( a2 == -316 )
    v6 = 0;
  else
    v6 = (_BYTE *)(a2 + 329);
  M_finish = v5->_M_finish;
  LOBYTE(__comp1.first) = *v6;
  v8 = stlp_std::priv::__lower_bound<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,unsigned int,associative_vector_compare_predicate<unsigned int,vostok::render::volume_fog_parameters,stlp_std::less<unsigned int>>,associative_vector_compare_predicate<unsigned int,vostok::render::volume_fog_parameters,stlp_std::less<unsigned int>>,int>(
         v5->_M_start,
         M_finish,
         &id);
  if ( v8 == M_finish || id < v8->first )
    v8 = M_finish;
  if ( v8 == *(stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> **)(a2 + 320) )
  {
    value.first = id;
    vostok::render::volume_fog_parameters::volume_fog_parameters(&value.second, in_parameters);
    associative_vector<unsigned int,vostok::render::volume_fog_parameters,vostok::render::vector,stlp_std::less<unsigned int>>::insert(
      (associative_vector<unsigned int,vostok::render::volume_fog_parameters,vostok::render::vector,stlp_std::less<unsigned int> > *)&__comp1,
      v5,
      &__comp1,
      &value);
  }
  else
  {
    qmemcpy(&v8->second, in_parameters, sizeof(v8->second));
  }
}

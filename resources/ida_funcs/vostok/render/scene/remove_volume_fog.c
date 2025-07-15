void __thiscall vostok::render::scene::remove_volume_fog(
        vostok::render::scene *this,
        vostok::render::scene *id,
        unsigned int ida)
{
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *M_finish; // esi
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *v4; // eax
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *v5; // eax
  unsigned int v6; // eax

  M_finish = id->m_volume_fogs._M_impl._M_finish;
  v4 = stlp_std::priv::__lower_bound<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,unsigned int,associative_vector_compare_predicate<unsigned int,vostok::render::volume_fog_parameters,stlp_std::less<unsigned int>>,associative_vector_compare_predicate<unsigned int,vostok::render::volume_fog_parameters,stlp_std::less<unsigned int>>,int>(
         id->m_volume_fogs._M_impl._M_start,
         M_finish,
         &ida);
  if ( v4 != M_finish && ida >= v4->first )
    M_finish = v4;
  if ( M_finish != id->m_volume_fogs._M_impl._M_finish )
  {
    v5 = id->m_volume_fogs._M_impl._M_finish;
    if ( &M_finish[1] != v5 )
    {
      v6 = (char *)v5 - (char *)&M_finish[1];
      if ( v6 )
        memmove((unsigned __int8 *)M_finish, (unsigned __int8 *)&M_finish[1], v6);
    }
    --id->m_volume_fogs._M_impl._M_finish;
  }
}

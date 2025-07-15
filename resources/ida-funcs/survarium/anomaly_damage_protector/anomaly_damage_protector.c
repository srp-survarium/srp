void __userpurge survarium::anomaly_damage_protector::anomaly_damage_protector(
        const survarium::damage_model *model@<eax>,
        survarium::anomaly_damage_protector *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function1<void,vostok::physics::contact_point const &> v3; // [esp+20h] [ebp-24h] BYREF

  this->reduce_incoming_damage_functor.vtable = 0;
  this->reduce_final_damage_functor.vtable = 0;
  this->protect_affect_functor.vtable = 0;
  this->m_model = model;
  v3.functor.vostok_pointer_size_alignment[3] = 0;
  v3.functor.vostok_pointer_size_alignment[2] = survarium::anomaly_damage_protector::reduce_damage;
  v3.functor.bound_memfunc_ptr.obj_ptr = this;
  this->next = 0;
  this->__vftable = (survarium::anomaly_damage_protector_vtbl *)&survarium::anomaly_damage_protector::`vftable';
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v3.vtable = 0;
  }
  else
  {
    v3.functor.obj_ptr = survarium::anomaly_damage_protector::reduce_damage;
    v3.functor.vostok_pointer_size_alignment[1] = 0;
    *((_QWORD *)&v3.functor.data + 1) = __PAIR64__(
                                          (unsigned int)v3.functor.vostok_pointer_size_alignment[5],
                                          (unsigned int)this);
    v3.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::anomaly_damage_protector,char const *,enum survarium::hit_type_enum,float &,float &>,boost::_bi::list5<boost::_bi::value<survarium::anomaly_damage_protector *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->reduce_incoming_damage_functor,
    &v3);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v3);
}

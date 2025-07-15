void __thiscall vostok::render::skeleton_decal_instance_node::skeleton_decal_instance_node(
        vostok::render::skeleton_decal_instance_node *this,
        vostok::render::decal_instance **in_decal,
        vostok::render::decal_instance *offset,
        const void *bid,
        __int16 a5)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  __int128 v6; // [esp+10h] [ebp-30h]
  boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> v7; // [esp+20h] [ebp-20h] BYREF

  vostok::render::decal_instance_node::decal_instance_node(this, in_decal, offset);
  *in_decal = (vostok::render::decal_instance *)&vostok::render::skeleton_decal_instance_node::`vftable';
  in_decal[4] = 0;
  in_decal[12] = 0;
  in_decal[20] = 0;
  in_decal[22] = 0;
  qmemcpy(in_decal + 23, bid, 0x40u);
  *((_WORD *)in_decal + 78) = a5;
  v7.functor.vostok_pointer_size_alignment[2] = vostok::render::skeleton_decal_instance_node::on_model_updated;
  *(_QWORD *)(&v7.functor.data + 12) = __PAIR64__((unsigned int)in_decal, 0);
  LODWORD(v6) = vostok::render::skeleton_decal_instance_node::on_model_updated;
  *(_QWORD *)((char *)&v6 + 4) = __PAIR64__((unsigned int)in_decal, 0);
  HIDWORD(v6) = v7.functor.vostok_pointer_size_alignment[5];
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v7.vtable = 0;
  }
  else
  {
    v7.functor.bound_memfunc_ptr.memfunc_ptr = v6;
    v7.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::render::skeleton_render_model_instance const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::skeleton_decal_instance_node,vostok::render::skeleton_render_model_instance const &>,boost::_bi::list2<boost::_bi::value<vostok::render::skeleton_decal_instance_node *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    (boost::function1<void,vostok::physics::contact_point const &> *)(in_decal + 4),
    &v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&v7);
}

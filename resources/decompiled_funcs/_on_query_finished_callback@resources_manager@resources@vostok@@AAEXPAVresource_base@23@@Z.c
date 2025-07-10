void __usercall vostok::resources::resources_manager::on_query_finished_callback(
        vostok::resources::resources_manager *this@<eax>,
        vostok::resources::resource_base *resource@<edx>)
{
  int v2; // ecx
  _DWORD *v3; // eax
  int v4; // ecx

  v2 = *(int *)((char *)&dword_205B0 + (_DWORD)this);
  v3 = (int *)((char *)&dword_205B0 + (_DWORD)this);
  v4 = -(v2 != 0);
  if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v4) != 0 )
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      (boost::function1<void,char const *> *)v4,
      v3,
      (const char *)resource);
}

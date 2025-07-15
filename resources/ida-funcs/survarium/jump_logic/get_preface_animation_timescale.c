void __usercall survarium::jump_logic::get_preface_animation_timescale(survarium::jump_logic *this@<ecx>, int a2@<edi>)
{
  vostok::animation::animation_player *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v4; // [esp-Ch] [ebp-D0h]
  vostok::resources::managed_resource *v5; // [esp-8h] [ebp-CCh]
  vostok::animation::animation_states_dumper dumper; // [esp+4h] [ebp-C0h] BYREF
  char v7[124]; // [esp+Ch] [ebp-B8h] BYREF
  int v8; // [esp+88h] [ebp-3Ch]
  int v9; // [esp+8Ch] [ebp-38h]
  boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> animation_resolver; // [esp+94h] [ebp-30h] BYREF
  int v11; // [esp+B4h] [ebp-10h]
  int v12; // [esp+B8h] [ebp-Ch]
  int v13; // [esp+BCh] [ebp-8h]
  float v14; // [esp+C0h] [ebp-4h]

  v5 = *(vostok::resources::managed_resource **)(a2 + 312);
  v4 = *(stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > **)(*(_DWORD *)(a2 + 304) + 56);
  v14 = g_jump_prepare_interval_length;
  survarium::fwd_animation_interval_end_time_calculator::fwd_animation_interval_end_time_calculator(
    (survarium::fwd_animation_interval_end_time_calculator *)this,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&dumper,
    v4,
    v5);
  animation_resolver.vtable = 0;
  vostok::animation::animation_player::dump_animation_states(
    v2,
    (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(a2 + 312) + 848),
    &dumper,
    &animation_resolver);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&animation_resolver);
  v12 = v9;
  v13 = v8;
  v11 = v9;
  `vector destructor iterator'(
    v7,
    4u,
    30,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::~resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>);
}

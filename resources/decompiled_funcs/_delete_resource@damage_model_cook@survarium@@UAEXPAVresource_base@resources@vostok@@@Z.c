void __thiscall survarium::damage_model_cook::delete_resource(
        survarium::damage_model_cook *this,
        survarium::damage_model *resource)
{
  survarium::affects_threshold *i; // [esp+28h] [ebp-28h]
  survarium::affects_threshold *threshold; // [esp+34h] [ebp-1Ch]
  const stlp_std::pair<survarium::body_part_parameters *,float> *it; // [esp+38h] [ebp-18h]
  survarium::hit_type_parameters *type; // [esp+44h] [ebp-Ch]
  survarium::body_part_parameters *part; // [esp+48h] [ebp-8h]
  survarium::damage_model *model_res; // [esp+4Ch] [ebp-4h]

  model_res = resource;
  while ( 1 )
  {
    part = (survarium::body_part_parameters *)survarium::damage_model::pop_body_part(model_res);
    if ( !part )
      break;
    while ( 1 )
    {
      type = (survarium::hit_type_parameters *)survarium::body_part_parameters::pop_hit_type(part);
      if ( !type )
        break;
      for ( it = (const stlp_std::pair<survarium::body_part_parameters *,float> *)&type[1];
            it != (const stlp_std::pair<survarium::body_part_parameters *,float> *)((char *)&type[1]
                                                                                  + 8 * type->m_bdb_count);
            ++it )
      {
        ;
      }
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)type);
    }
    while ( 1 )
    {
      threshold = (survarium::affects_threshold *)survarium::body_part_parameters::pop_threshold(part);
      if ( !threshold )
        break;
      for ( i = threshold + 1;
            i != (survarium::affects_threshold *)((char *)&threshold[1] + 4 * threshold->m_affects_count);
            i = (survarium::affects_threshold *)((char *)i + 4) )
      {
        ;
      }
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)threshold);
    }
    survarium::body_part_parameters::~body_part_parameters(part);
  }
  ((void (__thiscall *)(survarium::damage_model *, _DWORD))model_res->~vostok::resources::resource_base)(model_res, 0);
  ___free_helper_Vdoug_lea_allocator_memory_vostok____CBX_memory_vostok__YAXAAVdoug_lea_allocator_01_AAPBX_Z(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    (void **)&resource);
}

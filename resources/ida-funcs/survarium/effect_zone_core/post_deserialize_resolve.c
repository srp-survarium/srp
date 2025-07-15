void __userpurge survarium::effect_zone_core::post_deserialize_resolve(
        survarium::effect_zone_core *this@<ecx>,
        const stlp_std::__false_type *a2@<edi>,
        survarium::game_world_core *__formal)
{
  survarium::collision_sensor::requery_overlapping_objects(
    (survarium::effect_zone_core *)((char *)this - 44),
    a2,
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>)&this[-1].survarium::tickable_object);
}

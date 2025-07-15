bool __userpurge vostok::physics::bullet_character_controller::can_straighten@<al>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        const btVector3 *a2@<eax>,
        vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>::cache_predicate a3@<edi>,
        const stlp_std::random_access_iterator_tag *a4@<esi>,
        const btVector3 *current_position,
        btVector3 *current_step_offset,
        btVector3 *ceiling_normal)
{
  return !vostok::physics::character_controller_straighten_tester::convex_sweep_test(
            (vostok::physics::character_controller_straighten_tester *)this,
            a3,
            a4,
            (stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type> *)&a2[53],
            current_position->mVec128.m128_f32,
            current_step_offset,
            ceiling_normal);
}
